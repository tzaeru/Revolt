#include "QtGUI/mainwindow.hpp"
#include "info.hpp"

#include "nodes/supernode.hpp"
#include "nodes/timer.hpp"
#include "nodes/addition.hpp"

#include "nodecontainer.hpp"

using namespace node;

int currentFrame;
QTime myTimer;
QApplication *app;

int main(int argc, char *argv[])
{
  (void)NodeHandler::Instance();

  myTimer.start();


  app = new QApplication(argc, argv);
  MainWindow w;
  w.show();

  return qApp->exec();
}
