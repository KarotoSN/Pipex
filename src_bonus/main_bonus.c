/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:03:50 by aarab             #+#    #+#             */
/*   Updated: 2025/12/24 22:11:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **envp)
{
    t_pipex data;
    if(!av[1])
    {
        return(ft_putstr_fd("ERROR ARGUMENT", 2), EXIT_FAILURE);
    }

        data_init(ac, av, &data);
        ft_loop(&data, envp);
        ft_close(&data);
        ft_wait(&data);
}


void data_init(int ac, char **av, t_pipex *data)
{
    data->ac = ac;
    data->av = av;
    data->index = 0;
    data->nb_cmd = ac - 3;
    data->fd_temp = -1;
    data->fd_pipe[0] = -1;
    data->fd_pipe[1] = -1;

    data->pid = malloc(sizeof(pid_t) * data->nb_cmd);
}
void ft_loop(t_pipex *data, char **envp)
{
    data->fd_pipe[0] = -1;
    while(data->index <  data->nb_cmd)
    {
        data->fd_temp = data->fd_pipe[0];
        if(data->index < data->nb_cmd - 1)
        {
            if(pipe(data->fd_pipe) == -1)
                perror("Pipe");
        }
        data->pid[data->index] = fork();
        if(data->pid[data->index] == 0)
            exec(data, envp);
        if(data->fd_temp > 0)
            close(data->fd_temp);
        if(data->fd_pipe[1] > 0)
            close(data->fd_pipe[1]);
        data->index++;
    }
}
void ft_close(t_pipex *data)
{
    if(data->fd_pipe[0])
        close(data->fd_pipe[0]);
    if(data->fd_pipe[1])
        close(data->fd_pipe[1]);
    if(data->fd_temp)
        close(data->fd_temp);
}

void ft_wait(t_pipex *data)
{
    while(data->index--)
    {
        waitpid(data->pid[data->index], NULL, 0);
    }
    free(data->pid);
}