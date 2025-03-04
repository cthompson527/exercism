#include "matching_brackets.h"

void init(stack *s, size_t cap) {
  s->arr = malloc(sizeof(char) * cap);
  s->len = 0;
  s->cap = cap;
}

void push_stack(stack *s, const char ch) {
  if (s->len == s->cap) {
    s->arr = realloc(s->arr, s->cap * 2);
    s->cap = s->cap * 2;
  }
  s->arr[s->len++] = ch;
}

char peek_stack(stack *s) {
  if (s->len == 0) {
    fprintf(stderr, "cannot peek at empty stack\n");
  }
  return s->arr[s->len - 1];
}

char pop_stack(stack *s) {
  if (s->len == 0) {
    fprintf(stderr, "cannot pop off empty stack\n");
  }
  return s->arr[--s->len];
}

void free_stack(stack *s) {
  free(s->arr);
  s->arr = NULL;
  s->len = 0;
  s->cap = 0;
}

char compliment(const char ch) {
  switch (ch) {
  case '[':
    return ']';
  case '(':
    return ')';
  case '{':
    return '}';
  default:
    return 0;
  }
}

enum ACTION { NONE, PUSH, POP };
enum ACTION action(const char ch) {
  switch (ch) {
  case '[':
  case '(':
  case '{':
    return PUSH;
  case ']':
  case ')':
  case '}':
    return POP;
  default:
    return NONE;
  }
}

bool is_paired(const char *input) {
  stack s;
  init(&s, INITIAL_CAP);

  size_t len = strlen(input);
  for (size_t i = 0; i < len; ++i) {
    switch (action(input[i])) {
    case PUSH:
      push_stack(&s, compliment(input[i]));
      break;
    case POP:
      if (s.len == 0 || pop_stack(&s) != input[i]) {
        return false;
      }
      break;
    case NONE:
      break;
    }
  }
  const bool empty_stack = s.len == 0;
  free_stack(&s);
  return empty_stack;
}
