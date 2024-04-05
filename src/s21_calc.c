#include "s21_calc.h"

/**
 * @brief перевод  в польскую нотацию
 *
 * @param head возвращает список
 */
void polish(Node **head) {
  Node *revese_head = NULL;
  Node *stack_for_pop = NULL;
  Node *result = NULL;
  revese(head, &revese_head);
  clear_node(head);
  while (revese_head != NULL) {
    if (revese_head->codeOfValue == NUMBERS || revese_head->codeOfValue == X) {
      push_back(&result,
                creat_noda(revese_head->number, revese_head->codeOfValue,
                           revese_head->priority));
      // pop(&revese_head);
    } else if (revese_head->codeOfValue != NUMBERS ||
               revese_head->codeOfValue != X) {
      if (stack_for_pop == NULL) {
        push_back(&stack_for_pop,
                  creat_noda(revese_head->number, revese_head->codeOfValue,
                             revese_head->priority));
        // pop(&revese_head);
      } else if (revese_head->codeOfValue) {
        if (revese_head->codeOfValue == Sin ||
            revese_head->codeOfValue == ASin ||
            revese_head->codeOfValue == Cos ||
            revese_head->codeOfValue == ACos ||
            revese_head->codeOfValue == Tan ||
            revese_head->codeOfValue == Atan ||
            revese_head->codeOfValue == Ln || revese_head->codeOfValue == Log ||
            revese_head->codeOfValue == Sqrt) {
          push_back(&stack_for_pop,
                    creat_noda(revese_head->number, revese_head->codeOfValue,
                               revese_head->priority));
        } else if (revese_head->codeOfValue == Bracket_0) {
          push_back(&stack_for_pop,
                    creat_noda(revese_head->number, revese_head->codeOfValue,
                               revese_head->priority));
        } else {
          if (revese_head->codeOfValue == Bracket_1) {
            while (stack_for_pop != NULL &&
                   stack_for_pop->codeOfValue != Bracket_0) {
              push_back(&result, creat_noda(stack_for_pop->number,
                                            stack_for_pop->codeOfValue,
                                            stack_for_pop->priority));
              pop(&stack_for_pop);
            }
            pop(&stack_for_pop);
          } else {
            while (stack_for_pop != NULL &&
                   stack_for_pop->priority >= revese_head->priority) {
              push_back(&result, creat_noda(stack_for_pop->number,
                                            stack_for_pop->codeOfValue,
                                            stack_for_pop->priority));
              pop(&stack_for_pop);
            }
            push_back(&stack_for_pop,
                      creat_noda(revese_head->number, revese_head->codeOfValue,
                                 revese_head->priority));
          }
        }
      }
    }
    if (revese_head->next_node == NULL) {
      break;
    }
    revese_head = revese_head->next_node;
  }
  while (stack_for_pop != NULL) {
    push_back(&result,
              creat_noda(stack_for_pop->number, stack_for_pop->codeOfValue,
                         stack_for_pop->priority));
    pop(&stack_for_pop);
  }
  // printf("hyeta\n");
  // print_node(result);
  revese(&result, head);
  clear_node(&revese_head);
  clear_node(&stack_for_pop);  // было в комите
  clear_node(&result);
}

/**
 * @brief калькулятор
 *
 * @param str строка
 * @param result_new результат операции
 * @return int ошибка
 */
int calculator(char *str, double *result_new, double x) {
  int code_error = 0;
  Node *head;
  head = NULL;
  code_error = parser(&head, str, x);
  polish(&head);
  double result = 0;
  Node *stack_for_operation;
  Node *stack_for_numbers;
  stack_for_operation = NULL;
  stack_for_numbers = NULL;
  if (code_error == 0) {
    while (head != NULL) {
      if (head->codeOfValue == NUMBERS || head->codeOfValue == X) {
        push_back(&stack_for_numbers,
                  creat_noda(head->number, head->codeOfValue, head->priority));
        // pop(head);
      } else if (head->codeOfValue != NUMBERS || head->codeOfValue != X) {
        if (head->codeOfValue == Plus) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          double b = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = a + b;
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Minus) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          double b = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = b - a;
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Mul) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          double b = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = b * a;
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Div) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          double b = stack_for_numbers->number;
          pop(&stack_for_numbers);
          if (a != 0) {
            result = b / a;
            push_back(&stack_for_numbers, creat_noda(result, 18, 0));
          } else {
            code_error = 1;
            break;
          }
        }
        if (head->codeOfValue == Pow) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          double b = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = pow(b, a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Sin) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = sin(a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == ASin) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = asin(a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Cos) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = cos(a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }

        if (head->codeOfValue == ACos) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = acos(a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Tan) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = tan(a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Atan) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = atan(a);
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
        if (head->codeOfValue == Log) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          if (a > 0) {
            result = log10(a);
            push_back(&stack_for_numbers, creat_noda(result, 18, 0));
          } else {
            code_error = 1;
          }
        }
        if (head->codeOfValue == Ln) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          if (a > 0) {
            result = log(a);
            push_back(&stack_for_numbers, creat_noda(result, 18, 0));
          } else {
            code_error = 1;
          }
        }
        if (head->codeOfValue == Sqrt) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          if (a > 0) {
            result = sqrt(a);
            push_back(&stack_for_numbers, creat_noda(result, 18, 0));
          } else {
            code_error = 1;
          }
        }
        if (head->codeOfValue == MOOD) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          double b = stack_for_numbers->number;
          pop(&stack_for_numbers);
          if (a != 0) {
            result = fmod(b, a);
            push_back(&stack_for_numbers, creat_noda(result, 18, 0));
          }
        }
        if (head->codeOfValue == Umin) {
          double a = stack_for_numbers->number;
          pop(&stack_for_numbers);
          result = a * -1;
          push_back(&stack_for_numbers, creat_noda(result, 18, 0));
        }
      }
      if (code_error == 1) {
        break;
      }
      if (head->next_node == NULL) {
        break;
      }
      head = head->next_node;
    }
    if (stack_for_numbers != NULL) {
      *result_new = stack_for_numbers->number;
    }
    clear_node(&stack_for_numbers);  // тут кстати лежит получаеся решение?
    clear_node(&stack_for_operation);
    clear_node(&head);
  }
  return code_error;
}

// проверка строки

// int main() {
//   char *stroka = "asin(x)+sin(x)";
//   // polish(&head);
//   // print_node(head);
//   int a = 0;
//   double result = 0;
//   a = calculator(stroka, &result, 1);
//   printf("%lf\n", result);
//   printf("%d\n", a);
//   return 0;
// }