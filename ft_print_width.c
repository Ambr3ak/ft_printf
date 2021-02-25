/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:21:14 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/02 11:35:54 by ambrebour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int	ft_print_width(t_flags *flag, int size)
{
	int len;
	int zero;
	int space;

	len = 0;
	zero = flag->dot - size > 0 ? flag->dot - size : 0;
	space = flag->width - (size + zero) > 0 ? flag->width - (size + zero) : 0;
	if (flag->zero && flag->dot)
		while (space--)
			len += ft_putchar_fd('0', 1);
	else if (!flag->zero || flag->dot != -1)
		while (zero--)
			len += ft_putchar_fd('0', 1);
	return (len);
}

int	ft_print_zerop(t_flags *flag)
{
	int len;

	len = 0;
	while (flag->width--)
		len += ft_putchar_fd(' ', 1);
	return (len);
}

int	ft_print_dot_w(int c, t_flags *flag, int size)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = ft_itoa(c);
	if (!flag->dot && c == 0)
		len += ft_print_zerop(flag);
	else if (!flag->minus)
	{
		len += ft_print_space(size, flag);
		len += ft_print_minus(c);
		len += ft_print_width(flag, size);
		len += ft_putstr_fd(tmp, 1);
	}
	else if (flag->minus)
	{
		len += ft_print_minus(c);
		len += ft_print_width(flag, size);
		len += ft_putstr_fd(tmp, 1);
		len += ft_print_space(size, flag);
	}
	free(tmp);
	return (len);
}

int	ft_print_space_hexa(int size, t_flags *flag, int l)
{
	int len;

	len = 0;
	if (flag->dot > size)
		while (l > flag->dot)
		{
			len += ft_putchar_fd(' ', 1);
			l--;
		}
	else if (!flag->zero)
		while (l-- > size)
			len += ft_putchar_fd(' ', 1);
	return (len);
}

int	ft_print_dot_w_s(char *s, t_flags *flag, int size)
{
	int len;

	len = 0;
	if (flag->minus == 0)
	{
		len += ft_print_space_s(size, flag);
		if (flag->dot > 0)
			len += ft_print_width_s(s, flag, size);
	}
	else if (flag->minus == 1)
	{
		if (flag->dot > 0)
			len += ft_print_width_s(s, flag, size);
		len += ft_print_space_s(size, flag);
	}
	return (len);
}
