#ifndef GRID_H
#define GRID_H

#include "Sources/Core/square.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QColor>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class Grid : public QGraphicsItem
{
public:
    Grid();
    virtual ~Grid();

    void addSquare(int i, int j, Square* square);
    void addBackgroundSquares();
    void addUpgradeSquares();
    void addBonusSquares();

    // Overrides of QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QVector<QVector<Square*>> squares;

    float lineWidth;
    QColor lineColor;

public:
    static const int size;
};

#endif // GRID_H
