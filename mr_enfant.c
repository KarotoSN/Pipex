#include "pipex.h"

void exec(t_pipex *data, char **envp)
{
    if(data->index == 0)
        ft_first_command(data);
    else if(data->index != data->nb_cmd - 1)
        ft_middle_command(data);
    else
        ft_last_command(data);
    get_path(data, envp);
    execve(data->path, data->cmd, envp);
}


void ft_first_command(t_pipex *data)
{
    close(data->fd_pipe[0]);
    data->fd_infile = open(data->av[1], O_RDONLY);
    dup2(data->fd_infile, STDIN_FILENO);
    dup2(data->fd_pipe[1], STDOUT_FILENO);
}
void ft_middle_command(t_pipex *data)
{
    close(data->fd_pipe[0]);
    dup2(data->fd_temp, STDIN_FILENO);
    dup2(data->fd_pipe[1], STDOUT_FILENO);
}
void ft_last_command(t_pipex *data)
{
    data->fd_outfile = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    dup2(data->fd_temp, STDIN_FILENO);
    dup2(data->fd_outfile, STDOUT_FILENO);
}