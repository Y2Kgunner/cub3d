/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:43:18 by lel-khou          #+#    #+#             */
/*   Updated: 2021/10/15 17:01:51 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof (char) * len + 1);
	if (dest == 0)
		return (0);
	while (i <= len)
	{
		dest[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (dest);
}
