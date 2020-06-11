#ifndef POWERSQUARE_H
#define POWERSQUARE_H

#include "Sources/Core/square.h"

#include <QDebug>
#include <QColor>
#include <QString>

class PowerSquare : public Square
{
public:
    PowerSquare(const QString& name, const QString& description, const QColor& ltColor, const QString& imageFile);
    virtual ~PowerSquare();

    virtual QString squareType() const override {return "PowerSquare";}

    static PowerSquare* Upgrade();

    // Overrides of QGraphicsItem
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    static const float ltWidthRatio;
    QColor m_ltColor;

    QString m_imageFile;
};

#endif // POWERSQUARE_H
