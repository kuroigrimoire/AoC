// Advent of Code
// --- Day 3: Binary Diagnostic ---

// --- Part One ---
/*
The submarine has been making some odd creaking noises, so you ask it to produce a diagnostic report just in case.

The diagnostic report (your puzzle input) consists of a list of binary numbers which, when decoded properly, can tell you many
useful things about the conditions of the submarine. The first parameter to check is the power consumption.

You need to use the binary numbers in the diagnostic report to generate two new binary numbers (called the gamma rate and the
epsilon rate). The power consumption can then be found by multiplying the gamma rate by the epsilon rate.

Each bit in the gamma rate can be determined by finding the most common bit in the corresponding position of all numbers in the
diagnostic report. For example, given the following diagnostic report:

00100
11110
10110
10111
10101
01111
00111
11100
10000
11001
00010
01010

Considering only the first bit of each number, there are five 0 bits and seven 1 bits. Since the most common bit is 1, the
first bit of the gamma rate is 1.

The most common second bit of the numbers in the diagnostic report is 0, so the second bit of the gamma rate is 0.

The most common value of the third, fourth, and fifth bits are 1, 1, and 0, respectively, and so the final three bits of the
gamma rate are 110.

So, the gamma rate is the binary number 10110, or 22 in decimal.

The epsilon rate is calculated in a similar way; rather than use the most common bit, the least common bit from each position
is used. So, the epsilon rate is 01001, or 9 in decimal. Multiplying the gamma rate (22) by the epsilon rate (9) produces the
power consumption, 198.

Use the binary numbers in your diagnostic report to calculate the gamma rate and epsilon rate, then multiply them together.
What is the power consumption of the submarine? (Be sure to represent your answer in decimal, not binary.)
*/

/*
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdint>
#include<bitset>

int main(){
     std::ifstream read ("Day_3_Input.txt");
     std::string line;
     std::vector<int> numbers, count_0(12, 0), count_1(12, 0);
     std::vector<std::uint16_t> masks {0b0000'1000'0000'0000};
     int count{0}, pcon{0};
     
     for (size_t i = 0; i < 11; i++) {
          masks.push_back(masks[i] >> 1);
     }
     
     std::cout << std::endl;
     
     std::cout << "Opening Input File!" << std::endl;
     if(!read.is_open()){
          std::cerr << "Failed to open Input File!!! Please check the File name/path and try again!" << std::endl;
          return 1;
     }
     std::cout << "Input File was successfully opened! Beginning analysis." << std::endl;
               
     std::cout << std::endl;
     while(std::getline(read, line)){
          numbers.push_back(std::stoi(line, nullptr, 2));
          for(int i{0}; i < 12; i++){
               (numbers[count] & masks[i]) ? count_1[i]++ : count_0[i]++;
          }
          count++;
     }
          
     std::cout << "Printing out results: " << std::endl;
     for(auto c:count_0){
          std::cout << '\t' << c;
     }
     
     std::cout << std::endl;
     
     for(auto c:count_1){
          std::cout << '\t' << c;
     }
     
     std::cout << std::endl;
     
     std::uint16_t gamma {0b0000'0000'0000'0000};
     std::uint16_t epsilon {0b0000'0000'0000'0000};
     
     for(int x{0}; x < 12; x++){
          if(count_1[x] > count_0[x]){
               gamma |= masks[x];
          }else if(count_1[x] < count_0[x]){
               epsilon |= masks[x];
          }
     }
     std::bitset<16> x = gamma;
     std::bitset<16> y = epsilon;
     
     std::cout << "Gamma rate: " << gamma << " and in binary: " << x << std::endl;
     std::cout << "Epsilon rate: " << epsilon << " and in binary: " << y << std::endl;
     
     pcon = gamma * epsilon;
     
     std::cout << "Power Consumption rate: " << pcon << std::endl;
          
     std::cout << std::endl;
          
     return 0;
}
*/

// --- Part Two ---
/*
Next, you should verify the life support rating, which can be determined by multiplying the oxygen generator rating by the CO2
scrubber rating.

Both the oxygen generator rating and the CO2 scrubber rating are values that can be found in your diagnostic report - finding
them is the tricky part. Both values are located using a similar process that involves filtering out values until only one remains.
Before searching for either rating value, start with the full list of binary numbers from your diagnostic report and consider just
the first bit of those numbers. Then:

-    Keep only numbers selected by the bit criteria for the type of rating value for which you are searching. Discard numbers which
do not match the bit criteria.
-    If you only have one number left, stop; this is the rating value for which you are searching.
-    Otherwise, repeat the process, considering the next bit to the right.

The bit criteria depends on which type of rating value you want to find:

-    To find oxygen generator rating, determine the most common value (0 or 1) in the current bit position, and keep only numbers 
with that bit in that position. If 0 and 1 are equally common, keep values with a 1 in the position being considered.
-    To find CO2 scrubber rating, determine the least common value (0 or 1) in the current bit position, and keep only numbers with
that bit in that position. If 0 and 1 are equally common, keep values with a 0 in the position being considered.

For example, to determine the oxygen generator rating value using the same example diagnostic report from above:

-    Start with all 12 numbers and consider only the first bit of each number. There are more 1 bits (7) than 0 bits (5), so keep
only the 7 numbers with a 1 in the first position: 11110, 10110, 10111, 10101, 11100, 10000, and 11001.
-    Then, consider the second bit of the 7 remaining numbers: there are more 0 bits (4) than 1 bits (3), so keep only the 4 numbers
with a 0 in the second position: 10110, 10111, 10101, and 10000.
-    In the third position, three of the four numbers have a 1, so keep those three: 10110, 10111, and 10101.
-    In the fourth position, two of the three numbers have a 1, so keep those two: 10110 and 10111.
-    In the fifth position, there are an equal number of 0 bits and 1 bits (one each). So, to find the oxygen generator rating, keep
the number with a 1 in that position: 10111.
-    As there is only one number left, stop; the oxygen generator rating is 10111, or 23 in decimal.

Then, to determine the CO2 scrubber rating value from the same example above:

-    Start again with all 12 numbers and consider only the first bit of each number. There are fewer 0 bits (5) than 1 bits (7), so
keep only the 5 numbers with a 0 in the first position: 00100, 01111, 00111, 00010, and 01010.
-    Then, consider the second bit of the 5 remaining numbers: there are fewer 1 bits (2) than 0 bits (3), so keep only the 2 numbers
with a 1 in the second position: 01111 and 01010.
-    In the third position, there are an equal number of 0 bits and 1 bits (one each). So, to find the CO2 scrubber rating, keep the
number with a 0 in that position: 01010.
-    As there is only one number left, stop; the CO2 scrubber rating is 01010, or 10 in decimal.

Finally, to find the life support rating, multiply the oxygen generator rating (23) by the CO2 scrubber rating (10) to get 230.

Use the binary numbers in your diagnostic report to calculate the oxygen generator rating and CO2 scrubber rating, then multiply
them together. What is the life support rating of the submarine? (Be sure to represent your answer in decimal, not binary.)
*/

/*
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdint>
#include<bitset>

int main(){
     // std::ifstream read("Day_3_Input_test.txt");
     std::ifstream read("Day_3_Input.txt");
     std::string line;
     // std::vector<std::uint8_t> masks { 0b0001'0000};
     std::vector<std::uint16_t> masks { 0b0000'1000'0000'0000};
     std::vector<int> oxy_gen, co2_scrub, ox_pos, co2_pos;
     int oxy_count_1{0}, oxy_count_0{0}, co2_count_1{0}, co2_count_0{0}, lsr{0}, count{0};
     
     for(int m{0}; m < 11; m++){
          masks.push_back(masks[m] >> 1);
     }
     // std::cout << "Working with bits: " << std::endl;
     // std::bitset<8> x;
     // std::bitset<8> y;
     std::bitset<16> x;
     std::bitset<16> y;
     
     // for(auto b:masks){
     //      x = b;
     //      std::cout << "\t" << x << std::endl;
     // }
     std::cout << std::endl;
     
     while(std::getline(read, line)){
          oxy_gen.push_back(std::stoi(line, nullptr, 2));
          co2_scrub.push_back(std::stoi(line, nullptr, 2));
     }
     // std::cout << "Finished establishing vectors of Oxygen Generation rating and CO2 Scribbing rating" << std::endl;
     std::cout << std::endl;
     
     for(auto m:masks){
          y = m;
          for(int i{0}; i<oxy_gen.size(); i++){
               (oxy_gen[i] & m) ? oxy_count_1++ : oxy_count_0++;
          }
          // std::cout << "Ox rating bit " << count+1 << " count (1s):\t " << oxy_count_1 << "\tcount (0s):\t" << oxy_count_0 << std::endl;
          for(int i{0}; i < co2_scrub.size(); i++){
               (co2_scrub[i] & m) ? co2_count_1++ : co2_count_0++;
          }
          // std::cout << "Co2 rating bit " << count+1 << " count (1s):\t " << co2_count_1 << "\tcount (0s):\t" << co2_count_0 << std::endl;
          // std::cout << "Editing vectors" << std::endl;

               if(oxy_count_1 >= oxy_count_0){
                    int ox_posit{0};
                    // std::cout << "Oxygen bits that pass criteria " << count+1 << ": " << y << std::endl;
                    for(auto ox:oxy_gen){
                         if(ox & m){
                              x = ox;
                              // std::cout << "\t" << x << std::endl;
                         }else if(~(ox & m)){
                              x = ox;
                              // std::cout << "Failed binary: " << x << "\tFound at position: " << posit << std::endl;
                              ox_pos.insert(ox_pos.begin(), ox_posit);
                         }
                         ox_posit++;
                    }
                    // std::cout << " Vector positons: " << '\t';
                    for(int x = 0; x < (ox_pos.size()) ; x++){
                         // std::cout << pos[x] << '\t';
                    }
                    // std::cout << std::endl;
                    // std::cout << std::endl;
                    
               }else if(oxy_count_1 < oxy_count_0){
                    int ox_posit{0};
                    // std::cout << "Oxygen bits that pass criteria " << count+1 << ": " << y << std::endl;
                    for(auto ox:oxy_gen){
                         if(ox & m){
                              x = ox;
                              // std::cout << "Failed binary: " << x << "\tFound at position: " << posit << std::endl;
                              ox_pos.insert(ox_pos.begin(), ox_posit);
                         }else if(~(ox & m)){
                              x = ox;
                              // std::cout << "\t" << x << std::endl;
                         }
                         ox_posit++;
                    }
                    // std::cout << "Vector positons: " << '\t';
                    // for(int x = 0; x < (pos.size()) ; x++){
                    //      std::cout << pos[x] << '\t';
                    // }
               
                    // std::cout << std::endl;
                    // std::cout << std::endl;
               
               }
               // std::cout << std::endl;
               
               // for(auto v: oxy_gen){
               //      x = v;
               //      std::cout << x << '\t';
               // }
               // std::cout << std::endl;
               
               auto it_ox = ox_pos.begin();
               while(it_ox != ox_pos.end()){
                    // x = oxy_gen[*it-1];
                    // std::cout << "Removing binary: " << x << " at position: " << *it << std::endl;
                    oxy_gen.erase(oxy_gen.begin() + (*it_ox));
                    // std::cout << "Remaining numbers: ";
                    // for(auto v: oxy_gen){
                    //      x = v;
                    //      std::cout << x << '\t';
                    // }
                    // std::cout << std::endl;
                         
                    it_ox++;                                   
               }
          // }while(oxy_gen.size() > 0)
          
               if(co2_count_1 >= co2_count_0){
                    int co2_posit{0};
                    // std::cout << "Oxygen bits that pass criteria " << count+1 << ": " << y << std::endl;
                    for(auto co2:co2_scrub){
                         if(co2 & m){
                              x = co2;
                              // std::cout << "Failed binary: " << x << "\tFound at position: " << posit << std::endl;
                              co2_pos.insert(co2_pos.begin(), co2_posit);
                         }else if(~(co2 & m)){
                              x = co2;
                              // std::cout << "\t" << x << std::endl;
                         }
                         co2_posit++;
                    }
                    // std::cout << " Vector positons: " << '\t';
                    // for(int x = 0; x < (co2_pos.size()) ; x++){
                         // std::cout << pos[x] << '\t';
                    // }
                    // std::cout << std::endl;
                    // std::cout << std::endl;
                    
               }else if(co2_count_1 < co2_count_0){
                    int co2_posit{0};
                    // std::cout << "Oxygen bits that pass criteria " << count+1 << ": " << y << std::endl;
                    for(auto co2:co2_scrub){
                         if(co2 & m){
                              x = co2;
                              // std::cout << "\t" << x << std::endl;
                         }else if(~(co2 & m)){
                              x = co2;
                              // std::cout << "Failed binary: " << x << "\tFound at position: " << posit << std::endl;
                              co2_pos.insert(co2_pos.begin(), co2_posit);
                         }
                         co2_posit++;
                    }
                    // std::cout << "Vector positons: " << '\t';
                    // for(int x = 0; x < (pos.size()) ; x++){
                    //      std::cout << pos[x] << '\t';
                    // }
               
                    // std::cout << std::endl;
                    // std::cout << std::endl;
               
               }
               // std::cout << std::endl;
               
               // for(auto v: oxy_gen){
               //      x = v;
               //      std::cout << x << '\t';
               // }
               // std::cout << std::endl;
               
               auto it_co2 = co2_pos.begin();
               while(it_co2 != co2_pos.end()){
                    // x = oxy_gen[*it-1];
                    // std::cout << "Removing binary: " << x << " at position: " << *it << std::endl;
                    co2_scrub.erase(co2_scrub.begin() + (*it_co2));
                    // std::cout << "Remaining numbers: ";
                    // for(auto v: oxy_gen){
                    //      x = v;
                    //      std::cout << x << '\t';
                    // }
                    // std::cout << std::endl;
                         
                    it_co2++;                                   
          }
     
          // }while(co2_scrub.size() > 0)
               
          // std::cout << "Current vector list:" << std::endl;
          // for(auto vec:oxy_gen){
          //      x = vec;
          //      std::cout << "\t" << x << std::endl;
          // }
          // std::cout << std::endl;
          
          // resets
          ox_pos.clear();
          co2_pos.clear();
          oxy_count_0 = 0; oxy_count_1 = 0;
          co2_count_0 = 0; co2_count_1 = 0;
          count++;
     }
     std::cout << std::endl;
     
     std::cout << "Length of oxy_gen: " << oxy_gen.size() << std::endl;
     std::cout << "Length of co2_scrub: " << co2_scrub.size() << std::endl;
     
     x = oxy_gen[0];
     y = co2_scrub[0];
     lsr = oxy_gen[0] * co2_scrub[0];
     
     std::cout << "Oxygen rating: \t" << oxy_gen[0] << "\t\t\tIn Binary: " << x << std::endl
          << "CO2 Scubber rating: \t" << co2_scrub[0] << "\t\tIn Binary: " << y << std::endl
          << "Life Support Rating: \t" << lsr << std::endl;
          
     std::cout << std::endl;
     
     return 0;
}
*/