#ifndef BISECTIONMETHODDIALOG_H
#define BISECTIONMETHODDIALOG_H

#include <QDialog>
#include "../../common/math/bisectionmethod.h"

namespace Ui {
class BisectionMethodDialog;
}

class BisectionMethodDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BisectionMethodDialog(QWidget *parent = nullptr);
    ~BisectionMethodDialog();

private slots:
    void on_calculateButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::BisectionMethodDialog *ui;
};

#endif // BISECTIONMETHODDIALOG_H 