#ifndef __QNOTIFIERLISTENER_H__
#define __QNOTIFIERLISTENER_H__

#include <windows.h>
#include <dbt.h>

#include <QMainWindow>

class QNotifierListener : public QMainWindow
{
    Q_OBJECT

public:
    QNotifierListener();
    bool Start(GUID guid);

signals:
    void DeviceConnected(QString name);
    void DeviceDisconnected(QString name);

protected:
    virtual bool nativeEvent(const QByteArray & eventType,
                             void * message,
                             long * result);
};

#endif
