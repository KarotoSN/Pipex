/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarab <aarab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:23:45 by aarab             #+#    #+#             */
/*   Updated: 2025/11/12 11:53:10 by aarab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew((*f)(lst->content));
	if (!tmp)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	node = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&node, tmp);
	}
	return (node);
}
/*void del(void *content)
{
	free(content);
}
int main()
{
	t_list *Chainsaw = ft_lstnew("Pablito");
	t_list *Man = ft_lstnew("Dozo");
	t_list *Zergling = ft_lstnew("Chnowa");

	Chainsaw->next = Man;
	Man->next = Zergling;
	
	t_list *map = ft_lstmap(Chainsaw, (void *)ft_toupper, del);
	t_list *temp = map;

	while(temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	
	
}*/
