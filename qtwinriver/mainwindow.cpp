#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scatterplot.h"
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = new QMenu(tr("&File"), menuBar);
    QMenu *configMenu = new QMenu(tr("&Config"), menuBar);
    QMenu *watchMenu = new QMenu(tr("&Watch"), menuBar);
    QMenu *collectMenu = new QMenu(tr("C&ollect"), menuBar);
    QMenu *replayMenu = new QMenu(tr("&Replay"), menuBar);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(configMenu);
    menuBar->addMenu(watchMenu);
    menuBar->addMenu(collectMenu);
    menuBar->addMenu(replayMenu);

    //QAction *watchGraph = new QAction(tr("Graph"), watchMenu);
    QMenu *graphMenu = watchMenu->addMenu(tr("&Graphs"));
    QMenu *tableMenu = watchMenu->addMenu(tr("&Tables"));

    QAction *shipSpeed = new QAction(tr("&Ship"), graphMenu);
    graphMenu->addAction(shipSpeed);

    QAction *tableTemp1 = new QAction(tr("&table1"), tableMenu);
    tableMenu->addAction(tableTemp1);

    QAction *tableTemp2 = new QAction(tr("&table2"), tableMenu);
    tableMenu->addAction(tableTemp2);

    QAction *newFile = new QAction(tr("&New"), fileMenu);
    fileMenu->addAction(newFile);
    QAction *openFile = new QAction(tr("&Open"), fileMenu);
    fileMenu->addAction(openFile);

    setMenuBar(menuBar);
    //ui->menuBar;
    connect(shipSpeed, SIGNAL(triggered()), this, SLOT(showGraph()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showGraph() {
    //QWidget *table = new QWidget();
    //table->show();
    ScatterPlot *w = new ScatterPlot();
    w->resize( 800, 600 );
    w->show();
}
