#ifndef SEATCHANGE_H
#define SEATCHANGE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>

class SeatChange{//SeatChangeクラス．席順配列を保持する
public :
    static int width;
    static int height;
    static int clsNum;//クラス人数
    SeatChange( int w, int h);//コンストラクタ 高さと幅を与えて初期化
    void setSeatData(std::vector <int> seatArr);//Vectorを与えて席順配列を作る．
    std::vector<int> getSeatData();//席順配列を返す
    int getSeatID(int x, int y);//座標からその席の出席番号を返す
    void newSeat();//新しい席順を生成する 
    void newSeatDefined(std::vector <int [3]> defSeat);//vectorで絶対的に固定できる．フォーマットは{x,y,出席番号}
    void fromCsvSeat(std::string filename);//CSVから席順配列を生成する
    void noDuplicateSeat(std::vector<std::vector<int>> bofores,int howAgo);// 複数(howAgo)回前からのデータと重複しないように席順生成
    int createSeat(std::vector<int> already);//まだ席が決まってない出席番号を返す 引数は既に決まった出席番号を入れたvector
    void showSeat();
    //~SeatChange();//デストラクタ (一応)
private :
    std::vector <int> seatArray;
};


#endif //SEATCHANGE_H