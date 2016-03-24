#ifndef __QNOTIFIERICON_H__
#define __QNOTIFIERICON_H__

#include <QSystemTrayIcon>

class QNotifierApplication;

class QNotifierIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    QNotifierIcon();

signals:
private slots:
    void OnActionTriggered();

public slots:
    void OnDeviceConnected();
    void OnDeviceDisconnected();
};

#endif
