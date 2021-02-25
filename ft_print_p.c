/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:02:00 by abourdar          #+#    #+#             */
/*   Updated: 2021/01/25 16:19:48 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int		ft_print_space_p(int size, t_flags *flag, int l)
{
	int len;
	int i;

	len = 0;
	i = size + flag->dot;
	if (flag->dot > size)
		while (i++ < l)
			len += ft_putchar_fd(' ', 1);
	else
		while (l-- > size)
			len += ft_putchar_fd(' ', 1);
	return (len);
}

char	*ft_set_p(unsigned long long nbr, t_flags *flag)
{
	char *s;
	char *tmp;

	tmp = ft_itoa_base_p(nbr, 16);
	if (!nbr && flag->dot != -1)
		s = ft_strdup("0x");
	else
		s = ft_strjoin("0x", tmp);
	free(tmp);
	return (s);
}

int		ft_print_p(unsigned long long nbr, t_flags *flag, int *len)
{
	char	*ptr;
	int		l;

	l = flag->width;
	ptr = ft_set_p(nbr, flag);
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putstr_fd(ptr, 1);
	else if (flag->minus == 1)
	{
		*len += ft_print_width(flag, ft_strlen(ptr));
		*len += ft_putstr_fd(ptr, 1);
		*len += ft_print_space_p(ft_strlen(ptr), flag, l);
	}
	else if (flag->minus == 0)
	{
		*len += ft_print_space_p(ft_strlen(ptr), flag, l);
		*len += ft_print_width(flag, ft_strlen(ptr));
		*len += ft_putstr_fd(ptr, 1);
	}
	free(ptr);
	return (*len);
}
