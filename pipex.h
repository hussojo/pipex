/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:01:24 by jhusso            #+#    #+#             */
/*   Updated: 2023/04/07 11:55:19 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
// perror, prinf
# include <stdio.h>
// malloc, free exit
# include <stdlib.h>
// strerror
# include <string.h>
// open
# include <fcntl.h>
// errno
# include <errno.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	char	**cmd1;
	char	**cmd2;
	pid_t	pid1;
	pid_t	pid2;
	char	*path;
	char	**split_path;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_pipex;

// children.c
void	first_child(t_pipex *pipex, char **envp, char **av);
void	second_child(t_pipex *pipex, char **envp, char **av);

// pipex_utils.c
void	error(char *msg, int flag);
void	error_msg(char *msg, char *def, int flag);
void	close_pipe(t_pipex *pipex);
void	free_in_main(t_pipex *pipex);
void	waiter(t_pipex *pipex);

// main.c
char	*get_cmd_path(char *cmd, char **path);
char	*get_path(char **envp);
void	init_pipex(t_pipex *pipex, char **envp);

#endif
