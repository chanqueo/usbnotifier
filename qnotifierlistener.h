#ifndef __QNOTIFIERLISTENER_H__
#define __QNOTIFIERLISTENER_H__

#include <QMainWindow>

class QNotifierListener : public QMainWindow
{
    Q_OBJECT

public:
    QNotifierListener();
    bool Start();

signals:
    void DeviceConnected(QString name);
    void DeviceDisconnected(QString name);

public slots:

protected:
    virtual bool nativeEvent(const QByteArray & eventType,
                             void * message,
                             long * result);
};

#endif
