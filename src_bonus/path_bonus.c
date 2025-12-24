/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:53:52 by aarab             #+#    #+#             */
/*   Updated: 2025/12/24 09:44:12 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


void get_path(char **envp, t_pipex *data)
{
    int i;

    i = data->index + 2;
    ft_path(envp, data);
    data->cmd = ft_split(data->av[i], ' ');
    if(is_path(data->cmd[0]) == 0)
        data->path = path_check(data);
    else
        data->path = ft_strdup(data->av[i]);
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
            return (1);
        i++;
    }
    return (0);
}

char *path_check(t_pipex *data)
{
   char *str;
   char *path;
   int i;

   i = 0;
   if(!data->cmd || !data->cmd[0])
        ft_putstr_fd("embarrasing '' exsit in your dream", 2);
    str = ft_strjoin("/", data->cmd[0]);
    while(data->all_path[i])
    {
        path = ft_strjoin(data->all_path[i], str);
        if(access(path, X_OK) == 0)
            return(free(str), path);
        free(path);
        i++;
    }
    ft_error_path(data);
    ft_error(data);
    return(NULL);
}

void ft_error_path(t_pipex *data)
{
    char *str;
    char *str2;
    
    str = ft_strjoin("Commande '", data->cmd[0]);
    str2 = ft_strjoin(str, "' pas trouver");
    write(2, &str2, 3);
    free(str);
    free(str2);
    ft_close(data);
}

void ft_path(char **envp, t_pipex *data)
{
    int i;
    
    i = 0;
    
    while(envp[i] && envp && ft_strncmp(envp[i], "PATH=", 5))
        i++;
    if(!envp || !envp[i])
        return ;
    data->all_path = ft_split(envp[i] + 5, ':');
}