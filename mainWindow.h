#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "seatChange.h"
#include <QtGui>
#include <QtWidgets>
#include <QRadioButton>
#include <QCoreApplication>
#include <bits/stdc++.h>

class SeatChange;
class QLineEdit;
class QPushButton;
class QTableWidget;
class SeatChange;
class QRadioButton;

class MainWindow :public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);
    ~MainWindow();
    QLineEdit *studentNum;
    QLineEdit *columnSeat;
    QLineEdit *rowSeat;
    QLabel *stuNum;
    QLabel *seatCol;
    QLabel *seatRow;
    QTableWidget *seatView;
    QPushButton *createNewSeat;
    QPushButton *exportCSV;
    QPushButton *importCSV;
    QRadioButton *setSeatOption;
public slots:
    void createNew();
    void importCSVFile();
    void exportCSVFile();
};

#endif //MAINWINDOW_H