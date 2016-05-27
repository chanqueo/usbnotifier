#include "qnotifierviewer.h"

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

QNotifierViewer::QNotifierViewer()
{
    this->icon = new QSystemTrayIcon();

    QAction * action = new QAction("&Quit", NULL);
    QMenu * menu = new QMenu();

    connect(action, SIGNAL(triggered()), this, SLOT(OnActionTriggered()));

    menu->addAction(action);

    this->icon->setContextMenu(menu);
    this->icon->setIcon(QIcon(":/resources/viewer.ico"));
}

QNotifierViewer::~QNotifierViewer()
{
    delete this->icon;
}

void QNotifierViewer::Show()
{
    this->icon->show();
}

void QNotifierViewer::OnActionTriggered()
{
    QApplication::quit();
}

void QNotifierViewer::OnDeviceConnected(QString name)
{
    this->icon->showMessage("", name + " is connected");
}

void QNotifierViewer::OnDeviceDisconnected(QString name)
{
    this->icon->showMessage("", name + " is disconnected");
}
