#include "graphicsview.h"

//#include <qdebug.h>
GraphicsView::GraphicsView(QWidget *parent):QGraphicsView(parent)
{

}

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent):QGraphicsView(scene,parent)
{

}

GraphicsView::GraphicsView(QGraphicsViewPrivate &h, QWidget *parent):QGraphicsView(h,parent)
{

}

GraphicsView::~GraphicsView()
{

}



void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
	//qDebug("Test");
	emit mouserMove(event);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
	// 当前放缩倍数;
	//qreal scaleFactor = this->matrix().m11();
	int wheelDeltaValue = event->delta();
	// 向上滚动，放大;
	if (wheelDeltaValue > 0)
	{
		this->scale(1.1, 1.1);
	}
	// 向下滚动，缩小;
	else
	{
		this->scale(1.0 / 1.1, 1.0 / 1.1);
	}
	emit graphicsViewChangeScale();
}
