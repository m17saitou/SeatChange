#include "seatChange.h"
int main (){
    SeatChange seatPatern(6,7);
    SeatChange::clsNum = 40;
    seatPatern.newSeat();
    std::vector<int> newSeatPatern = seatPatern.getSeatData();
    for(int i=0;i<7;i++){
        for(int j=0;i<6;j++){
            std::cout << " " << newSeatPatern[i*seatPatern.width + j];
        }
        std::cout << std::endl;
    }
}