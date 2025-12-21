#include "pipex.h"

void ft_close(t_pipex *data)
{
    if(data->fd_infile)
        close(data->fd_infile);
    if(data->fd_outfile)
        close(data->fd_outfile);
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
        waitpid(data->pid[data->index], NULL, 0);
    free(data->pid);
}