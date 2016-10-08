/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:07:51 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/08 12:11:28 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm-otool.h>

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
