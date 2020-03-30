#ifndef FT_MD5_H
# define FT_MD5_H

# include "ft_ssl.h"

typedef struct  s_md5
{
   int          k[64];
   int          r[64];
   uint32_t     a;
   uint32_t     b;
   uint32_t     c;
   uint32_t     d;
   uint32_t     e;
   uint32_t     f;
   uint32_t     g;
   uint32_t     h0;
   uint32_t     h1;
   uint32_t     h2;
   uint32_t     h3;
   uint32_t     *w;
   uint32_t     tmp;
}               t_md5;

void            algo_md5(t_md5 *var, t_pars data); 

#endif
