#ifndef SYNTHWIDGET_H
#define SYNTHWIDGET_H

#include <QWidget>

#include "synth.hpp"

namespace Ui {
    class SynthWidget;
}

class SynthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SynthWidget(QWidget *parent = 0);
    ~SynthWidget();

    PresetData preset_data;
private:
    Ui::SynthWidget *ui;

    Synth *synth;

private slots:
    void on_verticalSlider_valueChanged(int value);
    void on_dial_valueChanged(int value);
};

#endif // SYNTHWIDGET_H
