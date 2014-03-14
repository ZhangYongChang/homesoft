#include "addbuyorderdialog.h"
#include "ui_addbuyorderdialog.h"

AddBuyOrderDialog::AddBuyOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBuyOrderDialog)
{
    ui->setupUi(this);
}

AddBuyOrderDialog::~AddBuyOrderDialog()
{
    delete ui;
}

void AddBuyOrderDialog::SetItems( const std::vector<std::string> &items )
{
	ui->comboBoxItemID->setMaxVisibleItems(10);
	for (std::vector<std::string>::const_iterator it = items.begin();
		it != items.end();
		++it)
	{
		ui->comboBoxItemID->addItem(it->c_str());
	}
}

QString AddBuyOrderDialog::GetItemName()
{
	return ui->comboBoxItemID->currentText();

}

void AddBuyOrderDialog::SetUsers( const std::vector<std::string> &users )
{
	ui->comboBoxUserID->setMaxVisibleItems(10);
	for (std::vector<std::string>::const_iterator it = users.begin();
		it != users.end();
		++it)
	{
		ui->comboBoxUserID->addItem(it->c_str());
	}

}

QString AddBuyOrderDialog::GetUser()
{
	return ui->comboBoxUserID->currentText();
}

QDate AddBuyOrderDialog::GetOrderDate()
{
	return ui->dateEdit->date();

}

double AddBuyOrderDialog::GetPrice()
{
	return ui->lineEditPrice->text().toDouble();
}

double AddBuyOrderDialog::GetNumber()
{
	return ui->lineEditNumber->text().toDouble();
}
