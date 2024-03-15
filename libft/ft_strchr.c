/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:33:01 by ede-cola          #+#    #+#             */
/*   Updated: 2023/11/09 18:30:20 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return (&((char *)s)[i]);
	else
		return ((void *) NULL);
}
