#include "mixerwidget.h"
#include "ui_mixerwidget.h"

MixerWidget::MixerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MixerWidget)
{
    ui->setupUi(this);
}

MixerWidget::~MixerWidget()
{
    delete ui;
}
