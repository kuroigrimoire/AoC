/**
 * @file Day_3_Rucksack_Reorganization.cpp
 * @author Sable
 * @brief 
 * @version 0.1
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * --- Day 3: Rucksack Reorganization ---
 * 
 * One Elf has the important job of loading all of the rucksacks with supplies for the jungle journey. 
 * Unfortunately, that Elf didn't quite follow the packing instructions, and so a few items now need to be
 * rearranged.
 * 
 * Each rucksack has two large compartments. All items of a given type are meant to go into exactly one of the
 * two compartments. The Elf that did the packing failed to follow this rule for exactly one item type per
 * rucksack.
 * 
 * The Elves have made a list of all of the items currently in each rucksack (your puzzle input), but they need
 * your help finding the errors. Every item type is identified by a single lowercase or uppercase letter (that
 * is, a and A refer to different types of items).
 * 
 * The list of items for each rucksack is given as characters all on a single line. A given rucksack always has
 * the same number of items in each of its two compartments, so the first half of the characters represent items
 * in the first compartment, while the second half of the characters represent items in the second compartment.
 * 
 * For example, suppose you have the following list of contents from six rucksacks:
 * 
 * vJrwpWtwJgWrhcsFMMfFFhFp
 * jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
 * PmmdzqPrVvPwwTWBwg
 * wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
 * ttgJtRGJQctTZtZT
 * CrZsJsPPZsGzwwsLwLmpwMDw
 * 
 *     The first rucksack contains the items vJrwpWtwJgWrhcsFMMfFFhFp, which means its first compartment
 *     contains the items vJrwpWtwJgWr, while the second compartment contains the items hcsFMMfFFhFp. The only
 *     item type that appears in both compartments is lowercase p.
 *     The second rucksack's compartments contain jqHRNqRjqzjGDLGL and rsFMfFZSrLrFZsSL. The only item type
 *     that appears in both compartments is uppercase L.
 *     The third rucksack's compartments contain PmmdzqPrV and vPwwTWBwg; the only common item type is uppercase P.
 *     The fourth rucksack's compartments only share item type v.
 *     The fifth rucksack's compartments only share item type t.
 *     The sixth rucksack's compartments only share item type s.
 * 
 * To help prioritize item rearrangement, every item type can be converted to a priority:
 * 
 *     Lowercase item types a through z have priorities 1 through 26.
 *     Uppercase item types A through Z have priorities 27 through 52.
 * 
 * In the above example, the priority of the item type that appears in both compartments of each rucksack is 16
 * (p), 38 (L), 42 (P), 22 (v), 20 (t), and 19 (s); the sum of these is 157.
 * 
 * Find the item type that appears in both compartments of each rucksack. What is the sum of the priorities of
 * those item types?
 *  
 */

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
// #include <sstream>

void find_item(const std::string& first, const std::string& second, uint8_t& k);

int main(){
    std::ifstream read("Day_3_Test_Input.txt");
    // std::ifstream read("Day_3_Input.txt");
    std::unordered_map<uint8_t, uint16_t> alpha_key;
    uint8_t alpha{97}, key{65};
    uint16_t pri{1}, len{0};
    uint32_t priorities{0};
    // std::stringstream iss;
    std::string line, f_comp, s_comp;

    for (size_t i = 0; i < 26; i++){
        alpha_key.insert({alpha, pri});
        alpha++;
        pri++;
    }
    alpha = 65;
    for (size_t i = 0; i < 26; i++){
        alpha_key.insert({alpha, pri});
        alpha++;
        pri++;
    }

    #if 0
    for(auto x: alpha_key)
        std::cout << x.first << "\t" << x.second << std::endl;
    #endif
    if(!read.is_open()){
        std::cerr << "Input file Failed to open.\nPlease check the name and location, then try again!\n";
        return 1;
    }
    std::cout << "File opened successfully!\n";

    while(!read.eof()){
        std::getline(read, line);
        len = line.size()/2;
        f_comp = line.substr(0, len);
        s_comp = line.substr(len, len);
        find_item(f_comp, s_comp, key);
        std::cout << f_comp << '\t' << s_comp << "\tduplicate item was: " << key << std::endl; 

    }

    return 0;
}


void find_item(const std::string& first, const std::string& second, uint8_t& k){
    uint16_t position{0};
    for(auto s:second){
        position = first.find(s);
        if(position != std::string::npos)
            k = first[position];
    }
    // k = 'A';
}