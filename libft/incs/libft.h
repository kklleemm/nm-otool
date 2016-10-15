/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:27:48 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/15 17:56:22 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

#include <errno.h> // TODO is it permitted ?
#include <stddef.h> // TODO is it permitted ?

void	ft_perror(const char *s);
void	ft_putstr(char *str);
void	ft_print_hex(void *ptr);
void	ft_putendl(char *str);
void	arr_sort(void *arr_);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int i);
void    *ft_memset(void *, int c, size_t);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_arr_sort(void *arr_, char *str_tab);
char	*ft_strdup(const char *s1);

#endif
