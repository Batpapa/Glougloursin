#include "Sources/Core/powersquare.h"

const float PowerSquare::ltWidthRatio = 0.1f;

PowerSquare::PowerSquare(const QString& name, const QString& description, const QColor& ltColor, const QString& imageFile)
    : Square(name, description, QColorConstants::White), m_ltColor(ltColor), m_imageFile(imageFile)
{

}

PowerSquare::~PowerSquare()
{

}

PowerSquare* PowerSquare::Upgrade()
{
    return new PowerSquare(QObject::tr("Case Upgrade"), QObject::tr("Procure une upgrade, donné par la valeur du dé."), QColorConstants::Transparent, ":Resources/upgrade.png");
}

void PowerSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QBrush brush(m_ltColor, Qt::SolidPattern);
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);

    painter->drawRect(0, 0, ltWidthRatio*side, side);
    painter->drawRect(0, 0, side, ltWidthRatio*side);
    painter->drawRect(side, 0, -ltWidthRatio*side, side);
    painter->drawRect(0, side, side, -ltWidthRatio*side);

    painter->drawPixmap(QRect(0,0,side,side), QPixmap::fromImage(QImage(m_imageFile)));
}
