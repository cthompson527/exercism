#include "matching_brackets.h"
#include "test-framework/unity.h"
#include <stdbool.h>

void setUp(void) {}

void tearDown(void) {}

static void test_creating_a_new_stack(void) {
  stack s;
  init(&s, INITIAL_CAP);
  TEST_ASSERT_EQUAL(INITIAL_CAP, s.cap);
  TEST_ASSERT_EQUAL(0, s.len);
}

static void test_pushing_and_popping_values_into_the_stack(void) {
  stack s;
  init(&s, INITIAL_CAP);
  push_stack(&s, 'a');
  push_stack(&s, 'b');
  push_stack(&s, 'c');
  push_stack(&s, 'd');
  TEST_ASSERT_EQUAL(4, s.len);
  TEST_ASSERT_EQUAL('d', pop_stack(&s));
  TEST_ASSERT_EQUAL('c', pop_stack(&s));
  TEST_ASSERT_EQUAL('b', pop_stack(&s));
  TEST_ASSERT_EQUAL('a', pop_stack(&s));
  TEST_ASSERT_EQUAL(0, s.len);
}

static void test_paired_square_brackets(void) {
  const char *input = "[]";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_empty_string(void) {
  const char *input = "";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_unpaired_brackets(void) {
  const char *input = "[[";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_wrong_ordered_brackets(void) {
  const char *input = "}{";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_wrong_closing_bracket(void) {
  const char *input = "{]";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_paired_with_whitespace(void) {
  const char *input = "{ }";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_partially_paired_brackets(void) {
  const char *input = "{[])";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_simple_nested_brackets(void) {
  const char *input = "{[]}";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_several_paired_brackets(void) {
  const char *input = "{}[]";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_paired_and_nested_brackets(void) {
  const char *input = "([{}({}[])])";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_unopened_closing_brackets(void) {
  const char *input = "{[)][]}";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_unpaired_and_nested_brackets(void) {
  const char *input = "([{])";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_paired_and_wrong_nested_brackets(void) {
  const char *input = "[({]})";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void
test_paired_and_wrong_nested_brackets_but_innermost_are_correct(void) {
  const char *input = "[({}])";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_paired_and_incomplete_brackets(void) {
  const char *input = "{}[";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_too_many_closing_brackets(void) {
  const char *input = "[]]";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_early_unexpected_brackets(void) {
  const char *input = ")()";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_early_mismatched_brackets(void) {
  const char *input = "{)()";
  TEST_ASSERT_FALSE(is_paired(input));
}

static void test_math_expression(void) {
  const char *input = "(((185 + 223.85) * 15) - 543)/2";
  TEST_ASSERT_TRUE(is_paired(input));
}

static void test_complex_latex_expression(void) {
  const char *input = "\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ "
                      "\\mathrm{e}^{x} &... x^2 \\end{array}\\right)";
  TEST_ASSERT_TRUE(is_paired(input));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_paired_square_brackets);
  RUN_TEST(test_empty_string);
  RUN_TEST(test_unpaired_brackets);
  RUN_TEST(test_wrong_ordered_brackets);
  RUN_TEST(test_wrong_closing_bracket);
  RUN_TEST(test_paired_with_whitespace);
  RUN_TEST(test_partially_paired_brackets);
  RUN_TEST(test_simple_nested_brackets);
  RUN_TEST(test_several_paired_brackets);
  RUN_TEST(test_paired_and_nested_brackets);
  RUN_TEST(test_unopened_closing_brackets);
  RUN_TEST(test_unpaired_and_nested_brackets);
  RUN_TEST(test_paired_and_wrong_nested_brackets);
  RUN_TEST(test_paired_and_wrong_nested_brackets_but_innermost_are_correct);
  RUN_TEST(test_paired_and_incomplete_brackets);
  RUN_TEST(test_too_many_closing_brackets);
  RUN_TEST(test_early_unexpected_brackets);
  RUN_TEST(test_early_mismatched_brackets);
  RUN_TEST(test_math_expression);
  RUN_TEST(test_complex_latex_expression);
  RUN_TEST(test_creating_a_new_stack);
  RUN_TEST(test_pushing_and_popping_values_into_the_stack);

  return UNITY_END();
}
