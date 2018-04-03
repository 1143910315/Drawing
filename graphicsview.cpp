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
