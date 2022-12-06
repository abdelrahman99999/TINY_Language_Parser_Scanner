#ifndef SCANNER_H
#define SCANNER_H

#include <QWidget>

namespace Ui {
class Scanner;
}

class Scanner : public QWidget
{
    Q_OBJECT

public:
    explicit Scanner(QWidget *parent = nullptr, QString str ="");
    ~Scanner();

private:
    Ui::Scanner *ui;
};

#endif // SCANNER_H
