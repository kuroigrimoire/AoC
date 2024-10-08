/**
 * @file Day_1_Calorie_Counting.cpp
 * @author Sable
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * --- Day 1: Calorie Counting ---
 * 
 * Santa's reindeer typically eat regular reindeer food, but they need a lot of magical energy to deliver presents on Christmas. 
 * For that, their favorite snack is a special type of star fruit that only grows deep in the jungle. The Elves have brought you
 * on their annual expedition to the grove where the fruit grows.
 * 
 * To supply enough magical energy, the expedition needs to retrieve a minimum of fifty stars by December 25th. Although the
 * Elves assure you that the grove has plenty of fruit, you decide to grab any fruit you see along the way, just in case.
 * 
 * Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle
 * is unlocked when you complete the first. Each puzzle grants one star. Good luck!
 * 
 * The jungle must be too overgrown and difficult to navigate in vehicles or access from the air; the Elves' expedition
 * traditionally goes on foot. As your boats approach land, the Elves begin taking inventory of their supplies. One important
 * consideration is food - in particular, the number of Calories each Elf is carrying (your puzzle input).
 * 
 * The Elves take turns writing down the number of Calories contained by the various meals, snacks, rations, etc. that they've
 * brought with them, one item per line. Each Elf separates their own inventory from the previous Elf's inventory (if any) by
 * a blank line.
 * 
 * For example, suppose the Elves finish writing their items' Calories and end up with the following list:
 * 
 * 1000
 * 2000
 * 3000
 * 
 * 4000
 * 
 * 5000
 * 6000
 * 
 * 7000
 * 8000
 * 9000
 * 
 * 10000
 * 
 * This list represents the Calories of the food carried by five Elves:
 * 
 *     The first Elf is carrying food with 1000, 2000, and 3000 Calories, a total of 6000 Calories.
 *     The second Elf is carrying one food item with 4000 Calories.
 *     The third Elf is carrying food with 5000 and 6000 Calories, a total of 11000 Calories.
 *     The fourth Elf is carrying food with 7000, 8000, and 9000 Calories, a total of 24000 Calories.
 *     The fifth Elf is carrying one food item with 10000 Calories.
 * 
 * In case the Elves get hungry and need extra snacks, they need to know which Elf to ask: they'd like to know how many Calories
 * are being carried by the Elf carrying the most Calories. In the example above, this is 24000 (carried by the fourth Elf).
 * 
 * Find the Elf carrying the most Calories. How many total Calories is that Elf carrying?
 * 
 * 
 * Your puzzle answer was 64929.
 * 
 * --- Part Two ---
 * 
 * By the time you calculate the answer to the Elves' question, they've already realized that the Elf carrying
 * the most Calories of food might eventually run out of snacks.
 * 
 * To avoid this unacceptable situation, the Elves would instead like to know the total Calories carried by the
 * top three Elves carrying the most Calories. That way, even if one of those Elves runs out of snacks, they
 * still have two backups.
 * 
 * In the example above, the top three Elves are the fourth Elf (with 24000 Calories), then the third Elf (with
 * 11000 Calories), then the fifth Elf (with 10000 Calories). The sum of the Calories carried by these three
 * elves is 45000.
 * 
 * Find the top three Elves carrying the most Calories. How many Calories are those Elves carrying in total?
 * 
 * Your puzzle answer was 193697.
 *  
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

int main(){
    // uint16_t input(0), sum(0), max_C(0), elf(0);
    uint16_t input(0), sum(0), max_C(0), second_C(0), third_C(0), elf_1(0), elf_2(0), elf_3(0);
    uint64_t calorie_sum(0);
    std::vector<uint16_t> elves;
    // std::ifstream read("Day_1_Test_Input.txt");
    std::ifstream read("Day_1_Input.txt");
    std::string input_text;
    // char exc{'\n'};

    #if 0
    #endif

    if(!read.is_open()){
        std::cerr << "Problem occured opening file!!" << std::endl;
        return 1;
    }
    std::cout << "File successfully Opened!\nNow importing data into vector\n\n";
    
    while(!read.eof()){
        std::getline(read, input_text);
        // std::cout << input_text << std::endl;
        if(input_text.size() > 1){
            // std::cout << "Reading in: " << input_text << " from file and storing into input\t\t";
            input = std::stoi(input_text);
            // std::cout << "input = " << input << std::endl;
            sum += input;
        }else{
            elves.push_back(sum);
            sum = 0;
        }
    }
    // elves.push_back(sum);
    // sum = 0;

    std::cout << "Elf calorie input has been collected and summed. Listing Elf and total calories they are carrying:\n";
    for (size_t i = 0; i < elves.size(); i++){
        std::cout << "Elf #" << i+1 << ":\t\t" << elves[i] << std::endl;
    }
    for (size_t i = 0; i < elves.size(); i++){
        if(max_C < elves[i]){
            third_C = second_C;
            elf_3 = elf_2;
            elf_2 = elf_1;
            second_C = max_C;
            max_C = elves[i];
            // elf = i+1;
            elf_1 = i+1;
        }
        if(elves[i]< max_C){
            if(second_C < elves[i]){
                third_C = second_C;
                elf_3 = elf_2;
                elf_2 = i+1;
                second_C = elves[i];
            }
        }if(elves[i]<second_C){
            if(third_C < elves[i])
                third_C = elves[i];
                elf_3 = i+1;
        }
    }

    calorie_sum = max_C + second_C + third_C;

    // std::cout <<std::endl << "Elf #: " << elf << " is carrying the most calories with a total of: " << max_C << std::endl;
    std::cout << std::endl << "Elf #: " << elf_1 << " is carrying the most calories with a total of: " << max_C << std::endl;
    std::cout << "Elf #: " << elf_2 << " is carrying the second most calories with a total of: " << second_C << std::endl;
    std::cout << "Elf #: " << elf_3 << " is carrying the third most calories with a total of: " << third_C << std::endl;

    std::cout << std::endl << "Total number of calories being caried by the trio is:\t" << calorie_sum << std::endl; 
    
    return 0;
}