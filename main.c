/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:01:04 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/07 13:59:02 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *cmd, char **path)
{
	char	*temp;
	char	*cmd_path;

	while (*path != NULL)
	{
		temp = ft_strjoin(*path, "/");
		cmd_path = ft_strjoin(temp, cmd);
		if (access(cmd_path, X_OK) == 0)
			return (free(temp), cmd_path);
		free (temp);
		free (cmd_path);
		path++;
	}
	return (NULL);
}

char	*get_path(char **envp)
{
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	init_pipex(t_pipex *pipex, char **envp)
{
	pipex->path = get_path(envp);
	if (pipex->path == NULL)
		error("Error getting envpath", 1);
	pipex->split_path = ft_split(pipex->path, ':');
	if (pipex->split_path == NULL)
		error("Error splitting envpath", 1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (pipe(pipex.fd) == -1)
		error("Error creating pipe", 1);
	if (ac == 5)
	{
		init_pipex(&pipex, envp);
		pipex.pid1 = fork();
		if (pipex.pid1 == -1)
			error("Error forking child1", 1);
		if (pipex.pid1 == 0)
			first_child(&pipex, envp, av);
		free (pipex.cmd1_path);
		pipex.pid2 = fork();
		if (pipex.pid2 == -1)
			error("Error forking child2", 1);
		if (pipex.pid2 == 0)
			second_child(&pipex, envp, av);
		free (pipex.cmd2_path);
		close_pipe(&pipex);
		waiter(&pipex);
		free_in_main(&pipex);
	}
	if (ac < 5 || ac > 5)
		error("Wrong ammount of arguments\n", 1);
}
