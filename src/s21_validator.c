#include "s21_calc.h"
/**
 * @brief переворачивает список
 *
 * @param head входной список
 * @param tmp перевернутый список
 */
void revese(Node **head, Node **tmp) {
  *tmp = NULL;
  while (*head) {
    push_back(tmp, creat_noda((*head)->number, (*head)->codeOfValue,
                              (*head)->priority));
    pop(head);
  }
  clear_node(head);
}
/**
 * @brief проверка входящей строки на ошибки
 *
 * @param str строка
 * @return int код ошибки
 */
int string_validation(char *str) {
  int return_value = 0;
  int count_open_bracket = 0;
  int count_close_bracket = 0;
  int error = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == '(') count_open_bracket++;
    if (str[i] == ')') count_close_bracket++;
    if (count_close_bracket > count_open_bracket) return_value = 2;
    if (strchr("+-*/", str[i])) {
      if ((!(strchr(SIGN_SYM, str[i + 1]) || strchr(OPER_LET, str[i + 1])) ||
           (str[i + 1] == '\0'))) {
        return_value = 3;
      }
    }
    if (str[i] == '.') {
      if (!strchr(NUM, str[i + 1]) || str[i + 1] == '\0') return_value = 4;
    }
    if (strchr(OPER_LET, str[i]) && !error) {
      error = check_function(str, i);
      if (!error) {
        return_value = 5;
      }
    }
    if (error != 0) error--;

    if (str[i] == '(') {
      if (strchr("+*/", str[i + 1])) return_value = 6;
    }
    // printf("%c", str[i]);
  }
  if (count_close_bracket != count_open_bracket) return_value = 2;
  return return_value;
}

int check_function(char *str, int i) {
  int return_value = 0;
  if (str[i] == 'c' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 3;
    }
  }
  if (str[i] == 's' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 3;
    }
  }
  if (str[i] == 't' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 3;
    }
  }
  if (str[i] == 'a' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 4;
    }
  }
  if (str[i] == 'a' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 4;
    }
  }
  if (str[i] == 'a' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 4;
    }
  }
  if (str[i] == 's' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 4;
    }
  }
  if (str[i] == 'l' && (i + 3 < (int)strlen(str))) {
    if (str[i + 1] == 'n' && str[i + 2] == '(' &&
        (strchr(SIGN_SYM, str[i + 3]) || strchr(OPER_LET, str[i + 3]))) {
      return_value = 2;
    }
  }
  if (str[i] == 'l' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'o' && str[i + 2] == 'g' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 3;
    }
  }
  if (str[i] == 'm' && (i + 3 < (int)strlen(str))) {
    if (str[i + 1] == 'o' && str[i + 2] == 'd' &&
        (strchr(SIGN_SYM, str[i + 3]) || strchr(OPER_LET, str[i + 3]))) {
      return_value = 3;
    }
  }

  return return_value;
}

/**
 * @brief переводит строку в правильную, заменяю к cos на c и так далее для
 * парсера
 *
 * @param str строка
 * @param i позиция
 * @return char символ
 */
char str_to_correct_str(char *str, int i) {
  char return_value = '\0';
  if (str[i] == 'c' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 'c';
    }
  }
  if (str[i] == 's' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 's';
    }
  }
  if (str[i] == 't' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 't';
    }
  }
  if (str[i] == 'a' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 'C';
    }
  }
  if (str[i] == 'a' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 'S';
    }
  }
  if (str[i] == 'a' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 'T';
    }
  }
  if (str[i] == 's' && (i + 5 < (int)strlen(str))) {
    if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't' &&
        str[i + 4] == '(' &&
        (strchr(SIGN_SYM, str[i + 5]) || strchr(OPER_LET, str[i + 5]))) {
      return_value = 'K';
    }
  }
  if (str[i] == 'l' && (i + 3 < (int)strlen(str))) {
    if (str[i + 1] == 'n' && str[i + 2] == '(' &&
        (strchr(SIGN_SYM, str[i + 3]) || strchr(OPER_LET, str[i + 3]))) {
      return_value = 'l';
    }
  }
  if (str[i] == 'l' && (i + 4 < (int)strlen(str))) {
    if (str[i + 1] == 'o' && str[i + 2] == 'g' && str[i + 3] == '(' &&
        (strchr(SIGN_SYM, str[i + 4]) || strchr(OPER_LET, str[i + 4]))) {
      return_value = 'L';
    }
  }
  if (str[i] == 'm' && (i + 3 < (int)strlen(str))) {
    if (str[i + 1] == 'o' && str[i + 2] == 'd' &&
        (strchr(SIGN_SYM, str[i + 3]) || strchr(OPER_LET, str[i + 3]))) {
      return_value = '%';
    }
  }
  if ((str[i] == '-' && i == 0) ||
      (i > 0 && str[i] == '-' && str[i - 1] == '(')) {
    return_value = '~';
  }
  return return_value;
}

/**
 * @brief подготовка строки к передачи в парсер
 *
 * @param str1 строка входная
 * @param str2 полученная строка после подготовки
 */
void prepare_str(char *str1, char *str2) {
  int j = 0;
  char value;
  for (int i = 0; str1[i] != '\0'; i++) {
    value = str_to_correct_str(str1, i);
    if (value) {
      str2[j] = value;
      j++;
      if (value == 'c') i = i + 2;
      if (value == 's') i = i + 2;
      if (value == 't') i = i + 2;
      if (value == 'C') i = i + 3;
      if (value == 'S') i = i + 3;
      if (value == 'T') i = i + 3;
      if (value == 'K') i = i + 3;
      if (value == 'l') i++;
      if (value == 'L') i = i + 2;
      if (value == '%') i = i + 2;
      value = '\0';
    } else {
      str2[j] = str1[i];
      j++;
    }
  }
  str2[j] = '\0';
}
/**
 * @brief парсер
 *
 * @param head_all входящая список
 * @param stroka строка из qt
 * @return int возврат ошибки
 */
int parser(Node **head_all, char *stroka, double x) {
  int code_error = 0;
  code_error = string_validation(stroka);
  if (code_error == 0) {
    char stroka2[256];
    prepare_str(stroka, stroka2);
    for (int i = 0; i < (int)strlen(stroka2); i++) {
      if (strchr("0123456789", stroka2[i])) {
        double d = atof(stroka2 + i);
        for (int k = i; strchr(".0123456789", stroka2[i]); i++, k++) {
          continue;
        }
        push_back(head_all, creat_noda(d, NUMBERS, 0));
      }
      if (stroka2[i] == '+') {
        push_back(head_all, creat_noda(0, Plus, 2));
      }
      if (stroka2[i] == '-') {
        push_back(head_all, creat_noda(0, Minus, 2));
      }
      if (stroka2[i] == '(') {
        push_back(head_all, creat_noda(0, Bracket_0, 1));
      }
      if (stroka2[i] == ')') {
        push_back(head_all, creat_noda(0, Bracket_1, 1));
      }
      if (stroka2[i] == '^') {
        push_back(head_all, creat_noda(0, Pow, 4));
      }
      if (stroka2[i] == '/') {
        push_back(head_all, creat_noda(0, Div, 3));
      }
      if (stroka2[i] == '*') {
        push_back(head_all, creat_noda(0, Mul, 3));
      }
      if (stroka2[i] == 'L') {  // деятичный логарифм
        push_back(head_all, creat_noda(0, Log, 3));
      }
      if (stroka2[i] == 'l') {  // обычный логарифм
        push_back(head_all, creat_noda(0, Ln, 3));
      }
      if (stroka2[i] == 'c') {  // cos
        push_back(head_all, creat_noda(0, Cos, 3));
      }
      if (stroka2[i] == 'C') {  // acos
        push_back(head_all, creat_noda(0, ACos, 3));
      }
      if (stroka2[i] == 's') {
        push_back(head_all, creat_noda(0, Sin, 3));
      }
      if (stroka2[i] == 'S') {
        push_back(head_all, creat_noda(0, ASin, 3));
      }
      if (stroka2[i] == 't') {
        push_back(head_all, creat_noda(0, Tan, 3));
      }
      if (stroka2[i] == 'T') {
        push_back(head_all, creat_noda(0, Atan, 3));
      }
      if (stroka2[i] == 'K') {
        push_back(head_all, creat_noda(0, Sqrt, 3));
      }
      if (stroka2[i] == 'x') {
        push_back(head_all, creat_noda(x, X, 0));
      }
      if (stroka2[i] == '~') {
        push_back(head_all, creat_noda(0, Umin, 4));  // вопрос в хуйне
      }
      if (stroka2[i] == '!') {
        push_back(head_all, creat_noda(0, Umax, 4));  // вопрос в хуйне
      }
      if (stroka2[i] == '%') {
        push_back(head_all, creat_noda(0, MOOD, 3));  // вопрос в хуйне
      }
    }
  }
  return code_error;
}