/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:21:35 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 11:35:34 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list *Chainsaw = ft_lstnew("Pablito");
	t_list *Man = ft_lstnew("Dozo");
	t_list *Zergling = ft_lstnew("Chnowa");

	Chainsaw->next = Man;
	Man->next = Zergling;
	
	printf("%d", ft_lstsize(Chainsaw));

	free(Chainsaw);
	free(Man);
	free(Zergling);
	
}*/
