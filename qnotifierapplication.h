#ifndef __QNOTIFIERAPPLICATION_H__
#define __QNOTIFIERAPPLICATION_H__

#include <QApplication>
#include "qnotifiericon.h"
#include "qnotifierlistener.h"

class QNotifierApplication : public QApplication
{
private:
    Q_OBJECT
    QNotifierIcon * icon;
    QNotifierListener * listener;

public:
    QNotifierApplication(int argc, char ** argv);
    virtual ~QNotifierApplication();

signals:

public slots:

};

#endif
