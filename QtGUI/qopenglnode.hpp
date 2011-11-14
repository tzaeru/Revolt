#ifndef QOPENGLNODE_HPP
#define QOPENGLNODE_HPP

#include "qbasicnode.hpp"
#include "../nodes/supernode.hpp"

#include <QtOpenGL/QGLWidget>

class GLWidget;

namespace Ui {
    class QOpenGLNode;
    class GLWidget;
}

class QOpenGLNode : public QBasicNode
{
    Q_OBJECT

public:
  explicit QOpenGLNode(QWidget *parent = 0, NodeHandler* handler = NULL, QString name = QString("node"),
                     int in = 0, int out = 0);
  ~QOpenGLNode();

  GLWidget *gl_widget;

  /*
public slots:
  void updateNode();
*/
private:
    //Ui::QCounter *ui;
};

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // QOPENGLNODE_HPP
