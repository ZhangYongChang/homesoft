#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include "additemdialog.h"

AddItemDialog::AddItemDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

AddItemDialog::~AddItemDialog()
{
}

QString AddItemDialog::GetItemName()
{
	return lineEditItemName->text();

}

void AddItemDialog::setupUi( QDialog *AddItemDialog )
{
	if (AddItemDialog->objectName().isEmpty())
		AddItemDialog->setObjectName(QString::fromUtf8("AddItemDialog"));
	AddItemDialog->resize(400, 300);
	buttonBox = new QDialogButtonBox(AddItemDialog);
	buttonBox->setGeometry(QRect(30, 240, 341, 32));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	lineEditItemName = new QLineEdit(AddItemDialog);
	lineEditItemName->setGeometry(QRect(170, 80, 113, 20));
	labelItemStyle = new QLabel(AddItemDialog);
	labelItemStyle->setGeometry(QRect(100, 80, 54, 12));

	retranslateUi(AddItemDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), AddItemDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), AddItemDialog, SLOT(reject()));
}

void AddItemDialog::retranslateUi( QDialog *AddItemDialog )
{
	AddItemDialog->setWindowTitle(QApplication::translate("AddItemDialog", "\346\267\273\345\212\240\345\225\206\345\223\201", 0, QApplication::UnicodeUTF8));
	labelItemStyle->setText(QApplication::translate("AddItemDialog", "\345\225\206\345\223\201\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
}
