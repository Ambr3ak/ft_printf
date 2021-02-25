/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:43:22 by abourdar          #+#    #+#             */
/*   Updated: 2021/01/25 16:29:35 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int	ft_print_s(char *s, t_flags *flag, int *len)
{
	int		size;
	char	*str;

	str = s;
	str = !str ? ft_strdup("(null)") : ft_strdup(str);
	size = ft_strlen(str);
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putstr(str);
	else if (flag->dot > -1)
		*len += ft_print_dot_w_s(str, flag, size);
	else if (flag->minus == 1)
	{
		*len += ft_putstr(str);
		*len += ft_print_width_s(str, flag, size);
	}
	else if (flag->minus == 0)
	{
		*len += ft_print_width_s(str, flag, size);
		*len += ft_putstr(str);
	}
	free(str);
	return (*len);
}

int	ft_print_space_s(int size, t_flags *flag)
{
	int len;
	int tmp;

	len = 0;
	tmp = flag->width;
	if (flag->dot < size)
		while (flag->width-- > flag->dot)
			len += ft_putchar_fd(' ', 1);
	else
		while (flag->width-- > size)
			len += ft_putchar_fd(' ', 1);
	return (len);
}

int	ft_print_width_s(char *s, t_flags *flag, int size)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (flag->dot > 0)
		while (i < flag->dot && s[i])
			len += ft_putchar_fd(s[i++], 1);
	else
	{
		if (flag->zero == 1)
			while (flag->width-- > size)
				len += ft_putchar_fd('0', 1);
		else
			while (flag->width-- > size)
				len += ft_putchar_fd(' ', 1);
	}
	return (len);
}

int	ft_print_c(int c, t_flags *flag, int *len)
{
	flag->dot = flag->dot != -1 ? -1 : flag->dot;
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putchar_fd(c, 1);
	else if (flag->minus == 1)
	{
		*len += ft_print_width(flag, 1);
		*len += ft_putchar_fd(c, 1);
		*len += ft_print_space(1, flag);
	}
	else if (flag->minus == 0)
	{
		*len += ft_print_space(1, flag);
		*len += ft_print_width(flag, 1);
		*len += ft_putchar_fd(c, 1);
	}
	return (*len);
}

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!(s))
		return (0);
	else
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	return (i);
}
