#ifndef QNOTIFIERSETTINGS_H
#define QNOTIFIERSETTINGS_H

#include <QDialog>
#include <windows.h>
#include <dbt.h>

namespace Ui {
class QNotifierSettings;
}

class QNotifierSettings : public QDialog
{
    Q_OBJECT

private:
    Ui::QNotifierSettings * ui;
    QString guid;

public:
    const QString Filename = ":/settings.ini";
    const QString DefaultGUID = "{4d36e967-e325-11ce-bfc108002be10318}";

public:
    explicit QNotifierSettings(QWidget *parent = 0);
    ~QNotifierSettings();
    void Load();
    void Save();
    GUID GetGUID();

signals:
    void NewGUID(GUID guid);
};

#endif // QNOTIFIERSETTINGS_H
