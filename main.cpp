#include <QtGui/QApplication>
#include "QtGUI/mainwindow.hpp"
#include "info.hpp"

#include "nodes/supernode.hpp"
#include "nodes/timer.hpp"
#include "nodes/addition.hpp"

int currentFrame;
QTime myTimer;

int main(int argc, char *argv[])
{
  /*
  Timer timer(0, 1);
  Addition addition(2, 1);
  (void)addition.Connect(0, 0, &timer);
  (void)addition.Connect(1, 0, &addition);
  currentFrame = 0;

  myTimer.start();

  while (myTimer.elapsed() < 2000)
  {
    addition.Update();
    currentFrame++;
  }

  printf("%d\n", currentFrame);

  return 0;
  */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
