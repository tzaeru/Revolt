/********************************************************************************
** Form generated from reading UI file 'synthwidget.ui'
**
** Created: Mon Feb 21 05:48:08 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNTHWIDGET_H
#define UI_SYNTHWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include <waveformwidget.h>

QT_BEGIN_NAMESPACE

class Ui_SynthWidget
{
public:
    QDial *dial;
    QLabel *label;
    WaveformWidget *widget;
    QLabel *label_2;
    QScrollBar *verticalScrollBar;
    QGroupBox *groupBox;
    QDial *dial_2;
    QLabel *label_3;
    QDial *dial_3;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_4;
    QSlider *verticalSlider;
    QLabel *label_5;

    void setupUi(QWidget *SynthWidget)
    {
        if (SynthWidget->objectName().isEmpty())
            SynthWidget->setObjectName(QString::fromUtf8("SynthWidget"));
        SynthWidget->resize(591, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SynthWidget->sizePolicy().hasHeightForWidth());
        SynthWidget->setSizePolicy(sizePolicy);
        SynthWidget->setAutoFillBackground(true);
        dial = new QDial(SynthWidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(0, 80, 171, 111));
        dial->setMaximum(1200);
        dial->setValue(220);
        label = new QLabel(SynthWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 71, 17));
        widget = new WaveformWidget(SynthWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(400, 110, 120, 80));
        widget->setAutoFillBackground(true);
        label_2 = new QLabel(SynthWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 90, 131, 17));
        verticalScrollBar = new QScrollBar(SynthWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(370, 100, 20, 91));
        verticalScrollBar->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(SynthWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 80, 161, 111));
        groupBox->setAutoFillBackground(true);
        dial_2 = new QDial(groupBox);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setGeometry(QRect(0, 80, 41, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 60, 67, 17));
        dial_3 = new QDial(groupBox);
        dial_3->setObjectName(QString::fromUtf8("dial_3"));
        dial_3->setGeometry(QRect(100, 80, 31, 31));
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(70, 0, 20, 111));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 20, 161, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 60, 67, 17));
        verticalSlider = new QSlider(SynthWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(550, 40, 29, 160));
        verticalSlider->setMaximum(32767);
        verticalSlider->setValue(4095);
        verticalSlider->setOrientation(Qt::Vertical);
        label_5 = new QLabel(SynthWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(540, 20, 67, 17));

        retranslateUi(SynthWidget);

        QMetaObject::connectSlotsByName(SynthWidget);
    } // setupUi

    void retranslateUi(QWidget *SynthWidget)
    {
        SynthWidget->setWindowTitle(QApplication::translate("SynthWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SynthWidget", "Frequency", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SynthWidget", "Waveform: Sine", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SynthWidget", "LFO", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SynthWidget", "Amount", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SynthWidget", "Velocity", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SynthWidget", "Volume", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SynthWidget: public Ui_SynthWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNTHWIDGET_H
