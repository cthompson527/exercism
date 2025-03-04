#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *arr;
  size_t len;
  size_t cap;
} stack;

#define INITIAL_CAP 8

void init(stack *s, size_t cap);
void push_stack(stack *s, const char ch);
char pop_stack(stack *s);
char peek_stack(stack *s);
void free_stack(stack *s);

bool is_paired(const char *input);

#endif
