/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:12:07 by aarab             #+#    #+#             */
/*   Updated: 2025/11/08 14:42:42 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int main()
{
	printf("%s", ft_strjoin("Chainsaw","Man"));
}*/