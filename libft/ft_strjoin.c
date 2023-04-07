/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:13:37 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/01 16:01:36 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(s1)) + (ft_strlen(s2)) + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		r[i] = s2[j];
		j++;
		i++;
	}
	r[i] = '\0';
	return (r);
}
