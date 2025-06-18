/********************************************************************************
** Form generated from reading UI file 'authdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHDIALOG_H
#define UI_AUTHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AuthDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_1;
    QHBoxLayout *horizontalLayout_1;
    QSpacerItem *horizontalSpacer_1;
    QGroupBox *serverGroupBox;
    QFormLayout *formLayout;
    QLabel *hostLabel;
    QLineEdit *hostEdit;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QPushButton *connectButton;
    QLabel *statusTextLabel;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *authGroupBox;
    QFormLayout *formLayout_2;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *AuthDialog)
    {
        if (AuthDialog->objectName().isEmpty())
            AuthDialog->setObjectName("AuthDialog");
        AuthDialog->resize(500, 450);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AuthDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AuthDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_1);

        serverGroupBox = new QGroupBox(AuthDialog);
        serverGroupBox->setObjectName("serverGroupBox");
        serverGroupBox->setMinimumSize(QSize(350, 120));
        formLayout = new QFormLayout(serverGroupBox);
        formLayout->setObjectName("formLayout");
        hostLabel = new QLabel(serverGroupBox);
        hostLabel->setObjectName("hostLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, hostLabel);

        hostEdit = new QLineEdit(serverGroupBox);
        hostEdit->setObjectName("hostEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, hostEdit);

        portLabel = new QLabel(serverGroupBox);
        portLabel->setObjectName("portLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, portLabel);

        portSpinBox = new QSpinBox(serverGroupBox);
        portSpinBox->setObjectName("portSpinBox");
        portSpinBox->setMinimum(1);
        portSpinBox->setMaximum(65535);
        portSpinBox->setValue(12345);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, portSpinBox);

        connectButton = new QPushButton(serverGroupBox);
        connectButton->setObjectName("connectButton");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, connectButton);

        statusTextLabel = new QLabel(serverGroupBox);
        statusTextLabel->setObjectName("statusTextLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, statusTextLabel);

        statusLabel = new QLabel(serverGroupBox);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setStyleSheet(QString::fromUtf8("color: red;"));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, statusLabel);


        horizontalLayout_1->addWidget(serverGroupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        authGroupBox = new QGroupBox(AuthDialog);
        authGroupBox->setObjectName("authGroupBox");
        authGroupBox->setMinimumSize(QSize(350, 120));
        formLayout_2 = new QFormLayout(authGroupBox);
        formLayout_2->setObjectName("formLayout_2");
        usernameLabel = new QLabel(authGroupBox);
        usernameLabel->setObjectName("usernameLabel");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, usernameLabel);

        usernameEdit = new QLineEdit(authGroupBox);
        usernameEdit->setObjectName("usernameEdit");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, usernameEdit);

        passwordLabel = new QLabel(authGroupBox);
        passwordLabel->setObjectName("passwordLabel");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, passwordLabel);

        passwordEdit = new QLineEdit(authGroupBox);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);


        horizontalLayout_2->addWidget(authGroupBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        registerButton = new QPushButton(AuthDialog);
        registerButton->setObjectName("registerButton");
        registerButton->setEnabled(false);
        registerButton->setMinimumSize(QSize(120, 30));

        horizontalLayout->addWidget(registerButton);

        loginButton = new QPushButton(AuthDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setEnabled(false);
        loginButton->setMinimumSize(QSize(120, 30));

        horizontalLayout->addWidget(loginButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(AuthDialog);

        loginButton->setDefault(true);


        QMetaObject::connectSlotsByName(AuthDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthDialog)
    {
        AuthDialog->setWindowTitle(QCoreApplication::translate("AuthDialog", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        serverGroupBox->setTitle(QCoreApplication::translate("AuthDialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \321\201\320\265\321\200\320\262\320\265\321\200\321\203", nullptr));
        hostLabel->setText(QCoreApplication::translate("AuthDialog", "\320\245\320\276\321\201\321\202:", nullptr));
        hostEdit->setText(QCoreApplication::translate("AuthDialog", "localhost", nullptr));
        portLabel->setText(QCoreApplication::translate("AuthDialog", "\320\237\320\276\321\200\321\202:", nullptr));
        connectButton->setText(QCoreApplication::translate("AuthDialog", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        statusTextLabel->setText(QCoreApplication::translate("AuthDialog", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        statusLabel->setText(QCoreApplication::translate("AuthDialog", "\320\235\320\265 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\276", nullptr));
        authGroupBox->setTitle(QCoreApplication::translate("AuthDialog", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        usernameLabel->setText(QCoreApplication::translate("AuthDialog", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("AuthDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        registerButton->setText(QCoreApplication::translate("AuthDialog", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginButton->setText(QCoreApplication::translate("AuthDialog", "\320\222\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthDialog: public Ui_AuthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHDIALOG_H
