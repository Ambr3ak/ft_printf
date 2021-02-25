/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:37:58 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/02 11:36:14 by ambrebour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int	ft_print_x(unsigned int nbr, t_flags *flag, int *len)
{
	int		l;
	char	*tmp;

	tmp = ft_itoa_base_x(nbr, 16);
	l = flag->width;
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putstr_fd(tmp, 1);
	else if (!flag->dot && nbr == 0)
		*len += ft_print_zerop(flag);
	else if (flag->minus == 1)
	{
		*len += ft_print_width(flag, ft_strlen(tmp));
		*len += ft_putstr_fd(tmp, 1);
		*len += ft_print_space_hexa(ft_strlen(tmp), flag, l);
	}
	else if (flag->minus == 0)
	{
		*len += ft_print_space_hexa(ft_strlen(tmp), flag, l);
		*len += ft_print_width(flag, ft_strlen(tmp));
		*len += ft_putstr_fd(tmp, 1);
	}
	free(tmp);
	return (*len);
}

int	ft_print_xx(unsigned int nbr, t_flags *flag, int *len)
{
	char	*tmp;
	int		l;

	tmp = ft_itoa_base_xx(nbr, 16);
	l = flag->width;
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putstr_fd(tmp, 1);
	else if (!flag->dot && nbr == 0)
		*len += ft_print_zerop(flag);
	else if (flag->minus == 1)
	{
		*len += ft_print_width(flag, ft_strlen(tmp));
		*len += ft_putstr_fd(tmp, 1);
		*len += ft_print_space_hexa(ft_strlen(tmp), flag, l);
	}
	else if (flag->minus == 0)
	{
		*len += ft_print_space_hexa(ft_strlen(tmp), flag, l);
		*len += ft_print_width(flag, ft_strlen(tmp));
		*len += ft_putstr_fd(tmp, 1);
	}
	free(tmp);
	return (*len);
}
