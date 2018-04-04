#ifndef GLOBALMODEL_H
#define GLOBALMODEL_H

#include "paintingmodel.h"
#include <QGraphicsScene>
class GlobalModel : public PaintingModel
{
	Q_OBJECT
public:
	GlobalModel(QGraphicsScene *scene);
	~GlobalModel();
	int getType();
	QString getDescription();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QStringList getData();
	QStringList getAttribute(int dataIndex);
	QStringList getValue(int dataIndex);
	int setValue(int dataIndex, int attrIndex, const QString &data);
	QString getErrorMessage(int errorCode);
	void addItem(PaintingModel *model);
	void removeItem(PaintingModel *model);
	void setSceneRect(qreal x,qreal y,qreal w,qreal h);
	void getSceneRect(qreal &x,qreal &y,qreal &w,qreal &h);
signals:
	void changeSceneRect();
private:
	QGraphicsScene *scene;
	qreal x;
	qreal y;
	qreal w;
	qreal h;
};

#endif // GLOBALMODEL_H
