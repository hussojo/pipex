/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:35:04 by jhusso            #+#    #+#             */
/*   Updated: 2022/11/15 10:25:14 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_len(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	set_nb(char *str, long *nb)
{
		str[0] = '-';
		*nb = *nb * -1;
}

void	count_nb(char *str, long *nb, int *len)
{
		str[*len - 1] = '0' + (*nb % 10);
		*nb = *nb / 10;
		(*len)--;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	long	nb;

	len = i_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	nb = (long)n;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		set_nb(str, &nb);
	i = len;
	while (nb > 0)
		count_nb(str, &nb, &len);
	str[i] = '\0';
	return (str);
}
