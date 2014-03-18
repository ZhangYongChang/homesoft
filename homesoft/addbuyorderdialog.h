#ifndef ADDBUYORDERDIALOG_H
#define ADDBUYORDERDIALOG_H

#include <QDialog>
#include <QDate>

class QDialogButtonBox;
class QDateEdit;
class QComboBox;
class QLineEdit;
class QLabel;

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
	QDialogButtonBox *buttonBox;
	QDateEdit *dateEdit;
	QComboBox *comboBoxUserID;
	QComboBox *comboBoxItemID;
	QLineEdit *lineEditNumber;
	QLineEdit *lineEditPrice;
	QLabel *labelPrice;
	QLabel *labelNumber;

	void setupUi(QDialog *AddBuyOrderDialog);
	void retranslateUi(QDialog *AddBuyOrderDialog);
};

#endif // ADDBUYORDERDIALOG_H
