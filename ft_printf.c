/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:29:42 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/02 11:36:44 by ambrebour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

static	t_flags	ft_flags_init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	return (flags);
}

int				ft_print_flags(char *str, int *i, t_flags *flag, va_list args)
{
	int len;

	len = 0;
	while (str[*i])
	{
		if (str[*i] == '0' && flag->width == 0 && flag->minus == 0)
			flag->zero = 1;
		if ((ft_isdigit(str[*i]) && flag->dot == -1))
			*i = ft_width_digit(flag, i, str);
		if (str[*i] == '.')
			*i = ft_set_dot_w(str, i, flag, args);
		if (str[*i] == '*')
			*i = ft_set_star_w(flag, args, i);
		if (str[*i] == '-')
			*i = ft_minus(flag, i);
		if (ft_convertion(str[*i]))
		{
			len = ft_call_print(str[*i], args, flag, &len);
			break ;
		}
		*i += 1;
	}
	return (len);
}

int				ft_printf(const char *str, ...)
{
	char	*print;
	va_list	args;
	int		i;
	int		len;
	t_flags	flag;

	i = 0;
	len = 0;
	va_start(args, str);
	if (!(print = ft_strdup(str)))
		return (0);
	while (print[i])
	{
		flag = ft_flags_init();
		if (print[i] == '%' && print[i++])
			len += ft_print_flags(print, &i, &flag, args);
		else if (print[i] != '%')
			len += ft_putchar_fd(print[i], 1);
		i++;
	}
	va_end(args);
	free(print);
	return (len);
}
