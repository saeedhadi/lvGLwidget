#ifndef LVGLWIDGET_H
#define LVGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QElapsedTimer>
#include <QLinkedList>
#include <QTimer>
#include <lvgl.h>

class LVGLwidget : public QOpenGLWidget
{
    public:
        LVGLwidget(QWidget * parent = 0);
        ~LVGLwidget();

    protected:
        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();
        void mousePressEvent(QMouseEvent * event);
        void mouseReleaseEvent(QMouseEvent * event);
        void mouseMoveEvent(QMouseEvent * event);

    private:
        QOpenGLBuffer * m_pPBO;
        QElapsedTimer * m_timerElapsed;
        QTimer * m_timerToRefresh;
        QLinkedList<bool> m_mousePressEvents;
};

#endif // LVGLWIDGET_H
