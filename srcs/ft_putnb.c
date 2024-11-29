/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:44:30 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/21 20:44:03 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put16(int a, int i)
{
	char	*hex;

	if (a == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	ft_putchar(hex[i]);
}

size_t	ft_putn16(void *v)
{
	unsigned long long	mp;
	size_t				result;

	result = 0;
	if (v == NULL)
		return (ft_putstr("0x0", 0));
	result += ft_putstr("0x", 0);
	mp = (unsigned long long)v;
	ft_putmp(mp, &result);
	return (result);
}

void	ft_putmp(unsigned long long mp, size_t *result)
{
	int	a;

	a = mp % 16;
	if (mp < 16)
	{
		ft_put16(1, a);
	}
	else
	{
		ft_putmp(mp / 16, result);
		ft_put16(1, a);
	}
	*result += 1;
}

void	ft_putnx16(unsigned int i, size_t *result)
{
	int	a;

	a = i % 16;
	if (i < 16)
	{
		ft_put16(1, i);
	}
	else
	{
		ft_putnx16(i / 16, result);
		ft_put16(1, a);
	}
	*result += 1;
}

void	ft_putxn16(unsigned int i, size_t *result)
{
	int	a;

	a = i % 16;
	if (i < 16)
	{
		ft_put16(2, i);
	}
	else
	{
		ft_putxn16(i / 16, result);
		ft_put16(2, a);
	}
	*result += 1;
}
