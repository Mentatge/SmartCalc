#include "vklad_calc.h"

#include "ui_vklad_calc.h"

vklad_calc::vklad_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::vklad_calc) {
  ui->setupUi(this);
}

vklad_calc::~vklad_calc() { delete ui; }

void vklad_calc::on_pushButton_clicked() {
  double result = 0;
  double nalog = 0;
  double persent = 0;
  s21_vklad_calc(ui->doubleSpinBox->value(), ui->spinBox->value(),
                 ui->doubleSpinBox_2->value(), &result, &nalog, &persent);
  ui->lineEdit_7->setText(QString::number(result));
  ui->lineEdit_8->setText(QString::number(nalog));
  ui->lineEdit_9->setText(QString::number(persent));
}

void vklad_calc::on_pushButton_2_clicked() { this->close(); }
