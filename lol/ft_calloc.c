/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:26:05 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 14:42:24 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*str;

	if (elementSize != 0 && elementCount > SIZE_MAX / elementSize)
		return (NULL);
	str = malloc(elementCount * elementSize);
	if (!str)
		return (NULL);
	ft_bzero(str, elementCount * elementSize);
	return (str);
}
/*int main()
{
	printf("%s", (char *)ft_calloc(4, 1));
	printf("%s", (char *)calloc(4, 1));
}*/