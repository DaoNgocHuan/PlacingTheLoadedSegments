/********************************************************************************
** Form generated from reading UI file 'diploma.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPLOMA_H
#define UI_DIPLOMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diploma
{
public:
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_11;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_10;
    QTableWidget *InputData;
    QWidget *tab_4;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_19;
    QLabel *formulas;
    QGridLayout *gridLayout_12;
    QPushButton *add;
    QPushButton *del;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QPushButton *Des;
    QPushButton *result;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QGridLayout *gridLayout_18;
    QGraphicsView *DesInput;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QGraphicsView *graph1;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_14;
    QPushButton *OFile;
    QPushButton *SFile;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDoubleSpinBox *c;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *select;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *N;

    void setupUi(QDialog *Diploma)
    {
        if (Diploma->objectName().isEmpty())
            Diploma->setObjectName(QString::fromUtf8("Diploma"));
        Diploma->resize(713, 512);
        gridLayout_17 = new QGridLayout(Diploma);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_3 = new QLabel(Diploma);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_11->addWidget(label_3, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Diploma);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_10 = new QGridLayout(tab_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        InputData = new QTableWidget(tab_3);
        InputData->setObjectName(QString::fromUtf8("InputData"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(InputData->sizePolicy().hasHeightForWidth());
        InputData->setSizePolicy(sizePolicy);
        InputData->setContextMenuPolicy(Qt::DefaultContextMenu);
        InputData->setFrameShape(QFrame::Box);
        InputData->setFrameShadow(QFrame::Plain);
        InputData->setMidLineWidth(0);
        InputData->setSelectionMode(QAbstractItemView::SingleSelection);

        gridLayout_10->addWidget(InputData, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_9 = new QGridLayout(tab_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        scrollArea = new QScrollArea(tab_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 580, 136));
        gridLayout_19 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        formulas = new QLabel(scrollAreaWidgetContents_2);
        formulas->setObjectName(QString::fromUtf8("formulas"));

        gridLayout_19->addWidget(formulas, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout_9->addWidget(scrollArea, 1, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_11->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_11, 0, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        add = new QPushButton(Diploma);
        add->setObjectName(QString::fromUtf8("add"));
        add->setFocusPolicy(Qt::NoFocus);

        gridLayout_12->addWidget(add, 0, 0, 1, 1);

        del = new QPushButton(Diploma);
        del->setObjectName(QString::fromUtf8("del"));
        del->setFocusPolicy(Qt::NoFocus);

        gridLayout_12->addWidget(del, 1, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_13, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        Des = new QPushButton(Diploma);
        Des->setObjectName(QString::fromUtf8("Des"));
        Des->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(Des, 0, 0, 1, 1);

        result = new QPushButton(Diploma);
        result->setObjectName(QString::fromUtf8("result"));
        result->setFocusPolicy(Qt::NoFocus);

        gridLayout_5->addWidget(result, 0, 1, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget_2 = new QTabWidget(Diploma);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_18 = new QGridLayout(tab_7);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        DesInput = new QGraphicsView(tab_7);
        DesInput->setObjectName(QString::fromUtf8("DesInput"));

        gridLayout_18->addWidget(DesInput, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_7, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        graph1 = new QGraphicsView(tab_5);
        graph1->setObjectName(QString::fromUtf8("graph1"));

        gridLayout_6->addWidget(graph1, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());

        gridLayout_8->addWidget(tabWidget_2, 1, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_8, 2, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        OFile = new QPushButton(Diploma);
        OFile->setObjectName(QString::fromUtf8("OFile"));
        OFile->setFocusPolicy(Qt::NoFocus);

        gridLayout_14->addWidget(OFile, 0, 0, 1, 1);

        SFile = new QPushButton(Diploma);
        SFile->setObjectName(QString::fromUtf8("SFile"));
        SFile->setFocusPolicy(Qt::NoFocus);

        gridLayout_14->addWidget(SFile, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_14, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Diploma);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        c = new QDoubleSpinBox(Diploma);
        c->setObjectName(QString::fromUtf8("c"));
        c->setMinimum(1);
        c->setMaximum(999.99);

        gridLayout->addWidget(c, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        select = new QPushButton(Diploma);
        select->setObjectName(QString::fromUtf8("select"));
        select->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(select, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(Diploma);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        N = new QSpinBox(Diploma);
        N->setObjectName(QString::fromUtf8("N"));
        N->setMinimum(1);
        N->setMaximum(9);

        gridLayout_2->addWidget(N, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_15->addLayout(gridLayout_4, 1, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_16, 0, 0, 1, 1);


        retranslateUi(Diploma);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Diploma);
    } // setupUi

    void retranslateUi(QDialog *Diploma)
    {
        Diploma->setWindowTitle(QApplication::translate("Diploma", "Diploma", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Diploma", "Input data:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Diploma", "Table", 0, QApplication::UnicodeUTF8));
        formulas->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Diploma", "Formulas", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("Diploma", "Add Row", 0, QApplication::UnicodeUTF8));
        del->setText(QApplication::translate("Diploma", "Delete Row", 0, QApplication::UnicodeUTF8));
        Des->setText(QApplication::translate("Diploma", "Describe problem", 0, QApplication::UnicodeUTF8));
        result->setText(QApplication::translate("Diploma", "Result", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("Diploma", "Describe problem", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("Diploma", "Segments", 0, QApplication::UnicodeUTF8));
        OFile->setText(QApplication::translate("Diploma", "OpenFile", 0, QApplication::UnicodeUTF8));
        SFile->setText(QApplication::translate("Diploma", "SaveFile", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Diploma", "Number c:", 0, QApplication::UnicodeUTF8));
        select->setText(QApplication::translate("Diploma", "Select", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Diploma", "Number of segments:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Diploma: public Ui_Diploma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPLOMA_H
