#include <unistd.h>

void	ft_print_matrix(char matrix[6][6]);
void	ft_check_one(char matrix[6][6]);
void	ft_check_two(char matrix[6][6]);
void	ft_eliminate(char matrix[6][6]);
void	ft_buf_matrix(char buf[6][6], char matrix[6][6]);
void	ft_blackout_circle(char matrix[6][6]);
void	ft_cancel_out(char matrix[6][6]);
int 	ft_count_spaces_row(char row[6]);
void	ft_replace_space_three(char buffer[6][6], char matrix[6][6]);

/* Already fancy edition */

int	main (void)
{
	char	matrix[6][6] = {
		{' ','1','3','2','2',' '},
		{'1',' ',' ',' ',' ','2'},
		{'3',' ',' ',' ',' ','2'},
		{'3',' ',' ',' ',' ','1'},
		{'2',' ',' ',' ',' ','3'},
		{' ','2','1','3','2',' '}
						};
	ft_check_one(matrix);
	ft_check_two(matrix);
	
	ft_eliminate(matrix);
	ft_print_matrix(matrix);
}

void ft_eliminate(char matrix[6][6])
{
	char buf[6][6];
	ft_buf_matrix(buf, matrix);
	ft_blackout_circle(buf);
	ft_cancel_out(buf);
	ft_replace_space_three(buf, matrix);
	ft_cancel_out(buf);
	ft_replace_space_three(buf, matrix);
	ft_print_matrix(buf);
}

void	ft_replace_space_three(char buffer[6][6], char matrix[6][6])
{
	int i;

	i = 0;
	while (i < 6)
	{
		int counter;

		counter = ft_count_spaces_row(buffer[i]);
		if (counter == 1)
		{
			int j;

			j = 0;
			while (j < 6)
			{
				if(buffer[i][j] == ' ')
				{
					char *pt_to_space;
					pt_to_space = &matrix[i][j];
					*pt_to_space = '3';
				}
				buffer[i][j] = 'X';
				j++;
			}
		}
		counter--;
		i++;
	}
}

int ft_count_spaces_row(char row[6])
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (i < 6)
	{
		if (row[i] == ' ')
		{
			counter++;
			i++;
		}
		else
			i++;
	}
	return (counter);
}

void	ft_cancel_out(char matrix[6][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (matrix[i][j] != '1'
			&& matrix[i][j] != '2'
			&& matrix[i][j] != '4')
			{
				if (matrix[i][j] == '3')
				{
					int	k;

					k = 0;
					while (k < 6)
					{
						matrix[k][j] = 'X';
						matrix[i][k] = 'X';
						k++;
					}
				}
			}
			j++;
		}
		i++;
	}
}

void	ft_blackout_circle(char matrix[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (i == 0 || i == 5)
			{
				matrix[i][j] = 'X';
				matrix[j][i] = 'X';
			}
			j++;
		}
		i++;
	}
}

void	ft_buf_matrix(char buf[6][6], char matrix[6][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			buf[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
}

void	ft_check_two(char matrix[6][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if(matrix[i][j] == '2' && matrix[5][j] == '1' && i == 0)
				matrix[i + 1][j] = '3';
			if(matrix[i][j] == '2' && matrix[0][j] == '1' && i == 5)
				matrix[i - 1][j] = '3';
			if(matrix[i][j] == '2' && matrix[i][5] == '1' && j == 0)
				matrix[i][j + 1] = '3';
			if(matrix[i][j] == '2' && matrix[i][0] == '1' && j == 5)
				matrix[i][j - 1] = '3';
			if(matrix[i][j] == '2' && matrix[5][j] == '3' && i == 0)
				matrix[i + 2][j] = '4';
			if(matrix[i][j] == '2' && matrix[0][j] == '3' && i == 5)
				matrix[i - 2][j] = '4';
			if(matrix[i][j] == '2' && matrix[i][5] == '3' && j == 0)
				matrix[i][j + 2] = '4';
			if(matrix[i][j] == '2' && matrix[i][0] == '3' && j == 5)
				matrix[i][j - 2] = '4';
			j++;
		}
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

void	ft_print_matrix(char matrix[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}