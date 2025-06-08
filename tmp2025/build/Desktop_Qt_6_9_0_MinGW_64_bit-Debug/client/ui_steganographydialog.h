/********************************************************************************
** Form generated from reading UI file 'steganographydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEGANOGRAPHYDIALOG_H
#define UI_STEGANOGRAPHYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SteganographyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabHide;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxSource;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSourceImage;
    QPushButton *buttonLoadImage;
    QGroupBox *groupBoxMessage;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *textEditMessage;
    QPushButton *buttonHideMessage;
    QGroupBox *groupBoxResult;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelResultImage;
    QPushButton *buttonSaveResult;
    QWidget *tabExtract;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBoxExtractSource;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelExtractImage;
    QPushButton *buttonLoadExtractImage;
    QPushButton *buttonExtractMessage;
    QGroupBox *groupBoxExtractedMessage;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *textEditExtractedMessage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SteganographyDialog)
    {
        if (SteganographyDialog->objectName().isEmpty())
            SteganographyDialog->setObjectName("SteganographyDialog");
        SteganographyDialog->resize(600, 450);
        verticalLayout = new QVBoxLayout(SteganographyDialog);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(SteganographyDialog);
        tabWidget->setObjectName("tabWidget");
        tabHide = new QWidget();
        tabHide->setObjectName("tabHide");
        verticalLayout_2 = new QVBoxLayout(tabHide);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBoxSource = new QGroupBox(tabHide);
        groupBoxSource->setObjectName("groupBoxSource");
        horizontalLayout = new QHBoxLayout(groupBoxSource);
        horizontalLayout->setObjectName("horizontalLayout");
        labelSourceImage = new QLabel(groupBoxSource);
        labelSourceImage->setObjectName("labelSourceImage");
        labelSourceImage->setMinimumSize(QSize(200, 150));
        labelSourceImage->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelSourceImage);

        buttonLoadImage = new QPushButton(groupBoxSource);
        buttonLoadImage->setObjectName("buttonLoadImage");

        horizontalLayout->addWidget(buttonLoadImage);


        verticalLayout_2->addWidget(groupBoxSource);

        groupBoxMessage = new QGroupBox(tabHide);
        groupBoxMessage->setObjectName("groupBoxMessage");
        verticalLayout_3 = new QVBoxLayout(groupBoxMessage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        textEditMessage = new QPlainTextEdit(groupBoxMessage);
        textEditMessage->setObjectName("textEditMessage");

        verticalLayout_3->addWidget(textEditMessage);


        verticalLayout_2->addWidget(groupBoxMessage);

        buttonHideMessage = new QPushButton(tabHide);
        buttonHideMessage->setObjectName("buttonHideMessage");

        verticalLayout_2->addWidget(buttonHideMessage);

        groupBoxResult = new QGroupBox(tabHide);
        groupBoxResult->setObjectName("groupBoxResult");
        horizontalLayout_2 = new QHBoxLayout(groupBoxResult);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelResultImage = new QLabel(groupBoxResult);
        labelResultImage->setObjectName("labelResultImage");
        labelResultImage->setMinimumSize(QSize(200, 150));
        labelResultImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelResultImage);

        buttonSaveResult = new QPushButton(groupBoxResult);
        buttonSaveResult->setObjectName("buttonSaveResult");

        horizontalLayout_2->addWidget(buttonSaveResult);


        verticalLayout_2->addWidget(groupBoxResult);

        tabWidget->addTab(tabHide, QString());
        tabExtract = new QWidget();
        tabExtract->setObjectName("tabExtract");
        verticalLayout_4 = new QVBoxLayout(tabExtract);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBoxExtractSource = new QGroupBox(tabExtract);
        groupBoxExtractSource->setObjectName("groupBoxExtractSource");
        horizontalLayout_3 = new QHBoxLayout(groupBoxExtractSource);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelExtractImage = new QLabel(groupBoxExtractSource);
        labelExtractImage->setObjectName("labelExtractImage");
        labelExtractImage->setMinimumSize(QSize(200, 150));
        labelExtractImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelExtractImage);

        buttonLoadExtractImage = new QPushButton(groupBoxExtractSource);
        buttonLoadExtractImage->setObjectName("buttonLoadExtractImage");

        horizontalLayout_3->addWidget(buttonLoadExtractImage);


        verticalLayout_4->addWidget(groupBoxExtractSource);

        buttonExtractMessage = new QPushButton(tabExtract);
        buttonExtractMessage->setObjectName("buttonExtractMessage");

        verticalLayout_4->addWidget(buttonExtractMessage);

        groupBoxExtractedMessage = new QGroupBox(tabExtract);
        groupBoxExtractedMessage->setObjectName("groupBoxExtractedMessage");
        verticalLayout_5 = new QVBoxLayout(groupBoxExtractedMessage);
        verticalLayout_5->setObjectName("verticalLayout_5");
        textEditExtractedMessage = new QPlainTextEdit(groupBoxExtractedMessage);
        textEditExtractedMessage->setObjectName("textEditExtractedMessage");
        textEditExtractedMessage->setReadOnly(true);

        verticalLayout_5->addWidget(textEditExtractedMessage);


        verticalLayout_4->addWidget(groupBoxExtractedMessage);

        tabWidget->addTab(tabExtract, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(SteganographyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SteganographyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SteganographyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SteganographyDialog, qOverload<>(&QDialog::reject));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SteganographyDialog);
    } // setupUi

    void retranslateUi(QDialog *SteganographyDialog)
    {
        SteganographyDialog->setWindowTitle(QCoreApplication::translate("SteganographyDialog", "\320\241\321\202\320\265\320\263\320\260\320\275\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        groupBoxSource->setTitle(QCoreApplication::translate("SteganographyDialog", "\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        labelSourceImage->setText(QCoreApplication::translate("SteganographyDialog", "\320\235\320\265\321\202 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        buttonLoadImage->setText(QCoreApplication::translate("SteganographyDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214...", nullptr));
        groupBoxMessage->setTitle(QCoreApplication::translate("SteganographyDialog", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\201\320\272\321\200\321\213\321\202\320\270\321\217", nullptr));
        buttonHideMessage->setText(QCoreApplication::translate("SteganographyDialog", "\320\241\320\272\321\200\321\213\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        groupBoxResult->setTitle(QCoreApplication::translate("SteganographyDialog", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        labelResultImage->setText(QCoreApplication::translate("SteganographyDialog", "\320\235\320\265\321\202 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        buttonSaveResult->setText(QCoreApplication::translate("SteganographyDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHide), QCoreApplication::translate("SteganographyDialog", "\320\241\320\272\321\200\321\213\321\202\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        groupBoxExtractSource->setTitle(QCoreApplication::translate("SteganographyDialog", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \321\201 \321\201\320\272\321\200\321\213\321\202\321\213\320\274 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265\320\274", nullptr));
        labelExtractImage->setText(QCoreApplication::translate("SteganographyDialog", "\320\235\320\265\321\202 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        buttonLoadExtractImage->setText(QCoreApplication::translate("SteganographyDialog", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214...", nullptr));
        buttonExtractMessage->setText(QCoreApplication::translate("SteganographyDialog", "\320\230\320\267\320\262\320\273\320\265\321\207\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        groupBoxExtractedMessage->setTitle(QCoreApplication::translate("SteganographyDialog", "\320\230\320\267\320\262\320\273\320\265\321\207\320\265\320\275\320\275\320\276\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExtract), QCoreApplication::translate("SteganographyDialog", "\320\230\320\267\320\262\320\273\320\265\321\207\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SteganographyDialog: public Ui_SteganographyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEGANOGRAPHYDIALOG_H
