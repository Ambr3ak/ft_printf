/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:42:42 by abourdar          #+#    #+#             */
/*   Updated: 2020/11/30 18:48:58 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libprintf.h"

static int		ft_count_int(int n)
{
	int				count;
	unsigned int	nb;

	count = 1;
	nb = n;
	if (n < 0)
	{
		count++;
		nb = (unsigned int)-n;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char			*dest;
	int				i;
	unsigned int	nb;

	nb = (n < 0 ? -n : (unsigned int)n);
	i = ft_count_int(n);
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (0);
	dest[i--] = '\0';
	if (n < 0)
		dest[0] = '-';
	if (n == 0)
		dest[i] = '0';
	while (nb > 0)
	{
		dest[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (dest);
}
