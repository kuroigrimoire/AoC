#include "Bingo_Board.h"

// Constructor
BingoBoard::BingoBoard(){ //   No args Cunstructor - should not be used
     std::cout << "Bingo Board object was created with no argument." << std::endl
          << "Wrong object initialized" << std::endl;
}
BingoBoard::BingoBoard(std::vector<std::vector<int>> bb, int n)
     :bboard(bb), b_num{n}{
          std::cout << "Bingo board Created properly and populated with numbers" << std::endl
               << "Printing Board: " << b_num << std::endl;
          for(int i{0}; i < bboard.size(); i++){
               for(int j{0}; j < bboard[i].size(); j++){
                    std::cout << bboard[i][j] << '\t';
               }
               std::cout << std::endl;
          }
          std::cout << std::endl;
}
BingoBoard::BingoBoard(const BingoBoard &source)
     :bboard(source.bboard), b_num(source.b_num), row(source.row), col(source.col), next_cri(source.next_cri), win_cri(source.win_cri){
          std::cout << "Copy Constructor made a copy of Board: " << b_num << '\n';
}
// Destructor
BingoBoard::~BingoBoard(){    //   Destructor - nothing necessary, but test cases...
     std::cout << "Destructor for Bingo Board called." << '\n';
}
// Member Functions

// Methods
// Display the board function?
void BingoBoard::display() const {
     std::cout << "Displaying contents of the board: " << b_num << std::endl;
     for(int i{0}; i < bboard.size(); i++){
          for(int j{0}; j < bboard[i].size(); j++){
               std::cout << bboard[i][j] << '\t';
          }
          std::cout << std::endl;
     }
     std::cout << "Printing Row Scores: " << "\t\t\t";
     for(auto r:row)
          std::cout << r << ",\t";
     std::cout << std::endl;
     std::cout << "Printing column Scores: " << "\t\t";
     for(auto c:col)
          std::cout << c << ",\t";
     std::cout << std::endl;
     
     std::cout << std::endl;     
}
void BingoBoard::call_check(int num){
     next_cri = {false};
     std::cout << "Checking for: " << num << " in board: " << b_num<< std::endl;
     for(int i(0); i < bboard.size(); i++){
          for(int j(0); j < bboard[i].size(); j++){
               if (num == bboard[i][j]) {
                    std::cout << "Number: " << num << " found on boards: " << b_num << " in row: " << i << " column: " << j << std::endl;
                    mark(i,j);
                    marked += bboard[i][j];
                    std::cout << "Board current marked value sum = " << marked << '\n';
                    next_cri = true;
                    break;
               }
          }
          if (next_cri == true) {
               break;
          }
     }
     // std::cout << std::endl;
}
void BingoBoard::mark(int x, int y){
     row[x]++;
     col[y]++;
}
// Check row and column value.
void BingoBoard::win_con(bool &b_val){
     for(auto r:row){
          if (r == 5) {
               win_cri = true;
          }
     }
     for(auto c:col){
          if (c == 5) {
               win_cri = true;
          }
     }
     if (win_cri == true) {
          std::cout << "Winner found at board: " << b_num << std::endl;
          b_val = true;
     }else{
          std::cout << "No Winner found at board: " << b_num << std::endl;
          std::cout << "Printing Row values: \t";
          for(auto r:row){
               std::cout << r << ' ';
          }
          std::cout << std::endl;
          std::cout << "Printing Col values: \t";
          for(auto c:col){
               std::cout << c << ' ';
          }
          std::cout << std::endl;
     }
     std::cout << std::endl;
}
// calculate the score of the winning board. 
// -    sum the numbers in the board, sum the numbers already called, and subtract the two.
// -    then multiply by the final number 
// -    Needs external inputs: vector of called numbers, count of the last number called, winning board number
// int finCal(std::vector<int> v, int nc, int wbn){
// 
// }
int BingoBoard::score(int num){
     for(int i(0); i < bboard.size(); i++){
          for(int j(0); j < bboard[i].size(); j++){
               sum += bboard[i][j];
          }
     }
     total = (sum - marked) * num;
     std::cout << "The board that won was: " << b_num << std::endl
          << "It's current sum total of called numbers is: " << sum << std::endl
          << "The last called number was: " << num << " the total is then: " << total << std::endl;
     return total;
}