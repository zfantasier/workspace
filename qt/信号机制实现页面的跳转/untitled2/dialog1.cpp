#include "dialog1.h"
#include "ui_dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include <QVBoxLayout>
#include <QStackedLayout>
#include  <QPushButton>

Dialog1::Dialog1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog1)
{
       ui->setupUi(this);
       setFixedSize(400, 300);
       two = new Dialog2;
       three = new Dialog3;
       stackLayout = new QStackedLayout;
       stackLayout->addWidget(this);
       stackLayout->addWidget(two);
       stackLayout->addWidget(three);
       connect(this, &Dialog1::display, stackLayout, &QStackedLayout::setCurrentIndex);             // 0
       connect(two, &Dialog2::display, stackLayout, &QStackedLayout::setCurrentIndex);             // 1
       connect(three, &Dialog3::display, stackLayout, &QStackedLayout::setCurrentIndex);       // 2

       mainLayout = new QVBoxLayout;
       mainLayout->addLayout(stackLayout);
       setLayout(mainLayout);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    emit display(1);
}
