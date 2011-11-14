#include "info.hpp"
#include "QtGUI/mainwindow.hpp"

#include "nodecontainer.hpp"
#include "nodes/supernode.hpp"

int currentFrame;
QTime myTimer;
QApplication *app;

int main(int argc, char *argv[])
{
  myTimer.start();

  /*
  NodeHandler node_handler;
  SuperNode *addition = node_handler.create_node("Addition");
  SuperNode *timer = node_handler.create_node("Timer");

  addition->Connect(0, 0, timer);
  addition->Disconnect(0);
  addition->Update();
  addition->Update();
  */

  app = new QApplication(argc, argv);
  MainWindow w;
  w.show();

  return qApp->exec();
}
