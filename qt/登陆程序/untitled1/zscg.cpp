#include "zscg.h"
#include "ui_zscg.h"

zscg::zscg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::zscg)
{
    ui->setupUi(this);
}

zscg::~zscg()
{
    delete ui;
}
