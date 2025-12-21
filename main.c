



#include "pipex.h"


int main(int ac, char **av, char **envp)
{
    t_pipex data;
    if(ac != 5)
        return(ft_putstr_fd("ERREUUUOWWRR", 2), 0);
    
    data_init(ac, av, &data);
    ft_loop(&data, envp);
    ft_close(&data);
    ft_wait(&data);
}
void    data_init(int ac, char **av, t_pipex *data)
{
    data->av = av;
    data->ac = ac;
    data->nb_cmd = ac - 3;
    data->index = 0;
    data->pid = malloc(sizeof(pid_t) * data->nb_cmd);
}

void ft_loop(t_pipex *data, char **envp)
{
    data->fd_pipe[0] = -1;
    while (data->index < data->nb_cmd)
    {
        data->fd_temp = data->fd_pipe[0];
        if(data->index < data->nb_cmd - 1)
        {
            if(pipe(data->fd_pipe) == -1)
            {
                perror("Pipe");
            }
        }
        data->pid[data->index] = fork();
        if(data->pid[data->index] == 0)
            exec(data, envp);
        if(data->fd_pipe[1] > 0)
            close(data->fd_pipe[1]);
        if(data->fd_temp > 0)
            close(data->fd_temp);
        data->index++;
    }
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	ft_error(t_pipex *data, int error)
{
	(void)error;
	if (data->all_path)
		ft_free_map(data->all_path);
	if (data->cmd)
		ft_free_map(data->cmd);
	if (data->pid)
		free(data->pid);
	if (data->path)
		free (data->path);
	ft_close(data);
	exit (EXIT_FAILURE);
}