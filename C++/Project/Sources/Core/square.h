#ifndef SQUARE_H
#define SQUARE_H

#include <QDebug>
#include <QGraphicsItem>
#include <QColor>
#include <QString>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#define sure_cast static_cast
#define unsure_cast dynamic_cast

class Square : public QGraphicsItem
{
public:
    Square(const QString& name, const QString& description, const QColor& backgroundColor);
    virtual ~Square();

    virtual QString squareType() const {return "Square";}

    static Square* Black();
    static Square* White();

    // Overrides of QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QString m_name;
    QString m_description;

    QColor m_backgroundColor;

public:
    static const float side;
};

#endif // SQUARE_H
