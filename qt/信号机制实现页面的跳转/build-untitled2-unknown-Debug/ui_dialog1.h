/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QStringLiteral("Dialog1"));
        Dialog1->resize(400, 300);
        centralWidget = new QWidget(Dialog1);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 170, 99, 27));
        Dialog1->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Dialog1);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 28));
        Dialog1->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Dialog1);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Dialog1->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Dialog1);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Dialog1->setStatusBar(statusBar);

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "Dialog1", 0));
        pushButton->setText(QApplication::translate("Dialog1", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
