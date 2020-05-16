/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:03:31 by heantoni          #+#    #+#             */
/*   Updated: 2020/03/01 13:03:34 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int     main()
{
    double e = -299999.9994678;
    double k1 = -3678.12;
    double k2 = 34;
    ft_printf("%d\n", ft_printf("+%5.2f+ \n", e));
    printf("%d\n", printf("+%5.2f+ \n", e));

    return (0);
}

// gcc main.c my_printf.c libft/ft_strlen.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c ft_analysis.c libft/ft_sizenbr.c trait.c libft/ft_isdigit.c libft/ft_atoi.c