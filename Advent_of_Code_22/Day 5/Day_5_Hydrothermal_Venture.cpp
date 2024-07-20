/*
Advent of Code
--- Day 5: Hydrothermal Venture ---
You come across a field of hydrothermal vents on the ocean floor! These vents constantly produce large, opaque clouds, so it
would be best to avoid them if possible.

They tend to form in lines; the submarine helpfully produces a list of nearby lines of vents (your puzzle input) for you to
review. For example:

0,9 -> 5,9
8,0 -> 0,8
9,4 -> 3,4
2,2 -> 2,1
7,0 -> 7,4
6,4 -> 2,0
0,9 -> 2,9
3,4 -> 1,4
0,0 -> 8,8
5,5 -> 8,2
Each line of vents is given as a line segment in the format x1,y1 -> x2,y2 where x1,y1 are the coordinates of one end the line
segment and x2,y2 are the coordinates of the other end. These line segments include the points at both ends. In other words:

An entry like 1,1 -> 1,3 covers points 1,1, 1,2, and 1,3.
An entry like 9,7 -> 7,7 covers points 9,7, 8,7, and 7,7.
For now, only consider horizontal and vertical lines: lines where either x1 = x2 or y1 = y2.

So, the horizontal and vertical lines from the above list would produce the following diagram:

.......1..
..1....1..
..1....1..
.......1..
.112111211
..........
..........
..........
..........
222111....

In this diagram, the top left corner is 0,0 and the bottom right corner is 9,9. Each position is shown as the number of lines
which cover that point or . if no line covers that point. The top-left pair of 1s, for example, comes from 2,2 -> 2,1; the very
bottom row is formed by the overlapping lines 0,9 -> 5,9 and 0,9 -> 2,9.

To avoid the most dangerous areas, you need to determine the number of points where at least two lines overlap. In the above
example, this is anywhere in the diagram with a 2 or larger - a total of 5 points.

Consider only horizontal and vertical lines. At how many points do at least two lines overlap?
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_map>
#include "Points.h"

// Function Declarations
void split_string(std::string str, std::string first_Del, std::string sec_Del, int &s_x, int &s_y, int &e_x, int &e_y);
void split_points(std::string str, std::string Del, int &sp, int &ep);
void print_move(std::pair<int, char> mv, Points sp, Points ep);

// struct Points_Hasher{
//      size_t operator()(const Points& Input) const{
//           return std::hash<int>{}(Input.X) ^ (std::hash<int>{}(Input.Y) + 0xbeef);
//      }
// };

int main(){
     // Variable Declarations
     std::ifstream read("Day_5_Input_test.txt");
     std::vector<std::string> movement;
     std::string temp, del_main{" -> "}, del_sub{","};
     int x1, x2, y1, y2;
     std::pair<int, char> move_vect;
     std::unordered_map<Points, int> HydroVent;
     Points SPoint, EPoint;
     
     if(!read.is_open()){
          std::cerr << "File Failed " << std::endl;
     }
     std::cout << "File opened successfully" << std::endl;
     
     std::cout << "Reading in from input text files" << std::endl;
     while(std::getline(read, temp)) {
          movement.push_back(temp);
     }
     
     for(auto m:movement){
          split_string(m, del_main, del_sub, x1, y1, x2, y2);
          Points *temp1 = new Points(x1, y1);
          Points *temp2 = new Points(x2, y2);
          
          SPoint = *temp1; 
          EPoint = *temp2;
          
          move_vect = SPoint - EPoint;
          print_move(move_vect, SPoint, EPoint);
           
          delete temp1; delete temp2;
     }
     
     read.close();
     return 0;
}

void split_string(std::string str, std::string first_Del, std::string sec_Del, int &s_x, int &s_y, int &e_x, int &e_y){
     std::string first, second;
     size_t posit = str.find(first_Del), sec_posit = posit+first_Del.size();
     first = str.substr(0, posit);
     second = str.substr(sec_posit, str.size());
     
     split_points(first, sec_Del, s_x, s_y);
     split_points(second, sec_Del, e_x, e_y);
}
void split_points(std::string str, std::string Del, int &sp, int &ep){
     size_t posit = str.find(Del), sec_posit = posit+Del.size();
     sp = std::stoi(str.substr(0,posit));
     ep = std::stoi(str.substr(sec_posit,str.size()));
}
void print_move(std::pair<int, char> mv, Points sp, Points ep){
     if(mv.second != 'N'){
          std::cout << "Moving from: " << sp << " to " << ep << std::endl
               << "Will be moving " << mv.second << ", " << mv.first << " spaces!" << std::endl;
     }else{
          std::cout << "No Movement allowed!" << std::endl;
     }
}
// void hv_verify()