/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:10:23 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/15 17:55:05 by cdeniau          ###   ########.fr       */
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

#define HUE 0xff

void						print_output(int nsyms, int symoff, int stroff, void *ptr)
{
	int						i;
	char					*str_tab;
	struct nlist_64			*array;

	array = ptr + symoff;
	str_tab = ptr + stroff;
	ft_arr_sort(array, str_tab);
	for (i = 0 ;  i < nsyms ; ++i)
	{
		array[i].n_value ? ft_print_hex((void *) array[i].n_value) : write (1, "                  ", 17);
	//	printf ("%d\n", array[i].n_type & HUE);
		if (array[i].n_type == N_PEXT)
			ft_putstr("T");// Private external symbol bit
		else if (array[i].n_type == N_TYPE)
			ft_putstr("t");// Mask for the type bits
		else if (array[i].n_type == N_EXT)
			ft_putstr("U");//External symbol bit, set for external symbols
	//	else// (array[i].n_type == N_STAB)
//			ft_putstr(" ");// Symbolic debugging entry
		/*
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
		*/
		if (ft_strlen(str_tab + array[i].n_un.n_strx))
			printf (" %s\n", str_tab + array[i].n_un.n_strx);
	}
}
