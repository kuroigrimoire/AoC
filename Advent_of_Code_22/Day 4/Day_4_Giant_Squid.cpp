/*
Advent of Code
--- Day 4: Giant Squid ---
You're already almost 1.5km (almost a mile) below the surface of the ocean, already so deep that you can't see any sunlight. What
you can see, however, is a giant squid that has attached itself to the outside of your submarine.

Maybe it wants to play bingo?

Bingo is played on a set of boards each consisting of a 5x5 grid of numbers. Numbers are chosen at random, and the chosen number
is marked on all boards on which it appears. (Numbers may not appear on all boards.) If all numbers in any row or any column of
a board are marked, that board wins. (Diagonals don't count.)

The submarine has a bingo subsystem to help passengers (currently, you and the giant squid) pass the time. It automatically
generates a random order in which to draw numbers and a random set of boards (your puzzle input). For example:

7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1

22 13 17 11  0
 8  2 23  4 24
21  9 14 16  7
 6 10  3 18  5
 1 12 20 15 19

 3 15  0  2 22
 9 18 13 17  5
19  8  7 25 23
20 11 10 24  4
14 21 16 12  6

14 21 17 24  4
10 16 15  9 19
18  8 23 26 20
22 11 13  6  5
 2  0 12  3  7
After the first five numbers are drawn (7, 4, 9, 5, and 11), there are no winners, but the boards are marked as follows (shown
here adjacent to each other to save space):

22 13 17 11  0         3 15  0  2 22        14 21 17 24  4
 8  2 23  4 24         9 18 13 17  5        10 16 15  9 19
21  9 14 16  7        19  8  7 25 23        18  8 23 26 20
 6 10  3 18  5        20 11 10 24  4        22 11 13  6  5
 1 12 20 15 19        14 21 16 12  6         2  0 12  3  7
After the next six numbers are drawn (17, 23, 2, 0, 14, and 21), there are still no winners:

22 13 17 11  0         3 15  0  2 22        14 21 17 24  4
 8  2 23  4 24         9 18 13 17  5        10 16 15  9 19
21  9 14 16  7        19  8  7 25 23        18  8 23 26 20
 6 10  3 18  5        20 11 10 24  4        22 11 13  6  5
 1 12 20 15 19        14 21 16 12  6         2  0 12  3  7
Finally, 24 is drawn:

22 13 17 11  0         3 15  0  2 22        14 21 17 24  4
 8  2 23  4 24         9 18 13 17  5        10 16 15  9 19
21  9 14 16  7        19  8  7 25 23        18  8 23 26 20
 6 10  3 18  5        20 11 10 24  4        22 11 13  6  5
 1 12 20 15 19        14 21 16 12  6         2  0 12  3  7
At this point, the third board wins because it has at least one complete row or column of marked numbers (in this case, the entire
top row is marked: 14 21 17 24 4).

The score of the winning board can now be calculated. Start by finding the sum of all unmarked numbers on that board; in this case,
the sum is 188. Then, multiply that sum by the number that was just called when the board won, 24, to get the final score, 188 * 24
= 4512.

To guarantee victory against the giant squid, figure out which board will win first. What will your final score be if you choose
that board?
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Bingo_Board.h"
/*
// Function Declarations
void new_board(std::vector<BingoBoard> &bb, std::vector<std::vector<int>> &b, int &num, int &n);

int main(){
     //   Variable Declaration
     std::ifstream read("Day_4_Input_test.txt");
     std::string calls, sub;
     int num{0}, count{0}, b_count{1}, win_bb{0}, last_call{0}, win_score{0};
     std::stringstream c_str, bing_str;
     std::vector<int> num_calls, rows;
     std::vector<std::vector<int>> bingo;
     std::vector<std::string> input, hold; 
     std::vector<BingoBoard> boards;
     bool winner{false};
     
     //   open the Tet file and check if it is successfully opened.
     if(!read.is_open()){
          std::cerr << "File Failed to open!!!\nPlease check the file name and try again!!" << std::endl;
     }
     std::cout << "Input File Opened successfully" << std::endl;
     
     //   Tansfer the contents of the text file into a string vector to be manipulated.
     while(std::getline(read, calls)){
          input.push_back(calls);
     }
     
     std::cout << std::endl;
     
     //   Tke the firdt row of the text file and store the numbers within in a vector.
     //   This vector will be used to read out th bingo numbers for the game.
     c_str << input[0];
     
     while(c_str.good()){
          std::getline(c_str, sub, ',');
          num_calls.push_back(std::stoi(sub, nullptr, 10));
     }
     
     std::cout << std::endl;
     
     //   Erase the first two rows of the vector.
     //   They are not used in the next part as we only need to focus on the inputs for the bingo board.
     for(int i{0}; i<2; i++){
          input.erase(input.begin());
     }
     
     //   Take the values stored within the input vector string and trasfer them into the Bingo Board object vector.
     for(auto in:input){
          if(in.size() > 0){
               bing_str << in;
               while(bing_str >> num){
                    rows.push_back(num);
               }
               bingo.push_back(rows);
               rows.clear();
               bing_str.clear();
               // std::cout << std::endl;     
               count++;
               if(count == 5){
                    new_board(boards, bingo, b_count, count);
               }
          }
     }
     
     //   Check to determine the nombers were stored into the objects correctly.
     // std::cout << "Printing the Bingo Boards stored in vector: " << std::endl;
     // for(auto b:boards)
     //      b.display();
     
     //   The next step in the process is to start with the bingo input.
     //   take each number, and check to see if it is on the bingo board.
     //   use a nested for loop to go through the columns and rows of the boards.
     
     //   main function is playing the bingo game
     //   will need inputs of the two main vectors - numbers to call and the Bingo Boards.
     
     /*   check
          read in recent number called and then search through each individual board using nested for loop
          first index is the row, second inner loop goes through each column.
          both iterated from 0 - 4.
          
          if the number is found, record the row and column position,
          Increment the corresponding position in the row and column vectors.
          check to see if the value in either row or column has reached 5. 
          If the value of any of the integers has reached 5, Winner has been found and the game is ended.
          otherwise break out of the loop and move onto the next board.
          
          van check with a boolean variable? or check at the end of each loop whether the game is won, also with boolean variable.
     
     do{
          // for(auto n:num_calls){
          for(int j = 0; (j < num_calls.size()) && (winner == false); j++){
               for(int i = 0; (i < boards.size()) && (winner == false); i++){
                    boards[i].call_check(num_calls[j]);
                    boards[i].win_con(winner);
                    if (winner == true) {
                         // win_bb = boards[i].b_num;
                         win_bb = i;
                         last_call = num_calls[j];
                    }
               }
               // for(auto b:boards){
                    // b.call_check(n);
                    // b.win_con();
               // }
          }
          
          std::cout << std::endl;
          
          std::cout << "Printing winning Board: "<< std::endl;
          boards[win_bb].display();
          
          std::cout << std::endl;
          
          win_score = boards[win_bb].score(last_call);
          std::cout << "Winning score was: " << win_score << '\n';
     }while(winner == false);
     
     // std::cout << "The winning board was: " << win_bb << std::endl
     //      << "Winning number that ended the game was: " << last_call << std::endl
     //      << "The final score of the winning Bingo board is: " << win_score << std::endl;
          
     std::cout << std::endl;
     
     return 0;
}

// Function Definitions
void new_board(std::vector<BingoBoard> &bb, std::vector<std::vector<int>> &b, int &num, int &n){
     bb.emplace_back(b, num);
     n = 0;
     num++;
     b.clear();
}
*/ 
/*
--- Part Two ---
On the other hand, it might be wise to try a different strategy: let the giant squid win.

You aren't sure how many bingo boards a giant squid could play at once, so rather than waste time counting its arms, the safe thing
to do is to figure out which board will win last and choose that one. That way, no matter which boards it picks, it will win for sure

In the above example, the second board is the last to win, which happens after 13 is eventually called and its middle column is
completely marked. If you were to keep playing until this point, the second board would have a sum of unmarked numbers equal to 148
for a final score of 148 * 13 = 1924.

Figure out which board will win last. Once it wins, what would its final score be?

Your puzzle answer was 2730.
*/
/*
// Function Declarations
void new_board(std::vector<BingoBoard> &bb, std::vector<std::vector<int>> &b, int &num, int &n);

int main(){
     //   Variable Declaration
     std::ifstream read("Day_4_Input.txt");
     std::string calls, sub;
     int num{0}, count{0}, b_count{1}, win_bb{0}, last_call{0}, win_score{0}, win_boards{0};
     std::stringstream c_str, bing_str;
     std::vector<int> num_calls, rows;
     std::vector<std::vector<int>> bingo;
     std::vector<std::string> input, hold; 
     std::vector<BingoBoard> boards;
     bool winner{false};
      
     //   open the Tet file and check if it is successfully opened.
     if(!read.is_open()){
          std::cerr << "File Failed to open!!!\nPlease check the file name and try again!!" << std::endl;
     }
     std::cout << "Input File Opened successfully" << std::endl;
      
     //   Tansfer the contents of the text file into a string vector to be manipulated.
     while(std::getline(read, calls)){
          input.push_back(calls);
     }
     std::cout << std::endl;
      
     //   Tke the firdt row of the text file and store the numbers within in a vector.
     //   This vector will be used to read out th bingo numbers for the game.
     c_str << input[0];
     while(c_str.good()){
          std::getline(c_str, sub, ',');
          num_calls.push_back(std::stoi(sub, nullptr, 10));
     }
     std::cout << std::endl;
      
     //   Erase the first two rows of the vector.
     //   They are not used in the next part as we only need to focus on the inputs for the bingo board.
     for(int i{0}; i<2; i++){
          input.erase(input.begin());
     }
      
      //   Take the values stored within the input vector string and trasfer them into the Bingo Board object vector.
     for(auto in:input){
          if(in.size() > 0){
               bing_str << in;
               while(bing_str >> num){
                    rows.push_back(num);
               }
               bingo.push_back(rows);
               rows.clear();
               bing_str.clear();
               count++;
               if(count == 5){
                    new_board(boards, bingo, b_count, count);
               }
          }
     }
      
     int total_wins = boards.size();
     do{
          for(int j = 0; (j < num_calls.size()) && (win_boards < total_wins); j++){
               for(int i = 0; (i < boards.size()) && (winner == false); i++){
                    boards[i].call_check(num_calls[j]);
                    boards[i].win_con(winner);
                    if (winner == true) {
                         win_bb = i;
                         last_call = num_calls[j];
                         win_boards++;
                         
                         std::cout << "Printing Board that just won: "<< std::endl;
                         boards[win_bb].display();
                         std::cout << std::endl;
                         
                         win_score = boards[win_bb].score(last_call);
                         std::cout << "Total of boards that have won the game currently is: " << win_boards << std::endl;
                         boards.erase(boards.begin() + i);
                         i--;
                         winner = false;
                         std::cout << std::endl;
                    }
               }
          }
     }while(win_boards < total_wins);           
      
     return 0;
} 
// Function Definitions
void new_board(std::vector<BingoBoard> &bb, std::vector<std::vector<int>> &b, int &num, int &n){
     bb.emplace_back(b, num);
     n = 0;
     num++;
     b.clear();
}
// void play_bingo()
*/