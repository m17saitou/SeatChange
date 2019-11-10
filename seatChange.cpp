#include "seatChange.h"

SeatChange::SeatChange(int w , int h){
    SeatChange::width = w;
    SeatChange::height = h;
    seatArray.resize(w*h+1);
    for(int y=0;y<=SeatChange::height;y++){
        for(int x=0;x<=SeatChange::width;x++){
            seatArray[y*SeatChange::width + x] = 0;//一度全て0で初期化
        }
    }
}
void SeatChange::setSeatData(std::vector <int> seatArr){
    for(int y=1;y<=SeatChange::height;y++){
        for(int x=1;x<=SeatChange::width;x++){
            seatArray[y*SeatChange::width + x] = seatArr[y*SeatChange::width + x];//代入
        }
    }
}
std::vector<int> SeatChange::getSeatData(){
    return seatArray;
}
int SeatChange::getSeatID(int x,int y){
    int id = seatArray[y*SeatChange::width + x];
    return id;
}
void SeatChange::newSeat(std::vector<int[3]> defSeat){
    if(defSeat.empty()){
        //座席指定が無く，全て乱数で決めて良い場合
    }
    else{
        //座席指定があった場合
    }
}