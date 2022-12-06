#ifndef SCANNER_TAB_H
#define SCANNER_TAB_H

#include <QWidget>

namespace Ui {
class scanner_tab;
}

class scanner_tab : public QWidget
{
    Q_OBJECT

public:
    explicit scanner_tab(QWidget *parent = nullptr, QString str="");
    ~scanner_tab();

private slots:
    void on_save_clicked();

private:
    Ui::scanner_tab *ui;
};

#endif // SCANNER_TAB_H
