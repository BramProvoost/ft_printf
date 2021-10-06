/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprovoos <bprovoos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:21:40 by bprovoos      #+#    #+#                 */
/*   Updated: 2021/10/04 19:55:20 by bprovoos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_islower(int c);

char	*ft_itoa_long_base(long number, int base);

char	*ft_itoa_unsigned_long_base(unsigned long number, int base);

int		ft_putchar_fd(char c, int fd);

int		ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c);

void	ft_strtoupper(char *str);

int		ft_toupper(int c);

#endif
