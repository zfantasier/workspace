/********************************************************************************
** Form generated from reading UI file 'zscg.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZSCG_H
#define UI_ZSCG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zscg
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *zscg)
    {
        if (zscg->objectName().isEmpty())
            zscg->setObjectName(QStringLiteral("zscg"));
        zscg->resize(800, 600);
        menubar = new QMenuBar(zscg);
        menubar->setObjectName(QStringLiteral("menubar"));
        zscg->setMenuBar(menubar);
        centralwidget = new QWidget(zscg);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        zscg->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(zscg);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        zscg->setStatusBar(statusbar);

        retranslateUi(zscg);

        QMetaObject::connectSlotsByName(zscg);
    } // setupUi

    void retranslateUi(QMainWindow *zscg)
    {
        zscg->setWindowTitle(QApplication::translate("zscg", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class zscg: public Ui_zscg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZSCG_H
