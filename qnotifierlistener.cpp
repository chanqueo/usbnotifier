#include "qnotifierlistener.h"

QNotifierListener::QNotifierListener() : QMainWindow()
{
}

bool QNotifierListener::Start(GUID guid)
{
    DEV_BROADCAST_DEVICEINTERFACE notificationFilter;

    memset(&notificationFilter, 0, sizeof(DEV_BROADCAST_DEVICEINTERFACE));
    notificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    notificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    notificationFilter.dbcc_classguid = guid;

    HDEVNOTIFY devNotify =
            RegisterDeviceNotification((HANDLE)this->winId(),
                                       &notificationFilter,
                                       DEVICE_NOTIFY_WINDOW_HANDLE);

    return devNotify != NULL;
}

bool QNotifierListener::nativeEvent(const QByteArray & eventType,
                                    void * message,
                                    long * result)
{
    Q_UNUSED(result);
    Q_UNUSED(eventType);

    MSG * msg = reinterpret_cast<MSG *>(message);
    DEV_BROADCAST_PORT * port = reinterpret_cast<DEV_BROADCAST_PORT *>(msg->lParam);

    // Does this specific message interest us?
    if(msg->message == WM_DEVICECHANGE)
    {
        switch(msg->wParam)
        {
        case DBT_DEVICEARRIVAL:
#ifdef UNICODE
            emit this->DeviceConnected(QString::fromStdWString(port->dbcp_name));
#else
            emit this->DeviceConnected(QString::fromStdString(port->dbcp_name));
#endif
            break;

        case DBT_DEVICEREMOVECOMPLETE:
#ifdef UNICODE
            emit this->DeviceDisconnected(QString::fromStdWString(port->dbcp_name));
#else
            emit this->DeviceDisconnected(QString::fromStdString(port->dbcp_name));
#endif
            break;
        }
    }

    // Qt handles the rest
    return false;
}
