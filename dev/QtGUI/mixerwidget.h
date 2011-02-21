#ifndef MIXERWIDGET_H
#define MIXERWIDGET_H

#include <QWidget>

namespace Ui {
    class MixerWidget;
}

class MixerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MixerWidget(QWidget *parent = 0);
    ~MixerWidget();

private:
    Ui::MixerWidget *ui;
};

#endif // MIXERWIDGET_H
