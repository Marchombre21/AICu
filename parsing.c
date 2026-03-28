#include "aicu.h"
#include "vector.h"
#include <stdio.h>

int	write_error(void)
{
	write(1, "ERROR\n", 6);
	return (-1);
}

static int	final_check_input(int i, char *nptr)
{
	int	result;

	result = 0;
	if (!(nptr[i] >= 48 && nptr[i] <= 57))
	{
		write(1, "mahcin", 6);
		return (write_error());
	}
	while (nptr[i])
	{
		if (!(nptr[i] <= 57 && nptr[i] >= 48))
		{
			write(1, "truc", 4);
			return (write_error());
		}
		result = (result * 10 + (nptr[i] - 48));
		if (result > 10000)
		{
			write(1, "ko", 2);
			return (write_error());
		}
		i++;
	}
	return (result);
}

static int	check_input(char *nptr)
{
	int			i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			write(1, "ok", 2);
			return (write_error());
		}
		i++;
	}
	return (final_check_input(i, nptr));
}

int	init_remain(t_vector *vec, char *remain, int nb)
{
	int	i;

	i = 0;
	vec->remain = malloc(sizeof(char) * nb + 1);
	if (!vec->remain)
		return (-1);
	while (i < nb)
	{
		vec->remain[i] = remain[i];
		i++;
	}
	vec->remain[i] = 0;
	return (1);
}

int	concat_store(t_vector *vec, char *next)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (vec->remain[i])
		i++;
	while (next[j++])
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	j = -1;
	i = 0;
	while (vec->remain[++j])
		new_str[j] = vec->remain[j];
	while (next[i])
	{
		new_str[j] = next[i];
		i++;
		j++;
	}
	new_str[j] = 0;
	if (store_datas(vec, new_str) == -1)
	{
		free(vec->remain);
		vec->remain = NULL;
		free(new_str);
		return (-1);
	}
	free(vec->remain);
	vec->remain = NULL;
	free(new_str);
	return (1);
}

int	store_datas(t_vector *vec, char *datas)
{
	int	res;

	res = 0;
	res = check_input(datas);
	if (res == -1)
		return (write_error());
	vec->data[vec->num_elements] = res;
	if (vec->max < res)
		vec->max = res;
	vec->num_elements += 1;
	return (1);
}

static inline int	parse_content(t_vector *vec, char *buffer)
{
	int	i;
	int	start;
	int	res;

	res = 0;
	i = 0;
	if (buffer[i] == '\n' && vec->remain)
	{
		res = check_input(vec->remain);
		free(vec->remain);
		vec->remain = NULL;
		if (res == -1)
			return (write_error());
		vec->data[vec->num_elements] = res;
		vec->num_elements += 1;
		i++;
	}
	start = i;
	while (buffer[i])
	{
		if (vec->max_elements == vec->num_elements)
		{
			if (vector_realloc(vec) == -1)
			{
				write(1, "87", 3);
				return (write_error());
			}
		}
		if (buffer[i] == '\n')
		{
			if (start == i)
				return (2);
			buffer[i] = 0;
			if (vec->remain)
				res = concat_store(vec, buffer + start);
			else
				res = store_datas(vec, buffer + start);
			if (res == -1)
				return (-1);
			start = i + 1;
		}
		i++;
	}
	if (start != i)
		init_remain(vec, buffer + start, i - start);
	return (1);
}

int	read_pro_max(t_vector *vec, int fd)
{
	int	n;
	char	buffer[4096];
	int		parse_status;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, 4095);
		if (n == -1)
			return (-1);
		else if (n == 0)
			return (0);
		buffer[n] = 0;

		parse_status = parse_content(vec, buffer);
		if (parse_status == -1)
			return (-1);
		if (parse_status == 2)
			return (0);
	}
	return (0);
}