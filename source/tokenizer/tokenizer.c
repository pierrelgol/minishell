/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:53:18 by pollivie          #+#    #+#             */
/*   Updated: 2024/06/04 13:53:19 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

t_tokenizer *tokenizer_create(void)
{
	t_tokenizer *self;

	self = memory_alloc(sizeof(t_tokenizer));
	if (!self)
		return (NULL);
	self->delim = NULL;
	self->input = NULL;
	self->output = vector_create();
	if (!self->output)
	{
		memory_dealloc(self);
		return (NULL);
	}
	self->is_dirty = false;
	return (self);
}

t_vector *tokenizer_tokenize(t_tokenizer *self, char *input, char *delim)
{
	char   **temp;
	t_token *token;
	uint64_t i;

	self->delim = string_clone(delim);      // |
	self->input = string_clone(input);      // |---> here we prepare our inputs
	temp = split(self->input, self->delim); // |
	if (!temp)
		return (NULL);
	i = 0;
	// @STEP17 at this stage we slice and dice our inputs based on the delim
	// this split unlike a traditional split, keeps the "delim" in the resulting
	// split so if you split("this_sentence_here","_")
	// [0]"This";
	// [1]"_";
	// [2]"sentence";
	// [3]"_";
	// [4]"here";
	// [5]"NULL;
	// This is the result you wil get
	while (temp[i]) // while we still have some inputs
	{
		token = token_create(temp[i]); // we create a new_token 
		// (which will clone the string so don't worry) if you want to change the strings call the 
		// token_set_str(char *my_new_replacement_string), it will destroy the old one, put the new one
		// and update the len of the current token.
		vector_insert_at(self->output, (uintptr_t) token, i); // and insert it inside our token verctor
		i += 1;
	}
	// @STEP18 at this stage we have a vector of our tokens
	// [0](t_token){.ptr = "This", .len = 4, .kind = KIND_NO_KIND};
	// [1](t_token){.ptr = "_", .len = 1, .kind = KIND_NO_KIND};
	// [2](t_token){.ptr = "sentence", .len = 8, .kind = KIND_NO_KIND};
	// [3](t_token){.ptr = "_", .len = 1, .kind = KIND_NO_KIND};
	// [4](t_token){.ptr = "here", .len = 4, .kind = KIND_NO_KIND};
	// [5](t_token){0,0,0,0};
	// This is the result you wil get inside the ressulting vector
	split_destroy(temp); // we dispose of our split
	self->is_dirty = true;
	// @STEP19 --> ./source/core/shell.c
	return (self->output);
}

t_tokenizer *tokenizer_clear(t_tokenizer *self)
{
	t_token *temp;

	if (!self->is_dirty)
		return (self);
	it_save(self->output);
	while (!it_end(self->output))
	{
		temp = (t_token *) it_peek_curr(self->output);
		if (temp)
		{
			if (temp->extra != 0)
				memory_dealloc((char*)temp->extra);
			token_destroy(temp);
		}
		it_advance(self->output);
	}
	it_restore(self->output);
	vector_clear(self->output);
	memory_dealloc(self->delim);
	memory_dealloc(self->input);
	self->delim = NULL;
	self->input = NULL;
	self->is_dirty = true;
	return (self);
}

t_tokenizer *tokenizer_destroy(t_tokenizer *self)
{
	if (!self)
		return (NULL);
	if (self->is_dirty)
		tokenizer_clear(self);
	vector_destroy(self->output);
	memory_dealloc(self->delim);
	memory_dealloc(self->input);
	memory_dealloc(self);
	return (NULL);
}
