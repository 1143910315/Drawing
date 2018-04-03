#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

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

	// QWidget interface
protected:
	void mouseMoveEvent(QMouseEvent *event);
};

#endif // GRAPHICSVIEW_H
