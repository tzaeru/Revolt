/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 4 01:33:50 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <mixerwidget.h>
#include <synthwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Synth;
    QWidget *centralwidget;
    MixerWidget *widget;
    SynthWidget *widget_2;
    SynthWidget *widget_3;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuRevoltophile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 698);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow#MainWindow { background-color: qradialgradient(spread:reflect, cx:0.576, cy:0.386364, radius:0.329, fx:0.467, fy:0.681409, stop:0 rgba(214, 214, 214, 255), stop:0.461905 rgba(227, 227, 227, 255)) }"));
        actionAdd_Synth = new QAction(MainWindow);
        actionAdd_Synth->setObjectName(QString::fromUtf8("actionAdd_Synth"));
        actionAdd_Synth->setCheckable(true);
        actionAdd_Synth->setMenuRole(QAction::TextHeuristicRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new MixerWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 591, 200));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(591, 0));
        widget->setMaximumSize(QSize(16777215, 200));
        widget->setAutoFillBackground(true);
        widget_2 = new SynthWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 220, 591, 200));
        widget_2->setAutoFillBackground(true);
        widget_3 = new SynthWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 430, 591, 200));
        widget_3->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 25));
        QPalette palette;
        menuBar->setPalette(palette);
        menuBar->setAutoFillBackground(false);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menuRevoltophile = new QMenu(menuBar);
        menuRevoltophile->setObjectName(QString::fromUtf8("menuRevoltophile"));
        QPalette palette1;
        QBrush brush(QColor(128, 128, 128, 255));
        brush.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        menuRevoltophile->setPalette(palette1);
        menuRevoltophile->setAutoFillBackground(true);
        menuRevoltophile->setStyleSheet(QString::fromUtf8("color : grey;"));
        menuRevoltophile->setTearOffEnabled(true);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuRevoltophile->menuAction());
        menuRevoltophile->addAction(actionAdd_Synth);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Revoltophile", 0, QApplication::UnicodeUTF8));
        actionAdd_Synth->setText(QApplication::translate("MainWindow", "Add Synth", 0, QApplication::UnicodeUTF8));
        menuRevoltophile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
