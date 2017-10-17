/********************************************************************************
** Form generated from reading UI file 'qnotifiersettings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNOTIFIERSETTINGS_H
#define UI_QNOTIFIERSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_QNotifierSettings
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *guidLineEdit;
    QLabel *guidLabel;

    void setupUi(QDialog *QNotifierSettings)
    {
        if (QNotifierSettings->objectName().isEmpty())
            QNotifierSettings->setObjectName(QStringLiteral("QNotifierSettings"));
        QNotifierSettings->resize(420, 100);
        buttonBox = new QDialogButtonBox(QNotifierSettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 50, 381, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        guidLineEdit = new QLineEdit(QNotifierSettings);
        guidLineEdit->setObjectName(QStringLiteral("guidLineEdit"));
        guidLineEdit->setGeometry(QRect(60, 20, 341, 20));
        guidLabel = new QLabel(QNotifierSettings);
        guidLabel->setObjectName(QStringLiteral("guidLabel"));
        guidLabel->setGeometry(QRect(20, 20, 46, 13));

        retranslateUi(QNotifierSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), QNotifierSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QNotifierSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(QNotifierSettings);
    } // setupUi

    void retranslateUi(QDialog *QNotifierSettings)
    {
        QNotifierSettings->setWindowTitle(QApplication::translate("QNotifierSettings", "Dialog", 0));
        guidLabel->setText(QApplication::translate("QNotifierSettings", "GUID", 0));
    } // retranslateUi

};

namespace Ui {
    class QNotifierSettings: public Ui_QNotifierSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNOTIFIERSETTINGS_H
