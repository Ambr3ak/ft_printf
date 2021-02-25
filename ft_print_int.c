/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:32:52 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/02 11:35:20 by ambrebour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int	ft_print_minus(int c)
{
	int len;

	len = 0;
	if (c < 0)
		len += ft_putchar_fd('-', 1);
	return (len);
}

int	ft_print_space(int size, t_flags *flag)
{
	int len;
	int l;

	len = 0;
	l = flag->width;
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

int	get_size(int c, t_flags *flag)
{
	int		l;
	char	*tmp;

	tmp = ft_itoa(c);
	l = ft_strlen(tmp);
	if (c < 0 && flag->dot > 1)
	{
		flag->width--;
		l--;
	}
	free(tmp);
	return (l);
}

int	ft_print_di(int c, t_flags *flag, int *len)
{
	char *tmp;

	tmp = ft_itoa(c);
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putstr(tmp);
	else if (flag->dot > -1)
		*len += ft_print_dot_w(c, flag, get_size(c, flag));
	else if (flag->minus == 1)
	{
		*len += ft_print_width(flag, get_size(c, flag));
		*len += ft_print_minus(c);
		*len += ft_putstr_fd(tmp, 1);
		*len += ft_print_space(get_size(c, flag), flag);
	}
	else if (flag->minus == 0)
	{
		*len += ft_print_space(get_size(c, flag), flag);
		*len += ft_print_minus(c);
		*len += ft_print_width(flag, get_size(c, flag));
		*len += ft_putstr_fd(tmp, 1);
	}
	free(tmp);
	return (*len);
}
