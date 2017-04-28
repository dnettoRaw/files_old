/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:33:44 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/25 21:37:37 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
typedef struct	s_index
{
	int i;
	int j;
	int x;
	int y;
}				t_index;

//============================================================================//
void	ft_putchar(char c)
{
	putchar(c);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return;
	}

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');

}
void ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
		ft_putchar(str[i++]);
}

int error(char *str, int nb)
{
	ft_putstr("\n\terror : ");
	ft_putstr(str);
	if (nb > 0)
	{
		ft_putstr("\tnbr :");
		ft_putnbr(nb);
	}
	ft_putstr("\n");
}
//============================================================================//
char	 *tranlaterchar (*tab)
{
	t_index v;
	char **str;
	char c;

	v.i = 0;
	v.x	= 0;
	v.y = 0;
	while (tab[v.i])
	{
		if (tab[v.i] == '\n')
		{
			v.x++;
			v.y = 0;
		}
		c = str[v.i];
		str[v.x][v.y] = c;
		v.i++;
		v.y++;
	}
	error(str[1], v.i);
	return (str);
}
int main(int agr, char **argv)
{
	return (0);
}
