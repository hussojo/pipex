/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:55:17 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/07 14:07:55 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *def, int flag)
{
	ft_putstr_fd((strerror(errno)), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(def, 2);
	ft_putchar_fd('\n', 2);
	if (flag == 1)
		exit(1);
}

void	error_msg(char *msg, char *def, int flag)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(def, 2);
	ft_putchar_fd('\n', 2);
	if (flag == 1)
		exit(1);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	free_in_main(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free_array(pipex->split_path);
	exit(0);
}

void	waiter(t_pipex *pipex)
{
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
