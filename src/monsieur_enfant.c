/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsieur_enfant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 01:41:55 by aarab             #+#    #+#             */
/*   Updated: 2025/12/24 21:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_pipex *data, char **envp)
{
	if (data->index == 0)
		ft_first_command(data);
	else if (data->index != data->nb_cmd - 1)
		ft_middle_command(data);
	else
		ft_final_command(data);
	get_path(envp, data);
	if(execve(data->path, data->cmd, envp) == -1)
    {
        ft_error_path(data);
        if(data->pid)
            free(data->pid);
        if(data->cmd)
            free(data->cmd);
        if(data->path)
            free(data->path);
        exit(EXIT_FAILURE);
    };
}

void	ft_first_command(t_pipex *data)
{
	close(data->fd_pipe[0]);
	data->fd_infile = open(data->av[1], O_RDONLY);
    if(data->fd_infile == -1)
    {
        close(data->fd_pipe[1]);
        perror(data->av[1]);
        free(data->pid);
        exit(EXIT_FAILURE);
    }
	if(dup2(data->fd_infile, STDIN_FILENO) == -1)
    {
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
	if(dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
    {
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
}

void	ft_middle_command(t_pipex *data)
{
	close(data->fd_pipe[0]);
	if(dup2(data->fd_temp, STDIN_FILENO) == -1)
    {
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
	if(dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
    {
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
}

void	ft_final_command(t_pipex *data)
{
	data->fd_outfile = open(data->av[data->ac - 1],
			O_TRUNC | O_WRONLY | O_CREAT ,0664);
    if(data->fd_outfile == -1)
    {
        close(data->fd_pipe[0]);
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
	if(dup2(data->fd_temp, STDIN_FILENO) == -1)
    {
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
	if(dup2(data->fd_outfile, STDOUT_FILENO) == -1)
    {
        perror("Error");
        free(data->pid);
        exit(EXIT_FAILURE);
    }
}
