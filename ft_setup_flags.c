/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:27:37 by abourdar          #+#    #+#             */
/*   Updated: 2021/01/25 16:34:44 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int	ft_set_dot_w(char *str, int *i, t_flags *flag, va_list args)
{
	int j;

	j = *i;
	j++;
	if (str[j] == '*')
	{
		flag->dot = va_arg(args, int);
		j++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(str[j]))
		{
			flag->dot = flag->dot * 10 + str[j] - '0';
			j++;
		}
	}
	return (j);
}

int	ft_width_digit(t_flags *flag, int *i, char *str)
{
	if (flag->star == 1)
		flag->width = 0;
	flag->width = flag->width * 10 + str[*i] - '0';
	return (*i);
}

int	ft_set_star_w(t_flags *flag, va_list args, int *i)
{
	flag->star = 1;
	if ((flag->width = va_arg(args, int)) < 0)
	{
		flag->minus = 1;
		flag->width *= (-1);
	}
	return (*i);
}

int	ft_minus(t_flags *flag, int *i)
{
	flag->minus = 1;
	flag->zero = 0;
	return (*i);
}
