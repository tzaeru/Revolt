#ifndef WAVEFORMWIDGET_H
#define WAVEFORMWIDGET_H

#include <QWidget>

#include "preset_data.hpp"

namespace Ui {
    class WaveformWidget;
}

class WaveformWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WaveformWidget(QWidget *parent = 0);
    ~WaveformWidget();

  void paintEvent(QPaintEvent * event);

private:
    Ui::WaveformWidget *ui;

    PresetData preset_data;
};

#endif // WAVEFORMWIDGET_H
