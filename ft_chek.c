/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:01:50 by abourdar          #+#    #+#             */
/*   Updated: 2021/01/29 11:01:53 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int		ft_convertion(int c)
{
	return (c == 'c' || c == 'd' || c == 's' || c == 'p' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%');
}

int		ft_check_flags(int c)
{
	return (ft_isdigit(c) || c == '-' || c == '*' || c == '.');
}

void	ft_check_all(int c, t_flags *flag)
{
	flag->dot = flag->dot < 0 ? -1 : flag->dot;
	if (c != '%')
		flag->zero = flag->dot != -1 ? 0 : flag->zero;
	flag->zero = flag->minus ? 0 : flag->zero;
}

int		ft_call_print(int c, va_list args, t_flags *flag, int *len)
{
	ft_check_all(c, flag);
	if (c == 'c')
		*len = ft_print_c(va_arg(args, int), flag, len);
	else if (c == 'd' || c == 'i')
		*len = ft_print_di(va_arg(args, int), flag, len);
	else if (c == 's')
		*len = ft_print_s(va_arg(args, char *), flag, len);
	else if (c == 'p')
		*len = ft_print_p(va_arg(args, unsigned long long), flag, len);
	else if (c == 'u')
		*len = ft_print_u(va_arg(args, unsigned int), flag, len);
	else if (c == 'x')
		*len = ft_print_x(va_arg(args, unsigned int), flag, len);
	else if (c == 'X')
		*len = ft_print_xx(va_arg(args, unsigned int), flag, len);
	else if (c == '%')
		*len += ft_print_pourcent(flag);
	return (*len);
}
