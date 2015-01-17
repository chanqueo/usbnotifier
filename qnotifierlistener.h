#ifndef __QNOTIFIERLISTENER_H__
#define __QNOTIFIERLISTENER_H__

#include <QMainWindow>

class QNotifierListener : public QMainWindow
{
    Q_OBJECT
public:
    QNotifierListener();
    bool start();

signals:
    void DeviceConnected();
    void DeviceDisconnected();

public slots:

protected:
    virtual bool nativeEvent(const QByteArray & eventType,
                             void * message,
                             long * result);
};

#endif
