/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:06:26 by luide-ca          #+#    #+#             */
/*   Updated: 2024/10/15 18:06:27 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		ch;

	ptr_s = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr_s == ch)
			return ((void *)ptr_s);
		ptr_s++;
		n--;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t		counter_len;
	const char	*ptr_s;

	counter_len = 0;
	ptr_s = s;
	while (*ptr_s++)
	{
		counter_len++;
	}
	return (counter_len);
}

char	*ft_strchr(const char *s, int c)
{
	int	n;

	n = (ft_strlen(s) + 1);
	return (ft_memchr(s, c, n));
}
