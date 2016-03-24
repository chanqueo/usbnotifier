#ifndef __QNOTIFIERAPPLICATION_H__
#define __QNOTIFIERAPPLICATION_H__

#include <QApplication>

class QNotifierIcon;
class QNotifierListener;

class QNotifierApplication : public QApplication
{
    Q_OBJECT

private:
    QNotifierIcon * icon;
    QNotifierListener * listener;

public:
    QNotifierApplication(int argc, char ** argv);
    virtual ~QNotifierApplication();

signals:

public slots:

};

#endif
