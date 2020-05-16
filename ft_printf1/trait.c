#include "ft_printf.h"

void    trait(char *c, t_result *res)
{
    if (c[res->number_character] == '\\')
        write(1, "\\", 1);
    else
        if (c[res->number_character] == '\a')
            write(1, "\a", 1);
        else
            if (c[res->number_character] == '\b')
                write(1, "\b", 1);
            else
                if (c[res->number_character] == '\f')
                    write(1, "\f", 1);
    res->characters += 1;
}

void    print_probel(int sizenbr, t_result **res, char c)
{
    if ((*res)->width2 != 0)
        sizenbr++;
    while (sizenbr < (*res)->width)
    {
        write(1, &c, 1);
        sizenbr++;
        (*res)->characters++;
    }
}