/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwarz <bschwarz@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:26:59 by bschwarz          #+#    #+#             */
/*   Updated: 2025/02/07 13:29:33 by bschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_matrix(char matrix[6][6]);
void	check_rules(char matrix[6][6]);

void	fill_matrix(char matrix[6][6], char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 5)
	{
		matrix[0][i] = argv[1][j];
		matrix[5][i] = argv[1][j + 8];
		matrix[i][0] = argv[1][j + 16];
		matrix[i][5] = argv[1][j + 24];
		//zwecks test
		matrix[0][0] = ' ';
		matrix[0][5] = ' ';
		matrix[5][0] = ' ';
		matrix[5][5] = ' ';
		matrix[1][i] = ' ';
		matrix[2][i] = ' ';
		matrix[3][i] = ' ';
		matrix[4][i] = ' ';
		//test ende
		i++;
		j = j + 2;
	}
}

int	validate_input(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(2, "ERROR\n", 6);
		return (0);
	}
	while (i < 32)
	{
		if (!(argv[1][0] > '0' && argv[1][0] < '5'))
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	matrix[6][6];

	if (!validate_input(argc, argv))
		return (1);
	fill_matrix(matrix, argv);
	check_rules(matrix);
	ft_print_matrix(matrix);
	return (0);
}
