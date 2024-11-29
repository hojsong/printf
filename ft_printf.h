/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lip.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:13:42 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/25 13:26:37 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_pty(va_list var, const char c, int *ch);
size_t	ft_putint(int s, const char c);
void	ft_putmp(unsigned long long mp, size_t *result);
void	ft_putnbr(int i, size_t *result);
size_t	ft_putstr(char *str, int *ch);
void	ft_putunbr(unsigned int i, size_t *result);
size_t	ft_putchar(char c);
void	ft_put16(int a, int i);
size_t	ft_putn16(void *v);
void	ft_putnx16(unsigned int i, size_t *result);
void	ft_putxn16(unsigned int i, size_t *result);
size_t	ft_putper(void);

#endif
