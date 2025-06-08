/********************************************************************************
** Form generated from reading UI file 'cryptodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRYPTODIALOG_H
#define UI_CRYPTODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CryptoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *keysGroupBox;
    QFormLayout *formLayout;
    QLabel *key1Label;
    QLineEdit *key1Edit;
    QLabel *key2Label;
    QLineEdit *key2Edit;
    QLabel *key3Label;
    QLineEdit *key3Edit;
    QPushButton *generateKeysButton;
    QSplitter *splitter;
    QGroupBox *plainTextGroupBox;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *cipherTextGroupBox;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *cipherTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QPushButton *closeButton;

    void setupUi(QDialog *CryptoDialog)
    {
        if (CryptoDialog->objectName().isEmpty())
            CryptoDialog->setObjectName("CryptoDialog");
        CryptoDialog->resize(600, 500);
        verticalLayout = new QVBoxLayout(CryptoDialog);
        verticalLayout->setObjectName("verticalLayout");
        keysGroupBox = new QGroupBox(CryptoDialog);
        keysGroupBox->setObjectName("keysGroupBox");
        formLayout = new QFormLayout(keysGroupBox);
        formLayout->setObjectName("formLayout");
        key1Label = new QLabel(keysGroupBox);
        key1Label->setObjectName("key1Label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, key1Label);

        key1Edit = new QLineEdit(keysGroupBox);
        key1Edit->setObjectName("key1Edit");
        key1Edit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, key1Edit);

        key2Label = new QLabel(keysGroupBox);
        key2Label->setObjectName("key2Label");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, key2Label);

        key2Edit = new QLineEdit(keysGroupBox);
        key2Edit->setObjectName("key2Edit");
        key2Edit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, key2Edit);

        key3Label = new QLabel(keysGroupBox);
        key3Label->setObjectName("key3Label");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, key3Label);

        key3Edit = new QLineEdit(keysGroupBox);
        key3Edit->setObjectName("key3Edit");
        key3Edit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, key3Edit);

        generateKeysButton = new QPushButton(keysGroupBox);
        generateKeysButton->setObjectName("generateKeysButton");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, generateKeysButton);


        verticalLayout->addWidget(keysGroupBox);

        splitter = new QSplitter(CryptoDialog);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        plainTextGroupBox = new QGroupBox(splitter);
        plainTextGroupBox->setObjectName("plainTextGroupBox");
        verticalLayout_2 = new QVBoxLayout(plainTextGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        plainTextEdit = new QPlainTextEdit(plainTextGroupBox);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout_2->addWidget(plainTextEdit);

        splitter->addWidget(plainTextGroupBox);
        cipherTextGroupBox = new QGroupBox(splitter);
        cipherTextGroupBox->setObjectName("cipherTextGroupBox");
        verticalLayout_3 = new QVBoxLayout(cipherTextGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        cipherTextEdit = new QPlainTextEdit(cipherTextGroupBox);
        cipherTextEdit->setObjectName("cipherTextEdit");

        verticalLayout_3->addWidget(cipherTextEdit);

        splitter->addWidget(cipherTextGroupBox);

        verticalLayout->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        encryptButton = new QPushButton(CryptoDialog);
        encryptButton->setObjectName("encryptButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/encrypt.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        encryptButton->setIcon(icon);

        horizontalLayout->addWidget(encryptButton);

        decryptButton = new QPushButton(CryptoDialog);
        decryptButton->setObjectName("decryptButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/decrypt.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        decryptButton->setIcon(icon1);

        horizontalLayout->addWidget(decryptButton);

        closeButton = new QPushButton(CryptoDialog);
        closeButton->setObjectName("closeButton");

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CryptoDialog);
        QObject::connect(closeButton, &QPushButton::clicked, CryptoDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(CryptoDialog);
    } // setupUi

    void retranslateUi(QDialog *CryptoDialog)
    {
        CryptoDialog->setWindowTitle(QCoreApplication::translate("CryptoDialog", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265 Triple DES", nullptr));
        keysGroupBox->setTitle(QCoreApplication::translate("CryptoDialog", "\320\232\320\273\321\216\321\207\320\270 Triple DES", nullptr));
        key1Label->setText(QCoreApplication::translate("CryptoDialog", "\320\232\320\273\321\216\321\207 1:", nullptr));
        key2Label->setText(QCoreApplication::translate("CryptoDialog", "\320\232\320\273\321\216\321\207 2:", nullptr));
        key3Label->setText(QCoreApplication::translate("CryptoDialog", "\320\232\320\273\321\216\321\207 3:", nullptr));
        generateKeysButton->setText(QCoreApplication::translate("CryptoDialog", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\265 \320\272\320\273\321\216\321\207\320\270", nullptr));
        plainTextGroupBox->setTitle(QCoreApplication::translate("CryptoDialog", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        cipherTextGroupBox->setTitle(QCoreApplication::translate("CryptoDialog", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        encryptButton->setText(QCoreApplication::translate("CryptoDialog", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        decryptButton->setText(QCoreApplication::translate("CryptoDialog", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        closeButton->setText(QCoreApplication::translate("CryptoDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CryptoDialog: public Ui_CryptoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRYPTODIALOG_H
