/**
 * Main file.
 */

#include <QApplication>
#include <QMainWindow>

/**
 * Application entry point.
 * @param  argc  Number of arguments.
 * @param  argv  Address of arguments.
 */
int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;

    mainWindow.show();

    return  app.exec();
 }
