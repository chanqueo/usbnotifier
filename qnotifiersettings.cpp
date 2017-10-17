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
}

QNotifierSettings::~QNotifierSettings()
{
}

void QNotifierSettings::Load()
{
    QString filename = QApplication::applicationDirPath().left(1) + QNotifierSettings::Filename;
    QSettings settings(filename, QSettings::NativeFormat);
    this->guid = settings.value("guid", this->DefaultGUID).toString();
    this->guidLineEdit->setPlaceholderText(this->guid);
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

    if (this->guid != this->guidLineEdit->placeholderText()) {
        this->guid = this->guidLineEdit->placeholderText();

        if (TextToGUID(this->guid, &guid)) {
            this->accept();
            emit this->NewGUID(guid);
        }
    }
}

void QNotifierSettings::CancelButtonClicked()
{

}
