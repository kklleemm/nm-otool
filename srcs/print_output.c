/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:10:23 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/08 12:20:19 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Output should look like :
 ** 0000000100000000 T _main
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
		printf ("%s\n", str_tab + array[i].n_un.n_strx);
	}
}
