#include "synthwidget.h"
#include "ui_synthwidget.h"

#include "mainwindow.h"

SynthWidget::SynthWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SynthWidget)
{
    MainWindow * real_parent = (MainWindow *)window();

    ui->setupUi(this);

    float *wave;
    int wave_length = real_parent->preset_data.GetPreset(wave);

    lfo = new LFO(48000);
    lfo->SetAmplitude(1000);
    lfo->SetFrequency(20);
    lfo->SetWaveform(wave, wave_length);

    synth = new Synth(48000);
    synth->SetAmplitude(4095);
    synth->SetFrequency(220);
    synth->SetWaveform(wave, wave_length);


    real_parent->mixer->AddSource(lfo);
    lfo->AddSource(synth);
}

SynthWidget::~SynthWidget()
{
    delete ui;
}

void SynthWidget::on_dial_valueChanged(int value)
{
    synth->SetFrequency(value);
}

void SynthWidget::on_verticalSlider_valueChanged(int value)
{
    synth->SetAmplitude(value);
}

void SynthWidget::on_dial_2_valueChanged(int value)
{
    lfo->SetAmplitude(value);
}

void SynthWidget::on_dial_3_valueChanged(int value)
{
    lfo->SetFrequency(value);
}
