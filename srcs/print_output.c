/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:10:23 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/08 15:58:42 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Output should look like :
 ** 0000000100000000 T _main
 ** With :
 ** Symbol value (default is hex),
 ** Symbol type. Uppercase means global symbol (external),
 ** Symbol name.
 */

#include <nm-otool.h>

void						print_output(int nsyms, int symoff, int stroff, void *ptr)
{
	int						i;
	char					*str_tab;
	struct nlist_64			*array;

	array = ptr + symoff;
	str_tab = ptr + stroff;
	for (i = 0 ;  i < nsyms ; ++i)
	{
		ft_print_hex((void *) array[i].n_value);
		if (array[i].n_type == N_STAB)
			ft_putstr("Symbolic debugging entry");
		else if (array[i].n_type == N_PEXT)
			ft_putstr("Private external symbol bit");
		else if (array[i].n_type == N_TYPE)
			ft_putstr("Mask for the type bits");
		else if (array[i].n_type == N_EXT)
			ft_putstr("External symbol bit, set for external symbols");

		write (1, " | ", 3);

		if (array[i].n_sect == N_INDR)
			ft_putstr("Type indirect");
		else if (array[i].n_sect == N_UNDF)
			ft_putstr("Undefined");
		else if (array[i].n_sect == N_SECT)
			ft_putstr("Defined in section number n_sect");
		else if (array[i].n_sect == N_PBUD)
			ft_putstr("Prebound undefined (defined in a dylib)");
		else if (array[i].n_sect == N_INDR)
			ft_putstr("Indirect");

		write (1, " | ", 3);
		printf ("%s\n", str_tab + array[i].n_un.n_strx);
	}
}
