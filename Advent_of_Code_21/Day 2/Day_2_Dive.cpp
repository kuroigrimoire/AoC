/*
Advent of Code
--- Day 2: Dive! ---
Now, you need to figure out how to pilot this thing.

It seems like the submarine can take a series of commands like forward 1, down 2, or up 3:

forward X increases the horizontal position by X units.
down X increases the depth by X units.
up X decreases the depth by X units.

Note that since you're on a submarine, down and up affect your depth, and so they have the opposite result of what you might expect.

The submarine seems to already have a planned course (your puzzle input). You should probably figure out where it's going. For example:

forward 5
down 5
forward 8
up 3
down 8
forward 2

Your horizontal position and depth both start at 0. The steps above would then modify them as follows:

forward 5 adds 5 to your horizontal position, a total of 5.
down 5 adds 5 to your depth, resulting in a value of 5.
forward 8 adds 8 to your horizontal position, a total of 13.
up 3 decreases your depth by 3, resulting in a value of 2.
down 8 adds 8 to your depth, resulting in a value of 10.
forward 2 adds 2 to your horizontal position, a total of 15.

After following these instructions, you would have a horizontal position of 15 and a depth of 10. (Multiplying these together 
produces 150.)

Calculate the horizontal position and depth you would have after following the planned course. What do you get if you multiply 
your final horizontal position by your final depth?
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<numeric>

/*
int main(){
     std::string line, direct;
     std::vector<int> for_vec, down_vec, up_vec;
     
     int str_val{0}, hori{0}, depth{0}, down{0}, up{0}, final{0};
     
     std::ifstream read;
     
     read.open("Day_2_Input.txt");
     if(!read.is_open()){
          std::cerr << "Failed to Open file, Check file name/path, and try again!" << std::endl;
          return 1;
     }
     std::cout << "File opened successfully. You may continue with your work." << std::endl;
     
     std::cout << std::endl;
     
     while(std::getline(read, line)){
          direct = line.substr(0, line.find(" "));
          line.erase(0, line.find(" ") + 1);          
          str_val = std::stoi(line);
          
          if(direct == "forward"){
               for_vec.push_back(str_val);
          }else if(direct == "down"){
               down_vec.push_back(str_val);
          }else if(direct == "up"){
               up_vec.push_back(str_val);
          } 
     }
     
     std::cout << std::endl;
     
     hori = std::accumulate(for_vec.begin(), for_vec.end(), 0);
     down = std::accumulate(down_vec.begin(), down_vec.end(), 0);
     up = std::accumulate(up_vec.begin(), up_vec.end(), 0);
     
     depth = down - up;
     final = hori * depth;
     std::cout << "The final value and position will be: " << final << std::endl;
     
     std::cout << std::endl;
     
     read.close();
     
     return 0;
}
*/
/*

--- Part Two ---
Based on your calculations, the planned course doesn't seem to make any sense. You find the submarine manual and discover that the
process is actually slightly more complicated.

In addition to horizontal position and depth, you'll also need to track a third value, aim, which also starts at 0. The commands
also mean something entirely different than you first thought:

down X increases your aim by X units.
up X decreases your aim by X units.
forward X does two things:
It increases your horizontal position by X units.
It increases your depth by your aim multiplied by X.
Again note that since you're on a submarine, down and up do the opposite of what you might expect: "down" means aiming in the positive
direction.

Now, the above example does something different:

forward 5 adds 5 to your horizontal position, a total of 5. Because your aim is 0, your depth does not change.
down 5 adds 5 to your aim, resulting in a value of 5.
forward 8 adds 8 to your horizontal position, a total of 13. Because your aim is 5, your depth increases by 8*5=40.
up 3 decreases your aim by 3, resulting in a value of 2.
down 8 adds 8 to your aim, resulting in a value of 10.
forward 2 adds 2 to your horizontal position, a total of 15. Because your aim is 10, your depth increases by 2*10=20 to a total of
60.
After following these new instructions, you would have a horizontal position of 15 and a depth of 60. (Multiplying these produces 900.)

Using this new interpretation of the commands, calculate the horizontal position and depth you would have after following the planned
 course. What do you get if you multiply your final horizontal position by your final depth?

*/

/*
int main(){
     std::string line, direct;
     std::ifstream read;
     int num{0}, hori{0}, aim{0}, depth{0}, end_pos{0};
     
     // read.open("Day_2_Input_test.txt");
     read.open("Day_2_Input.txt");
     if(!read.is_open()){
          std::cerr << "Failed to Open Input File!!! Check Name and try again!" << std::endl;
          return 1;
     }
     std::cout << "File Opened successfully! \nNow beginning to process data!." << std::endl;
     
     std::cout << std::endl;
     
     while(std::getline(read, line)){
          direct = line.substr(0, line.find(" "));
          line.erase(0, line.find(" ") + 1);
          num = std::stoi(line);
          
          if(direct == "forward"){
               if(aim == 0){
                    hori += num;
               }else{
                    hori += num;
                    depth = depth + num * aim;
               }
          }else if(direct == "down"){
               aim += num;
          }else if(direct == "up"){
               aim -= num;
          }
     }
     
     std::cout << std::endl;
     
     end_pos = hori * depth;
     std::cout << "Final Horizontal: " << hori << "\tFinal Depth: " << depth << "\tFinal Position: " << end_pos << std::endl;
     
     std::cout << std::endl;
     
     read.close();
     
     return 0;
}
*/
