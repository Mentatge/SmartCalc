#include "s21_calc.h"

/**
 * @brief Функция добавляет в стэк значение и создает на нее ссылку
 *
 * @param head главная нода (строка)
 * @param new1 новая нода (строка) от головы
 */
void push_back(Node **head, Node *new1) {
  if (head) {
    if (head && new1) {
      new1->next_node = *head;
      (*head) = new1;
    } else if (new1) {
      *head = new1;
    }
  }
}

/**
 * @brief Удаляет с верху стэка ноду (строку)
 *
 * @param head верхние значение стэка
 */
void pop(Node **head) {
  if (head) {
    if ((*head)) {
      Node *tmp = (*head)->next_node;
      free(*head);
      *head = tmp;
    }
  }
}

/**
 * @brief очистка памяти из ноды (список)
 *
 * @param head верхние значение список
 */
void clear_node(Node **head) {
  while (*head != NULL) {
    if ((*head)->next_node == NULL) {
      pop(head);
      break;
    }
    pop(head);
  }
}

/**
 * @brief создание ноды (список)
 *
 * @param number число которое необходимо записать в ноду
 * @param codeofValue код того что поступает через энам в главном файле
 * @param priority приоритет того что поступает
 * @return Node* возвращает ноду (строку)
 */
Node *creat_noda(double number, int codeofValue,
                 int priority) {  // можно сделать тип *сreat но вопрос зачем
  Node *tmp = (Node *)calloc(1, sizeof(Node));
  // if (tmp == NULL) {
  //     exit(1); // вопрос в целесообразности? хотя пусть будет
  // }
  // else {
  tmp->number = number;            // число
  tmp->codeOfValue = codeofValue;  // скобка знак и тд и тп
  tmp->priority = priority;
  tmp->next_node = NULL;
  // }
  return tmp;
}

// void print_node(Node *head) {
//   while (head != NULL) {
//     printf("Number %lf ", head->number);
//     printf("Code Value %d ", head->codeOfValue);
//     printf("Prioritet %d ", head->priority);
//     printf("\n");
//     head = head->next_node;
//   }
//   printf("\n");
// }