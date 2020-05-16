/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:03:42 by heantoni          #+#    #+#             */
/*   Updated: 2020/03/01 13:03:44 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int             ft_printf(const char* format, ...)
{
    t_result    res;
    t_result    *res2;
    char        *c;

    res.characters = 0;
    va_start(res.factor, format);
    c = (char*)format;
    res.line_length = ft_strlen(c);
    res.number_character = 0;
    res.flag = 0;
    while (c[res.number_character])
    {
        res.width = 0;
        res.width2 = 0;
        res.flag = 0;
        res.flag1 = 0;
        res.flag2 = 0;
        res.flag3 = 0;
        res.simvol = ' ';
        res.point = 0;
        if (c[res.number_character] != '%')
        {
            write(1, &c[res.number_character], 1);
            res.characters++;
        }
        else
            analysis(&c, &res);
        res.number_character++;
    }
    va_end(res.factor);
    return(res.characters);
}