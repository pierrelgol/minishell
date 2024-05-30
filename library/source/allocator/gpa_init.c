/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpa_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:31:05 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/16 09:20:37 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/clib.h"

t_allocator *gpa_init(void)
{
	t_allocator *gpa;

	gpa = memory_alloc(sizeof(t_allocator));
	gpa->logging = false;
	gpa->create = gpa_create;
	gpa->destroy = gpa_destroy;
	gpa->dup = gpa_dup;
	gpa->dupz = gpa_dupz;
	gpa->clear = gpa_clear;
	gpa->reserve = gpa_reserve;
	gpa->usedlist = NULL;
	gpa->freelist = NULL;
	return (gpa);
}
