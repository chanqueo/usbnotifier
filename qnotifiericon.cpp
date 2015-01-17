#include "qnotifiericon.h"

#include <QAction>
#include <QApplication>
#include <QMenu>

QNotifierIcon::QNotifierIcon() : QSystemTrayIcon()
{
    QAction * action = new QAction("&Quit", NULL);
    QMenu * menu = new QMenu();

    QObject::connect(action, &QAction::triggered, this, &QApplication::quit);

    menu->addAction(action);

    this->setContextMenu(menu);
    this->setIcon(QIcon("usb.ico"));
}

void QNotifierIcon::OnDeviceConnected()
{
    this->showMessage("Hello", "Device connected");
}

void QNotifierIcon::OnDeviceDisconnected()
{
    this->showMessage("Hello", "Device disconnected");
}
