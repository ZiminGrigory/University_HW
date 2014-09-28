#include "parsetree.h"


bool isAction(QChar c)
{
    return ((c == '*')||(c == '/')||(c == '+')||(c == '-'));
}


ParseTree::~ParseTree()
{
    inp.close();
    delete root;
}

void ParseTree::makeTree(Node *&node, ifstream &inp)
{
    QChar chr = ' ';
    do{
        chr = QChar(inp.get());
        if (isAction(chr))
        {
            Node *nodeSec = new Operator(chr);
            nodeSec->setLeftChild();
            nodeSec->setRightChild();
            makeTree(nodeSec->getLeftChild(), inp);
            makeTree(nodeSec->getRightChild(), inp);
            node = nodeSec;
        }
        else if ((chr != '(') && (chr != ')') && (chr != ' '))
        {
            inp.putback(chr.toAscii());
            double value = 0;
            inp >> value;
            node = new Operand(value);
            return;
        }
        else if (chr == ')')
            return;
    }
    while (!inp.eof());
}

void ParseTree::makeTreeFromFile()
{
    if (inp.is_open())
        makeTree(root,inp);
}

void ParseTree::setFileName(QString str)
{
    inp.open(str.toUtf8());
}

double ParseTree::calculate()
{
    if (root == NULL)
        return 0;
    return root->calculate();
}


void ParseTree::print()
{
    if (root == NULL)
        return;
    root->print();
}
