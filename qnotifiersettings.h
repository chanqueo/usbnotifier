#ifndef QNOTIFIERSETTINGS_H
#define QNOTIFIERSETTINGS_H

#include <QDialog>

#include <windows.h>
#include <dbt.h>

class QLineEdit;
class QDialogButtonBox;

class QNotifierSettings : public QDialog
{
    Q_OBJECT

private:
    QLineEdit * guidLineEdit;
    QDialogButtonBox * buttonBox;
    QString guid;

public:
    const QString Filename = tr(":/settings.ini");
    const QString DefaultGUID = tr("{4d36e967-e325-11ce-bfc108002be10318}");

public:
    explicit QNotifierSettings(QWidget *parent = 0);
    ~QNotifierSettings();
    void Load();
    void Save();
    GUID GetGUID();

signals:
    void NewGUID(GUID guid);

private slots:
    void OkButtonClicked();
    void CancelButtonClicked();
};

#endif // QNOTIFIERSETTINGS_H
