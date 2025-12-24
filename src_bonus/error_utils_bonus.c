/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:28:29 by aarab             #+#    #+#             */
/*   Updated: 2025/12/24 09:45:21 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void ft_free_map(char **str)
{
    int i;
    
    i = 0;
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