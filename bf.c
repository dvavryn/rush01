#include <unistd.h>

void	ft_check_four(char matrix[6][6]);
void	check_rules(char matrix[6][6]);
void	ft_print_matrix(char matrix[6][6]);
void	search_number(char matrix[6][6]);
void	fill_matrix(char matrix[6][6], char **argv);
int	validate_input(int argc, char **argv);



int	main(int argc, char **argv)
{
	char	matrix[6][6];
	int		i;

	if (!validate_input(argc, argv))
		return (1);
	fill_matrix(matrix, argv);
	check_rules(matrix);
	i = 0;
	while (i < 10)
	{
		search_number(matrix);
		i++;
	}
	ft_print_matrix(matrix);
	return (0);
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

void	check_postion(char matrix[6][6], int i, int j, char *pt_to_space)
{
	int		k;
	int		d;
	char	c;

	c = '1';
	while (c < '5')
	{
		d = 0;
		k = 1;
		while (k < 5)
		{
			if (matrix[k][j] == c || matrix[i][k] == c)
				d++;
			k++;
		}
		if (d < 1 && matrix[i][j] == ' ')
		{
			pt_to_space = &matrix[i][j];
			*pt_to_space = c;
		}
		c++;
	}
}

void	search_number(char matrix[6][6])
{
 	int		i;
	int		j;
	char	*pt_to_space;

    i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			check_postion(matrix, i, j, pt_to_space);
			j++;
		}
		i++;
	}

}

void	ft_print_matrix(char matrix[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_check_one(char matrix[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (matrix[i][j] == '1' && i == 0)
				matrix[i + 1][j] = '4';
			if (matrix[i][j] == '1' && i == 5)
				matrix[i - 1][j] = '4';
			if (matrix[i][j] == '1' && j == 0)
				matrix[i][j + 1] = '4';
			if (matrix[i][j] == '1' && j == 5)
				matrix[i][j - 1] = '4';
			j++;
		}
		i++;
	}
}

void	ft_check_two_b(char matrix[6][6], int i, int j)
{
	if (matrix[i][j] == '2' && matrix[5][j] == '1' && i == 0)
		matrix[i + 1][j] = '3';
	if (matrix[i][j] == '2' && matrix[0][j] == '1' && i == 5)
		matrix[i - 1][j] = '3';
	if (matrix[i][j] == '2' && matrix[i][5] == '1' && j == 0)
		matrix[i][j + 1] = '3';
	if (matrix[i][j] == '2' && matrix[i][0] == '1' && j == 5)
		matrix[i][j - 1] = '3';
	if (matrix[i][j] == '2' && matrix[5][j] == '3' && i == 0)
		matrix[i + 2][j] = '4';
	if (matrix[i][j] == '2' && matrix[0][j] == '3' && i == 5)
		matrix[i - 2][j] = '4';
	if (matrix[i][j] == '2' && matrix[i][5] == '3' && j == 0)
		matrix[i][j + 2] = '4';
	if (matrix[i][j] == '2' && matrix[i][0] == '3' && j == 5)
		matrix[i][j - 2] = '4';
}

void	ft_check_two_a(char matrix[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			ft_check_two_b(matrix, i, j);
			j++;
		}
		i++;
	}
}

void	check_rules(char matrix[6][6])
{
	ft_check_four(matrix);
	ft_check_one(matrix);
	ft_check_two_a(matrix);
}

void	ft_check_four_top(char matrix[6][6], int i, int j)
{
	matrix[i + 1][j] = '1';
	matrix[i + 2][j] = '2';
	matrix[i + 3][j] = '3';
	matrix[i + 4][j] = '4';
}

void	ft_check_four_bottom(char matrix[6][6], int i, int j)
{
	matrix[i - 1][j] = '1';
	matrix[i - 2][j] = '2';
	matrix[i - 3][j] = '3';
	matrix[i - 4][j] = '4';
}

void	ft_check_four_left(char matrix[6][6], int i, int j)
{
	matrix[i][j + 1] = '1';
	matrix[i][j + 2] = '2';
	matrix[i][j + 3] = '3';
	matrix[i][j + 4] = '4';
}

void	ft_check_four_right(char matrix[6][6], int i, int j)
{
	matrix[i][j - 1] = '1';
	matrix[i][j - 2] = '2';
	matrix[i][j - 3] = '3';
	matrix[i][j - 4] = '4';
}

void	ft_check_four(char matrix[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (matrix[i][j] == '4')
			{
				if (i == 0)
					ft_check_four_top(matrix, i, j);
				else if (i == 5)
					ft_check_four_bottom(matrix, i, j);
				else if (j == 0)
					ft_check_four_left(matrix, i, j);
				else if (j == 5)
					ft_check_four_right(matrix, i, j);
			}
			j++;
		}
		i++;
	}
}
