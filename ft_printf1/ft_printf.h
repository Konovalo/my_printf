#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct      s_result
{
    int             characters;       //kol simvolov
    int             line_length;      //length string
    int             number_character; //nomer cehashnego simvola
    int             d;                 //permenna dla chelogo type
    char            *s;                 //permenna dla string type
    double          f;                  //permenna dla float type
    va_list         factor;             //ykasatel na spisok
    int             width;              //sherena
    int             width2;             //sherena dla double
    int             flag;               //flag dla vuravnivania po pravomy cray
    int             flag1;              //postavet plus vpered
    int             flag2;
    int             flag3;              //zapolnet nulame
    char            simvol;             //simvol zapolnenia
    int             point;              //veshestv cheslo
    unsigned long   cheloe;             //cheloe chast pre double
    int             m;                  //kol cefr v celou chasty
    char            *cely;
    char            *drobny;
}                   t_result;

int     ft_printf(const char* format, ...);
void    analysis(char **c, t_result *res);
void    trait(char *c, t_result *res);
void    print_probel(int sizenbr, t_result **res, char c);
int     pr(char **c, t_result *res);
void   ft_cheloedouble(t_result *res);