/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:37:27 by jhusso            #+#    #+#             */
/*   Updated: 2022/11/16 13:35:15 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(ptr);
	while (len >= 0)
	{
		if (ptr[len] == (char)c)
			return ((char *)(&ptr[len]));
		len--;
	}
	return (NULL);
}
