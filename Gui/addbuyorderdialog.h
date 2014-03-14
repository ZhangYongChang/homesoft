#ifndef ADDBUYORDERDIALOG_H
#define ADDBUYORDERDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class AddBuyOrderDialog;
}

class AddBuyOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBuyOrderDialog(QWidget *parent = 0);
    ~AddBuyOrderDialog();

	void SetItems(const std::vector<std::string> &items);
	void SetUsers(const std::vector<std::string> &users);

	QDate GetOrderDate();
	QString GetItemName();
	QString GetUser();
	double GetPrice();
	double GetNumber();

private:
    Ui::AddBuyOrderDialog *ui;
};

#endif // ADDBUYORDERDIALOG_H
