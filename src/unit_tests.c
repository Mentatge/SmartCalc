#include <check.h>

#include "s21_calc.h"

START_TEST(s21_calculator_1) {
  char input[] = "((4+5)*4)^2";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 1296, 1e07);
}
END_TEST

START_TEST(s21_calculator_2) {
  char input[] = "sqrt(-9)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_calculator_3) {
  char input[] = "cos(0)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 1, 1e07);
}
END_TEST

START_TEST(s21_calculator_4) {
  char input[] = "(4*(8+2))+(3*2-(2*3-1)/4)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 44.75, 1e07);
}
END_TEST

START_TEST(s21_calculator_5) {
  char input[] = "2+(+2)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 6);
}
END_TEST

START_TEST(s21_calculator_6) {
  char input[] = "(1.345587654387512387+2)*2+(tan(12*19^2))";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 6.4291445, 1e07);
}
END_TEST

START_TEST(s21_calculator_7) {
  char input[] = "acos(3845)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_calculator_8) {
  char input[] = "atan(0.6483608)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 0);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 0.5752220, 1e07);
}
END_TEST

START_TEST(s21_calculator_9) {
  char input[] = "x^2";
  double res_of_func;
  int result = calculator(input, &res_of_func, 2);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 4, 1e07);
}
END_TEST

START_TEST(s21_calculator_10) {
  char input[] = "asin(x)+sin(x)";
  double res_of_func;
  int result = calculator(input, &res_of_func, 1);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(res_of_func, 2.412267, 1e07);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_calc: ");
  TCase *tc1_1 = tcase_create("s21_calc: ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_calculator_1);
  tcase_add_test(tc1_1, s21_calculator_2);
  tcase_add_test(tc1_1, s21_calculator_3);
  tcase_add_test(tc1_1, s21_calculator_4);
  tcase_add_test(tc1_1, s21_calculator_5);
  tcase_add_test(tc1_1, s21_calculator_6);
  tcase_add_test(tc1_1, s21_calculator_7);
  tcase_add_test(tc1_1, s21_calculator_8);
  tcase_add_test(tc1_1, s21_calculator_9);
  tcase_add_test(tc1_1, s21_calculator_10);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}