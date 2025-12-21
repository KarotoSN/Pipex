#include "pipex.h"


void get_path(t_pipex *data, char **envp)
{
    int i;

    i = data->index + 2;
    data->cmd = ft_split(data->av[i], ' ');
    ft_path(envp, data);
    if(is_path(data->av[i]) == 0)
        data->path = path_check(data);
    else
        data->path = strdup(data->av[i]);
    if(data->all_path)
        ft_free_map(data->all_path);
}


int is_path(char *str)
{
    int i;
    i = 0;

    while(str[i])
    {
        if(str[i] == '/')
            return(1);
        i++;
    }
    return(0);
}

char *path_check(t_pipex *data)
{
    char *str;
    char *path;
    int i;
    i = 0;
    if(!data->cmd[0] || !data->cmd)
    {
        ft_putstr_fd("command '' not found", 2);
    }
    str = ft_strjoin("/", data->cmd[0]);
    while(data->all_path[i])
    {
        path = ft_strjoin(data->all_path[i], str);
        if(access(path, X_OK) == 0)
        {
            return(free(str), path);
        }
        free(path);
        i++;
    }
	return (NULL);
}

void ft_path(char **envp, t_pipex *data)
{
    int i;
    i = 0;
    while (envp[i] && envp &&strncmp(envp[i], "PATH=", 5))
        i++;
    if(!envp[i] || !envp)
        return ;
    data->all_path = ft_split(envp[i]+5, ':'); 
}