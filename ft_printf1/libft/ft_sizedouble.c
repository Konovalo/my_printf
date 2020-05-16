int         ft_sizedouble(double nbr)
{
    int     n;

    n = 0;
    if (nbr == 0)
        return (1);
    if (nbr < 0)
        n++;
    nbr = nbr / 10;
    n++;
    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= 1)
    {
        nbr /= 10;
        n++;
    }
    return (n);
}