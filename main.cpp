/**
 * Main file.
 */

#include <QApplication>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

/**
 * Application entry point.
 * @param  argc  Number of arguments.
 * @param  argv  Address of arguments.
 */
int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QSystemTrayIcon icon;
    QMenu menu;
    QAction action("&Quit");

    connect(action, SIGNAL(triggered()), qApp, SLOT(quit()));
    menu.addAction(action);

    icon.setContextMenu(menu);
    icon.setIcon(QIcon icon("bullet-connect-icon.png"));
    icon.show();

    return  app.exec();
 }
