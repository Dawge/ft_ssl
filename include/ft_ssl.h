#ifndef FT_SSL_H
# define FT_SSL_H

#include "../libft/include/libft.h"
#include <stdio.h>
#include <unistd.h>

# define NB_OPT 5

typedef struct  s_pars
{
    int         end;
    int         std;
    int         qut;
    int         rev;
    int         str;
}               t_pars;

# define NB_CMD 2

void            ft_md5(t_pars data);
#endif
