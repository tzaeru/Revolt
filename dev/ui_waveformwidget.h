/********************************************************************************
** Form generated from reading UI file 'waveformwidget.ui'
**
** Created: Fri Mar 4 01:33:50 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORMWIDGET_H
#define UI_WAVEFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveformWidget
{
public:

    void setupUi(QWidget *WaveformWidget)
    {
        if (WaveformWidget->objectName().isEmpty())
            WaveformWidget->setObjectName(QString::fromUtf8("WaveformWidget"));
        WaveformWidget->resize(188, 137);

        retranslateUi(WaveformWidget);

        QMetaObject::connectSlotsByName(WaveformWidget);
    } // setupUi

    void retranslateUi(QWidget *WaveformWidget)
    {
        WaveformWidget->setWindowTitle(QApplication::translate("WaveformWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WaveformWidget: public Ui_WaveformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORMWIDGET_H
