#include "inputfile.h"
#include "GUI_tabs/scanner_tab.h"
#include "ui_inputfile.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
inputFile::inputFile(QTabWidget *parent) :
    QWidget(nullptr),
    ui(new Ui::inputFile),
    tabWidget(parent)
{
    ui->setupUi(this);
}

void inputFile::create_new_tab(QString type){
    if(ui->input_TextEdit->toPlainText()==""){
               QMessageBox::critical(this,"error","please open a file first");
                    return;
        }
    QWidget * new_tab = nullptr;
    if(type == "compile")
    {
        new_tab = new scanner_tab(nullptr , ui->input_TextEdit->toPlainText());
    }
    else if(type == "tree"){

    }


   tabWidget->addTab(new_tab,type);
   tabWidget ->setCurrentIndex(tabWidget->count()-1);
}


void inputFile::open(){
    on_openFile_clicked();
}

void inputFile::on_openFile_clicked()
{
    QString filter = "Text (*.txt);;All files (*.*)";
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file","C:\\",filter);
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","file not open");
        return;
      }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->input_TextEdit->setText(text);
    file.close();

}



void inputFile::on_compile_clicked()
{
    create_new_tab("compile");
}

inputFile::~inputFile()
{
    delete ui;
}








