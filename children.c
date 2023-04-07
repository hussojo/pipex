/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:13:14 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/07 12:45:59 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex *pipex, char **envp, char **av)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		error(av[1], 1);
	pipex->cmd1 = ft_pipex_split(av[2], ' ');
	if (!pipex->cmd1[0])
		error_msg("command not found", *pipex->cmd1, 1);
	pipex->cmd1_path = get_cmd_path(*pipex->cmd1, pipex->split_path);
	if (pipex->cmd1_path == NULL)
		error_msg("command not found", *pipex->cmd1, 1);
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		error("Error", 1);
	close(pipex->fd[0]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		error("Error", 1);
	if (pipex->infile != -1)
	{
		if (execve(pipex->cmd1_path, pipex->cmd1, envp) == -1)
			error("Error in execve1()", 1);
	}
	exit(0);
}

void	second_child(t_pipex *pipex, char **envp, char **av)
{
	pipex->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		error(av[4], 1);
	pipex->cmd2 = ft_pipex_split(av[3], ' ');
	if (!pipex->cmd2[0])
		error_msg("command not found", *pipex->cmd2, 1);
	pipex->cmd2_path = get_cmd_path(*pipex->cmd2, pipex->split_path);
	if (pipex->cmd2_path == NULL)
		error_msg("command not found", *pipex->cmd2, 1);
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		error("Error 3", 1);
	close(pipex->fd[1]);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		error("Error 4", 1);
	if (pipex->outfile != -1)
	{
		if ((execve(pipex->cmd2_path, pipex->cmd2, envp) == -1))
			error("Error in execve2()", 1);
	}
	exit(0);
}
