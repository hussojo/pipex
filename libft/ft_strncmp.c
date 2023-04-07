/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:28:55 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/06 14:30:41 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
