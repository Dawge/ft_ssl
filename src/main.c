#include "ft_ssl.h"

int     check_opt(int **var)
{
    int             i;
    int             ret;

    i = 0;
    ret = 0;
    while (i < NB_OPT)
    {
        ret += *var[i];
        i++;
    }
    return (ret);
}

int     find_opt(t_pars *data, char *str)
{
    int             i;
    int             j;
    int             ret;
    int             *var[NB_OPT] = {&(data->end), &(data->std), &(data->qut), &(data->rev), &(data->str)};
    static char     opt[NB_OPT] = {'-', 'p', 'q', 'r', 's'};

    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        ret = 0;
        while (j < NB_OPT)
        {
            if (str[i] == opt[j])
            {
                *var[j] = 1;
                ret = 1;
            }
            if (data->end == 1 || data->str == 1)
                return (0);
            j++;
        }
        if (ret == 0)
        {
            ft_printf("%c: option unknown\nKnowed option: p q r s\n", str[i]);
            return (-1);
        }
        i++;
    }
    return (0);
}

int     parsing(t_pars *data, int nb_arg, char **arg)
{
    int     i;

    i = 2;
    while (i < nb_arg)
    {
        if (arg[i][0] == '-')
        {
            if (find_opt(data, arg[i] + 1) == -1)
                return (-1);
        }
        i++;
    }
    return (0);
}

int     check_command(char *cmd)
{
    int             i;
    static int      name_len[NB_CMD] = {3};
    static char     *name[NB_CMD] = {"md5"};
    
    i = 0;
    while (i < NB_CMD)
    {
        if (ft_strncmp(cmd, name[i], name_len[i]) == 0)
            return (i);
        i++;
    }
    ft_printf("No digest command named %s\n", cmd);
    return (-1);
}

int		main(int argc, char **argv)
{
    int             idx;
    t_pars          data;
    static void     (*command[NB_CMD])(t_pars data) = {&ft_md5};

    ft_bzero(&data, sizeof(t_pars));
	if (argc == 1)
        ft_printf("%s: Error parsing\n", argv[0]);
    else
    {
        if ((idx = check_command(argv[1])) == -1)
            return (0);
        if (parsing(&data, argc, argv) == 0)
           command[idx](data); 
    }
    return (0);
}
