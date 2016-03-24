#ifndef __QNOTIFIERAPPLICATION_H__
#define __QNOTIFIERAPPLICATION_H__

#include <QApplication>

class QNotifierViewer;
class QNotifierListener;

class QNotifierApplication : public QApplication
{
    Q_OBJECT

private:
    QNotifierViewer * viewer;
    QNotifierListener * listener;

public:
    QNotifierApplication(int argc, char ** argv);
    virtual ~QNotifierApplication();

signals:

public slots:

};

#endif
