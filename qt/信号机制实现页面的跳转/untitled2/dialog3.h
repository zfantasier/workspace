#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
    ~Dialog3();
signals:
    void display(int number);
private slots:
    void on_previousPushButton_clicked();

private:
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
