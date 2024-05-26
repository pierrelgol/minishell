/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:47:01 by pollivie          #+#    #+#             */
/*   Updated: 2024/05/26 13:47:41 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIB_H
#define CLIB_H

#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define clib_assert(b) (_clib_assert((b), (char *) __PRETTY_FUNCTION__))

#define NOTFOUND (UINT64_MAX)
typedef struct s_allocator t_allocator;

typedef void *(t_fn_create) (t_allocator *self, uint64_t size);
typedef void *(t_fn_dup) (t_allocator *self, void *ptr, uint64_t size);
typedef void *(t_fn_dupz) (t_allocator *self, void *ptr, uint64_t size);
typedef void *(t_fn_realloc) (t_allocator *self, void *ptr, uint64_t size);
typedef void *(t_fn_destroy) (t_allocator *self, void *ptr);
typedef void *(t_fn_clear) (t_allocator *self, void *ptr);
typedef void(t_fn_reserve)(t_allocator *self, uint64_t size, uint64_t count);

typedef struct s_memory_node
{
	struct s_memory_node *next;
	uint64_t              size;
	uint64_t              used;
	uint8_t              *block;
} t_memory_node;

typedef struct s_allocator
{
	bool           logging;
	uint64_t       alloced;
	uint64_t       dealloced;
	uint64_t       size;
	uint64_t       used;
	uint8_t       *region;
	t_memory_node *usedlist;
	t_memory_node *freelist;
	t_fn_create   *create;
	t_fn_destroy  *destroy;
	t_fn_realloc  *realloc;
	t_fn_dup      *dup;
	t_fn_dupz     *dupz;
	t_fn_clear    *clear;
	t_fn_reserve  *reserve;

} t_allocator;

t_memory_node *mem_node_create(uint64_t size, uint64_t count);
t_memory_node *mem_node_destroy(t_memory_node *self);
t_memory_node *mem_node_get_nchild(t_memory_node *self, uint64_t n);
t_memory_node *mem_node_next(t_memory_node *self);
t_memory_node *mem_node_remove_child(t_memory_node *self);
t_memory_node *mem_node_remove_matching(t_memory_node **head, uintptr_t address);
t_memory_node *mem_node_remove_suitable(t_memory_node **head, uint64_t size);
uint64_t       mem_node_count_child(t_memory_node *self);
void           mem_node_insert_child(t_memory_node *self, t_memory_node *child);

t_allocator *heap_init(void);
void        *heap_create(t_allocator *self, uint64_t size);
void        *heap_destroy(t_allocator *self, void *ptr);
void        *heap_dup(t_allocator *self, void *ptr, uint64_t bytes);
void        *heap_dupz(t_allocator *self, void *ptr, uint64_t bytes);
void        *heap_clear(t_allocator *self, void *ptr);
void         heap_reserve(t_allocator *self, uint64_t size, uint64_t count);
void        *heap_deinit(t_allocator *self);

t_allocator *gpa_init(void);
void        *gpa_create(t_allocator *self, uint64_t size);
void        *gpa_destroy(t_allocator *self, void *ptr);
void        *gpa_dup(t_allocator *self, void *ptr, uint64_t bytes);
void        *gpa_dupz(t_allocator *self, void *ptr, uint64_t bytes);
void        *gpa_clear(t_allocator *self, void *ptr);
void         gpa_reserve(t_allocator *self, uint64_t size, uint64_t count);
void        *gpa_deinit(t_allocator *self);

/******************************************************************************/
/*                                Bit                                         */
/******************************************************************************/

int32_t bit_compare_bits(uint64_t num, uint64_t num2, uint64_t pos1, uint64_t pos2);
uint64_t bit_bitmask_combine(uint64_t mask1, uint64_t mask2);
uint64_t bit_bitmask_create(uint64_t start, uint64_t end);
uint64_t bit_check_parity(uint64_t num);
uint64_t bit_count_set_bits(uint64_t num);
uint64_t bit_count_unset_bits(uint64_t num);
uint64_t bit_is_set(uint64_t num, uint64_t pos);
uint64_t bit_reverse_bits(uint64_t num);
uint64_t bit_rotate_left(uint64_t num, uint64_t shift);
uint64_t bit_rotate_right(uint64_t num, uint64_t shift);
uint64_t bit_set_bit(uint64_t num, uint64_t pos);
uint64_t bit_swap_bits(uint64_t num, uint64_t pos1, uint64_t pos2, uint64_t nbits);
uint64_t bit_toggle_bit(uint64_t num, uint64_t pos);
uint64_t bit_unset_bit(uint64_t num, uint64_t pos);

// ***********************************+************************************** //
//                                  Char                                      //
// ************************************************************************** //

/// is_alnum - check if a character is alphanumeric
bool is_alnum(int32_t ch);

/// is_alpha - check if a character is alphabetic
bool is_alpha(int32_t ch);

/// is_ascii - check if a character is ascii
bool is_ascii(int32_t ch);

/// is_binary - check if a character is binary
bool is_binary(int32_t ch);

/// is_decimal - check if a character is decimal
bool is_decimal(int32_t ch);

/// is_digit - check if a character is a digit
bool is_digit(int32_t ch);

/// is_even - check if a character is even
bool is_even(int32_t ch);

/// is_hex - check if a character is hex
bool is_hex(int32_t ch);

/// is_lowercase - check if a character is lowercase
bool is_lowercase(int32_t ch);

/// is_newline - check if a character is a newline
bool is_newline(int32_t ch);

/// is_null - check if a character is null
bool is_octal(int32_t ch);

/// is_odd - check if a character is odd
bool is_odd(int32_t ch);

/// is_printable - check if a character is printable
bool is_printable(int32_t ch);

/// is_spaces - check if a character is 32 || (9-13)
bool is_spaces(int32_t ch);

/// is_uppercase - check if a character is uppercase
bool is_uppercase(int32_t ch);

/// is_whitespace - check if a character is whitespace (32 || (9,11,12,13))
bool is_whitespace(int32_t ch);

/// to_lowercase - convert a character to lowercase
int32_t to_lowercase(int32_t ch);

/// to_reversecase - convert a character to reversecase
int32_t to_reversecase(int32_t ch);

/// to_uppercase - convert a character to uppercase
int32_t to_uppercase(int32_t ch);

// ***********************************+************************************** //
//                                  Memory                                    //
// ************************************************************************** //

/// wrapper around malloc
void *memory_alloc(uint64_t size);

/// memory_ccopy - copy memory from src to dst for n bytes or until c is found
void *memory_ccopy(void *dst, const void *src, int32_t c, uint64_t n);

/// memory_compare - compare memory s1 and s2 for n bytes and return the
/// difference between the first two differing bytes or 0 if they are the same.

int32_t memory_compare(const void *s1, const void *s2, uint64_t n);

/// memory_copy - copy memory from src to dst for n bytes
void *memory_copy(void *dst, const void *src, uint64_t n);

/// memory_dealloc - deallocate memory (wrapper around free)
void memory_dealloc(void *ptr);

/// memory_dup - duplicate memory from ptr for size bytes
void *memory_dup(void *ptr, uint64_t size);

/// memory_dupz - duplicate memory from ptr for size bytes and zero the memory
void *memory_dupz(void *ptr, uint64_t size);

/// memory_move - move memory from src to dst for n bytes (handles overlapping
/// memory)
void *memory_move(void *dst, const void *src, uint64_t len);

/// memory_search - search memory for c for n bytes and return the first
/// occurrence or NULL if not found
void *memory_search(const void *s, int32_t c, uint64_t n);

/// memory_set - set memory to c for len bytes
void *memory_set(void *b, int32_t c, uint64_t len);

/// memory_zalloc - allocate memory and zero it out (wrapper around calloc)
void *memory_zalloc(uint64_t size);

/// memory_realloc - reallocate memory from ptr for osize bytes to nsize bytes
/// (wrapper around realloc)
void *memory_realloc(void *ptr, uint64_t osize, uint64_t nsize);

// ***********************************+************************************** //
//                                  bitset                                    //
// ************************************************************************** //

#define BITSET_SIZE 256

typedef struct s_bitset
{
	union
	{
		uint64_t set[4];
		struct
		{
			uint64_t a;
			uint64_t b;
			uint64_t c;
			uint64_t d;
		};
	};
} t_bitset;

void bitset_set_bit(t_bitset *bitset, const uint64_t index, const bool value);
bool bitset_is_set(const t_bitset *bitset, const uint64_t index);
t_bitset bitset_set_bit_range(t_bitset *bitset, const char *string);
t_bitset bitset_init_empty(void);
t_bitset bitset_init_from_str(const char *string);
t_bitset bitset_reset(t_bitset *bitset);
t_bitset bitset_and(const t_bitset *bitset1, const t_bitset *bitset2);
t_bitset bitset_or(const t_bitset *bitset1, const t_bitset *bitset2);
t_bitset bitset_xor(const t_bitset *bitset1, const t_bitset *bitset2);
t_bitset bitset_difference(const t_bitset *bitset1, const t_bitset *bitset2);

// ***********************************+************************************** //
//                                  String                                    //
// ************************************************************************** //

typedef bool(t_predicate)(int32_t ch);

/* IMMUTABLE */
uint64_t string_length(const char *string);
uint64_t string_split_length(const char **split);
uint64_t string_index_of_difference(const char *s1, const char *s2);
uint64_t string_compute_replace_sequence_size(const char *haystack, const char *needle, const char *with);

uint64_t string_compute_scalar_split_size(const char *source, const int32_t scalar);
uint64_t string_compute_any_split_size(const char *source, t_bitset const *delimiters);
uint64_t string_compute_none_split_size(const char *source, t_bitset const *delimiters);
uint64_t string_compute_predicate_split_size(const char *source, bool(predicate)(int32_t ch));
uint64_t string_compute_sequence_split_size(const char *source, const char *needle);

int32_t string_compare(const char *s1, const char *s2);
int32_t string_ncompare(const char *s1, const char *s2, const uint64_t n);
int32_t string_casecompare(const char *s1, const char *s2);
int32_t string_ncasecompare(const char *s1, const char *s2, const uint64_t n);

uint64_t string_copy_until_scalar(char *dest, const char *src, const int32_t scalar, const uint64_t destsize);
uint64_t string_copy_until_any(char *dest, const char *src, const t_bitset *delimiters, const uint64_t destsize);
uint64_t string_copy_until_none(char *dest, const char *src, const t_bitset *delimiters, const uint64_t destsize);
uint64_t string_copy_until_predicate(char *dest, const char *src, bool(predicate)(int32_t ch), const uint64_t destsize);
uint64_t string_copy_until_sequence(char *dest, const char *src, const char *needle, const uint64_t destsize);

bool string_is_all_scalar(const char *source, const int32_t scalar);
bool string_is_all_any(const char *source, t_bitset const *any);
bool string_is_all_none(const char *source, t_bitset const *none);
bool string_is_all_predicate(const char *source, bool(predicate)(int32_t ch));
bool string_is_all_sequence(const char *source, const char *sequence);

char *string_tokenize_scalar(t_allocator *const allocator, const char *source, const int32_t scalar, const int32_t marker);
char *string_tokenize_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters, const int32_t marker);
char *string_tokenize_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters, const int32_t marker);
char *string_tokenize_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch), const int32_t marker);
char *string_tokenize_sequence(t_allocator *const allocator, const char *haystack, const char *needle, const int32_t marker);

char *string_search_scalar(const char *source, const int32_t scalar, const uint64_t n);
char *string_search_any(const char *source, t_bitset const *delimiters, const uint64_t n);
char *string_search_none(const char *source, t_bitset const *delimiters, const uint64_t n);
char *string_search_predicate(const char *source, bool(predicate)(int32_t ch), const uint64_t n);
char *string_search_sequence(const char *haystack, const char *needle, const uint64_t n);

bool string_contains_scalar(const char *source, const int32_t scalar, const uint64_t n);
bool string_contains_any(const char *source, t_bitset const *delimiters, const uint64_t n);
bool string_contains_none(const char *source, t_bitset const *delimiters, const uint64_t n);
bool string_contains_predicate(const char *source, bool(predicate)(int32_t ch), const uint64_t n);
bool string_contains_sequence(const char *needle, const char *haystack, const uint64_t n);

bool string_starts_with_scalar(const char *source, const int32_t scalar);
bool string_starts_with_any(const char *source, t_bitset const *delimiters);
bool string_starts_with_none(const char *source, t_bitset const *delimiters);
bool string_starts_with_predicate(const char *source, bool(predicate)(int32_t ch));
bool string_starts_with_sequence(const char *haystack, const char *needle);

bool string_ends_with_scalar(const char *source, const int32_t scalar);
bool string_ends_with_any(const char *source, t_bitset const *delimiters);
bool string_ends_with_none(const char *source, t_bitset const *delimiters);
bool string_ends_with_predicate(const char *source, bool(predicate)(int32_t ch));
bool string_ends_with_sequence(const char *haystack, const char *needle);

uint64_t string_index_of_first_scalar(const char *source, const int32_t scalar);
uint64_t string_index_of_first_any(const char *source, t_bitset const *delimiters);
uint64_t string_index_of_first_none(const char *source, t_bitset const *delimiters);
uint64_t string_index_of_first_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_index_of_first_sequence(const char *haystack, const char *needle);

uint64_t string_index_of_last_scalar(const char *source, const int32_t scalar);
uint64_t string_index_of_last_any(const char *source, t_bitset const *delimiters);
uint64_t string_index_of_last_none(const char *source, t_bitset const *delimiters);
uint64_t string_index_of_last_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_index_of_last_sequence(const char *haystack, const char *needle);

uint64_t string_count_scalar(const char *source, const int32_t scalar, const uint64_t n);
uint64_t string_count_any(const char *source, t_bitset const *delimiters, const uint64_t n);
uint64_t string_count_none(const char *source, t_bitset const *delimiters, const uint64_t n);
uint64_t string_count_predicate(const char *source, bool(predicate)(int32_t ch), const uint64_t n);
uint64_t string_count_sequence(const char *haystack, const char *needle, const uint64_t n);

uint64_t string_count_until_scalar(const char *source, const int32_t scalar);
uint64_t string_count_until_any(const char *source, t_bitset const *delimiters);
uint64_t string_count_until_none(const char *source, t_bitset const *delimiters);
uint64_t string_count_until_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_count_until_sequence(const char *haystack, const char *needle);

uint64_t string_count_leading_scalar(const char *source, const int32_t scalar);
uint64_t string_count_leading_any(const char *source, t_bitset const *delimiters);
uint64_t string_count_leading_none(const char *source, t_bitset const *delimiters);
uint64_t string_count_leading_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_count_leading_sequence(const char *haystack, const char *needle);

uint64_t string_count_trailing_scalar(const char *source, const int32_t scalar);
uint64_t string_count_trailing_any(const char *source, t_bitset const *delimiters);
uint64_t string_count_trailing_none(const char *source, t_bitset const *delimiters);
uint64_t string_count_trailing_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_count_trailing_sequence(const char *haystack, const char *needle);

uint64_t string_wcount_scalar(const char *source, const int32_t scalar);
uint64_t string_wcount_any(const char *source, const t_bitset *delimiters);
uint64_t string_wcount_none(const char *source, const t_bitset *delimiters);
uint64_t string_wcount_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_wcount_sequence(const char *source, const char *sequence);

uint64_t string_wlength_scalar(const char *source, const int32_t scalar);
uint64_t string_wlength_any(const char *source, const t_bitset *delimiters);
uint64_t string_wlength_none(const char *source, const t_bitset *delimiters);
uint64_t string_wlength_predicate(const char *source, bool(predicate)(int32_t ch));
uint64_t string_wlength_sequence(const char *source, const char *sequence);

uint64_t string_wfind_scalar(const char *source, const int32_t scalar, uint64_t *out_start, uint64_t *out_end);
uint64_t string_wfind_any(const char *source, const t_bitset *delimiters, uint64_t *out_start, uint64_t *out_end);
uint64_t string_wfind_none(const char *source, const t_bitset *delimiters, uint64_t *out_start, uint64_t *out_end);
uint64_t string_wfind_predicate(const char *source, bool(predicate)(int32_t ch), uint64_t *out_start, uint64_t *out_end);
uint64_t string_wfind_sequence(const char *source, const char *needle, uint64_t *out_start, uint64_t *out_end);

/* MUTABLE */

char *string_clone(t_allocator *const allocator, const char *src);
char *string_clone_scalar(t_allocator *const allocator, const int32_t ch);
char *string_nclone(t_allocator *const allocator, const char *src, uint64_t n);

char *string_clone_until_scalar(t_allocator *const allocator, const char *src, const int32_t scalar);
char *string_clone_until_any(t_allocator *const allocator, const char *src, const t_bitset *delimiters);
char *string_clone_until_none(t_allocator *const allocator, const char *src, const t_bitset *delimiters);
char *string_clone_until_predicate(t_allocator *const allocator, const char *src, bool(predicate)(int32_t ch));
char *string_clone_until_sequence(t_allocator *const allocator, const char *src, const char *needle);

char *string_substring_scalar(t_allocator *const allocator, const char *src, const int32_t scalar);
char *string_substring_any(t_allocator *const allocator, const char *src, const t_bitset *delimiters);
char *string_substring_none(t_allocator *const allocator, const char *src, const t_bitset *delimiters);
char *string_substring_predicate(t_allocator *const allocator, const char *src, bool(predicate)(int32_t ch));
char *string_substring_sequence(t_allocator *const allocator, const char *src, const char *needle);

char *string_join_scalar(t_allocator *const allocator, const char *string, const int32_t scalar);
char *string_join_sequence(t_allocator *const allocator, const char *string, const char *sequence);
char *string_join_scalar_sequence(t_allocator *const allocator, const char *string, const int32_t scalar, const char *sequence);
char *string_join_many_sequence(t_allocator *const allocator, const char *string, const char **many);
char *string_join_many_scalar_sequence(t_allocator *const allocator, const char *string, const int32_t scalar, const char **many);

char *string_pad_left_scalar(t_allocator *const allocator, const char *string, const int32_t scalar, const uint64_t amount);
char *string_pad_right_scalar(t_allocator *const allocator, const char *string, const int32_t scalar, const uint64_t amount);
char *string_pad_left_sequence(t_allocator *const allocator, const char *string, const char *sequence, const uint64_t amount);
char *string_pad_right_sequence(t_allocator *const allocator, const char *string, const char *sequence, const uint64_t amount);

char *string_append_scalar(char *dest, const int32_t scalar, const uint64_t destsize);
char *string_append_sequence(char *dest, const char *sequence, const uint64_t destsize);
char *string_append_scalar_sequence(char *dest, const int32_t scalar, const char *sequence, const uint64_t destsize);
char *string_append_many_sequence(char *dest, const char **many, const uint64_t destsize);
char *string_append_many_scalar_sequence(char *dest, const int32_t scalar, const char **many, const uint64_t destsize);

char *string_trim_left(t_allocator *const allocator, const char *source, const uint64_t amount);
char *string_trim_right(t_allocator *const allocator, const char *source, const uint64_t amount);
char *string_trim_both(t_allocator *const allocator, const char *source, const uint64_t amount);

char *string_trim_leading_scalar(t_allocator *const allocator, const char *source, const int32_t scalar);
char *string_trim_leading_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char *string_trim_leading_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char *string_trim_leading_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch));
char *string_trim_leading_sequence(t_allocator *const allocator, const char *haystack, const char *needle);

char *string_trim_trailing_scalar(t_allocator *const allocator, const char *source, const int32_t scalar);
char *string_trim_trailing_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char *string_trim_trailing_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char *string_trim_trailing_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch));
char *string_trim_trailing_sequence(t_allocator *const allocator, const char *haystack, const char *needle);

char *string_filter_scalar(t_allocator *const allocator, const char *source, const int32_t scalar);
char *string_filter_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char *string_filter_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char *string_filter_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch));
char *string_filter_sequence(t_allocator *const allocator, const char *haystack, const char *needle);

char *string_replace_scalar(t_allocator *const allocator, const char *source, const int32_t scalar, const int32_t with);
char *string_replace_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters, const int32_t with);
char *string_replace_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters, const int32_t with);
char *string_replace_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch), const int32_t with);
char *string_replace_sequence(const char *haystack, const char *needle, const char *with, char *out_buffer);

char **string_split_scalar(t_allocator *const allocator, const char *source, const int32_t scalar);
char **string_split_any(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char **string_split_none(t_allocator *const allocator, const char *source, t_bitset const *delimiters);
char **string_split_predicate(t_allocator *const allocator, const char *source, bool(predicate)(int32_t ch));
char **string_split_sequence(t_allocator *const allocator, const char *haystack, const char *needle);

char *string_to_reverse(char *source);
char *string_to_uppercase(char *source);
char *string_to_lowercase(char *source);
char *string_to_titlecase(char *source);
char *string_to_capitalcase(char *source);

// ***********************************+************************************** //
//                                  List                                      //
// ************************************************************************** //

typedef struct s_node
{
	struct s_node *next;
	uintptr_t      data;

} t_node;

t_node  *node_create(t_allocator *allocator, uintptr_t data);
t_node  *node_get_nchild(t_node *self, uint64_t n);
void     node_insert_child(t_node *self, t_node *child);
t_node  *node_remove_child(t_node *self);
uint64_t node_count_child(t_node *self);
t_node  *node_next(t_node *self);
t_node  *node_destroy(t_node *self, t_allocator *allocator);

typedef struct s_list
{
	t_node      *head;
	t_node      *tail;
	t_allocator *allocator;
	uint64_t     size;

} t_list;

t_list *list_create(t_allocator *allocator);

void      list_insert_front(t_list *self, t_node *new_head);
void      list_insert_at(t_list *self, t_node *node, uint64_t index);
void      list_insert_back(t_list *self, t_node *new_tail);
bool      list_is_empty(t_list *self);
uint64_t  list_size(t_list *self);
t_node   *list_remove_front(t_list *self);
t_node   *list_remove_back(t_list *self);
t_node   *list_remove_at(t_list *self, uint64_t index);
void      list_push_front(t_list *self, uintptr_t data);
void      list_push_back(t_list *self, uintptr_t data);
void      list_push_at(t_list *self, uintptr_t data, uint64_t index);
uintptr_t list_pop_front(t_list *self);
uintptr_t list_pop_back(t_list *self);
uintptr_t list_pop_at(t_list *self, uint64_t index);
void      list_sort(t_node **list, int (*f)(uintptr_t d1, uintptr_t d2));

t_list *list_destroy(t_list *self);

// ***********************************+************************************** //
//                                 Stack                                      //
// ************************************************************************** //

typedef struct s_stack
{
	uint64_t     size;
	uint64_t     count;
	t_list      *top;
	t_list      *freelist;
	t_allocator *allocator;

} t_stack;

/// stack_create - create a new stack and return a pointer to it
t_stack *stack_create(t_allocator *allocator);

/// stack_destroy - destroy a stack and free all of its nodes
t_stack *stack_destroy(t_stack *self);

/// stack_growth - grow the stack by a factor of 2
void stack_growth(t_stack *self);

/// stack_is_empty - return true if the stack is empty
bool stack_is_empty(t_stack *self);

/// stack_is_full - return true if the stack is full
bool stack_is_full(t_stack *self);

/// stack_push - push data onto the stack
void stack_push(t_stack *self, uintptr_t data);

/// stack_pop - pop data from the stack
uintptr_t stack_pop(t_stack *self);

/// stack_peek - peek at the top of the stack
uintptr_t stack_peek(t_stack *self);

/// stack_length - return the length of the stack
uint64_t stack_length(t_stack *self);

/// stack_clear - clear the stack
void stack_clear(t_stack *self);

// ***********************************+************************************** //
//                                Queue                                      //
// ************************************************************************** //

typedef struct s_queue
{
	uint64_t     size;
	uint64_t     count;
	t_list      *head;
	t_list      *tail;
	t_list      *freelist;
	t_allocator *allocator;

} t_queue;

/// queue_create - create a new queue and return a pointer to it
t_queue *queue_create(t_allocator *allocator);

/// queue_destroy - destroy a queue and free all of its nodes
t_queue *queue_destroy(t_queue *self);

/// queue_is_empty - return true if the queue is empty
bool queue_is_empty(t_queue *self);

/// queue_is_full - return true if the queue is full
bool queue_is_full(t_queue *self);

/// queue_enqueue - enqueue data onto the queue
void queue_enqueue(t_queue *self, uintptr_t data);

/// queue_dequeue - dequeue data from the queue
uintptr_t queue_dequeue(t_queue *self);

/// queue_peek - peek at the head of the queue
uintptr_t queue_peek(t_queue *self);

/// queue_length - return the length of the queue
uint64_t queue_length(t_queue *self);

/// queue_clear - clear the queue
void queue_clear(t_queue *self);

/// queue_growth - grow the queue by a factor of 2
void queue_growth(t_queue *self);

// ***********************************+************************************** //
//                               Vector                                       //
// ************************************************************************** //

typedef int32_t(t_compare)(uintptr_t v1, uintptr_t v2);
typedef bool(t_eql)(uintptr_t v1, uintptr_t v2);
typedef uintptr_t(t_ctor)(t_allocator *allocator, uintptr_t elem);
typedef void(t_dtor)(t_allocator *allocator, uintptr_t elem);

#define DEFAULT_VECTOR_CAPACITY 32
typedef struct s_vector
{
	t_allocator *allocator;
	uint64_t     capacity;
	uint64_t     count;
	uintptr_t   *data;

} t_vector;

t_vector *vector_create(t_allocator *allocator);
t_vector *vector_destroy(t_vector *vector);
t_vector *vector_clear(t_vector *vector);
bool      vector_resize(t_vector *vector, uint64_t new_size);
t_vector *vector_compact(t_vector *vector, uint64_t from);
t_vector *vector_expand(t_vector *vector, uint64_t at);
bool      vector_is_empty(t_vector *vector);
bool      vector_is_full(t_vector *vector);
bool      vector_insert_at(t_vector *vector, uintptr_t value, uint64_t index);
bool      vector_insert_back(t_vector *vector, uintptr_t value);
bool      vector_insert_front(t_vector *vector, uintptr_t value);
bool vector_insert_after(t_vector *vector, uintptr_t value, uint64_t index);
uintptr_t  vector_peek_at(t_vector *vector, uint64_t index);
uintptr_t  vector_peek_back(t_vector *vector);
uintptr_t  vector_peek_front(t_vector *vector);
uintptr_t *vector_get_at(t_vector *vector, uint64_t index);
uintptr_t *vector_get_back(t_vector *vector);
uintptr_t *vector_get_front(t_vector *vector);
bool       vector_set_at(t_vector *vector, uintptr_t value, uint64_t index);
bool       vector_set_back(t_vector *vector, uintptr_t value);
bool       vector_set_front(t_vector *vector, uintptr_t value);
bool       vector_remove_at(t_vector *vector, uintptr_t index);
bool       vector_remove_back(t_vector *vector);
bool       vector_remove_front(t_vector *vector);
bool       vector_remove_after(t_vector *vector, uintptr_t index);
bool vector_copy_from(t_vector *vector, uint64_t offset, uintptr_t *src, uint64_t srcsize);
bool      vector_copy(t_vector *vector, uintptr_t *src, uint64_t srcsize);
bool      vector_push(t_vector *vector, uintptr_t elem);
uintptr_t vector_pop(t_vector *vector);
bool      vector_enqueue(t_vector *vector, uintptr_t elem);
uintptr_t vector_dequeue(t_vector *vector);
t_vector *vector_concat(t_vector *dest, t_vector *src);
t_vector *vector_join(t_allocator *allocator, t_vector *v1, t_vector *v2);
uint64_t  vector_count(t_vector *vector);
uint64_t  vector_capacity(t_vector *vector);
bool      vector_end_of_vec(t_vector *vector, uint64_t index);
void      vector_sort(t_vector *vector, t_compare *compare);
bool      vector_end(t_vector *vector, uint64_t index);
int64_t vector_index_of(t_vector *vector, uint64_t offset, uintptr_t elem, bool (*eql)(uintptr_t e1, uintptr_t e2));
void vector_map_dtor(t_vector *vector, t_allocator *allocator, uintptr_t (*dtor)(t_allocator *allocator, uintptr_t elem));

// ***********************************+************************************** //
//                               Buffer                                       //
// ************************************************************************** //

// equivalent to EOF
#define EOBUFF -777777
#define PAGE_SIZE 4096

typedef struct s_buffer
{
	uint64_t     bsize;
	uint64_t     r;
	uint64_t     w;
	char         ch;
	bool         is_fixed;
	char        *buffer;
	t_allocator *allocator;

} t_buffer;

bool      buffer_clear(t_buffer *self);
bool      buffer_grow(t_buffer *self);
bool      buffer_should_grow(t_buffer *self, uint32_t requested);
int32_t   buffer_getch(t_buffer *self);
int32_t   buffer_putch(t_buffer *self, char ch);
uint64_t  buffer_reserve(t_buffer *self, uint64_t size);
t_buffer *buffer_create(t_allocator *allocator, uint32_t size, bool is_fixed);
t_buffer *buffer_destroy(t_buffer *self);
uint64_t  buffer_read(t_buffer *self, char *buf, uint32_t size);
uint64_t  buffer_cache(t_buffer *self, int32_t fd);
uint64_t  buffer_unread_count(t_buffer *self);
uint64_t  buffer_unwrite_count(t_buffer *self);
uint64_t  buffer_write(t_buffer *self, char *buf, uint32_t size);
char     *buffer_gets(t_buffer *self, char *dest, uint32_t size);
char     *buffer_puts(t_buffer *self, char *str);
void      buffer_compact(t_buffer *self);

/******************************************************************************/
/*                                Table                                       */
/******************************************************************************/

#ifndef DEFAULT_TABLE_SIZE
#define DEFAULT_TABLE_SIZE 37781
#endif

typedef struct s_entry
{
	char     *key;
	uintptr_t value;
} t_entry;

typedef struct s_table
{
	uint64_t size;
	uint64_t capacity;
	t_entry *body;

	t_allocator *allocator;
} t_table;

t_table  *table_create(t_allocator *allocator);
void      table_destroy(t_table *self);
void      table_entry_set(t_table *self, char *key, uintptr_t value);
uintptr_t table_entry_get(t_table *self, char *key);
uint64_t  table_hash(char *str);
t_entry  *table_body_create(t_allocator *allocator, uint64_t capacity);
void      table_body_remove(t_table *self, char *key);
void      table_body_resize(t_table *self, uint64_t capacity);
uint64_t  table_body_find_empty(t_table *self, char *key);

// ***********************************+************************************** //
//                           print                                            //
// ************************************************************************** //

typedef int(t_print_fmt)(va_list arg, int fd);

typedef struct s_printer
{
	t_print_fmt *fmt;

} t_printer;

int32_t put_unumber_base(uint64_t num, const char *base, int32_t radix, int fd);
int32_t put_inumber_base(int64_t num, const char *base, int32_t radix, int fd);
int     put_char(va_list arg, int fd);
int     put_string(va_list arg, int fd);
int     put_int32(va_list arg, int fd);
int     put_ilong64(va_list arg, int fd);
int     put_ulong64(va_list arg, int fd);
int     put_uint32(va_list arg, int fd);
int     put_lowhex32(va_list arg, int fd);
int     put_upehex32(va_list arg, int fd);
int     put_ptr(va_list arg, int fd);
int     put_err(va_list arg, int fd);
t_printer print_fmt_parser(const char *fmt);
int32_t   arg_len(const char *fmt);
int32_t   print(int fd, const char *fmt, ...);

// misc

void _clib_assert(bool condition, char *func);

typedef struct s_iterator
{
	t_allocator *allocator;
	t_vector    *vec;
	t_dtor      *dtor;
	uint64_t     index;
	uint64_t     saved;
} t_iterator;

t_iterator *it_create(t_allocator *allocator);
t_iterator *it_init_with_split(t_iterator *self, char **split);
t_iterator *it_init_with_list(t_iterator *self, t_list *list);
t_iterator *it_init_with_vector(t_iterator *self, t_vector *vector);
t_iterator *it_set_dtor(t_iterator *self, t_dtor *dtor);

uintptr_t it_next(t_iterator *self);
uintptr_t it_insert_front(t_iterator *self, uintptr_t elem);
uintptr_t it_remove_front(t_iterator *self);
uintptr_t it_prev(t_iterator *self);
uintptr_t it_match(t_iterator *self, uintptr_t elem, bool(compare)(uintptr_t e1, uintptr_t e2));
bool      it_contains_matching(t_iterator *self, uintptr_t elem, bool(compare)(uintptr_t e1, uintptr_t e2));
uintptr_t it_peekcurr(t_iterator *self);
uintptr_t it_peeknext(t_iterator *self);
uintptr_t it_peekprev(t_iterator *self);
bool      it_end(t_iterator *self);
bool      it_reset(t_iterator *self);
uint64_t it_skip(t_iterator *self, uintptr_t elem, bool(compare)(uintptr_t e1, uintptr_t e2));

t_iterator *it_deinit(t_iterator *self);
bool        it_save(t_iterator *self);
bool        it_restore(t_iterator *self);
t_iterator *it_destroy(t_iterator *self);

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"


#endif
