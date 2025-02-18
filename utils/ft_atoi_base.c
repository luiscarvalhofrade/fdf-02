/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:49:19 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/12 19:56:24 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	hex_util(char ptr, int *digit, int *value)
{
	if ('0' <= ptr && ptr <= '9')
		*digit = ptr - '0';
	else if ('a' <= ptr && ptr <= 'f')
		*digit = ptr - 'a' + 10;
	else if ('A' <= ptr && ptr <= 'F')
		*digit = ptr - 'A' + 10;
	else
	{
		*digit = 16;
		return ;
	}
	*value = *value * 16 + *digit;
}

int	ft_atoi_hex(char *nptr)
{
	int	value;
	int	minus;
	int	digit;

	value = 0;
	minus = 1;
	if (*nptr == '0' && (*(nptr + 1) == 'x' || *(nptr + 1) == 'X'))
		nptr += 2;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr)
	{
		hex_util(*nptr, &digit, &value);
		if (digit >= 16)
			break ;
		nptr++;
	}
	return (minus * value);
}
