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
			if (matrix[i][j] == '4' && i == 0)
			{
				matrix[i + 1][j] = '1';
				matrix[i + 2][j] = '2';
				matrix[i + 3][j] = '3';
				matrix[i + 4][j] = '4';
			}
			if (matrix[i][j] == '4' && i == 5)
			{
				matrix[i - 1][j] = '1';
				matrix[i - 2][j] = '2';
				matrix[i - 3][j] = '3';
				matrix[i - 4][j] = '4';
			}
			if (matrix[i][j] == '4' && j == 0)
			{
				matrix[i][j + 1] = '1';
				matrix[i][j + 2] = '2';
				matrix[i][j + 3] = '3';
				matrix[i][j + 4] = '4';
			}
			if (matrix[i][j] == '4' && j == 5)
			{	
				matrix[i][j - 1] = '1';
				matrix[i][j - 2] = '2';
				matrix[i][j - 3] = '3';
				matrix[i][j - 4] = '4';
			}
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

void	check_rules(char matrix[6][6])
{
	ft_check_four(matrix);
	ft_check_one(matrix);
	ft_check_two(matrix);
}