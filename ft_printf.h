/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:03:40 by abourdar          #+#    #+#             */
/*   Updated: 2021/02/01 17:20:42 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_H
# define LFTPRINTF_H
# include <stdarg.h>

typedef struct	s_flags
{
	int	zero;
	int width;
	int dot;
	int star;
	int minus;
	int type;
}				t_flags;

int				ft_printf(const char *str,
							...) __attribute__((format(printf,1,2)));

int				ft_print_c(int c, t_flags *flag, int *len);
int				ft_print_di(int c, t_flags *flag, int *len);
int				ft_print_s(char *s, t_flags *flag, int *len);
int				ft_print_p(unsigned long long nbr, t_flags *flag, int *len);
int				ft_print_u(unsigned int c, t_flags *flag, int *len);
int				ft_print_x(unsigned int nbr, t_flags *flag, int *len);
int				ft_print_xx(unsigned int nbr, t_flags *flag, int *len);
int				ft_print_pourcent(t_flags *flag);

void			ft_print_base(unsigned long long nbr, int *len);

int				ft_width_digit(t_flags *flag, int *i, char *str);
int				ft_minus(t_flags *flag, int *i);
int				ft_set_dot_w(char *str, int *i, t_flags *flag, va_list args);
int				ft_set_star_w(t_flags *flag, va_list args, int *i);

int				ft_convertion(int c);
int				ft_check_flags(int c);
int				ft_call_print(int c, va_list args, t_flags *flag, int *len);

int				ft_print_width(t_flags *flag, int size);
int				ft_print_width_s(char *s, t_flags *flag, int size);
int				ft_putstr(char *s);

int				ft_print_dot_w(int c, t_flags *flag, int size);
int				ft_print_dot_w_x(int c, t_flags *flag, int size, int *len);
int				ft_print_dot_w_xx(int c, t_flags *flag, int size, int *len);
int				ft_print_dot_w_s(char *s, t_flags *flag, int size);
int				ft_print_dot_u(unsigned int c, t_flags *flag, int size);

int				ft_print_zerop(t_flags *flag);

int				ft_print_space_s(int size, t_flags *flag);
int				ft_print_space(int size, t_flags *flag);
int				ft_print_space_hexa(int size, t_flags *flag, int l);

int				ft_print_minus(int c);

char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_base_xx(unsigned int value, int base);
char			*ft_itoa_base_x(unsigned int value, int base);
char			*ft_itoa_base_p(unsigned long long nbr, int base);
void			ft_stolower(char *s);
#endif
