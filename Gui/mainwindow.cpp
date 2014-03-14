#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adduserdialog.h"
#include "addusertransaction.h"
#include "additemdialog.h"
#include "additemstyletransaction.h"
#include "addbuyorderdialog.h"
#include "menudatabase.h"
#include "addordertransaction.h"
#include "querybydatedialog.h"
#include "loadtransaction.h"
#include "savetransaction.h"
#include "countermonthtransaction.h"
#include "counterbymonthandusertransaction.h"

#include <QFileDialog>

using namespace transactions;
using namespace database;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Text"), "", tr("TEXT Files (*.txt)"));
	if (fileName.isEmpty())
	{
		return;
	}

	Transaction *transaction = new LoadTransaction(fileName.toStdString());
	transaction->Execute();
	delete transaction;
}

void MainWindow::on_actionSave_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
		"",
		tr("TEXT (*.txt)"));
	if (fileName.isEmpty())
	{
		return;
	}

	Transaction *transaction = new SaveTransaction(fileName.toStdString());
	transaction->Execute();
	delete transaction;
}

void MainWindow::on_actionExit_triggered()
{
	close();
}

void MainWindow::on_actionAddUser_triggered()
{
	AddUserDialog *dlg = new AddUserDialog();
	if (dlg->exec() == QDialog::Accepted)
	{
		QString name = dlg->GetUserName();
		Transaction *t = new AddUserTransaction(name.toStdString());
		t->Execute();
		delete t;
	}
}

void MainWindow::on_actionAddItem_triggered()
{
	AddItemDialog *dlg = new AddItemDialog();
	if (dlg->exec() == QDialog::Accepted)
	{
		QString name = dlg->GetItemName();
		Transaction *t = new AddItemClassificationTransaction(name.toStdString());
		t->Execute();
		delete t;
	}
}

void MainWindow::on_actionAddOrder_triggered()
{
	AddBuyOrderDialog *dlg = new AddBuyOrderDialog();
	dlg->SetItems(g_mDatabase.GetItems());
	dlg->SetUsers(g_mDatabase.GetUsers());
	if (dlg->exec() == QDialog::Accepted)
	{
		QString itemname = dlg->GetItemName();
		QString username = dlg->GetUser();

		double dfPrice = dlg->GetPrice();
		double dfNumber = dlg->GetNumber();
		Transaction *t = new AddOrderTransaction(
			g_mDatabase.GetItemID(itemname.toStdString()),
			g_mDatabase.GetUserID(username.toStdString()),
			dfPrice, dfNumber, dlg->GetOrderDate());
		t->Execute();
		delete t;
	}
}

void MainWindow::on_actionQueryByDate_triggered()
{
	QueryByDateDialog *dlg = new QueryByDateDialog();
	dlg->exec();
}

void MainWindow::on_actionQueryByNameAndDate_triggered()
{

}

void MainWindow::on_actionCounterByMonth()
{
	QDate date;
	CounterTransaction *t = new CounterMonthTransaction(date);
	t->Execute();
	double fSum = t->GetCount();
	delete t;
}

void MainWindow::on_actionCounterByNameAndDate_triggered()
{

}
