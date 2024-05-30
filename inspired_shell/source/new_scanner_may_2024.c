#include "../minishell.h"

/*nouvelles focntions du mercredi 29 mai */

int	is_pipe(char c)
{
	return (c == '|');
}

int	is_input_redirect(char c)
{
	return (c == '<');
}

int	is_output_redirect(char c)
{
	return (c == '>');
}


/**************************************/

int	ft_issep(char c, char *sep)
{
	while (*sep != '\0')
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_terminator(char c)
{
	return (c == '\0');
}

void	increase_if_not_space_or_null(char c, int *size)
{
	if (!ft_isspace(c) && !is_terminator(c))
		*size += 1;
}

void	skip_spaces(char *str, int *index)
{
	while (ft_isspace(str[*index]))
		*index += 1;
}

void	increase(int *integer)
{
	*integer += 1;
}

void	increase_if_quote(char c, int *integer)
{
	if (is_quote(c))
		increase(integer);
}

int	string_extended_len(char *str, char *sep)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	skip_spaces(str, &i);
	while (!is_terminator(str[i]))
	{
		if (is_pipe(str[i])) //modified 05/29/24
		{
			increase(&size);
			if (!ft_isspace(str[i + 1]) && !is_terminator(str[i + 1]) && !is_pipe(str[i + 1]))
				increase(&size);
		}
		else if (is_output_redirect(str[i])) //modified 05/29/24
		{
			increase(&size);
			if (!ft_isspace(str[i + 1]) && !is_terminator(str[i + 1]) && !is_output_redirect(str[i + 1]))
				increase(&size);
		}
		else if (is_input_redirect(str[i])) //modified 05/29/24
		{
			increase(&size);
			if (!ft_isspace(str[i + 1]) && !is_terminator(str[i + 1]) && !is_input_redirect(str[i + 1]))
				increase(&size);
		}
		else if (is_quote(str[i]))
		{
			increase(&size);
			increase_if_not_space_or_null(str[i + 1], &size);
		}
		else if (ft_isspace(str[i]))
			increase_if_not_space_or_null(str[i + 1], &size);
		else
		{
			increase(&size);
			increase_if_quote(str[i + 1], &size);
			if (is_pipe(str[i + 1]) || is_output_redirect(str[i + 1]) || is_input_redirect(str[i + 1])) // modified 05/29/24
			{
				increase(&size);
			}
		}
		increase(&i);
	}
	(void)sep;
	return (size);
}

void	insert_wedge(char *str, int *index, char wedge)
{
	if (!str)
		return ;
	str[*index] = wedge;
	increase(index);
}

void	copy_char(char *dest, int *index, char c)
{
	if (!dest)
		return ;
	dest[*index] = c;
	increase(index);
}

void	insert_wedge_if_not_space_or_null(char c, char *str, int *index, char wedge)
{
	if (!ft_isspace(c) && !is_terminator(c))
		insert_wedge(str, index, wedge);
}

void	string_extend_copy(char *dest, char *source, char *sep, char wedge)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	(void)sep;
	skip_spaces(source, &i);
	while (!is_terminator(source[i]))
	{
		if (is_pipe(source[i])) // modified 05/29/24
		{
			copy_char(dest, &j, source[i]);
			if (!ft_isspace(source[i + 1]) && !is_terminator(source[i + 1]) && !is_pipe(source[i + 1]))
				insert_wedge(dest, &j, wedge);
		}
		else if (is_output_redirect(source[i])) // modified 05/29/24
		{
			copy_char(dest, &j, source[i]);
			if (!ft_isspace(source[i + 1]) && !is_terminator(source[i + 1]) && !is_output_redirect(source[i + 1]))
				insert_wedge(dest, &j, wedge);
		}
		else if (is_input_redirect(source[i])) // modified 05/29/24
		{
			copy_char(dest, &j, source[i]);
			if (!ft_isspace(source[i + 1]) && !is_terminator(source[i + 1]) && !is_output_redirect(source[i + 1]))
				insert_wedge(dest, &j, wedge);
		}
		else if (is_quote(source[i]))
		{
			copy_char(dest, &j, source[i]);
			insert_wedge_if_not_space_or_null(source[i + 1], dest, &j, wedge);
		}
		else if (ft_isspace(source[i]))
			insert_wedge_if_not_space_or_null(source[i + 1], dest, &j, wedge);
		else // modified 05/29/24
		{
			copy_char(dest, &j, source[i]);
			if (is_quote(source[i + 1]) || is_pipe(source[i + 1]) || is_output_redirect(source[i + 1]) || is_input_redirect(source[i + 1]))
				insert_wedge(dest, &j, wedge);
		}
		increase(&i);
	}
	dest[j] = '\0';
}

char	*string_add_delimiter(char *str, char *sep, char wedge)
{
	int	extended_len;
	char	*extended_string;

	extended_len = string_extended_len(str, sep);
	extended_string = (char *)malloc(sizeof(char) * (extended_len + 1));
	if (!extended_string)
		return (NULL);
	string_extend_copy(extended_string, str, sep, wedge);
	return (extended_string);
}

char	*ft_strtok(char *str, char sep)
{
	static int	i;
	char	*start;

	if (!str)
		return (NULL);
	start = &str[i];
	if (str[i] == '\0')
	{
		i = 0;
		return (NULL);
	}
	while (str[i] != sep && str[i] != '\0')
		i++;
	if (str[i] == sep)
	{
		str[i] = '\0';
		i++;
	}
	return (start);
}
