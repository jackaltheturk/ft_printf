/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:11:16 by etorun            #+#    #+#             */
/*   Updated: 2024/12/24 20:44:11 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int x)
{
	return (write(1, &x, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = (nb * -1);
	}
	if (nb < 10)
		count += ft_putchar(nb + 48);
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_un_sign(unsigned int x)
{
	unsigned long	nb;
	int				count;

	nb = x;
	if (nb < 0)
		nb = 4294967295 + nb + 1;
	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + 48);
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_printper(void)
{
	return (write(1, "%", 1));
}
