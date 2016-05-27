#ifndef __QNOTIFIERVIEWER_H__
#define __QNOTIFIERVIEWER_H__

#include <QObject>

#ifndef UNICODE
  typedef std::string String;
#else
  typedef std::wstring String;
#endif

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
    void OnDeviceConnected(QString name);
    void OnDeviceDisconnected(QString name);
};

#endif
