/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:33:39 by aarab             #+#    #+#             */
/*   Updated: 2025/11/08 14:44:18 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int searchedChar, size_t size)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s1;
	i = 0;
	while (i < size)
	{
		if (str[i] == (unsigned char)searchedChar)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
