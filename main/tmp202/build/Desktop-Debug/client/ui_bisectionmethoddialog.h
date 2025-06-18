/********************************************************************************
** Form generated from reading UI file 'bisectionmethoddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BISECTIONMETHODDIALOG_H
#define UI_BISECTIONMETHODDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BisectionMethodDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *equationEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *aEdit;
    QLabel *label_3;
    QLineEdit *bEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *epsilonEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *calculateButton;
    QPushButton *clearButton;
    QLabel *resultLabel;

    void setupUi(QDialog *BisectionMethodDialog)
    {
        if (BisectionMethodDialog->objectName().isEmpty())
            BisectionMethodDialog->setObjectName("BisectionMethodDialog");
        BisectionMethodDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(BisectionMethodDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(BisectionMethodDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        equationEdit = new QLineEdit(BisectionMethodDialog);
        equationEdit->setObjectName("equationEdit");

        verticalLayout->addWidget(equationEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(BisectionMethodDialog);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        aEdit = new QLineEdit(BisectionMethodDialog);
        aEdit->setObjectName("aEdit");

        horizontalLayout->addWidget(aEdit);

        label_3 = new QLabel(BisectionMethodDialog);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        bEdit = new QLineEdit(BisectionMethodDialog);
        bEdit->setObjectName("bEdit");

        horizontalLayout->addWidget(bEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(BisectionMethodDialog);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        epsilonEdit = new QLineEdit(BisectionMethodDialog);
        epsilonEdit->setObjectName("epsilonEdit");

        horizontalLayout_2->addWidget(epsilonEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        calculateButton = new QPushButton(BisectionMethodDialog);
        calculateButton->setObjectName("calculateButton");

        horizontalLayout_3->addWidget(calculateButton);

        clearButton = new QPushButton(BisectionMethodDialog);
        clearButton->setObjectName("clearButton");

        horizontalLayout_3->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout_3);

        resultLabel = new QLabel(BisectionMethodDialog);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(resultLabel);


        retranslateUi(BisectionMethodDialog);

        QMetaObject::connectSlotsByName(BisectionMethodDialog);
    } // setupUi

    void retranslateUi(QDialog *BisectionMethodDialog)
    {
        BisectionMethodDialog->setWindowTitle(QCoreApplication::translate("BisectionMethodDialog", "\320\234\320\265\321\202\320\276\320\264 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\277\320\276\320\277\320\276\320\273\320\260\320\274", nullptr));
        label->setText(QCoreApplication::translate("BisectionMethodDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 (\320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200, x^2 - 4):", nullptr));
        label_2->setText(QCoreApplication::translate("BisectionMethodDialog", "a:", nullptr));
        label_3->setText(QCoreApplication::translate("BisectionMethodDialog", "b:", nullptr));
        label_4->setText(QCoreApplication::translate("BisectionMethodDialog", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 (\316\265):", nullptr));
        epsilonEdit->setText(QCoreApplication::translate("BisectionMethodDialog", "0.0001", nullptr));
        calculateButton->setText(QCoreApplication::translate("BisectionMethodDialog", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        clearButton->setText(QCoreApplication::translate("BisectionMethodDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        resultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BisectionMethodDialog: public Ui_BisectionMethodDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BISECTIONMETHODDIALOG_H
