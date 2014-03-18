#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QLineEdit;
class QLabel;

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = 0);
    ~AddItemDialog();

	QString GetItemName();

private:
	QDialogButtonBox *buttonBox;
	QLineEdit *lineEditItemName;
	QLabel *labelItemStyle;

	void setupUi(QDialog *AddItemDialog);
	void retranslateUi(QDialog *AddItemDialog);
};

#endif // ADDITEMDIALOG_H
