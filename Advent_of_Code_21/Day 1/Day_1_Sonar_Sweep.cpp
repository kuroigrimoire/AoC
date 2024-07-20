/*
Advent of Code

--- Day 1: Sonar Sweep ---
You're minding your own business on a ship at sea when the overboard alarm goes off! You rush to see if you can help. Apparently,
one of the Elves tripped and accidentally sent the sleigh keys flying into the ocean!

Before you know it, you're inside a submarine the Elves keep ready for situations like this. It's covered in Christmas lights
(because of course it is), and it even has an experimental antenna that should be able to track the keys if you can boost its signal
strength high enough; there's a little meter that indicates the antenna's signal strength by displaying 0-50 stars.

Your instincts tell you that in order to save Christmas, you'll need to get all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is
unlocked when you complete the first. Each puzzle grants one star. Good luck!

As the submarine drops below the surface of the ocean, it automatically performs a sonar sweep of the nearby sea floor. On a small
screen, the sonar sweep report (your puzzle input) appears: each line is a measurement of the sea floor depth as the sweep looks
further and further away from the submarine.

For example, suppose you had the following report:

199
200
208
210
200
207
240
269
260
263
This report indicates that, scanning outward from the submarine, the sonar sweep found depths of 199, 200, 208, 210, and so on.

The first order of business is to figure out how quickly the depth increases, just so you know what you're dealing with - you
never know if the keys will get carried into deeper water by an ocean current or a fish or something.

To do this, count the number of times a depth measurement increases from the previous measurement. (There is no measurement
before the first measurement.) In the example above, the changes are as follows:

199 (N/A - no previous measurement)
200 (increased)
208 (increased)
210 (increased)
200 (decreased)
207 (increased)
240 (increased)
269 (increased)
260 (decreased)
263 (increased)
In this example, there are 7 measurements that are larger than the previous measurement.

How many measurements are larger than the previous measurement?
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

// int main() {
//      std::ifstream read;
//      std::string line;
// 
//      // Test
//      // read.open("Day_1_input_test.txt");
//      // Actual
//      read.open("Day_1_input.txt");
// 
//      if(!read.is_open()){
//           std::cerr << "Problem occured opening file!!" << std::endl;
//           return 1;
//      }
//      std::cout << "Input File opened successfully!" << std::endl;
// 
//      std::cout << std::endl;
// 
//      std::vector<int> inp;
//      int inc{0}, dec{0}, diff{0};
// 
//      while (std::getline(read, line)) {
//           inp.push_back(std::stoi(line));
//      }
// 
//      // Test related message
//      // std::cout << "Beginning analysis of depth measurements taken from Sonar Sweep" << std::endl
//      //      << "Sampels Data set from the Sonar provided the following measurements to analyze: " <<std::endl
//      //      << std::endl << "[ ";
//      // for(auto a:inp){
//      //      std::cout << a << " ";
//      // }
//      // std::cout << "]" << std::endl;
//      // 
//      // std::cout << std::endl;
// 
//      for (std::size_t i = 1; i < inp.size(); i++) {
//           diff = inp[i] - inp[i-1];
//           if(diff > 0){
//                // std::cout << "Depth Increase from " << inp[i-1] << " to " << inp[i] << std::endl;
//                inc++;
//           }else if(diff < 0){
//                // std::cout << "Depth Increase from " << inp[i-1] << " to " << inp[i] << std::endl;
//                dec++;
//           }else{
//                std::cout << "No depth increase or decrease" << std::endl;
//           }
//      }
// 
//      std::cout << std::endl;
// 
//      std::cout << "Increase: " << inc << std::endl;
//      std::cout << "Decrease: " << dec << std::endl;
// 
//      std::cout << std::endl;
// 
//      if (inc > dec) {
//           std::cout << inc << " Measurements were larger than their previous measurements" << std::endl;
//      } else {
//           std::cout << "A majority of the measurements were lower than the previous measurement" << std::endl;
//      }
// 
//      std::cout << std::endl;
// 
//      std::cout << "Closing input file " << std::endl;
//      read.close();
// 
//      std::cout << std::endl;
// 
//      return 0;
// }

/*
--- Part Two ---
Considering every single measurement isn't as useful as you expected: there's just too much noise in the data.

Instead, consider sums of a three-measurement sliding window. Again considering the above example:

199  A      
200  A B    
208  A B C  
210    B C D
200  E   C D
207  E F   D
240  E F G  
269    F G H
260      G H
263        H

Start by comparing the first and second three-measurement windows. The measurements in the first window are marked A (199, 200,
208); their sum is 199 + 200 + 208 = 607. The second window is marked B (200, 208, 210); its sum is 618. The sum of measurements
in the second window is larger than the sum of the first, so this first comparison increased.

Your goal now is to count the number of times the sum of measurements in this sliding window increases from the previous sum. So,
compare A with B, then compare B with C, then C with D, and so on. Stop when there aren't enough measurements left to create a new
three-measurement sum.

In the above example, the sum of each three-measurement window is as follows:

A: 607 (N/A - no previous sum)
B: 618 (increased)
C: 618 (no change)
D: 617 (decreased)
E: 647 (increased)
F: 716 (increased)
G: 769 (increased)
H: 792 (increased)
In this example, there are 5 sums that are larger than the previous sum.

Consider sums of a three-measurement sliding window. How many sums are larger than the previous sum?
*/

int main(){
     std::ifstream read;
     std::string line;
     std::vector<int> meas_vec, tmw_vec;
     int inc{0}, dec{0}, no_ch{0}, diff{0}, sum{0};
     
     // Test
     // read.open("Day_1_input_test.txt");
     // Actual
     read.open("Day_1_input.txt");
     
     if(!read.is_open()){
          std::cout << "Error opening input file!!!" << std::endl;
          return 1;
     }
     std::cout << "Opening of input file was successful!" << std::endl;
     std::cout << std::endl;
     
     while(std::getline(read, line)){
          meas_vec.push_back(std::stoi(line));
     }
     
     // take initial data set and conver to sliding window.
     for (size_t i = 2; i < meas_vec.size(); i++) {
          sum = meas_vec[i] + meas_vec[i-1] + meas_vec[i-2];
          tmw_vec.push_back(sum);
     }
     
     // Test related message
     // std::cout << "Beginning analysis of three-window measurements taken from Sonar Sweep" << std::endl
     //      << "Three-Window Measurement Data set from the Sonar provided the following measurements to analyze: " <<std::endl
     //      << std::endl << "[ ";
     // for(auto a:tmw_vec){
     //      std::cout << a << " ";
     // }
     // std::cout << "]" << std::endl;
     // 
     // std::cout << std::endl;

     // checks
     // std::cout << "length of TWM Vector:" << tmw_vec.size() << std::endl
     //      << "value of Increase:" << inc << std::endl
     //      << "value of Decrease:" << dec << std::endl
     //      << "value of No Change:" << no_ch << std::endl;
          
     std::cout << std::endl;
     
     for (size_t i = 1; i < tmw_vec.size(); i++) {
          // std::cout << "working with measuremeant in position " << i-1 << " (" << tmw_vec[i-1] << ") and position " << i << " ("  << tmw_vec[i] << ")\t\t";
          diff = tmw_vec[i] - tmw_vec[i-1];
          // std::cout << "Difference measured = " << diff << std::endl;
          if(diff > 0){
               std::cout << "Sum of depth measuremeant increase detected: " << tmw_vec[i] << " (increased)" << std::endl;
               inc++;
          }else if(diff < 0){
               std::cout << "Sum of depth measuremeant decrease detected: " << tmw_vec[i] << " (decreased)" << std::endl;
               dec++;
          }else if(diff == 0){
               std::cout << "Sum of depth measuremeant neither increased of decreased: " << tmw_vec[i] << " (no change)" << std::endl;
               no_ch++;
          }
     }
     
     // std::cout << std::endl;
     
     // checks
     // std::cout << "value of Increase:" << inc << std::endl
     //      << "value of Decrease:" << dec << std::endl
     //      << "value of No Change:" << no_ch << std::endl;
          
     // std::cout << std::endl;
     
     std::cout << inc << " sums are larger than the previous sum" << std::endl;
     
     std::cout << std::endl;
               
     return 0;
}