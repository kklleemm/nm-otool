/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:37:27 by cdeniau           #+#    #+#             */
/*   Updated: 2016/10/15 17:56:55 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	arr_swap(void *arr_, int i, int j)
{
	void	*tmp;
	void	**arr;

	arr = arr_;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int 	cmp_fn(void *ptr1, void *ptr2, char *str_tab)
{
	char	*str1;
	char	*str2;
	int		ret;

	str1 = ft_strdup(str_tab + (struct nlist_64 *) ptr1.n_un.n_strx);
	str2 = ft_strdup(str_tab + (struct nlist_64 *) ptr2.n_un.n_strx);
	ret = (ft_strcmp(str1, str2) < 0);
	free (str1);
	free (str2);
	return (ret);
}

static int	arr_len(void *arr_)
{
	int		size;
	void	**arr;

	arr = arr_;
	size = 0;
	while (arr[size])
		size++;
	return (size);
}

void		ft_arr_sort(void *arr_, char *str_tab)
{
	int		i;
	int		j;
	int		size;
	void	**arr;

	i = 0;
	size = arr_len(arr_);
	arr = arr_;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (cmp_fn(arr[j + 1], arr[j], str_tab))
				arr_swap(arr, j + 1, j);
			j++;
		}
		i++;
	}
}
