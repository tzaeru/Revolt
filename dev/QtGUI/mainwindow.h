#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "mixerwidget.h"

#include "wrapper.hpp"

#include "synthwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    PresetData preset_data;

    Wrapper wrapper;
    Mixer *mixer;

    Synth *synth;

    SoundHardware *sound_hardware;

    std::vector<SynthWidget > synth_widgets;

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionAdd_Synth_triggered();
};

#endif // MAINWINDOW_H
