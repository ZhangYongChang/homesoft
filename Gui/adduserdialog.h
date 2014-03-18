#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QLabel;
class QLineEdit;

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = 0);
    ~AddUserDialog();

	QString GetUserName();

private:
	QDialogButtonBox *buttonBox;
	QLabel *labelUserName;
	QLineEdit *lineEditUserName;

	void setupUi(QDialog *AddUserDialog);
	void retranslateUi(QDialog *AddUserDialog);
};

#endif // ADDUSERDIALOG_H
