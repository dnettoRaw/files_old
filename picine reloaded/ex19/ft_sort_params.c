/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_prarams.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 08:13:32 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/11 18:38:34 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_sort_integer_table(char **tab, int size)
{
	int		i;
	char	*a;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			a = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = a;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	ft_sort_integer_table(argv + 1, (argc - 2));
	ft_print_tab(argv + 1);
	return (0);
}
