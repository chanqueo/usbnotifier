#include "qnotifiersettings.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSettings>
#include <QVBoxLayout>

QNotifierSettings::QNotifierSettings(QWidget * parent) : QDialog(parent)
{
    QVBoxLayout * layout = new QVBoxLayout();

    QGroupBox * groupBox = new QGroupBox();
    QFormLayout * formLayout = new QFormLayout();
    this->guidLineEdit = new QLineEdit();
    formLayout->addRow(new QLabel(tr("GUID:")), this->guidLineEdit);
    groupBox->setLayout(formLayout);

    this->buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(this->buttonBox, SIGNAL(accepted()), this, SLOT(OkButtonClicked()));
    connect(this->buttonBox, SIGNAL(rejected()), this, SLOT(CancelButtonClicked()));

    layout->addWidget(groupBox);
    layout->addWidget(this->buttonBox);

    this->setLayout(layout);
    this->setWindowTitle(tr("Settings"));
}

QNotifierSettings::~QNotifierSettings()
{
}

void QNotifierSettings::Load()
{
    QString filename = QApplication::applicationDirPath().left(1) + QNotifierSettings::Filename;
    QSettings settings(filename, QSettings::NativeFormat);
    this->guid = settings.value("guid", this->DefaultGUID).toString();
    this->guidLineEdit->setText(this->guid);
}

bool TextToGUID(QString text, GUID * guid)
{
    bool ok;

    //QRegExp sep("^\\{?([a-fA-F\\d]+)-([a-fA-F\\d]+)-([a-fA-F\\d]+)-([a-fA-F\\d]+)\\}?$");
    QRegExp sep("([a-fA-F0-9]+)-([a-fA-F0-9]+)-([a-fA-F0-9]+)-([a-fA-F0-9]+)");
    //QStringList list = text.split(sep);
    sep.indexIn(text);
    QStringList list = sep.capturedTexts();
    if (list.size() == 5) {
        guid->Data1 = list.at(1).toULong(&ok, 16);
        if (!ok)
            return false;
        guid->Data2 = list.at(2).toUShort(&ok, 16);
        if (!ok)
            return false;
        guid->Data3 = list.at(3).toUShort(&ok, 16);
        if (!ok)
            return false;
        unsigned long long data4 = list.at(4).toULongLong(&ok, 16);
        if (!ok)
            return false;
        memcpy(guid->Data4, &data4, 8);
        return true;
    } else
        return false;
}

void QNotifierSettings::Save()
{
    QString filename = QApplication::applicationDirPath().left(1) + QNotifierSettings::Filename;
    QSettings settings(filename, QSettings::NativeFormat);
    settings.setValue("guid", this->guid);
}

GUID QNotifierSettings::GetGUID()
{
    GUID guid;
    TextToGUID(this->guid, &guid);
    return guid;
}

void QNotifierSettings::OkButtonClicked()
{
    GUID guid;

    if (TextToGUID(this->guidLineEdit->text(), &guid)) {
        if (this->guid != this->guidLineEdit->text()) {
            this->guid = this->guidLineEdit->text();
            emit this->NewGUID(guid);
            this->Save();
        }
        this->accept();
    }
}

void QNotifierSettings::CancelButtonClicked()
{
    this->reject();
}
