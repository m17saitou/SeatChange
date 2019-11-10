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
    for(int y=0;y<=SeatChange::height;y++){
        for(int x=0;x<=SeatChange::width;x++){
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
        for(int y=0;y<=SeatChange::height;y++){
            for(int x=0;x<=SeatChange::width;x++){
                seatArray[y*SeatChange::width + x] = createSeat(seatArray);
            }
        }
    }
    else{
        //座席指定があった場合
    }
}
void SeatChange::fromCsvSeat(std::string filename){
    std::ifstream inputcsv(filename);
}
void SeatChange::noDuplicateSeat(std::vector<std::vector<int>> bofores, int howAgo){
    // 特にnewSeatとやることに変化はない．
}
int SeatChange::createSeat(std::vector<int> already){
    //乱数を発生させて重複を確認して返すだけ．
}