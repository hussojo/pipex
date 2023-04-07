/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:25:42 by jhusso            #+#    #+#             */
/*   Updated: 2022/11/15 13:46:02 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen > dstsize)
		return (slen + dstsize);
	i = 0;
	while (src[i] && dlen + i < dstsize - 1)
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = '\0';
	while (src[i])
		i++;
	return (slen + dlen);
}
