#include "synthwidget.h"
#include "ui_synthwidget.h"

#include "mainwindow.h"

SynthWidget::SynthWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SynthWidget)
{
    MainWindow * real_parent = (MainWindow *)window();

    ui->setupUi(this);

    synth = new Synth(220, 4095, 48000, &real_parent->preset_data);

    printf("1\n");
    real_parent->mixer->AddSynth(synth);
     printf("666\n");
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
