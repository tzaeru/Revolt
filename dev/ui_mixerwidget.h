/********************************************************************************
** Form generated from reading UI file 'mixerwidget.ui'
**
** Created: Fri Mar 4 01:33:50 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIXERWIDGET_H
#define UI_MIXERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MixerWidget
{
public:
    QFrame *line;
    QFrame *line_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;

    void setupUi(QWidget *MixerWidget)
    {
        if (MixerWidget->objectName().isEmpty())
            MixerWidget->setObjectName(QString::fromUtf8("MixerWidget"));
        MixerWidget->resize(581, 200);
        MixerWidget->setStyleSheet(QString::fromUtf8("QWidget#MixerWidget { background-color :qlineargradient(spread:pad, x1:0.666, y1:0.0113636, x2:1, y2:0, stop:0 rgba(231, 231, 231, 255), stop:1 rgba(191, 191, 191, 255)) }"));
        line = new QFrame(MixerWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 180, 581, 20));
        line->setLineWidth(5);
        line->setMidLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(MixerWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 0, 581, 20));
        line_2->setLineWidth(5);
        line_2->setMidLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(MixerWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 60, 271, 115));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        verticalSlider = new QSlider(widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 1, 0, 1, 1);

        verticalSlider_2 = new QSlider(widget);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_2, 1, 1, 1, 1);

        verticalSlider_3 = new QSlider(widget);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_3, 1, 2, 1, 1);

        verticalSlider_4 = new QSlider(widget);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_4, 1, 3, 1, 1);


        retranslateUi(MixerWidget);

        QMetaObject::connectSlotsByName(MixerWidget);
    } // setupUi

    void retranslateUi(QWidget *MixerWidget)
    {
        MixerWidget->setWindowTitle(QApplication::translate("MixerWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MixerWidget", "Volume 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MixerWidget", "Volume 2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MixerWidget", "Volume 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MixerWidget", "Volume 4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MixerWidget: public Ui_MixerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIXERWIDGET_H
