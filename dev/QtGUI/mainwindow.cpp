#include "mainwindow.h"
#include "ui_mainwindow.h"

 #include <QVBoxLayout>

#include "synthwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
  int max_amp = 32767;
  int sample_length = 4096;
  int channels = 2;

  preset_data.Init();

  //synth = new Synth(440, max_amp/2, 48000, &preset_data);
  //Synth *synth2 = new Synth(440, max_amp/4, 48000, &preset_data);
  mixer = new Mixer(max_amp);

  mixer->SetSampleLength(sample_length*channels);
  //mixer->AddSynth(synth);

  sound_hardware = new SDLSoundHardware(48000, sample_length);

  sound_hardware->AddMixer(mixer);

  sound_hardware->Init();

  wrapper.AddSoundHardware(sound_hardware);
  wrapper.AddSoundObject("mixer", mixer);

  ui = new Ui::MainWindow;
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Synth_triggered()
{
  mixer->AddSource(synth);

  wrapper.AddSoundObject("synth1", synth);

  SynthWidget *synth_widget = new SynthWidget(this);
  layout()->addWidget(synth_widget);
}
