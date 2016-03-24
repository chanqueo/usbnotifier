#ifndef __QNOTIFIERVIEWER_H__
#define __QNOTIFIERVIEWER_H__

#include <QObject>

class QNotifierApplication;
class QSystemTrayIcon;

class QNotifierViewer : public QObject
{
    Q_OBJECT

private:
    QSystemTrayIcon * icon;

public:
    QNotifierViewer();
    virtual ~QNotifierViewer();
    void Show();

private slots:
    void OnActionTriggered();

public slots:
    void OnDeviceConnected();
    void OnDeviceDisconnected();
};

#endif
