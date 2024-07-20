#ifndef _BBOARD_H_
#define _BBOARD_H_

#include<iostream>
#include<string>
#include<vector>

class BingoBoard
{
private:
     int marked{0}, sum{0}, total{0};
     std::vector<std::vector<int>> bboard;
     std::vector<int> row{0,0,0,0,0}, col{0,0,0,0,0};
     bool next_cri{false}, win_cri{false};
public:
     int b_num{0};
     // Constructors
     BingoBoard();
     BingoBoard(std::vector<std::vector<int>> bb, int n);
     BingoBoard(const BingoBoard &source);
     // Destructor
     ~BingoBoard();
     
     // Methods
     // Display the board function?
     void display() const;
     // Iterate the board function - take the number from call and search the board for that number.
     //      Inputs: int from call
     void call_check(int num);
     // void call_num(int num);
     // update row and column value - if a number is found take it's position and increment the corresponding row and column values.
     //      Inputs: two int which are the index for location of the number just found
     void mark(int x, int y);
     // Check row and column value.
     void win_con(bool &b_val);
     int score(int num);
};

#endif // _BBOARD_H_