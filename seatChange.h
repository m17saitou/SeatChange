#ifndef SEATCHANGE_H
#define SEATCHANGE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class SeatChange{//SeatChangeクラス．席順配列を保持する
public :
    static int width;
    static int height;
    SeatChange( int w, int h);//コンストラクタ 高さと幅を与えて初期化
    void setSeatData(std::vector <int> seatArr[]);//Vectorを与えて席順配列を作る．
    std::vector<int> getSeatData();//席順配列を返す
    int getSeatID(int x, int y);//座標からその席の出席番号を返す
    void newSeat(std::vector <int[3]> defSeat);//新しい席順を生成する vectorで絶対的に固定できる．フォーマットは{x,y,出席番号}
    void fromCsvSeat(std::string filename);
    ~SeatChange();//デストラクタ (一応)
private :
    std::vector <int> seatArray;
};


#endif SEATCHANGE_H