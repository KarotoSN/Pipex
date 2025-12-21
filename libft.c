
#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*str;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[x++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[x++] = s2[i++];
	}
	str[x] = '\0';
	return (str);
}

static int	ischar(char s, char c)
{
	if (s == c)
	{
		return (1);
	}
	return (0);
}

static size_t	countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ischar(s[i], c))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !ischar(s[i], c))
			{
				i++;
			}
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	debut;
	size_t	fin;
	char	**tab;

	i = 0;
	debut = 0;
	fin = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[fin])
	{
		while (s[fin] && ischar(s[fin], c))
			fin++;
		debut = fin;
		while (s[fin] && !ischar(s[fin], c))
			fin++;
		if (fin > debut)
			tab[i++] = ft_substr(s, debut, fin - debut);
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	i = 0;
	while (s[i])
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}