#ifndef ZSCG_H
#define ZSCG_H

#include <QMainWindow>

namespace Ui {
class zscg;
}

class zscg : public QMainWindow
{
    Q_OBJECT

public:
    explicit zscg(QWidget *parent = 0);
    ~zscg();

private:
    Ui::zscg *ui;
};

#endif // ZSCG_H
