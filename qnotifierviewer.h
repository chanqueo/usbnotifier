#ifndef __QNOTIFIERVIEWER_H__
#define __QNOTIFIERVIEWER_H__

#include <QObject>

class QNotifierSettings;
class QSystemTrayIcon;

class QNotifierViewer : public QObject
{
    Q_OBJECT

private:
    QNotifierSettings * settings;
    QSystemTrayIcon * icon;

public:
    QNotifierViewer(QNotifierSettings * settings);
    virtual ~QNotifierViewer();
    void Show();

private slots:
    void OnQuitActionTriggered();
    void OnSettingsActionTriggered();

public slots:
    void OnDeviceConnected(QString name);
    void OnDeviceDisconnected(QString name);
};

#endif
