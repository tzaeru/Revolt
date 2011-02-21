#include <QPaintEvent>
#include <QPainter>

#include <stdio.h>

#include "waveformwidget.h"
#include "ui_waveformwidget.h"

WaveformWidget::WaveformWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaveformWidget)
{
    ui->setupUi(this);

    preset_data.Init();
}

void WaveformWidget::paintEvent(QPaintEvent *event) {
    printf("test\n");
  QPainter painter(this);

  float *data;

  int wave_length = preset_data.GetPreset(data);

  float stepsize = wave_length/(float)width();

   /*! Loops through the widget's width, drawing lines according to the wave. */
  for (int x = 0; x < width()-1; x++) {
    painter.drawLine(x, (int)((data[(int)(x*stepsize)] + 1) * height()/2), x+1, (int)((data[(int)((x+1)*stepsize)] + 1) * height()/2));
  }
/*
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
  painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
  painter.drawEllipse(20, 20, 400, 240);*/
}

WaveformWidget::~WaveformWidget()
{
    delete ui;
}
