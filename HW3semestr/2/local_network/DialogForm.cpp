#include "DialogForm.h"
#include "ui_DialogForm.h"

DialogForm::DialogForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DialogForm)
{
	ui->setupUi(this);
	this->setWindowTitle("ЛОГ ЛОКАЛЬНОЙ СЕТИ");
	connect(ui->pushButton, SIGNAL(clicked()), this, SIGNAL(clickButtonNextTurn()));
	connect(ui->StatusOfOs, SIGNAL(clicked()), this, SIGNAL(clickButtonLogStatus()));
}

void DialogForm::appendText(QString text)
{
	ui->textBrowser->append(text);
}

DialogForm::~DialogForm()
{
	delete ui;
}
