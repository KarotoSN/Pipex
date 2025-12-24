/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:36:40 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 11:02:34 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t length)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if ((!str1 && !str2) || !length)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i] && i < length - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*int main()
{
	char a[] = "Chainsaw Man";
	char b[] = "Chainsaw Girl";

	printf("fake -> %d\n", ft_strncmp(a,b, 10));
	printf("vreel -> %d", strncmp(a,b, 10));
}*/