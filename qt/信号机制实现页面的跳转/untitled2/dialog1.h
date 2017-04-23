#ifndef DIALOG1_H
#define DIALOG1_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QDialog>
class Dialog2;
class Dialog3;
class QStackedLayout;
class QVBoxLayout;

namespace Ui {
class Dialog1;
}

class Dialog1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
signals:
    void display(int number);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog1 *ui;
    Dialog2 *two;
    Dialog3 *three;
    QStackedLayout *stackLayout;
    QVBoxLayout *mainLayout;
};

#endif // DIALOG1_H
