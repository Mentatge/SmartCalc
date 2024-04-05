#ifndef S21_CALC_H
#define S21_CALC_H

#define STACK_MAX_SIZE 256
// #define STACK_OVERFLOW -100
// #define STACK_UNDERFLOW -101
#define SIGN_SYM "x1234567890(-"
#define OPER_LET "cstal"
#define NUM "1234567890"


#define DOUBLE 1
#define STR 2
#define GEOM 3

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum codeOfValue {
  X,          // 0
  Plus,       // 1 +
  Minus,      // 2 -
  Div,        // 3 /
  Mul,        // 4 *
  Pow,        // 5 ^
  Bracket_0,  // 6 (
  Bracket_1,  // 7 )
  Sin,        // 8 sin
  Cos,        // 9 cos
  Tan,        // 10 tan
  Atan,       // 11 atan
  Ln,         // 12 ln
  Log,        // 13 log
  Umin,       // 14 tilda
  Sqrt,       // 15 корень
  ASin,       // 16 asin
  ACos,       // 17 acos
  NUMBERS,    // 18 числа
  MOOD,       // 19 MOOD
  Umax,       //  20 unar+
};

typedef struct Node {
  double number;    // число?
  int codeOfValue;  // код значения?
  int priority;     // приоритет
  struct Node *next_node;
} Node;

void push_back(Node **head, Node *new1);
void pop(Node **head);
void clear_node(Node **head);
Node *creat_noda(double number, int codeofValue, int priority);
int string_validation(char *str);
int check_function(char *str, int i);
char str_to_correct_str(char *str, int i);
void prepare_str(char *str1, char *str2);
int parser(Node **head_all, char *stroka, double x);
void print_node(Node *head);
void revese(Node **head, Node **tmp);
void polish(Node **head);
int calculator(char *str, double *result, double x);
void s21_credit_calc_diff(double sum, double persent, int time, double *result, double *result2, double *result_persent);
void s21_credit_calc_anu(double sum, double persent, int time, double *result);
void s21_vklad_calc(double sum, int time, double persent, double *result, double *nalog_na_vklad, double *persent_na_vkald);

#endif