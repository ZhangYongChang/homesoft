#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include "addbuyorderdialog.h"

AddBuyOrderDialog::AddBuyOrderDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

AddBuyOrderDialog::~AddBuyOrderDialog()
{
}

void AddBuyOrderDialog::SetItems( const std::vector<std::string> &items )
{
	comboBoxItemID->setMaxVisibleItems(10);
	for (std::vector<std::string>::const_iterator it = items.begin();
		it != items.end();
		++it)
	{
		comboBoxItemID->addItem(it->c_str());
	}
}

QString AddBuyOrderDialog::GetItemName()
{
	return comboBoxItemID->currentText();
}

void AddBuyOrderDialog::SetUsers( const std::vector<std::string> &users )
{
	comboBoxUserID->setMaxVisibleItems(10);
	for (std::vector<std::string>::const_iterator it = users.begin();
		it != users.end();
		++it)
	{
		comboBoxUserID->addItem(it->c_str());
	}

}

QString AddBuyOrderDialog::GetUser()
{
	return comboBoxUserID->currentText();
}

QDate AddBuyOrderDialog::GetOrderDate()
{
	return dateEdit->date();

}

double AddBuyOrderDialog::GetPrice()
{
	return lineEditPrice->text().toDouble();
}

double AddBuyOrderDialog::GetNumber()
{
	return lineEditNumber->text().toDouble();
}

void AddBuyOrderDialog::setupUi( QDialog *AddBuyOrderDialog )
{
	if (AddBuyOrderDialog->objectName().isEmpty())
		AddBuyOrderDialog->setObjectName(QString::fromUtf8("AddBuyOrderDialog"));
	AddBuyOrderDialog->resize(400, 300);
	buttonBox = new QDialogButtonBox(AddBuyOrderDialog);
	buttonBox->setGeometry(QRect(30, 240, 341, 32));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	dateEdit = new QDateEdit(AddBuyOrderDialog);
	dateEdit->setGeometry(QRect(20, 80, 110, 22));
	comboBoxUserID = new QComboBox(AddBuyOrderDialog);
	comboBoxUserID->setGeometry(QRect(20, 20, 111, 22));
	comboBoxItemID = new QComboBox(AddBuyOrderDialog);
	comboBoxItemID->setGeometry(QRect(160, 20, 111, 22));
	lineEditNumber = new QLineEdit(AddBuyOrderDialog);
	lineEditNumber->setGeometry(QRect(260, 150, 113, 20));
	lineEditPrice = new QLineEdit(AddBuyOrderDialog);
	lineEditPrice->setGeometry(QRect(80, 150, 113, 20));
	labelPrice = new QLabel(AddBuyOrderDialog);
	labelPrice->setGeometry(QRect(10, 150, 54, 12));
	labelNumber = new QLabel(AddBuyOrderDialog);
	labelNumber->setGeometry(QRect(200, 150, 54, 12));

	retranslateUi(AddBuyOrderDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), AddBuyOrderDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), AddBuyOrderDialog, SLOT(reject()));

	this->dateEdit->setDate(QDate::currentDate());
}

void AddBuyOrderDialog::retranslateUi( QDialog *AddBuyOrderDialog )
{
	AddBuyOrderDialog->setWindowTitle(QApplication::translate("AddBuyOrderDialog", "\346\267\273\345\212\240\350\264\255\344\271\260", 0, QApplication::UnicodeUTF8));
	labelPrice->setText(QApplication::translate("AddBuyOrderDialog", "\345\215\225\344\273\267", 0, QApplication::UnicodeUTF8));
	labelNumber->setText(QApplication::translate("AddBuyOrderDialog", "\346\225\260\351\207\217", 0, QApplication::UnicodeUTF8));
}
