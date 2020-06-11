#include "Sources/Window/view.h"

#include "Sources/Core/grid.h"

View::View(QGraphicsScene* scene)
    : QGraphicsView(scene)
{
    setStyleSheet("QToolTip { color: #ffffff; background-color: #444444; border: 0px; }");
}

void View::resizeEvent(QResizeEvent *event)
{
    fitInView(-Square::side, -Square::side, Square::side*(Grid::size+1), Square::side*(Grid::size+1), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}
