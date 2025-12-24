/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:37:22 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 10:46:24 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int charset)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)charset)
			return ((char *)(s + i));
		i--;
	}
	if ((char)charset == '\0')
		return ((char *)&s[i]);
	return (0);
}

/*int	main()
{
	char	a[] = "Chainsaw man";

	printf("%s\n", ft_strrchr(a, 'n'));
	printf("%s", strrchr(a, 'n'));
}*/
