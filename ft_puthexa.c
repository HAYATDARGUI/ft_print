/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:55 by hdargui           #+#    #+#             */
/*   Updated: 2024/11/20 11:58:50 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	converttohexa(unsigned long num)
{
	int		len;
	char	hex[16];
	int		i;
	int		r;

	len = 0;
	i = 0;
	if (num == 0)
		ft_putchar('0', &len);
	while (num != 0)
	{
		r = num % 16;
		if (r < 10)
			hex[i] = r + '0';
		else
			hex[i] = r - 10 + 'a';
		i++;
		num = num / 16;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(hex[i], &len);
	}
	return (len);
}

static int	converttoHEXA(unsigned long num)
{
	int		len;
	char	hex[16];
	int		i;
	int		r;

	i = 0;
	len = 0;
	if (num == 0)
		ft_putchar('0', &len);
	while (num != 0)
	{
		r = num % 16;
		if (r < 10)
			hex[i] = r + '0';
		else
			hex[i] = r - 10 + 'A';
		i++;
		num = num / 16;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(hex[i], &len);
	}
	return (len);
}

int	ft_puthexa(unsigned long long num, char format)
{
	int	len;

	len = 0;
	if (format == 'x')
	{
		len += converttohexa(num);
	}
	else if (format == 'X')
	{
		len += converttoHEXA(num);
	}
	else if (format == 'p')
	{
		ft_putstr("0x", &len);
		len += converttohexa(num);
	}
	return (len);
}
