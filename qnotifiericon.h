#ifndef __QNOTIFIERICON_H__
#define __QNOTIFIERICON_H__

#include <QSystemTrayIcon>

class QNotifierIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    QNotifierIcon();

signals:

public slots:
    void OnDeviceConnected();
    void OnDeviceDisconnected();
};

#endif
