/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:19:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/07 15:50:43 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
** TODO use libft
 */

void						print_output(int nsyms, int symoff, int stroff, void *ptr)
{
	int						i;
	char					*str_tab;
	struct nlist_64			*array;

	array = ptr + symoff;
	str_tab = ptr + stroff;
	for (i = 0 ;  i < nsyms ; ++i)
	{
		printf ("%s\n", str_tab + array[i].n_un.n_strx);
	}
}

void						handle_64(char *ptr)
{
	int						ncmds;
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						i;
	struct symtab_command	*sym;

	i = 0;
	header = (struct mach_header_64 *) ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header); 
	for (i = 0 ; i < ncmds ; ++i)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *) lc + lc->cmdsize;
	}
}

void						nm(void *ptr)
{
	int						first_bytes;

	first_bytes = *(int *) ptr;
	if (first_bytes == MH_MAGIC_64)
		handle_64(ptr);
}

int							main(int ac, char **av)
{
	int						fd;
	char					*ptr;
	struct stat				buf;

	if (ac != 2)
	{
		fprintf(stderr, "Argument required\n");
		return (EXIT_FAILURE);
	}

	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		perror("open");
		return (EXIT_FAILURE);
	}

	if (fstat(fd, &buf) < 0)
	{
		perror("fstat");
		return (EXIT_FAILURE);
	}

	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		perror("mmap");
		return (EXIT_FAILURE);
	}

	nm(ptr);

	if (munmap(ptr, buf.st_size) < 0)
	{
		perror("munmap");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
