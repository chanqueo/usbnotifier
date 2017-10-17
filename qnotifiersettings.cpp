#include "qnotifiersettings.h"
#include "ui_qnotifiersettings.h"

#include <QSettings>

QNotifierSettings::QNotifierSettings(QWidget *parent) : QDialog(parent), ui(new Ui::QNotifierSettings)
{
    ui->setupUi(this);
}

QNotifierSettings::~QNotifierSettings()
{
    delete ui;
}

void QNotifierSettings::Load()
{
    QString filename = QApplication::applicationDirPath().left(1) + QNotifierSettings::Filename;
    QSettings settings(filename, QSettings::NativeFormat);
    this->guid = settings.value("guid", this->DefaultGUID).toString();
    this->ui->guidLineEdit->setPlaceholderText(this->guid);
}

bool TextToGUID(QString text, GUID * guid)
{
    QRegExp sep("[{-}]");
    QStringList list = text.split(sep, QString::SkipEmptyParts);
    if (list.size() == 4) {
        guid->Data1 = list.at(0).toULong(NULL, 16);
        guid->Data2 = list.at(1).toUShort(NULL, 16);
        guid->Data3 = list.at(2).toUShort(NULL, 16);
        unsigned long long data4 = list.at(3).toULongLong(NULL, 16);
        memcpy(guid->Data4, &data4, 8);
        return true;
    } else
        return false;
}

void QNotifierSettings::Save()
{
    GUID guid;
    QString filename = QApplication::applicationDirPath().left(1) + QNotifierSettings::Filename;
    QSettings settings(filename, QSettings::NativeFormat);

    if (this->guid != this->ui->guidLineEdit->placeholderText()) {
        this->guid = this->ui->guidLineEdit->placeholderText();
        settings.setValue("guid", this->guid);
        if (TextToGUID(this->guid, &guid))
            emit this->NewGUID(guid);
    }
}

GUID QNotifierSettings::GetGUID()
{
    return TextToGUID(this->guid);
}
