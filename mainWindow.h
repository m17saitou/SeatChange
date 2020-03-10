#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "seatChange.h"
#include <QtGui>
#include <QtWidgets>
#include <QCoreApplication>
#include <bits/stdc++.h>

class SeatChange;

class MainWindow :public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);
    ~MainWindow();
};

#endif //MAINWINDOW_H