/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:28:29 by aarab             #+#    #+#             */
/*   Updated: 2025/12/24 21:37:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free_map(char **str)
{
    int i;
    
    i = 0;
    if(!str)
        return;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    if(str)
        free(str);
}

void ft_error(t_pipex *data)
{
    if(data->all_path)
        free(data->all_path);
    if(data->cmd)
        free(data->cmd);
    if(data->pid)
        free(data->pid);
    if(data->path)
        free(data->path);
    ft_close(data);
    exit(EXIT_FAILURE); 
}