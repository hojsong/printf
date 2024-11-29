/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:35:35 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/25 13:42:15 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	var;
	size_t	i;
	size_t	len;
	int		ch;

	ch = 0;
	i = 0;
	len = 0;
	va_start(var, str);
	while (str[i] && ch == 0)
	{
		if (str[i] == '%')
		{
			len += ft_pty(var, str[i + 1], &ch);
			if (ch == -1)
				return (-1);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(var);
	return (len);
}

size_t	ft_pty(va_list	var, const char c, int *ch)
{
	size_t	result;

	result = 0;
	if (c == 'c')
		result = ft_putchar((char)va_arg(var, int));
	else if (c == 's')
		result = ft_putstr(va_arg(var, char *), ch);
	else if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		result = ft_putint(va_arg(var, int), c);
	else if (c == 'u')
		ft_putunbr((unsigned int)va_arg(var, int), &result);
	else if (c == 'p')
		result = ft_putn16(va_arg(var, void *));
	else if (c == '%' || c == ' ')
		result = ft_putper();
	return (result);
}

size_t	ft_putint(int s, const char c)
{
	size_t	result;

	result = 0;
	if (c == 'd' || c == 'i')
		ft_putnbr(s, &result);
	else if (c == 'x')
		ft_putnx16((unsigned int)s, &result);
	else
		ft_putxn16((unsigned int)s, &result);
	return (result);
}

size_t	ft_putper(void)
{
	write(1, "%", 1);
	return (1);
}
