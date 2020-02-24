#ifndef EXITPASS_H
#define EXITPASS_H

#include <QDialog>


namespace Ui {
class exitPass;
}

class exitPass : public QDialog
{
    Q_OBJECT

public:
    explicit exitPass(QWidget *parent = nullptr);
    ~exitPass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::exitPass *ui;
};

#endif // EXITPASS_H
