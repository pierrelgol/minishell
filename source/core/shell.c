/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:30:24 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/25 12:30:24 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_shell *shell_create(t_allocator *allocator, int32_t argc, char **argv, char **envp)
{
	t_shell *self;

	assert(allocator != NULL);
	self = allocator->create(allocator, sizeof(*self));
	assert(self != NULL);
	self->allocator = allocator;
	self->argc = argc;
	self->argv = argv;
	self->envp = envp;
	self->sh_env = shell_env_create(allocator);
	self->sh_input = shell_input_create(allocator);
	self->sh_lexer = shell_lexer_create(allocator);
	self->sh_linker = shell_linker_create(allocator);
	self->sh_prompt = shell_prompt_create(allocator);
	self->sh_tokenizer = shell_tokenizer_create(allocator);
	self->blt_cd = builtin_cd_create(allocator);
	self->blt_env = builtin_env_create(allocator);
	self->blt_pwd = builtin_pwd_create(allocator);
	self->blt_echo = builtin_echo_create(allocator);
	self->blt_exit = builtin_exit_create(allocator);
	self->blt_unset = builtin_unset_create(allocator);
	self->blt_export = builtin_export_create(allocator);
	return (self);
}

void shell_init(t_allocator *allocator, t_shell *self)
{
	shell_env_init(allocator, self->sh_env);
	shell_input_init(allocator, self->sh_input);
	shell_lexer_init(allocator, self->sh_lexer);
	shell_linker_init(allocator, self->sh_linker);
	shell_prompt_init(allocator, self->sh_prompt);
	shell_tokenizer_init(allocator, self->sh_tokenizer);
	// builtin_cd_init(allocator, self->blt_cd);
	// builtin_env_init(allocator, self->blt_env);
	// builtin_pwd_init(allocator, self->blt_pwd);
	// builtin_echo_init(allocator, self->blt_echo);
	// builtin_exit_init(allocator, self->blt_exit);
	// builtin_unset_init(allocator, self->blt_unset);
	// builtin_export_init(allocator, self->blt_export);
}

void shell_main(t_allocator *allocator, t_shell *self)
{
	(void) allocator;
	(void) self;
}
void shell_deinit(t_allocator *allocator, t_shell *self)
{
	assert(allocator != NULL);
	assert(self != NULL);
	shell_env_deinit(allocator, self->sh_env);
	shell_input_deinit(allocator, self->sh_input);
	shell_lexer_deinit(allocator, self->sh_lexer);
	shell_linker_deinit(allocator, self->sh_linker);
	shell_prompt_deinit(allocator, self->sh_prompt);
	shell_tokenizer_deinit(allocator, self->sh_tokenizer);
}

t_shell *shell_destroy(t_allocator *allocator, t_shell *self)
{
	assert(self != NULL);
	assert(allocator != NULL);
	shell_env_destroy(allocator, self->sh_env);
	shell_input_destroy(allocator, self->sh_input);
	shell_lexer_destroy(allocator, self->sh_lexer);
	shell_linker_destroy(allocator, self->sh_linker);
	shell_prompt_destroy(allocator, self->sh_prompt);
	shell_tokenizer_destroy(allocator, self->sh_tokenizer);
	builtin_cd_destroy(allocator, self->blt_cd);
	builtin_env_destroy(allocator, self->blt_env);
	builtin_pwd_destroy(allocator, self->blt_pwd);
	builtin_echo_destroy(allocator, self->blt_echo);
	builtin_exit_destroy(allocator, self->blt_exit);
	builtin_unset_destroy(allocator, self->blt_unset);
	builtin_export_destroy(allocator, self->blt_export);
	allocator->destroy(allocator, self);
	return (NULL);
}
