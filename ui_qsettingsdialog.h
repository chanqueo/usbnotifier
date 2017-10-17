/********************************************************************************
** Form generated from reading UI file 'qsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSETTINGSDIALOG_H
#define UI_QSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_QSettingsDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QSettingsDialog)
    {
        if (QSettingsDialog->objectName().isEmpty())
            QSettingsDialog->setObjectName(QStringLiteral("QSettingsDialog"));
        QSettingsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(QSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(QSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *QSettingsDialog)
    {
        QSettingsDialog->setWindowTitle(QApplication::translate("QSettingsDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class QSettingsDialog: public Ui_QSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSETTINGSDIALOG_H
