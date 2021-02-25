/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:16:26 by abourdar          #+#    #+#             */
/*   Updated: 2021/01/25 16:20:59 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprintf.h"
#include "includes/lftprintf.h"

void		ft_stolower(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
		i++;
	}
}

static char	*treat_base(unsigned int nb_tmp, int base, char *s, int count)
{
	while (nb_tmp != 0)
	{
		if ((nb_tmp % base) < 10)
			s[count - 1] = (nb_tmp % base) + 48;
		else
			s[count - 1] = (nb_tmp % base) + 55;
		nb_tmp /= base;
		count--;
	}
	return (s);
}

char		*ft_itoa_base_x(unsigned int nbr, int base)
{
	char			*s;
	unsigned int	nb_tmp;
	int				count;

	s = 0;
	count = 0;
	nb_tmp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	if (!(s = malloc(sizeof(char) * (count + 1))))
		return (0);
	s[count] = '\0';
	s = treat_base(nb_tmp, base, s, count);
	ft_stolower(s);
	return (s);
}

char		*ft_itoa_base_xx(unsigned int nbr, int base)
{
	char			*s;
	unsigned int	nb_tmp;
	int				count;

	s = 0;
	count = 0;
	nb_tmp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	if (!(s = malloc(sizeof(char) * (count + 1))))
		return (0);
	s[count] = '\0';
	s = treat_base(nb_tmp, base, s, count);
	return (s);
}
