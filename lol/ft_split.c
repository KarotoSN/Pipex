/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:23:03 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 10:36:03 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	int		i;
	char	**tab;


	char	a[] = "Chainsaw,man,en,bien";
	i = 0;
	tab = ft_split(a, ',');
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
	printf("%s\n", tab[4]);
}*/
