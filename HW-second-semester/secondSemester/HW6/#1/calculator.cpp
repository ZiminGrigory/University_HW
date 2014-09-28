#include "calculator.h"
#include "parsetree.h"

using namespace std;

double calculate(double argFirst, double argumentSec , QString action)
{
    if (action == "+")
        return argFirst + argumentSec;
    if (action == "-")
        return argFirst - argumentSec;
    if (action == "*")
        return argFirst * argumentSec;
    if (action == "/")
        return double (argFirst) / argumentSec;

}

bool isAction(QString str)
{
    return ((str == "*")||(str == "/")||(str == "+")||(str == "-"));
}

double calcChild(TreeNode *node)
{
    if (!isAction(node->str))
        return QString(node->str).toDouble();
    return calculate(calcChild(node->left),calcChild(node->right), node->str);
}

double Calculator::calculator(Tree *&tree)
{
    if (tree->root != NULL && tree->root->left != NULL && tree->root->right != NULL)
        return calculate(calcChild(tree->root->left), calcChild(tree->root->right), tree->root->str);
    else{
        cout << "MISTAKE!!!";
        return +100500;
    }
}

void Printer::print(Tree *&tree, TreeNode *&node)
{
    if (tree->root != NULL && tree->root->left != NULL && tree->root->right != NULL){
        if (isAction(node->str))
        {
            cout << "(" << node->str.toStdString() << " ";
            if (isAction(node->left->str))
                print(tree, node->left);
            else
            {
                cout << node->left->str.toStdString() << " ";
            }
            if (isAction(node->right->str))
                print(tree, node->right);
            else{
                cout << node->right->str.toStdString() << " ";
            }
            cout << ") ";
        }
        else{
            cout << node->str.toStdString() << " ";
            print(tree, node->left);
            print(tree, node->right);
        }
    }
    else
        cout << "MISTAKE!!!";
}
