/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:36:17 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/25 13:25:39 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_putstr(char *str, int *ch)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] && i < 2147483648)
		i++;
	if (i >= 2147483647)
	{
		*ch = -1;
		return (-1);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int i, size_t *result)
{
	int	ms;

	ms = i % 10;
	if (i >= -9 && i <= 9)
	{
		if (i < 0)
		{
			i *= -1;
			ft_putchar('-');
			*result += 1;
		}
		ft_putchar(i + '0');
	}
	else
	{
		ft_putnbr(i / 10, result);
		if (ms < 0)
			ms *= -1;
		ft_putchar(ms + '0');
	}
	*result += 1;
}

void	ft_putunbr(unsigned int i, size_t *result)
{
	if (i <= 9)
		ft_putchar(i + '0');
	else
	{
		ft_putunbr(i / 10, result);
		ft_putchar((i % 10) + '0');
	}
	*result += 1;
}
