#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QFileDialog>

#include "mainwindow.h"
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
#include "counterbymonthanduserdialog.h"
#include "querybynameanddatedialog.h"
#include "countermonthdialog.h"

using namespace transactions;
using namespace database;

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent)
{
	setupUi(this);
}

void MainWindow::setupUi( QMainWindow *MainWindow )
{
	if (MainWindow->objectName().isEmpty())
		MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
	MainWindow->resize(400, 300);

	CreateMenu(MainWindow);

	MainWindow->setMenuBar(menuBar);
	fileToolBar = new QToolBar(MainWindow);
	addInfoToolBar = new QToolBar(MainWindow);
	counterToolBar = new QToolBar(MainWindow);
	queryToolBar = new QToolBar(MainWindow);
	helpToolBar = new QToolBar(MainWindow);

	MainWindow->addToolBar(Qt::TopToolBarArea, fileToolBar);
	MainWindow->addToolBar(addInfoToolBar);
	MainWindow->addToolBar(queryToolBar);
	MainWindow->addToolBar(counterToolBar);
	MainWindow->addToolBar(helpToolBar);

	statusBar = new QStatusBar(MainWindow);
	MainWindow->setStatusBar(statusBar);	

	retranslateUi(MainWindow);
	ActionRelation(MainWindow);
	CreateToolBar(MainWindow);
}

void MainWindow::CreateToolBar( QMainWindow *MainWindow )
{
	this->fileToolBar->addAction(actionLoad);
	this->fileToolBar->addAction(actionSave);
	this->fileToolBar->addAction(actionExit);

	this->addInfoToolBar->addAction(actionAddUser);
	this->addInfoToolBar->addAction(actionAddItem);
	this->addInfoToolBar->addAction(actionAddOrder);

	this->queryToolBar->addAction(actionQueryByDate);
	this->queryToolBar->addAction(actionQueryByNameAndDate);

	this->counterToolBar->addAction(actionCounterByDate);
	this->counterToolBar->addAction(actionCounterByNameAndDate);

	this->helpToolBar->addAction(actionAbout);
}

void MainWindow::CreateMenu( QMainWindow * MainWindow )
{
	actionLoad = new QAction(QIcon(":/images/open.png"), tr("&Open..."), MainWindow);
	actionSave = new QAction(QIcon(":/images/save.png"), tr("&Save..."), MainWindow);
	actionExit = new QAction(QIcon(":/images/exit.png"), tr("&Exit..."), MainWindow);

	actionAddUser = new QAction(QIcon(":/images/adduser.png"), tr("&Add User..."), MainWindow);
	actionAddItem = new QAction(QIcon(":/images/additem.png"), tr("&Add Item..."), MainWindow);
	actionAddOrder = new QAction(QIcon(":/images/addorder.png"), tr("&Add Order..."), MainWindow);

	actionQueryByDate = new QAction(QIcon(":/images/querybydate.png"), tr("&Add User..."), MainWindow);
	actionQueryByNameAndDate = new QAction(QIcon(":/images/querybyname.png"), tr("&Add User..."), MainWindow);
	
	actionCounterByDate = new QAction(QIcon(":/images/countbydate.png"), tr("&CountByDate..."), MainWindow);
	actionCounterByNameAndDate = new QAction(QIcon(":/images/countbyname.png"), tr("&CountByName..."), MainWindow);

	actionAbout = new QAction(QIcon(":/images/help.png"), tr("&Help..."), MainWindow);

	centralWidget = new QWidget(MainWindow);
	MainWindow->setCentralWidget(centralWidget);
	menuBar = new QMenuBar(MainWindow);
	menuBar->setGeometry(QRect(0, 0, 400, 21));
	menuFile = new QMenu(menuBar);
	menuAdd = new QMenu(menuBar);
	menuQuery = new QMenu(menuBar);
	menuCounter = new QMenu(menuBar);
	menuHelp = new QMenu(menuBar);

	menuBar->addAction(menuFile->menuAction());
	menuBar->addAction(menuAdd->menuAction());
	menuBar->addAction(menuQuery->menuAction());
	menuBar->addAction(menuCounter->menuAction());
	menuBar->addAction(menuHelp->menuAction());
	menuFile->addAction(actionLoad);
	menuFile->addAction(actionSave);
	menuFile->addAction(actionExit);
	menuAdd->addAction(actionAddUser);
	menuAdd->addAction(actionAddItem);
	menuAdd->addAction(actionAddOrder);
	menuQuery->addAction(actionQueryByDate);
	menuQuery->addAction(actionQueryByNameAndDate);
	menuCounter->addAction(actionCounterByDate);
	menuCounter->addAction(actionCounterByNameAndDate);
	menuHelp->addAction(actionAbout);
}

void MainWindow::retranslateUi( QMainWindow *MainWindow )
{
	MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\264\255\350\217\234\347\256\241\347\220\206\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
	actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
	actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
	actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
	actionAddUser->setText(QApplication::translate("MainWindow", "AddUser", 0, QApplication::UnicodeUTF8));
	actionAddItem->setText(QApplication::translate("MainWindow", "AddItem", 0, QApplication::UnicodeUTF8));
	actionAddOrder->setText(QApplication::translate("MainWindow", "AddOrder", 0, QApplication::UnicodeUTF8));
	actionQueryByDate->setText(QApplication::translate("MainWindow", "QueryByDate", 0, QApplication::UnicodeUTF8));
	actionQueryByNameAndDate->setText(QApplication::translate("MainWindow", "QueryByNameAndDate", 0, QApplication::UnicodeUTF8));
	actionCounterByDate->setText(QApplication::translate("MainWindow", "CounterByDate", 0, QApplication::UnicodeUTF8));
	actionCounterByNameAndDate->setText(QApplication::translate("MainWindow", "CounterByNameAndDate", 0, QApplication::UnicodeUTF8));
	actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
	menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
	menuAdd->setTitle(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
	menuQuery->setTitle(QApplication::translate("MainWindow", "Query", 0, QApplication::UnicodeUTF8));
	menuCounter->setTitle(QApplication::translate("MainWindow", "Counter", 0, QApplication::UnicodeUTF8));
	menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
}

void MainWindow::ActionRelation( QMainWindow * MainWindow )
{
	connect(actionLoad, SIGNAL(triggered()), MainWindow, SLOT(onActionLoad()));
	connect(actionSave, SIGNAL(triggered()), MainWindow, SLOT(onActionSave()));
	connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(onActionExit()));
	connect(actionAddUser, SIGNAL(triggered()), MainWindow, SLOT(onActionAddUser()));
	connect(actionAddItem, SIGNAL(triggered()), MainWindow, SLOT(onActionAddItem()));
	connect(actionAddOrder, SIGNAL(triggered()), MainWindow, SLOT(onActionAddOrder()));
	connect(actionQueryByDate, SIGNAL(triggered()), MainWindow, SLOT(onActionQueryByDate()));
	connect(actionQueryByNameAndDate, SIGNAL(triggered()), MainWindow, SLOT(onActionQueryByNameAndDate()));
	connect(actionCounterByDate, SIGNAL(triggered()), MainWindow, SLOT(onActionCounterByMonth()));
	connect(actionCounterByNameAndDate, SIGNAL(triggered()), MainWindow, SLOT(onActionCounterByNameAndDate()));
	connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(onActionAbout()));
}

void MainWindow::onActionAbout()
{

}

MainWindow::~MainWindow()
{
}

void MainWindow::onActionLoad()
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

void MainWindow::onActionSave()
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

void MainWindow::onActionExit()
{
	close();
}

void MainWindow::onActionAddUser()
{
	AddUserDialog *dlg = new AddUserDialog();
	if (dlg->exec() == QDialog::Accepted)
	{
		QString name = dlg->GetUserName();
		Transaction *t = new AddUserTransaction(name.toStdString());
		t->Execute();
		delete t;
	}
	delete dlg;
}

void MainWindow::onActionAddItem()
{
	AddItemDialog *dlg = new AddItemDialog();
	if (dlg->exec() == QDialog::Accepted)
	{
		QString name = dlg->GetItemName();
		Transaction *t = new AddItemClassificationTransaction(name.toStdString());
		t->Execute();
		delete t;
	}
	delete dlg;
}

void MainWindow::onActionAddOrder()
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
	delete dlg;
}

void MainWindow::onActionQueryByDate()
{
	QueryByDateDialog *dlg = new QueryByDateDialog();
	dlg->exec();
	delete dlg;
}

void MainWindow::onActionQueryByNameAndDate()
{
	QueryByNameAndDateDialog *dlg = new QueryByNameAndDateDialog();
	dlg->exec();
	delete dlg;
}

void MainWindow::onActionCounterByMonth()
{
	CounterMonthDialog *dlg = new CounterMonthDialog();
	dlg->exec();
	delete dlg;
}

void MainWindow::onActionCounterByNameAndDate()
{
	CounterByMonthAndUserDialog *dlg = new CounterByMonthAndUserDialog();
	dlg->exec();
	delete dlg;
}
