#include "credit_calc.h"

#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent)
    : QWidget(parent), ui(new Ui::credit_calc) {
  ui->setupUi(this);
  connect(ui->calculate, SIGNAL(clicked()), this, SLOT(calculate()));
}

credit_calc::~credit_calc() { delete ui; }

void credit_calc::calculate() {
  double result = 0;
  if (ui->radioButton->isChecked()) {
    s21_credit_calc_anu(ui->sum_credit->value(), ui->prosent_credit->value(),
                        ui->time_credit->value(), &result);
    ui->lineEdit_7->setText(QString::number(result));
    double g = result * ui->time_credit->value() - ui->sum_credit->value();
    ui->lineEdit_8->setText(QString::number(g));
    double b = g + ui->sum_credit->value();
    ui->lineEdit_9->setText(QString::number(b));

  } else {
    double result = 0;
    double result2 = 0;
    double res_per = 0;
    s21_credit_calc_diff(ui->sum_credit->value(), ui->prosent_credit->value(),
                         ui->time_credit->value(), &result, &result2, &res_per);
    ui->lineEdit_7->setText(QString::number(result) + "->" +
                            QString::number(result2));
    ui->lineEdit_8->setText(QString::number(res_per));
    double d = res_per + ui->sum_credit->value();
    ui->lineEdit_9->setText(QString::number(d));
  }
}

void credit_calc::on_pushButton_2_clicked() { this->close(); }
