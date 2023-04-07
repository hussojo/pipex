/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:38:35 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/07 08:43:40 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *str, char c, int nb_words)
{
	int	flag;
	int	i;

	flag = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != c)
		{
			if (str[i] == 39)
			{
				i++;
				while (str[i] != 39)
					i++;
				nb_words++;
			}
			else if ((str[i + 1] == c && flag == 0)
				|| str[i + 1] == '\0' || str[i + 1] == 39)
			{
				nb_words++;
				flag = 0;
			}
		}
	}
	return (nb_words);
}

int	count_p_words(char const *str, char c)
{
	int	nb_words;
	int	flag;

	nb_words = 0;
	flag = 0;
	if (*str == 0)
		return (0);
	nb_words = count(str, c, nb_words);
	return (nb_words);
}

int	word_p_length(char const *s, int i, char c)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	if (s[i - 1] == 39)
	{
		flag = 1;
	}
	while (((s[i] != c && s[i] != 39) || (s[i] == c && flag == 1)) && s[i])
	{
		size++;
		i++;
		if (flag == 1 && s[i] == 39)
			flag = 0;
	}
	return (size);
}

char	**set_p_words(char **array, int words, char const *s, char c)
{
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c || s[j] == 39)
			j++;
		size = word_p_length(s, j, c);
		array[i] = malloc(size + 1);
		ft_strlcpy(array[i], &s[j], size + 1);
		if (array[i] == NULL)
		{
			while (--i)
				free(array[i]);
			return (NULL);
		}
		j = j + size;
		i++;
	}
	return (array);
}

char	**ft_pipex_split(char const *s, char c)
{
	char	**array;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_p_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	array = set_p_words(array, words, s, c);
	return (array);
}
