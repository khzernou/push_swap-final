/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzernou <khzernou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:31 by khzernou          #+#    #+#             */
/*   Updated: 2025/12/31 17:17:55 by khzernou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_cases(char c, va_list *arg);
int	ft_s_print(char *s);
int	ft_c_print(int c);
int	ft_di_print(long n);
int	ft_u_print(unsigned long n);
int	ft_hex_print(unsigned int n, char *base);
int	ft_x_print(unsigned int n);
int	ft_xupper_print(unsigned int n);
int	ft_p_print(void *ptr);
int	ft_hex_print_ull(unsigned long long n, char *base);

#endif