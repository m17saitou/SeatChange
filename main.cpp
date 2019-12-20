#include "seatChange.h"
int main (){
    SeatChange seatPatern = SeatChange(6,7);
    SeatChange::clsNum = 40;
    seatPatern.newSeat();
    seatPatern.showSeat();
}