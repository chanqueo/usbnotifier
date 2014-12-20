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
int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    QSystemTrayIcon sysTrayIcon;
    QMenu menu;
    QAction action("&Quit", NULL);

    QObject::connect(&action, &QAction::triggered, &app, &QApplication::quit);
    menu.addAction(&action);

    QIcon icon("bullet-connect-icon.png");

    sysTrayIcon.setContextMenu(&menu);
    sysTrayIcon.setIcon(icon);
    sysTrayIcon.show();

    return  app.exec();
 }
