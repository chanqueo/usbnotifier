#ifndef __QNOTIFIERAPPLICATION_H__
#define __QNOTIFIERAPPLICATION_H__

#include <QApplication>

class QNotifierListener;
class QNotifierSettings;
class QNotifierViewer;

class QNotifierApplication : public QApplication
{
    Q_OBJECT

private:
    QNotifierListener * listener;
    QNotifierSettings * settings;
    QNotifierViewer * viewer;

private:
    void LoadSettings();
    void SaveSettings();

public:
    QNotifierApplication(int argc, char ** argv);
    virtual ~QNotifierApplication();
};

#endif
