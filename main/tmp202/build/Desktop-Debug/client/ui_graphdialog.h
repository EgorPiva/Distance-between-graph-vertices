/********************************************************************************
** Form generated from reading UI file 'graphdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHDIALOG_H
#define UI_GRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *vertexGroupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *vertexSpinBox;
    QPushButton *addVertexButton;
    QGroupBox *edgeGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *fromVertexComboBox;
    QLabel *label_3;
    QComboBox *toVertexComboBox;
    QLabel *label_4;
    QDoubleSpinBox *weightSpinBox;
    QPushButton *addEdgeButton;
    QGroupBox *pathGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *startVertexComboBox;
    QLabel *label_6;
    QComboBox *endVertexComboBox;
    QPushButton *findPathButton;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *edgesGroupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *edgesListWidget;
    QGroupBox *resultGroupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *resultLabel;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;

    void setupUi(QDialog *GraphDialog)
    {
        if (GraphDialog->objectName().isEmpty())
            GraphDialog->setObjectName("GraphDialog");
        GraphDialog->resize(600, 400);
        verticalLayout = new QVBoxLayout(GraphDialog);
        verticalLayout->setObjectName("verticalLayout");
        vertexGroupBox = new QGroupBox(GraphDialog);
        vertexGroupBox->setObjectName("vertexGroupBox");
        horizontalLayout = new QHBoxLayout(vertexGroupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(vertexGroupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        vertexSpinBox = new QSpinBox(vertexGroupBox);
        vertexSpinBox->setObjectName("vertexSpinBox");
        vertexSpinBox->setMinimum(0);
        vertexSpinBox->setMaximum(999);

        horizontalLayout->addWidget(vertexSpinBox);

        addVertexButton = new QPushButton(vertexGroupBox);
        addVertexButton->setObjectName("addVertexButton");

        horizontalLayout->addWidget(addVertexButton);


        verticalLayout->addWidget(vertexGroupBox);

        edgeGroupBox = new QGroupBox(GraphDialog);
        edgeGroupBox->setObjectName("edgeGroupBox");
        horizontalLayout_2 = new QHBoxLayout(edgeGroupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(edgeGroupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        fromVertexComboBox = new QComboBox(edgeGroupBox);
        fromVertexComboBox->setObjectName("fromVertexComboBox");

        horizontalLayout_2->addWidget(fromVertexComboBox);

        label_3 = new QLabel(edgeGroupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        toVertexComboBox = new QComboBox(edgeGroupBox);
        toVertexComboBox->setObjectName("toVertexComboBox");

        horizontalLayout_2->addWidget(toVertexComboBox);

        label_4 = new QLabel(edgeGroupBox);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        weightSpinBox = new QDoubleSpinBox(edgeGroupBox);
        weightSpinBox->setObjectName("weightSpinBox");
        weightSpinBox->setMinimum(0.000000000000000);
        weightSpinBox->setMaximum(999999.989999999990687);
        weightSpinBox->setSingleStep(0.100000000000000);
        weightSpinBox->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(weightSpinBox);

        addEdgeButton = new QPushButton(edgeGroupBox);
        addEdgeButton->setObjectName("addEdgeButton");

        horizontalLayout_2->addWidget(addEdgeButton);


        verticalLayout->addWidget(edgeGroupBox);

        pathGroupBox = new QGroupBox(GraphDialog);
        pathGroupBox->setObjectName("pathGroupBox");
        horizontalLayout_3 = new QHBoxLayout(pathGroupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(pathGroupBox);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        startVertexComboBox = new QComboBox(pathGroupBox);
        startVertexComboBox->setObjectName("startVertexComboBox");

        horizontalLayout_3->addWidget(startVertexComboBox);

        label_6 = new QLabel(pathGroupBox);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        endVertexComboBox = new QComboBox(pathGroupBox);
        endVertexComboBox->setObjectName("endVertexComboBox");

        horizontalLayout_3->addWidget(endVertexComboBox);

        findPathButton = new QPushButton(pathGroupBox);
        findPathButton->setObjectName("findPathButton");

        horizontalLayout_3->addWidget(findPathButton);


        verticalLayout->addWidget(pathGroupBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        edgesGroupBox = new QGroupBox(GraphDialog);
        edgesGroupBox->setObjectName("edgesGroupBox");
        verticalLayout_2 = new QVBoxLayout(edgesGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        edgesListWidget = new QListWidget(edgesGroupBox);
        edgesListWidget->setObjectName("edgesListWidget");

        verticalLayout_2->addWidget(edgesListWidget);


        horizontalLayout_4->addWidget(edgesGroupBox);

        resultGroupBox = new QGroupBox(GraphDialog);
        resultGroupBox->setObjectName("resultGroupBox");
        verticalLayout_3 = new QVBoxLayout(resultGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        resultLabel = new QLabel(resultGroupBox);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(resultLabel);


        horizontalLayout_4->addWidget(resultGroupBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        clearButton = new QPushButton(GraphDialog);
        clearButton->setObjectName("clearButton");

        horizontalLayout_5->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(GraphDialog);

        QMetaObject::connectSlotsByName(GraphDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphDialog)
    {
        GraphDialog->setWindowTitle(QCoreApplication::translate("GraphDialog", "\320\237\320\276\320\270\321\201\320\272 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\265\320\263\320\276 \320\277\321\203\321\202\320\270 \320\262 \320\263\321\200\320\260\321\204\320\265", nullptr));
        vertexGroupBox->setTitle(QCoreApplication::translate("GraphDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        label->setText(QCoreApplication::translate("GraphDialog", "\320\235\320\276\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275\321\213:", nullptr));
        addVertexButton->setText(QCoreApplication::translate("GraphDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
        edgeGroupBox->setTitle(QCoreApplication::translate("GraphDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\200\320\265\320\261\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("GraphDialog", "\320\236\321\202:", nullptr));
        label_3->setText(QCoreApplication::translate("GraphDialog", "\320\224\320\276:", nullptr));
        label_4->setText(QCoreApplication::translate("GraphDialog", "\320\222\320\265\321\201:", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("GraphDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\265\320\261\321\200\320\276", nullptr));
        pathGroupBox->setTitle(QCoreApplication::translate("GraphDialog", "\320\237\320\276\320\270\321\201\320\272 \320\277\321\203\321\202\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("GraphDialog", "\320\236\321\202:", nullptr));
        label_6->setText(QCoreApplication::translate("GraphDialog", "\320\224\320\276:", nullptr));
        findPathButton->setText(QCoreApplication::translate("GraphDialog", "\320\235\320\260\320\271\321\202\320\270 \320\277\321\203\321\202\321\214", nullptr));
        edgesGroupBox->setTitle(QCoreApplication::translate("GraphDialog", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\200\321\221\320\261\320\265\321\200", nullptr));
        resultGroupBox->setTitle(QCoreApplication::translate("GraphDialog", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        resultLabel->setText(QString());
        clearButton->setText(QCoreApplication::translate("GraphDialog", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphDialog: public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHDIALOG_H
