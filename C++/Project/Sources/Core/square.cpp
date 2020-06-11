#include "Sources/Core/square.h"

const float Square::side = 1000.0f;

Square::Square(const QString& name, const QString& description, const QColor& backgroundColor)
    : m_name(name), m_description(description), m_backgroundColor(backgroundColor)
{
    if (m_name == QString())
    {
        m_name = QObject::tr("Nom de la case (à compléter)");
    }

    if (m_description == QString())
    {
        m_description = QObject::tr("Description de la case (à compléter).");
    }

    setToolTip(QString("<span style=\" font-size:12pt; font-weight:500; color:#ffffff;\">%1</span>").arg(m_name)
                       +"<qt/>\n\r<qt>"+
               QString("<span style=\" font-size:10pt; font-weight:100; color:#ffffff;\">%2</span>").arg(m_description));

    setZValue(-1);
}

Square::~Square()
{

}

Square* Square::Black()
{
    return new Square(QObject::tr("Case noire"), QObject::tr("Le joueur boit 1 gorgée."), QColorConstants::Black);
}

Square* Square::White()
{
    return new Square(QObject::tr("Case blanche"), QObject::tr("Le joueur donne 1 gorgée."), QColorConstants::White);
}

QRectF Square::boundingRect() const
{
    return QRectF(0, 0, Square::side, Square::side);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QBrush brush(m_backgroundColor, Qt::SolidPattern);
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);

    painter->drawRect(0, 0, Square::side, Square::side);
}
