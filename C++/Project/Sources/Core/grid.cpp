#include "Sources/Core/grid.h"

#include "Sources/Core/powersquare.h"

#include <QPointF>
#include <QGraphicsScene>

const int Grid::size = 8;

Grid::Grid()
{
    lineWidth = 0.01f;
    lineColor = QColor::fromRgb(128,128,128);

    // Set 2D grid
    squares.resize(size);
    for (int i = 0; i < size; ++i)
    {
        squares[i].resize(size);
        for (int j = 0; j < size; ++j)
        {
            squares[i][j] = nullptr;
        }
    }

    setZValue(0);
}

Grid::~Grid()
{

}

void Grid::addSquare(int i, int j, Square* square)
{
    if (squares[i][j] != nullptr)
    {
        delete squares[i][j];
    }

    squares[i][j] = square;

    // Add to grid's scene
    square->setPos(j*Square::side, i*Square::side);
    Q_ASSERT(scene() != nullptr);
    scene()->addItem(square);
}

void Grid::addBackgroundSquares()
{
    addSquare(0, 0, Square::White());
    addSquare(0, 1, Square::Black());
    addSquare(0, 2, Square::White());
    addSquare(0, 3, Square::Black());
    addSquare(0, 4, Square::Black());
    addSquare(0, 5, Square::White());
    addSquare(0, 6, Square::Black());
    addSquare(0, 7, Square::White());

    addSquare(1, 0, Square::Black());
    addSquare(1, 1, Square::White());
    addSquare(1, 2, Square::White());
    addSquare(1, 3, Square::White());
    addSquare(1, 4, Square::White());
    addSquare(1, 5, Square::Black());
    addSquare(1, 6, Square::White());
    addSquare(1, 7, Square::Black());

    addSquare(2, 0, Square::White());
    addSquare(2, 1, Square::White());
    addSquare(2, 2, Square::White());
    addSquare(2, 3, Square::Black());
    addSquare(2, 4, Square::White());
    addSquare(2, 5, Square::White());
    addSquare(2, 6, Square::Black());
    addSquare(2, 7, Square::White());

    addSquare(3, 0, Square::Black());
    addSquare(3, 1, Square::White());
    addSquare(3, 2, Square::Black());
    addSquare(3, 3, Square::White());
    addSquare(3, 4, Square::Black());
    addSquare(3, 5, Square::White());
    addSquare(3, 6, Square::White());
    addSquare(3, 7, Square::Black());

    addSquare(4, 0, Square::Black());
    addSquare(4, 1, Square::White());
    addSquare(4, 2, Square::White());
    addSquare(4, 3, Square::Black());
    addSquare(4, 4, Square::White());
    addSquare(4, 5, Square::Black());
    addSquare(4, 6, Square::White());
    addSquare(4, 7, Square::Black());

    addSquare(5, 0, Square::White());
    addSquare(5, 1, Square::Black());
    addSquare(5, 2, Square::White());
    addSquare(5, 3, Square::White());
    addSquare(5, 4, Square::Black());
    addSquare(5, 5, Square::White());
    addSquare(5, 6, Square::White());
    addSquare(5, 7, Square::White());

    addSquare(6, 0, Square::Black());
    addSquare(6, 1, Square::White());
    addSquare(6, 2, Square::Black());
    addSquare(6, 3, Square::White());
    addSquare(6, 4, Square::White());
    addSquare(6, 5, Square::White());
    addSquare(6, 6, Square::White());
    addSquare(6, 7, Square::Black());

    addSquare(7, 0, Square::White());
    addSquare(7, 1, Square::Black());
    addSquare(7, 2, Square::White());
    addSquare(7, 3, Square::Black());
    addSquare(7, 4, Square::Black());
    addSquare(7, 5, Square::White());
    addSquare(7, 6, Square::Black());
    addSquare(7, 7, Square::White());
}

void Grid::addUpgradeSquares()
{
    addSquare(0, 0, PowerSquare::Upgrade());
    addSquare(0, 7, PowerSquare::Upgrade());
    addSquare(7, 0, PowerSquare::Upgrade());
    addSquare(7, 7, PowerSquare::Upgrade());
    addSquare(2, 2, PowerSquare::Upgrade());
    addSquare(5, 5, PowerSquare::Upgrade());
    addSquare(4, 1, PowerSquare::Upgrade());
    addSquare(3, 6, PowerSquare::Upgrade());
}

void Grid::addBonusSquares()
{
    addSquare(1, 1, new PowerSquare(QObject::tr("Case d'attaque"), QObject::tr(""), QColor::fromRgb(255,   0,   0), ""));
    addSquare(3, 3, new PowerSquare(QObject::tr("Case d'attaque"), QObject::tr(""), QColor::fromRgb(255,   0,   0), ""));
    addSquare(5, 2, new PowerSquare(QObject::tr("Case d'attaque"), QObject::tr(""), QColor::fromRgb(255,   0,   0), ""));
    addSquare(0, 2, new PowerSquare(QObject::tr("Case de défense"), QObject::tr(""), QColor::fromRgb(  0,   0, 255), ""));
    addSquare(2, 5, new PowerSquare(QObject::tr("Case de défense"), QObject::tr(""), QColor::fromRgb(  0,   0, 255), ""));
    addSquare(4, 4, new PowerSquare(QObject::tr("Case de défense"), QObject::tr(""), QColor::fromRgb(  0,   0,   0), ""));
    addSquare(6, 1, new PowerSquare(QObject::tr("Case d'amour"), QObject::tr(""), QColor::fromRgb(255,   0, 255), ""));
    addSquare(7, 5, new PowerSquare(QObject::tr("Case d'amour"), QObject::tr(""), QColor::fromRgb(255,   0, 255), ""));
    addSquare(1, 6, new PowerSquare(QObject::tr("Case d'amour"), QObject::tr(""), QColor::fromRgb(255,   0, 255), ""));
}

QRectF Grid::boundingRect() const
{
    return QRectF(0, 0, size*Square::side, size*Square::side);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setWidthF(Square::side/50);
    pen.setCosmetic(false);
    painter->setPen(pen);

    for (int k = 0; k <= size; ++k)
    {
        painter->drawLine(0, k*Square::side, size*Square::side, k*Square::side);
        painter->drawLine(k*Square::side, 0, k*Square::side, size*Square::side);
    }
}
