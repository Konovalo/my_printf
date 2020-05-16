#include "ft_printf.h"

void     analysis(char **c, t_result *res)
{
    res->number_character++;
    while (((*c)[res->number_character]) != 'd' && ((*c)[res->number_character]) != 's' \
    && ((*c)[res->number_character]) != 'f')
    {
        if (((*c)[res->number_character]) == '-')
                res->flag = 1;
        else if (((*c)[res->number_character]) == '+')
                res->flag1 = 1;
        else if (((*c)[res->number_character]) == ' ')
                    res->flag2 = 1;
        else if (((*c)[res->number_character]) == '0')
                {
                    res->flag3 = 1;
                    res->simvol = '0';
                }
        else if (ft_isdigit((*c)[res->number_character]))
            {
            res->width = ft_atoi(&(*c)[res->number_character]);
            res->number_character += ft_sizenbr(res->width) - 1;
            }
        else if (((*c)[res->number_character]) == '.')
            {
                res->point = 1;
                res->number_character++;
                if (ft_isdigit((*c)[res->number_character]))
                {
                    res->width2 = ft_atoi(&(*c)[res->number_character]);
                    res->number_character += ft_sizenbr(res->width2) - 1;
                }
            }
        res->number_character++;
    }
    res->characters = pr(c, res);
}

int       pr_d0(t_result *res)
{
    if (res->flag1 == 1 && res->d >= 0)
    {
        res->width -= 1;
        if (res->simvol != '0')
            print_probel(ft_sizenbr((res)->d), &res, res->simvol);
        write(1, "+", 1);
        if (res->simvol == '0')
            print_probel(ft_sizenbr((res)->d), &res, res->simvol);
        res->characters += 1;
    }
    else {
        if (res->d < 0 && res->simvol != ' ' && res->flag2 != 1)
        {
            write(1, "-", 1);
            res->width -= 1;
            res->d *= -1;
            res->flag1 = 0;
        }
        if (res->d > 0 && res->flag2 == 1)
        {
            write(1, " ", 1);
            res->width -= 1;
            res->characters += 1;
        }
            print_probel(ft_sizenbr((res)->d), &res, res->simvol);
        }
            ft_putnbr(res->d);
    return (res->characters);
}

int       pr_d1(t_result *res)
{
    if (res->d >= 0 && res->flag2 == 1)
    {
        write(1, " ", 1);
        res->width -= 1;
        res->characters += 1;
    }
    if (res->flag1 == 1 && res->d >= 0)
    {
        write(1, "+", 1);
        res->characters += 1;
    }
    ft_putnbr(res->d);
    if (res->d < 0 && res->simvol != ' ' && res->flag2 != 1)
    {
        write(1, "-", 1);
        res->width -= 1;
        res->d *= -1;
    }
    if (res->flag1 == 1 && res->d >= 0)
        res->width -= 1;   
    print_probel(ft_sizenbr((res)->d), &res, res->simvol);
    return(res->characters);
}

int       pr(char **c, t_result *res)
{
    if ((*c)[(res)->number_character] == 'd')
    {
        res->d = va_arg((res)->factor, int);
        res->characters += ft_sizenbr((res)->d);
        if (res->flag == 0)
            return(pr_d0(res));
        if (res->flag == 1)
            return(pr_d1(res));
    } else
    if ((*c)[res->number_character] == 's')
    {
        res->s = va_arg(res->factor, char*);
        if (res->flag == 1)
            ft_putstr(res->s);
        print_probel(ft_strlen((res)->s), &res, res->simvol);
        res->characters += ft_strlen(res->s);
        if (res->flag == 0)
            ft_putstr(res->s);
    } else
    if ((*c)[res->number_character] == 'f')
    {
        res->f = va_arg((res)->factor, double);
        if (res->point == 0)
            res->width2 = 6;
        res->m = ft_sizedouble(res->f);
        res->characters += res->m;
        if (res->width2 != 0)
            res->characters += res->width2 + 1;
        if (res->flag1 == 1 && res->f > 0)
            res->characters += 1;
        if (res->flag2 == 1 && res->f > 0)
            res->characters += 1;
        ft_cheloedouble(res);
        
    }
    return (res->characters);
}