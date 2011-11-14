/*! Main window, contains initial QNodeGroup and file bar.
  */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMenu>

#include <iostream>
#include <fstream>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  std::ofstream fileOutputStream;
  std::streambuf* sbuf;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
