#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include "adduserdialog.h"

AddUserDialog::AddUserDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

AddUserDialog::~AddUserDialog()
{
}

QString AddUserDialog::GetUserName()
{
	return lineEditUserName->text();
}

void AddUserDialog::setupUi( QDialog *AddUserDialog )
{
	if (AddUserDialog->objectName().isEmpty())
		AddUserDialog->setObjectName(QString::fromUtf8("AddUserDialog"));
	AddUserDialog->resize(400, 300);
	buttonBox = new QDialogButtonBox(AddUserDialog);
	buttonBox->setGeometry(QRect(30, 240, 341, 32));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	labelUserName = new QLabel(AddUserDialog);
	labelUserName->setGeometry(QRect(70, 110, 54, 12));
	lineEditUserName = new QLineEdit(AddUserDialog);
	lineEditUserName->setGeometry(QRect(130, 110, 113, 20));

	retranslateUi(AddUserDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), AddUserDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), AddUserDialog, SLOT(reject()));
}

void AddUserDialog::retranslateUi( QDialog *AddUserDialog )
{
	AddUserDialog->setWindowTitle(QApplication::translate("AddUserDialog", "\346\267\273\345\212\240\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
	labelUserName->setText(QApplication::translate("AddUserDialog", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
}
