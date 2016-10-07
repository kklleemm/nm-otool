/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:59:58 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/07 17:12:14 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void						ft_error(int errnum)
{
	char						*ret;
	extern const char *const	sys_errlist[];
	extern const int			sys_nerr;

	ret = NULL;
	if (errnum < 0 || errnum >= sys_nerr)
	{
		errno = EINVAL;
		write (1, "Error ID = ", 11);
		ret = ft_itoa(errnum);
		write (1, ret, ft_strlen(ret));
	}
	ret = (char*)sys_errlist[errnum];
	write (1, ret, ft_strlen(ret));
}

void							ft_perror(const char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
		write(2, " :", 2);
	}
	ft_error(errno);
	write(2, "\n", 1);
}
