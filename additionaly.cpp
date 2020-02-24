

#include "exitpass.h"
#include "additionaly.h"
#include "ui_additionaly.h"
#include "settings.h"

additionaly::additionaly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additionaly)
{
    ui->setupUi(this);
}

additionaly::~additionaly()
{
    delete ui;
}

void additionaly::on_pushButton_clicked()
{
    exitPass exi;
    exi.setModal(true);
    exi.exec();
}

void additionaly::on_pushButton_2_clicked()
{
    settings sety;
    sety.setModal(true);
    sety.exec();
}
