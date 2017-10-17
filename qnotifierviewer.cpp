#include "qnotifierviewer.h"
#include "qnotifiersettings.h"

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

QNotifierViewer::QNotifierViewer(QNotifierSettings * settings)
{
    this->settings = settings;
    this->icon = new QSystemTrayIcon();

    QAction * quitAction = new QAction("&Quit", NULL);
    QAction * settingsAction = new QAction("&Settings", NULL);
    QMenu * menu = new QMenu();

    connect(quitAction, SIGNAL(triggered()), this, SLOT(OnQuitActionTriggered()));
    connect(settingsAction, SIGNAL(triggered()), this, SLOT(OnSettingsActionTriggered()));

    menu->addAction(quitAction);
    menu->addAction(settingsAction);

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

void QNotifierViewer::OnQuitActionTriggered()
{
    QApplication::quit();
}

void QNotifierViewer::OnSettingsActionTriggered()
{
    this->settings->show();
}

void QNotifierViewer::OnDeviceConnected(QString name)
{
    this->icon->showMessage("", name + " is connected");
}

void QNotifierViewer::OnDeviceDisconnected(QString name)
{
    this->icon->showMessage("", name + " is disconnected");
}
