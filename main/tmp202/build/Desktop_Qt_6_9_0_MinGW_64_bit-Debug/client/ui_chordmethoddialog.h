/********************************************************************************
** Form generated from reading UI file 'chordmethoddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHORDMETHODDIALOG_H
#define UI_CHORDMETHODDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChordMethodDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *inputGroupBox;
    QFormLayout *formLayout;
    QLabel *equationLabel;
    QLineEdit *equationEdit;
    QLabel *aLabel;
    QDoubleSpinBox *aSpinBox;
    QLabel *bLabel;
    QDoubleSpinBox *bSpinBox;
    QLabel *epsilonLabel;
    QDoubleSpinBox *epsilonSpinBox;
    QLabel *maxIterationsLabel;
    QSpinBox *maxIterationsSpinBox;
    QGroupBox *resultGroupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *resultEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QPushButton *solveButton;
    QPushButton *closeButton;

    void setupUi(QDialog *ChordMethodDialog)
    {
        if (ChordMethodDialog->objectName().isEmpty())
            ChordMethodDialog->setObjectName("ChordMethodDialog");
        ChordMethodDialog->resize(500, 400);
        verticalLayout = new QVBoxLayout(ChordMethodDialog);
        verticalLayout->setObjectName("verticalLayout");
        inputGroupBox = new QGroupBox(ChordMethodDialog);
        inputGroupBox->setObjectName("inputGroupBox");
        formLayout = new QFormLayout(inputGroupBox);
        formLayout->setObjectName("formLayout");
        equationLabel = new QLabel(inputGroupBox);
        equationLabel->setObjectName("equationLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, equationLabel);

        equationEdit = new QLineEdit(inputGroupBox);
        equationEdit->setObjectName("equationEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, equationEdit);

        aLabel = new QLabel(inputGroupBox);
        aLabel->setObjectName("aLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, aLabel);

        aSpinBox = new QDoubleSpinBox(inputGroupBox);
        aSpinBox->setObjectName("aSpinBox");
        aSpinBox->setMinimum(-1000.000000000000000);
        aSpinBox->setMaximum(1000.000000000000000);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, aSpinBox);

        bLabel = new QLabel(inputGroupBox);
        bLabel->setObjectName("bLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, bLabel);

        bSpinBox = new QDoubleSpinBox(inputGroupBox);
        bSpinBox->setObjectName("bSpinBox");
        bSpinBox->setMinimum(-1000.000000000000000);
        bSpinBox->setMaximum(1000.000000000000000);
        bSpinBox->setValue(5.000000000000000);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, bSpinBox);

        epsilonLabel = new QLabel(inputGroupBox);
        epsilonLabel->setObjectName("epsilonLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, epsilonLabel);

        epsilonSpinBox = new QDoubleSpinBox(inputGroupBox);
        epsilonSpinBox->setObjectName("epsilonSpinBox");
        epsilonSpinBox->setDecimals(8);
        epsilonSpinBox->setMinimum(0.000000010000000);
        epsilonSpinBox->setMaximum(0.100000000000000);
        epsilonSpinBox->setSingleStep(0.000100000000000);
        epsilonSpinBox->setValue(0.000100000000000);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, epsilonSpinBox);

        maxIterationsLabel = new QLabel(inputGroupBox);
        maxIterationsLabel->setObjectName("maxIterationsLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, maxIterationsLabel);

        maxIterationsSpinBox = new QSpinBox(inputGroupBox);
        maxIterationsSpinBox->setObjectName("maxIterationsSpinBox");
        maxIterationsSpinBox->setMinimum(10);
        maxIterationsSpinBox->setMaximum(1000);
        maxIterationsSpinBox->setValue(100);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, maxIterationsSpinBox);


        verticalLayout->addWidget(inputGroupBox);

        resultGroupBox = new QGroupBox(ChordMethodDialog);
        resultGroupBox->setObjectName("resultGroupBox");
        verticalLayout_2 = new QVBoxLayout(resultGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        resultEdit = new QTextEdit(resultGroupBox);
        resultEdit->setObjectName("resultEdit");
        resultEdit->setReadOnly(true);

        verticalLayout_2->addWidget(resultEdit);


        verticalLayout->addWidget(resultGroupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(ChordMethodDialog);
        clearButton->setObjectName("clearButton");

        horizontalLayout->addWidget(clearButton);

        solveButton = new QPushButton(ChordMethodDialog);
        solveButton->setObjectName("solveButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/math.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        solveButton->setIcon(icon);

        horizontalLayout->addWidget(solveButton);

        closeButton = new QPushButton(ChordMethodDialog);
        closeButton->setObjectName("closeButton");

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChordMethodDialog);
        QObject::connect(closeButton, &QPushButton::clicked, ChordMethodDialog, qOverload<>(&QDialog::accept));

        solveButton->setDefault(true);


        QMetaObject::connectSlotsByName(ChordMethodDialog);
    } // setupUi

    void retranslateUi(QDialog *ChordMethodDialog)
    {
        ChordMethodDialog->setWindowTitle(QCoreApplication::translate("ChordMethodDialog", "\320\234\320\265\321\202\320\276\320\264 \321\205\320\276\321\200\320\264", nullptr));
        inputGroupBox->setTitle(QCoreApplication::translate("ChordMethodDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        equationLabel->setText(QCoreApplication::translate("ChordMethodDialog", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265:", nullptr));
        equationEdit->setPlaceholderText(QCoreApplication::translate("ChordMethodDialog", "\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: 1*x^2 -5*x +6", nullptr));
        aLabel->setText(QCoreApplication::translate("ChordMethodDialog", "\320\235\320\260\321\207\320\260\320\273\320\276 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\260 (a):", nullptr));
        bLabel->setText(QCoreApplication::translate("ChordMethodDialog", "\320\232\320\276\320\275\320\265\321\206 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\260 (b):", nullptr));
        epsilonLabel->setText(QCoreApplication::translate("ChordMethodDialog", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 (epsilon):", nullptr));
        maxIterationsLabel->setText(QCoreApplication::translate("ChordMethodDialog", "\320\234\320\260\320\272\321\201. \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        resultGroupBox->setTitle(QCoreApplication::translate("ChordMethodDialog", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        clearButton->setText(QCoreApplication::translate("ChordMethodDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        solveButton->setText(QCoreApplication::translate("ChordMethodDialog", "\320\240\320\265\321\210\320\270\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("ChordMethodDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChordMethodDialog: public Ui_ChordMethodDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHORDMETHODDIALOG_H
