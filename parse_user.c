
#include "aicu.h"
#include <stdio.h>

static int	final_check_input_user(int i, char *nptr, int limit)
{
	int	result;

	result = 0;
	if (!(nptr[i] >= 49 && nptr[i] <= limit + 48))
		return (-1);
	while (nptr[i])
	{
		if (!(nptr[i] <= 57 && nptr[i] >= 49))
			return (-1);
		result = (result * 10 + (nptr[i] - 48));
		if (result > 3)
			return (-1);
		i++;
	}
	return (result);
}

int	check_input_user(char *nptr, int limit)
{
	int			i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
	}
	return (final_check_input_user(i, nptr, limit));
}

int	read_user(int limit)
{
	int	n;
	char	buffer[4096];
	int		input;
	int		i;
	int		fd;
	int		start;

	i = 0;
	start = i;
	n = 1;
	fd = open("/dev/tty", O_RDONLY);
	while(n > 0)
	{
		n = read(fd, buffer, 4095);
		if (n == -1)
			return (-1);
		buffer[n] = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		buffer[i] = 0;
		input = check_input_user(buffer, limit);
		if (input == -1)
		{
			write(1, buffer, i + 1);
			write(1, " - Invalid choice\n", 18);
			close(fd);
			return (-1);
		}
		close(fd);
		return (input);
	}
	return (0);
}
