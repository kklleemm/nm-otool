/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:19:16 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/08 12:19:14 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO use libft
 */

#include <nm-otool.h>

static void					nm(void *ptr)
{
	unsigned int			first_bytes;

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
