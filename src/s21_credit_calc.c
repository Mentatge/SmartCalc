#include "s21_calc.h"

/**
 * @brief Расчет платежу по аннуитетному методу
 *
 * @param sum сумма
 * @param persent процент
 * @param time  срок займа
 * @param result ежемесячный платеж
 */
void s21_credit_calc_anu(double sum, double persent, int time, double *result) {
  double koif = 0;
  double i = persent / 1200;
  koif = i * pow((1 + i), time) / (pow((1 + i), time) - 1);
  *result = koif * sum;
}

/**
 * @brief Расчет платежа по диффирициальному платежу
 *
 * @param sum сумма кредита
 * @param persent проценты по кредиту
 * @param time срок
 * @param result максимальный разовый платеж
 * @param result2 минимальный разовый платеж
 * @param result_persent процент по кредиту
 */
void s21_credit_calc_diff(double sum, double persent, int time, double *result,
                          double *result2, double *result_persent) {
  double month_pay = sum / time;
  *result = month_pay + sum * persent / 1200;
  for (int i = 0; i < time; i++) {
    *result_persent += sum * persent / 1200;
    *result2 = sum * persent / 1200 + month_pay;
    sum -= month_pay;
  }
}
