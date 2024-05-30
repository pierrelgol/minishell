#include "../minishell.h"

int	is_executable(char *path)
{
	if (!path)
		return (-1);
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

char	**get_path_vector(char *path_variable)
{
	char	**path_vector;

	path_vector = ft_split(path_variable, ':');
	if (!path_vector)
		return (NULL);
	return (path_vector);
}

char	*make_exec_path(char *path_variable, char *value)
{
	char	*candidate_path;
	char	**path_vector;
	char	*temp;
	int	i;
	i = 0;
	
	if (!path_variable || !value)
		return (ft_strdup(value));
	temp = ft_strjoin("/", value);
	path_vector = get_path_vector(path_variable);
	if (!path_vector)
	{//big mistake that must be dealt with as a big mistake
		free(temp);
		return (NULL);
	}
	while (path_vector[i] != NULL)
	{
		candidate_path = ft_strjoin(path_vector[i], temp);
		if (is_executable(candidate_path))
		{
			free(temp);
			//liberer path vector
			free_array(&path_vector);	
			return (candidate_path);
		}
		free(candidate_path);
		i++;
	}
	free_array(&path_vector);	
	free(temp);
	return (NULL);
}

int	test_if_executable(t_minishell *sh, t_token *token)
{
	char	*exec_path;

	if (!sh || !token)
		return (-1);
	if (!sh->path_variable)
	{
		return (is_executable(token->value));
	}
	exec_path = make_exec_path(sh->path_variable, token->value);
	if (is_executable(exec_path))
	{
		free(exec_path);
		return (1);
	}
	return (0);
}
