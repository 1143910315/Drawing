#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
class GraphicsView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit GraphicsView(QWidget *parent = Q_NULLPTR);
	explicit GraphicsView(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
	explicit GraphicsView(QGraphicsViewPrivate &h,QWidget *parent = Q_NULLPTR);
	~GraphicsView();
signals:
	void mouserMove(QMouseEvent *event);
	void graphicsViewChangeScale();

protected:
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
};

#endif // GRAPHICSVIEW_H
