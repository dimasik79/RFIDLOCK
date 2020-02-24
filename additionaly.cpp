
#include "exitpass.h"
#include "additionaly.h"
#include "ui_additionaly.h"
#include "settings.h"
#include "card.h"

additionaly::additionaly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additionaly)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
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

void additionaly::on_pushButton_3_clicked()
{
    Card card;
    card.setModal(true);
    card.exec();

}
