#ifndef SYNTAXTREE_TAB_H
#define SYNTAXTREE_TAB_H
#include <QWidget>
#include <QFileDialog>
#include <string>
#include <QString>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "Parser/Parse.h"
#include "Parser/Tree.h"
#include "gvc.h"
#include "cdt.h"
#include "cgraph.h"

namespace Ui {
class syntaxTree_tab;
}

class syntaxTree_tab : public QWidget
{
    Q_OBJECT

public:
    explicit syntaxTree_tab(QWidget *parent = nullptr, string str="");
    ~syntaxTree_tab();
    int drawNode(Node* node, string &str, int id);
    void draw(Node* tree);
private:
    Ui::syntaxTree_tab *ui;
};

#endif // SYNTAXTREE_TAB_H
