/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:06:00 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/06 20:07:43 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strrev_sign(char *s, int sign)
{
	int		start;
	int		end;
	char	temp;

	start = sign;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
	return (s);
}

static long long	ft_abs(long long n)
{
	long long	nbr;

	nbr = 1;
	if (n < 0)
		nbr *= -n;
	else
		nbr *= n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	int				size;
	int				sign;
	unsigned int	nbr;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	size = ft_nbrlen(n);
	res = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (!res)
		return (NULL);
	nbr = ft_abs(n);
	if (sign)
		res[i++] = '-';
	while (i < size + sign)
	{
		res[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	res[i] = '\0';
	ft_strrev_sign(res, sign);
	return (res);
}
