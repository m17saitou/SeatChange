#include "seatChange.h"
int SeatChange::height=-1;
int SeatChange::width=-1;
int SeatChange::clsNum=0;
SeatChange::SeatChange(int w , int h){
    SeatChange::width = w;
    SeatChange::height = h;
    for(int y=0;y<=SeatChange::height+1;y++){
        for(int x=0;x<=SeatChange::width+1;x++){
            seatArray.push_back(0);//一度全て0で初期化
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
void SeatChange::newSeat(){
    for(int y=0;y<=SeatChange::height;y++){
        for(int x=0;x<=SeatChange::width;x++){
            seatArray[y*SeatChange::width + x] = createSeat(seatArray);
        }
    }
}
void SeatChange::newSeatDefined(std::vector<int [3]> defSeat){
    for(int i=0;i<defSeat.size();i++){
        seatArray[defSeat[i][1]*SeatChange::width + defSeat[i][0]] = defSeat[i][2];
    }
    for(int y=0;y<=SeatChange::height;y++){
        for(int x=0;x<=SeatChange::width;x++){
            if(seatArray[y*SeatChange::width + x] != 0)seatArray[y*SeatChange::width + x] = createSeat(seatArray);
        }
    }

}
void SeatChange::fromCsvSeat(std::string filename){
    std::ifstream inputCsv(filename);
    std::string linebuf;
    std::vector<std::string> valueArr;
    while(getline(inputCsv, linebuf)){
        std::istringstream stream(linebuf);
        std::string str;
        while(getline(stream,str,','))valueArr.push_back(str);
    }
    for(int i=0;i<valueArr.size();i++){
        seatArray[i] = std::stoi(valueArr[i]);
    }
}
void SeatChange::noDuplicateSeat(std::vector<std::vector<int>> bofores, int howAgo){
    // 特にnewSeatとやることに変化はない．以前との重複チェック追加だけ
}
int SeatChange::createSeat(std::vector<int> already){
    std::random_device randSeed;
    std::mt19937_64 mt(randSeed());
    std::uniform_int_distribution<int> intRand(1,SeatChange::clsNum);
    int ID;
    while(1){
        int tmpRand = intRand(mt);
        auto tmpRslt = std::find(already.begin(),already.end(),tmpRand);
        if(tmpRslt == already.end()){
            ID = tmpRand;
            break;
        }
    }
    return ID;
}