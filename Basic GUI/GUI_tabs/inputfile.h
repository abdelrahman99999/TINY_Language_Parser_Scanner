#ifndef INPUTFILE_H
#define INPUTFILE_H

#include <QWidget>
#include <QTabWidget>
#include <string>

namespace Ui {
class inputFile;
}

class inputFile : public QWidget
{
    Q_OBJECT

public:
    explicit inputFile(QTabWidget *parent = nullptr);
    void open();
    ~inputFile();

private slots:
    void on_openFile_clicked();

    void create_new_tab(QString type);

    void on_compile_clicked();

private:
    Ui::inputFile *ui;
    QTabWidget *tabWidget;
    QString file_path_;
};

#endif // INPUTFILE_H
