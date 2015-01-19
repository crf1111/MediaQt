#include "mainwindow.h"

//qt
#include <QMovie>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Movie Show");

    //doc widget
    myDockWidget = new DockWidget();
    myDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,myDockWidget);

    //center widget
    myCenterWidget = new CenterWidget();
    setCentralWidget(myCenterWidget);

    connect(myDockWidget,SIGNAL(signalUpdatePlaylist(QMediaPlaylist*)),
            myCenterWidget,SLOT(slotUpdatePlaylist(QMediaPlaylist*)));
    connect(this,SIGNAL(signalUpdatePlaylist(QMediaPlaylist*)),myCenterWidget,SLOT(slotUpdatePlaylist(QMediaPlaylist*)));

    connect(myDockWidget,SIGNAL(signalFullScreen(bool)),
            myCenterWidget,SLOT(slotFullScreen(bool)));

    connect(myCenterWidget,SIGNAL(signalUpdateAlltime(qint64)),
            myDockWidget,SLOT(slotUpdateAlltime(qint64)));

    connect(myDockWidget,SIGNAL(signalChangedPosition(qint64)),
            myCenterWidget,SLOT(slotChangePosition(qint64)));

    setMinimumSize(QSize(800,600));

}

void MainWindow::slotPositionChanged(qint64 pos)
{

    qDebug()<<"position of the mp3 is :"<<pos;

}
