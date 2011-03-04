#ifndef SYNTHWIDGET_H
#define SYNTHWIDGET_H

#include <QWidget>

#include "preset_data.hpp"
#include "lfo.hpp"
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

private:
    Ui::SynthWidget *ui;

    LFO *lfo;
    Synth *synth;

private slots:
    void on_dial_3_valueChanged(int value);
    void on_dial_2_valueChanged(int value);
    void on_verticalSlider_valueChanged(int value);
    void on_dial_valueChanged(int value);
};

#endif // SYNTHWIDGET_H
