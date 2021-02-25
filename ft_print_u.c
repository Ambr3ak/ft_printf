/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:28:24 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/02 11:43:19 by ambrebour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

int			ft_print_dot_u(unsigned int c, t_flags *flag, int size)
{
	int		len;
	int		l;
	char	*tmp;

	len = 0;
	l = flag->width;
	tmp = ft_itoa_u(c);
	if (!flag->dot && c == 0)
		len += ft_print_zerop(flag);
	else if (flag->minus == 0)
	{
		len += ft_print_space_hexa(size, flag, l);
		len += ft_print_width(flag, size);
		len += ft_putstr_fd(tmp, 1);
	}
	else if (flag->minus == 1)
	{
		flag->width -= flag->dot;
		len += ft_print_width(flag, size);
		len += ft_putstr_fd(tmp, 1);
		len += ft_print_space_hexa(size, flag, l);
	}
	free(tmp);
	return (len);
}

static int	ft_count_int_u(unsigned int n)
{
	int				count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa_u(unsigned int n)
{
	char			*dest;
	int				i;

	i = ft_count_int_u(n);
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (0);
	dest[i--] = '\0';
	if (n == 0)
		dest[i] = '0';
	while (n > 0)
	{
		dest[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (dest);
}

int			ft_print_u(unsigned int c, t_flags *flag, int *len)
{
	char	*tmp;
	int		l;

	tmp = ft_itoa_u(c);
	l = flag->width;
	if (flag->width == 0 && flag->dot == -1)
		*len += ft_putstr_fd(tmp, 1);
	else if (flag->dot > -1)
		*len += ft_print_dot_u(c, flag, ft_strlen(tmp));
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
