#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Sources/Core/grid.h"
#include "Sources/Window/view.h"

#include <QDebug>
#include <QMainWindow>
#include <QAction>
#include <QShowEvent>
#include <QCloseEvent>
#include <QGraphicsScene>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Grid* g, QWidget *parent = nullptr);
    ~MainWindow();

    void setInputs(const QList<QString>& sl);

protected:
    virtual void showEvent(QShowEvent* event) override;
    virtual void closeEvent(QCloseEvent *event) override;

private:
    Grid* grid;

    QGraphicsScene* scene;
    View* view;

    QList<QString> inputs;

    void createActions();
    QAction* newAct;
    QAction* loadAct;
    QAction* saveAct;
    QAction* saveAsAct;
    QAction* exitAct;
    QAction* aboutAct;
    void about();
    QAction* aboutQtAct;

    void createMenus();
};

#endif // MAINWINDOW_H
