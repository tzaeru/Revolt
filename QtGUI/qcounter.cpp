#include <QTimer>

#include "qcounter.hpp"
#include "ui_qcounter.h"

QCounter::QCounter(QWidget *parent, NodeHandler *handler, QString name, int in, int out) :
  QBasicNode(parent, handler, name, in, out)
{
  layout->removeWidget(nameLabel);
  nameLabel->hide();

  lcd_number = new QLCDNumber(this);
  layout->addWidget(lcd_number, 1, 0);

  update_timer = new QTimer(this);
  connect(update_timer, SIGNAL(timeout()), this, SLOT(updateNode()));
  update_timer->start(1000/4);

  this->setLayout(layout);
  layout->activate();
  layout->setMargin(1);
  this->show();
}

void QCounter::updateNode()
{
  node->Update();

  cout<<"Called!"<<"\n";
  if (node->input_slot[0].connected_output)
  {
    lcd_number->display(*(node->input_slot[0].connected_output->data[0]));
    cout<<"Value: "<<node->input_slot[0].connected_output->data[0]<<"\n";
  }
  else
     cout<<"Not connected!\n";
  lcd_number->update();
}

QCounter::~QCounter()
{

}
