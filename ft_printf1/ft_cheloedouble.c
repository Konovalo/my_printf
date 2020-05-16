#include "ft_printf.h"

double ft_fpow(double nbr, int k)
{
    int     i;
    double     n;

    n = 1;
    i = 0;
    while (i < k)
    {
        n = n * nbr;
        i++;
    }
    return (n);
}


unsigned long ft_pow(double nbr, int k)
{
    unsigned long ot;
    unsigned long t;
    unsigned long st;
    int i;

    st = 1;
    while (i < k)
    {
        st = st * 10;
        i++;
    }
    ot = nbr * st;
    st *= 10;
    t = nbr * st;
    if (t % 10 >= 5)
        ot += 1;
    return (ot);
}

void    ft_drobn(t_result **res)
{
    double  drob;
    int     i;
    int     p;
    char    *dr;
    
    //dr = (char*)malloc(sizeof(char) * ((*res)->width2 + 1));
    //dr[(*res)->width2] = '\0';
    drob = (*res)->f;
    (*res)->cely[(*res)->m] = '.';
    i = (*res)->m + 1;
    while (i < ((*res)->m + (*res)->width2 + 1))
    {
        drob = drob * 10;
        p = drob;
        drob -= p;
        (*res)->cely[i] = p + '0';
        i++;
    }
    p = drob * 10;
    i--;
    if (p > 5)
        {
            while ((*res)->cely[i] == '9' && (*res)->cely[i] != '.')
            {
                (*res)->cely[i] = '0';
                i--;
            }
        if (i >= 0 && (*res)->cely[i] != '.')
            (*res)->cely[i] = ((((*res)->cely[i] - '0') + 1) + '0');
        } 
    if ((*res)->cely[i] == '.')
    {
        i--;
        while (i >= 0 && (*res)->cely[i] == '9')
        {
            (*res)->cely[i] = '0';
            i--;
        }
        if (i >= 0)
            (*res)->cely[i] = ((((*res)->cely[i] - '0') + 1) + '0');
        if (i < 0)
            {
                (*res)->characters += 1;
                write(1, "1", 1);
            }
    }
    if ((*res)->point != 1)
        (*res)->cely[(*res)->m] = '\0';
    ft_putstr((*res)->cely);
}

void    double_cel(char *cel, t_result **res)
{
    double  nb;
    int     p;
    int     i;
    int     m;

    nb = (*res)->f;
    m = (*res)->m;
    i = 0;
    while (i < m)
    {
    p = nb / ft_fpow(10, (*res)->m - i - 1);
    p = p % 10;
    nb -= p * ft_fpow(10, (*res)->m - i-1);
    (cel)[i] = p + '0';
    i++;
    }
    (*res)->cely = cel;
    (*res)->f = nb;
}

void   ft_cheloedouble(t_result *res)
{
    char   *cel;
    char   dr;
    int    flag;

    flag = 0;
    cel = (char*)malloc(sizeof(char) * (res->m + res->width2 + 2));
    cel[res->m + res->width2 + 1] = '\0';
    if (res->f < 0)
    {
        //cel[0] = '-';
        res->f *= -1;
        flag = 1;
    }
    if (res->flag1 == 1 && flag == 0)
            res->width -= 1;
    if (res->flag2 == 1 && flag == 0)
            {
                res->width -= 1;
                write(1, " ", 1);
            }
    if (res->flag == 0 && res->flag3 != 1)
        print_probel(res->m + res->width2, &res, res->simvol);
    if (res->flag1 == 1 && flag == 0)
        write(1, "+", 1);
    if (res->flag == 0 && res->flag3 == 1 && flag == 0)
        print_probel(res->m + res->width2, &res, res->simvol);
    if (flag == 1)
        write(1, "-", 1);
    if (res->flag == 0 && res->flag3 == 1 && flag == 1)
        print_probel(res->m + res->width2, &res, res->simvol);
    double_cel(cel, &res); //chelay chast
    ft_drobn(&res);
    //ochestet cel
    /*if (res->width2 != 0)
        {
            write(1, ".", 1);
            ft_drobn(&res);
        }*/
    if (res->flag == 1)
        print_probel(res->m + res->width2, &res, res->simvol);
}
