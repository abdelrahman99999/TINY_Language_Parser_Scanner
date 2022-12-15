#include "syntaxtree_tab.h"
#include "Parser/Tree.h"
#include "Scanner/Scan.h"
#include "ui_syntaxtree_tab.h"

syntaxTree_tab::syntaxTree_tab(QWidget *parent,string str) :
    QWidget(parent),
    ui(new Ui::syntaxTree_tab)
{
    ui->setupUi(this);

    queue<Token> input =string_parse(str);
    Node* root = program(&input);

    draw(root);

    QString path = QCoreApplication::applicationDirPath()+"/syntax_tree.png";
    QByteArray ba = path.toLocal8Bit();
    const char *c_str2 = ba.data();
    QPixmap *myPixMap = new QPixmap(c_str2);
    ui->label->setPixmap(*myPixMap);
    ui->label->setScaledContents(true);
    ui->label->show();
}



int counter = 1;

int syntaxTree_tab::drawNode(Node* node, string &str, int id) {
    int edge;

    if(node->key.type == "READ"|| node->key.type == "ASSIGN"){
        str += "node[shape = rect label=\"" + node->key.type+"\n(" + node->key.value + ")\"]id" + to_string(id)+" ";
    }

    if (node->key.type == "IF" || node->key.type == "WRITE" || node->key.type == "REPEAT" ) {
        str += "node[shape = rect label=\"" + node->key.type + "\"]id" + to_string(id)+" ";
    }
    else {
        str += "node[shape = oval label=\"" + node->key.type +"\n(" + node->key.value + ")\"]id" + to_string(id)+" ";
    }

    for (int i = 0; i < (int) node->child.size(); i++) {
        counter++;
        edge = drawNode(node->child[i], str, counter);
        str += "id" + to_string(id) + "--id" + to_string(edge)+" ";
        node->child[i]->key.id = edge;
        qDebug() << QString::number(node->key.id);
    }

    if (node->key.type == "IF") {
         Node* temp, *temp2;
        for (int i = 0; i < (int) node->child.size() - 1; i++) {
            if (node->child[i]->sibling != nullptr) {
                temp = node->child[i]->sibling;
                temp2 = node->child[i + 1];
                str += "{rank = same; id" + to_string(temp->key.id) + "; id" + to_string(temp2->key.id) + "; }" + " id" + to_string(temp->key.id) + "--id" + to_string(temp2->key.id)+" [style = invis]; ";
            }
        }
    }


    for (int i = 0; i < (int) node->child.size() - 1; i++) {
        Node* temp, *temp2;
        if (node->child.size() != 1 && node->child.size() != 0 && node->sibling == nullptr) {
            temp = node->child[i];
            temp2 = node->child[i + 1];
            str += "{rank = same; id" + to_string(temp->key.id) + "; id" + to_string(temp2->key.id) + "; }" + " id" + to_string(temp->key.id) + "--id" + to_string(temp2->key.id)+" [style = invis]; ";
        }
    }
    if (node->sibling != nullptr) {
        counter++;
        edge = drawNode(node->sibling, str, counter);
        str += "{rank = same; id" + to_string(id) + "; id" + to_string(edge) + "; }" + " id" + to_string(id) + "--id" + to_string(edge)+" ";
        node->sibling->key.id = edge;
    }
    return id;
}


void syntaxTree_tab::draw(Node* tree) {
    Agraph_t* G;
    GVC_t* gvc;
    gvc = gvContext();
    string dotLang="graph main{";
    drawNode(tree->child[0], dotLang, 1);
    dotLang += "}";
    qDebug()<<QString::fromStdString(dotLang);
    char * y= &dotLang[0];
    G = agmemread(y);
    gvLayout (gvc, G, "dot");
    QString path = QCoreApplication::applicationDirPath()+"/syntax_tree.png";
    QByteArray ba = path.toLocal8Bit();
    const char *c_str2 = ba.data();
    qDebug() << path;
    gvRenderFilename(gvc,G,"png",c_str2);
    gvFreeLayout(gvc, G);
    agclose (G);
    gvFreeContext(gvc);
}

syntaxTree_tab::~syntaxTree_tab()
{
    delete ui;
}
