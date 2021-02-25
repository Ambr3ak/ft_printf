/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:48:17 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/02 11:45:09 by ambrebour        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!(s))
		return (0);
	else
	{
		if (s[0] == '-')
			i++;
		while (s[i])
		{
			len += ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	return (len);
}
