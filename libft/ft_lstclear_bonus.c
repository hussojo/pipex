/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:55:36 by jhusso            #+#    #+#             */
/*   Updated: 2022/11/20 13:55:40 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		old = *lst;
		*lst = old->next;
		free(old);
	}
	*lst = NULL;
}
