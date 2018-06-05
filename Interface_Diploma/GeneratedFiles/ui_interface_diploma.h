/********************************************************************************
** Form generated from reading UI file 'interface_diploma.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_DIPLOMA_H
#define UI_INTERFACE_DIPLOMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface_DiplomaClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Interface_DiplomaClass)
    {
        if (Interface_DiplomaClass->objectName().isEmpty())
            Interface_DiplomaClass->setObjectName(QString::fromUtf8("Interface_DiplomaClass"));
        Interface_DiplomaClass->resize(501, 187);
        centralWidget = new QWidget(Interface_DiplomaClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        Interface_DiplomaClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Interface_DiplomaClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 501, 21));
        Interface_DiplomaClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Interface_DiplomaClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Interface_DiplomaClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Interface_DiplomaClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Interface_DiplomaClass->setStatusBar(statusBar);

        retranslateUi(Interface_DiplomaClass);

        QMetaObject::connectSlotsByName(Interface_DiplomaClass);
    } // setupUi

    void retranslateUi(QMainWindow *Interface_DiplomaClass)
    {
        Interface_DiplomaClass->setWindowTitle(QApplication::translate("Interface_DiplomaClass", "Interface_Diploma", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Interface_DiplomaClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Interface_DiplomaClass", "Sing In", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Interface_DiplomaClass", "User name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Interface_DiplomaClass", "Password", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Interface_DiplomaClass", "Log In", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Interface_DiplomaClass: public Ui_Interface_DiplomaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_DIPLOMA_H
