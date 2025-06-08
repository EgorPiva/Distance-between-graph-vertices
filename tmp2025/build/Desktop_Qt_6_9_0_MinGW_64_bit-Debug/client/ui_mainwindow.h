/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionCrypto;
    QAction *actionChordMethod;
    QAction *actionSteganography;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *toolsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *cryptoButton;
    QPushButton *chordMethodButton;
    QPushButton *steganographyButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionCrypto = new QAction(MainWindow);
        actionCrypto->setObjectName("actionCrypto");
        actionChordMethod = new QAction(MainWindow);
        actionChordMethod->setObjectName("actionChordMethod");
        actionSteganography = new QAction(MainWindow);
        actionSteganography->setObjectName("actionSteganography");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolsGroupBox = new QGroupBox(centralwidget);
        toolsGroupBox->setObjectName("toolsGroupBox");
        verticalLayout_2 = new QVBoxLayout(toolsGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        cryptoButton = new QPushButton(toolsGroupBox);
        cryptoButton->setObjectName("cryptoButton");
        cryptoButton->setMinimumSize(QSize(250, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/encrypt.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cryptoButton->setIcon(icon);

        verticalLayout_2->addWidget(cryptoButton);

        chordMethodButton = new QPushButton(toolsGroupBox);
        chordMethodButton->setObjectName("chordMethodButton");
        chordMethodButton->setMinimumSize(QSize(250, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/math.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chordMethodButton->setIcon(icon1);

        verticalLayout_2->addWidget(chordMethodButton);

        steganographyButton = new QPushButton(toolsGroupBox);
        steganographyButton->setObjectName("steganographyButton");
        steganographyButton->setMinimumSize(QSize(250, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/stegano.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        steganographyButton->setIcon(icon2);

        verticalLayout_2->addWidget(steganographyButton);


        horizontalLayout->addWidget(toolsGroupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName("menuExit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\211\320\270\321\211\320\265\320\275\320\275\321\213\320\271 \320\272\320\273\320\270\320\265\320\275\321\202", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        actionCrypto->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        actionChordMethod->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\205\320\276\321\200\320\264", nullptr));
        actionSteganography->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\265\320\263\320\260\320\275\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        toolsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", nullptr));
        cryptoButton->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        chordMethodButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\205\320\276\321\200\320\264", nullptr));
        steganographyButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\265\320\263\320\260\320\275\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        menuExit->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
