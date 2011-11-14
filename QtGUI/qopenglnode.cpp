#include "qopenglnode.hpp"
#include "ui_qcounter.h"

QOpenGLNode::QOpenGLNode(QWidget *parent, NodeHandler *handler, QString name, int in, int out) :
  QBasicNode(parent, handler, name, in, out)
{
  layout->removeWidget(nameLabel);
  nameLabel->hide();


  gl_widget = new GLWidget(this);
  gl_widget->resize(100, 40);

  layout->setSizeConstraint(QLayout::SetNoConstraint);
  this->resize(320, 240);
  layout->setRowStretch(0, 0);
  layout->setRowStretch(1, 1);
  layout->addWidget(gl_widget, 1, 0, 0);

  this->setLayout(layout);
  layout->activate();
  layout->setMargin(1);
  this->show();
}

QOpenGLNode::~QOpenGLNode()
{

}

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);
}

void GLWidget::initializeGL() {
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 0);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0, w, 0, h); // set origin to bottom left corner
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(1,1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {

}
void GLWidget::mouseMoveEvent(QMouseEvent *event) {

}

void GLWidget::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        event->ignore();
        break;
    }
}
