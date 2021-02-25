/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:48:06 by abourdar          #+#    #+#             */
/*   Updated: 2021/01/25 16:42:27 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int	ft_print_pourcent(t_flags *flag)
{
	int		i;

	i = 1;
	if (flag->minus)
	{
		ft_putchar_fd('%', 1);
		while (i < flag->width)
			i += ft_putchar_fd(' ', 1);
		return (i);
	}
	if (flag->zero)
	{
		while (i < flag->width)
			i += ft_putchar_fd('0', 1);
	}
	while (i < flag->width)
		i += ft_putchar_fd(' ', 1);
	ft_putchar_fd('%', 1);
	return (i);
}
