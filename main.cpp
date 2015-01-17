/**
 * Main file.
 */

#include "qnotifierapplication.h"

/**
 * Application entry point.
 * @param  argc  Number of arguments.
 * @param  argv  Address of arguments.
 */
int main(int argc, char ** argv)
{
    QNotifierApplication app(argc, argv);

    return  app.exec();
 }
