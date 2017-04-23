/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QPushButton *previousPushButton;
    QPushButton *nextPushButton;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QStringLiteral("Dialog2"));
        Dialog2->resize(400, 300);
        previousPushButton = new QPushButton(Dialog2);
        previousPushButton->setObjectName(QStringLiteral("previousPushButton"));
        previousPushButton->setGeometry(QRect(80, 190, 99, 27));
        nextPushButton = new QPushButton(Dialog2);
        nextPushButton->setObjectName(QStringLiteral("nextPushButton"));
        nextPushButton->setGeometry(QRect(230, 190, 99, 27));

        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QApplication::translate("Dialog2", "Dialog", 0));
        previousPushButton->setText(QApplication::translate("Dialog2", "Previous", 0));
        nextPushButton->setText(QApplication::translate("Dialog2", "Next", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
