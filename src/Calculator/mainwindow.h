#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "QPushButton"
#include "qcustomplot.h"
#include "credit_calc.h"
#include "vklad_calc.h"

extern "C" {
    #include "../s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double x  = INFINITY;
    credit_calc *creditcalc;
    vklad_calc *vklad;

private slots:
    void Obrabotchik();
    void Endoffunc();
    void GetXValue();
    void on_button_obnyl_clicked();
    void on_button_credit_clicked();
    void on_pushButton_clicked();
    void show_graph(char *prefix_str, int minX, int maxX);
//    void on_pushButton_2_clicked();
};


#endif // MAINWINDOW_H
