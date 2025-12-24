/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 01:02:41 by aarab             #+#    #+#             */
/*   Updated: 2025/12/24 09:44:04 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include "lol/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		index;
	char	**all_path;
	char	**cmd;
	char	**av;
	char	*path;
	int		ac;
	int		nb_cmd;
	int		fd_pipe[2];
	int		fd_infile;
	int		fd_outfile;
	int		fd_temp;
	pid_t	*pid;

}			t_pipex;

// le main, oui.
void data_init(int ac, char **av, t_pipex *data);
void ft_loop(t_pipex *data, char **envp);
void ft_close(t_pipex *data);
void ft_wait(t_pipex *data);

// avoir le path
void get_path(char **envp, t_pipex *data);
int is_path(char *str);
char *path_check(t_pipex *data);
void ft_path(char **envp, t_pipex *data);

//enfant (fork)
void exec(t_pipex *data, char **envp);
void ft_first_command(t_pipex *data);
void ft_middle_command(t_pipex *data);
void ft_final_command(t_pipex *data);

//errowrrs
void ft_error_path(t_pipex *data);
void ft_error(t_pipex *data);
void ft_free_map(char **str);

#endif