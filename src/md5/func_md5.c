/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:44:36 by rostroh           #+#    #+#             */
/*   Updated: 2018/11/07 14:54:49 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		func_1(t_md5_var *var, int j)
{
	var->f = (var->b & var->c) | ((~var->b) & var->d);
	var->g = j;
}

void		func_2(t_md5_var *var, int j)
{
	var->f = (var->d & var->b) | ((~var->d) & var->c);
	var->g = (5 * j + 1) % 16;
}

void		func_3(t_md5_var *var, int j)
{
	var->f = var->b ^ var->c ^ var->d;
	var->g = (3 * j + 5) % 16;
}

void		func_4(t_md5_var *var, int j)
{
	var->f = var->c ^ (var->b | (~var->d));
	var->g = 7 * j % 16;
}
