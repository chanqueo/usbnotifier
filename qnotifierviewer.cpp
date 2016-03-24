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
    this->icon->setIcon(QIcon("usb.ico"));
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

void QNotifierViewer::OnDeviceConnected()
{
    this->icon->showMessage("Hello", "Device connected");
}

void QNotifierViewer::OnDeviceDisconnected()
{
    this->icon->showMessage("Hello", "Device disconnected");
}
