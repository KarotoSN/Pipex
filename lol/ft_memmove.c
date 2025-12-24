/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:33:23 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 10:48:09 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*s;

	dest = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dest > s)
	{
		while (len-- > 0)
			dest[len] = s[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
/*int	main(void)
{
	char	a[] = "Jeune pablito";
	char	b[] = "sacre dozo";

	printf("%s\n", (char *)ft_memmove(b, a, 10));
	printf("%s", (char *)memmove(b, a, 10));
}*/
