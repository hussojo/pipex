/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:22:08 by jhusso            #+#    #+#             */
/*   Updated: 2022/11/16 15:14:35 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			n_len;
	size_t			h_len;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	i = 0;
	while (i < h_len && i <= len - n_len)
	{
		if (haystack[i] == *needle)
		{
			if (ft_strncmp(&haystack[i], needle, n_len) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
