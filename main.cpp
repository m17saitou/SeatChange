#include "seatChange.h"
#include "mainWindow.h"
int main (int argc, char *argv[]){
    QApplication graphical(argc, argv);
    MainWindow seatChangeGui;
    seatChangeGui.show();
    return graphical.exec();
}