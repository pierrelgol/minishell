#include "../../header/minishell.h"


int	is_path(char *str)
{
	while (*str != '\0')
	{
		if (*str == '/')
			return (1);
		str++;
	}
	return (0);
}

int	is_file(char *str)
{
	while (*str != '\0')
	{
		if (*str == '.')
			return (1);
		str++;
	}
	return (0);
}

int	is_option(char *str)
{
	if (str[0] != '-')
		return (0);
	while (*str != '\0')
	{
		if (*str == '.')
			return (0);
		str++;
	}
	return (1);
}

void	set_token_type(t_token_2 *token) //will be better to check against token->value length
{
	if (!token)
	{
		return ;
	}
	//if (ft_memcmp(token->value, "-", 1) == 0)
	//	token->type = MINUS;
	else if (ft_memcmp(token->value, "|", token->size) == 0)
		token->type = PIPE;
	//else if (ft_memcmp(token->value, ".", 1) == 0)
	//	token->type = DOT;
	else if (ft_memcmp(token->value, "(", token->size) == 0)
		token->type = LEFT_PARENTHESIS;
	else if (ft_memcmp(token->value, ")", token->size) == 0)
		token->type = RIGHT_PARENTHESIS;
	else if (ft_memcmp(token->value, "<", token->size) == 0)
		token->type = INPUT_REDIRECT;
	else if (ft_memcmp(token->value, ">", token->size) == 0)
		token->type = OUTPUT_REDIRECT;
	else if (ft_memcmp(token->value, ">>", token->size) == 0)
		token->type = APPEND_REDIRECT;
	else if (ft_memcmp(token->value, "<<", token->size) == 0)
		token->type = HERE_DOC;
	else if (ft_memcmp(token->value, "&", token->size) == 0)
		token->type = AMPERSAND;
	else if (ft_memcmp(token->value, ";", token->size) == 0)
		token->type = SEMICOLON;
	else if (ft_memcmp(token->value, "!", token->size) == 0)
		token->type = EXCLAMATION;
	else if (ft_memcmp(token->value, "'", token->size) == 0)
		token->type = SINGLE_QUOTE;
	else if (ft_memcmp(token->value, "\"", token->size) == 0)
		token->type = DOUBLE_QUOTE;
	else if (ft_memcmp(token->value, "$", token->size) == 0)
		token->type = DOLLAR;
	else if (is_identifier(token))
		token->type = IDENTIFIER;
	else if (is_keyword(token))
		token->type = KEYWORD;
	else if (is_path(token->value))
		token->type = PATH;
	else if (is_file(token->value))
		token->type = GUESS_FILE;
	else if (is_option(token->value))
		token->type = CMD_OPTION;
	else if (ft_isspace(token->value[0]))
		token->type = SPC;
	else
		token->type = UNKNOWN;
}

int	is_keyword_1st_check(t_token_2 *token)
{
	if (ft_memcmp("if", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("export", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("declare", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("function", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("else", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("float", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("end", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("do", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("typeset", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("then", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("integer", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("select", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("readonly", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("coproc", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("case", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("repeat", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("done", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("for", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("while", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("time", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("esac", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("until", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("local", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("fi", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("nocorrect", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("foreach", token->value, token->size) == 0)
		return (1);
	else if (ft_memcmp("elif", token->value, token->size) == 0) //what if we do a elif.txt ? -> Bug
		return (1);
	else
		return (0);
}

int	is_keyword_2nd_check(t_token_2 *token)
{
	if (ft_memcmp("if", token->value, 2) == 0)
		return (1);
	else if (ft_memcmp("export", token->value, 7) == 0)
		return (1);
	else if (ft_memcmp("declare", token->value, 7) == 0)
		return (1);
	else if (ft_memcmp("function", token->value, 8) == 0)
		return (1);
	else if (ft_memcmp("else", token->value, 4) == 0)
		return (1);
	else if (ft_memcmp("float", token->value, 5) == 0)
		return (1);
	else if (ft_memcmp("end", token->value, 3) == 0)
		return (1);
	else if (ft_memcmp("do", token->value, 2) == 0)
		return (1);
	else if (ft_memcmp("typeset", token->value, 7) == 0)
		return (1);
	else if (ft_memcmp("then", token->value, 4) == 0)
		return (1);
	else if (ft_memcmp("integer", token->value, 7) == 0)
		return (1);
	else if (ft_memcmp("select", token->value, 6) == 0)
		return (1);
	else if (ft_memcmp("readonly", token->value, 8) == 0)
		return (1);
	else if (ft_memcmp("coproc", token->value, 6) == 0)
		return (1);
	else if (ft_memcmp("case", token->value, 4) == 0)
		return (1);
	else if (ft_memcmp("repeat", token->value, 6) == 0)
		return (1);
	else if (ft_memcmp("done", token->value, 4) == 0)
		return (1);
	else if (ft_memcmp("for", token->value, 3) == 0)
		return (1);
	else if (ft_memcmp("while", token->value, 5) == 0)
		return (1);
	else if (ft_memcmp("time", token->value, 4) == 0)
		return (1);
	else if (ft_memcmp("esac", token->value, 4) == 0)
		return (1);
	else if (ft_memcmp("until", token->value, 5) == 0)
		return (1);
	else if (ft_memcmp("local", token->value, 5) == 0)
		return (1);
	else if (ft_memcmp("fi", token->value, 2) == 0)
		return (1);
	else if (ft_memcmp("nocorrect", token->value, 9) == 0)
		return (1);
	else if (ft_memcmp("foreach", token->value, 7) == 0)
		return (1);
	else if (ft_memcmp("elif", token->value, token->size) == 4) //what if we do a elif.txt ? -> Bug
		return (1);
	else
		return (0);
}

int	is_keyword(t_token_2 *token)
{
	return (is_keyword_1st_check(token) && is_keyword_2nd_check(token));
}

int	is_identifier(t_token_2 *token)
{
	int	i;

	i = 0;
	if (is_keyword(token))
		return (0);
	if (!ft_isalpha(token->value[0]))
		return (0);
	while (token->value[i] != '\0')
	{
		if (!ft_isalnum(token->value[i]) && token->value[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
