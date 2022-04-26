/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 18:32:52 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/09 17:06:28 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(char *str, int len)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = len - 1;
	while (j > i)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static int	int_to_string(int nb, char *str, int min_nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	while (i < min_nb)
	{
		str[i] = '0';
		i++;
	}
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

void	ft_ftoa(float nb, char *str)
{
	int	decimal;
	int	fractional;
	int	i;

	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		str += 1;
	}
	decimal = (int)nb;
	fractional = (nb - (float)decimal) * 100;
	i = int_to_string(decimal, str, 1);
	str[i] = '.';
	int_to_string(fractional, str + i + 1, 2);
}
