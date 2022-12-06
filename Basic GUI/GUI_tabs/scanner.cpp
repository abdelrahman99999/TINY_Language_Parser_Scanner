#include "scanner.h"
#include "ui_scanner.h"

Scanner::Scanner(QWidget *parent,QString str) :
    QWidget(parent),
    ui(new Ui::Scanner)
{
    ui->setupUi(this);
    ui->textEdit->setText(QString::fromStdString(Scanner_scan(str.toStdString()));
}

Scanner::~Scanner()
{
    delete ui;
}
