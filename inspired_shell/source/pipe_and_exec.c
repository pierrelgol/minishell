#include "../minishell.h"

int	pipe_count(cmdTable *self)
{
	if (!self)
		return (-1);
	return (self->size - 1);
}

int	open_file_append_mode(char *filename)
{
	return(open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777));
}

int	open_file_input_mode(char *filename)
{
	return(open(filename, O_RDONLY));
}

int	open_file_output_mode(char *filename)
{
	return(open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777));
}


// fd_array[0] = input files
// fd_array[1] = output_files
// fd_array[2] = append_files

int	open_all_input_files_and_get_last(char	**input_vector)
{
	int	i;
	int	fd;

	i = 0;
	while (input_vector[i] != NULL)
	{
		fd = open_file_input_mode(input_vector[i]);
		i++;
	}
	return (fd);
}

int	open_all_output_files_and_get_last(char	**output_vector)
{
	int	i;
	int	fd;

	i = 0;
	while (output_vector[i] != NULL)
	{
		fd = open_file_output_mode(output_vector[i]);
		i++;
	}
	return (fd);
}

int	open_all_append_files_and_get_last(char	**o_append_vector)
{
	int	i;
	int	fd;

	i = 0;
	while (o_append_vector[i] != NULL)
	{
		fd = open_file_output_mode(o_append_vector[i]);
		i++;
	}
	return (fd);
}
