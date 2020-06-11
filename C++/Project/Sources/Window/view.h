#ifndef VIEW_H
#define VIEW_H

#include <QDebug>
#include <QGraphicsView>
#include <QResizeEvent>

class View : public QGraphicsView
{
public:
    View(QGraphicsScene* scene);

    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // VIEW_H
