#ifndef QCOUNTER_HPP
#define QCOUNTER_HPP

#include <QLCDNumber>

#include "qbasicnode.hpp"
#include "../nodes/supernode.hpp"

namespace Ui {
    class QCounter;
}

class QCounter : public QBasicNode
{
    Q_OBJECT

public:
  explicit QCounter(QWidget *parent = 0, QString name = QString("node"),
                     int in = 0, int out = 0);
  ~QCounter();

  QLCDNumber *lcd_number;

public slots:
  void updateNode();

private:
    Ui::QCounter *ui;
};

#endif // QCOUNTER_HPP
