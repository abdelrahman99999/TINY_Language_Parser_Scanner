#include "scanner_tab.h"
#include "Scanner/Scan.h"
#include "ui_scanner_tab.h"
#include "mainwindow.h"
#include <QtDebug>

scanner_tab::scanner_tab(QWidget *parent,QString str) :
    QWidget(parent),
    ui(new Ui::scanner_tab)
{
    ui->setupUi(this);
    ui->textEdit->setText(QString::fromStdString(Scanner_scan(str.toStdString())));
//    qDebug()<<QString::fromStdString(Scanner_scan(str.toStdString()));
}

void scanner_tab::on_save_clicked()
{
    MainWindow::save_file(ui->textEdit);
}


scanner_tab::~scanner_tab()
{
    delete ui;
}


