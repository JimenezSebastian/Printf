/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:16:33 by almejia-          #+#    #+#             */
/*   Updated: 2024/09/18 12:46:48 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_all(unsigned long long num, int d, int alert,
			const char *hex_chars);
int		ft_ext_pf(const char *format, va_list args);
int		ft_process_format(const char *format, va_list args);
int		ft_search_format(const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif
