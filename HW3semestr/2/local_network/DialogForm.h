#ifndef DIALOGFORM_H
#define DIALOGFORM_H

#include <QWidget>

namespace Ui {
class DialogForm;
}

class DialogForm : public QWidget
{
	Q_OBJECT

public:
	explicit DialogForm(QWidget *parent = 0);
	/**
	 * @brief appendText:apeend text on display
	 * @param text
	 */
	void appendText(QString text);
	~DialogForm();
signals:
	void clickButtonNextTurn();
	void clickButtonLogStatus();
private:
	Ui::DialogForm *ui;
};

#endif // DIALOGFORM_H
