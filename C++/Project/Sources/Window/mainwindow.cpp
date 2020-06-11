#include "Sources/Window/mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QKeySequence>
#include <QMessageBox>
#include <QApplication>

#define NO_SLOT [](){qDebug() << "Not implemented";}

MainWindow::MainWindow(Grid* g, QWidget *parent)
    : QMainWindow(parent), grid(g)
{
    setWindowTitle(tr("Glougloursin Creator"));
    setWindowIcon(QIcon(":Resources/icon.png"));

    scene = new QGraphicsScene();
    scene->addItem(grid);

    grid->addBackgroundSquares();
    grid->addUpgradeSquares();
    grid->addBonusSquares();

    view = new View(scene);
    setCentralWidget(view);

    createActions();
    createMenus();

    view->show();
}

MainWindow::~MainWindow()
{
    qInfo() << "===== Exiting application =====";
}

void MainWindow::setInputs(const QList<QString>& sl)
{
    inputs = sl;
}

#include <QTimer>
void MainWindow::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);

    if (!inputs.isEmpty())
    {
        qInfo() << "Parsing" << inputs.size() << "input(s):";
        for (int k = 0; k < inputs.size(); ++k)
        {
            qInfo() << "Input" << k << "=" << inputs[k];
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("Nouveau"), this);
    newAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    connect(newAct, &QAction::triggered, this, NO_SLOT);

    loadAct = new QAction(tr("Ouvrir"), this);
    loadAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    connect(loadAct, &QAction::triggered, this, NO_SLOT);

    saveAct = new QAction(tr("Enregistrer"), this);
    saveAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    connect(saveAct, &QAction::triggered, this, NO_SLOT);

    saveAsAct = new QAction(tr("Enregistrer sous..."), this);
    connect(saveAsAct, &QAction::triggered, this, NO_SLOT);

    exitAct = new QAction(tr("Quitter"), this);
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);

    aboutAct = new QAction(tr("À propos"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("À propos de Qt"), this);
    connect(aboutQtAct, &QAction::triggered, this, &QApplication::aboutQt);
}

void MainWindow::createMenus()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("Fichier"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(loadAct);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    QMenu* helpMenu = menuBar()->addMenu(tr("Aide"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::about()
{
    // Show About
    QMessageBox::about(this,
                       tr("À propos"),
                       tr("Logiciel développé par la Mimi Company.")
                       );
}
