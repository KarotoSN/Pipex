




#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>




typedef struct s_pipex
{
    char **av;
    char **cmd;
    char **all_path;
    char *path;
    int ac;
    int nb_cmd;
    int index;
    int fd_pipe[2];
    int fd_infile;
    int fd_outfile;
    int fd_temp;
    pid_t *pid;
} t_pipex;

/* Project function prototypes */
void    data_init(int ac, char **av, t_pipex *data);
void    ft_loop( t_pipex *data, char **envp);
void    ft_free_map(char **str);
void    ft_error(t_pipex *data, int error);

/* execution / child helpers */
void    exec( t_pipex *data, char **envp);
void    ft_first_command(t_pipex *data);
void    ft_middle_command(t_pipex *data);
void    ft_last_command(t_pipex *data);

/* path helpers */
void    get_path(t_pipex *data, char **envp);
int     is_path(char *str);
char    *path_check(t_pipex *data);
void    ft_path(char **envp, t_pipex *data);

/* misc helpers */
void    ft_close(t_pipex *data);
void    ft_wait(t_pipex *data);

char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
void ft_putstr_fd(char *s, int fd);
size_t ft_strlen(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);


#endif
