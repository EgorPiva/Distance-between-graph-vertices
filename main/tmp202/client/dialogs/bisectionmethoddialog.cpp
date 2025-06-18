#include "bisectionmethoddialog.h"
#include "ui_bisectionmethoddialog.h"
#include <QMessageBox>

BisectionMethodDialog::BisectionMethodDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BisectionMethodDialog)
{
    ui->setupUi(this);
    setWindowTitle("Метод деления пополам");
}

BisectionMethodDialog::~BisectionMethodDialog()
{
    delete ui;
}

void BisectionMethodDialog::on_calculateButton_clicked()
{
    // Получаем значения из полей ввода
    QString equation = ui->equationEdit->text();
    bool ok1, ok2, ok3;
    double a = ui->aEdit->text().toDouble(&ok1);
    double b = ui->bEdit->text().toDouble(&ok2);
    double epsilon = ui->epsilonEdit->text().toDouble(&ok3);

    // Проверяем корректность ввода
    if (!ok1 || !ok2 || !ok3) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректные числовые значения");
        return;
    }

    if (equation.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите уравнение");
        return;
    }

    // Вычисляем корень
    auto result = BisectionMethod::solveEquation(equation, a, b, epsilon);

    // Выводим результат
    if (result.success) {
        ui->resultLabel->setText(QString("Корень: %1\nКоличество итераций: %2")
                               .arg(result.root, 0, 'g', 10)
                               .arg(result.iterations));
    } else {
        ui->resultLabel->setText("Ошибка: " + result.errorMessage);
    }
}

void BisectionMethodDialog::on_clearButton_clicked()
{
    ui->equationEdit->clear();
    ui->aEdit->clear();
    ui->bEdit->clear();
    ui->epsilonEdit->setText("0.0001");
    ui->resultLabel->clear();
} 