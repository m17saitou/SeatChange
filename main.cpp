#include "seatChange.h"
#include "mainWindow.h"
int main (int argc, char *argv[]){
    SeatChange seatPatern = SeatChange(6,7);
    SeatChange::clsNum = 40;
    seatPatern.newSeat();
    seatPatern.showSeat();
    QApplication graph(argc, argv);
    MainWindow seatChangeGui;
    seatChangeGui.show();
    return graph.exec();
}