#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <string>

// Function Declaration
bool nice_list(std::string str);
bool vowel_crit(std::string str);
bool double_crit(std::string str);
bool pattern_crit(std::string str);

bool rsl_crit(std::string str);
bool pair_crit(std::string str);
bool nice_list_modded(std::string str);

int main(){
    // Variable Declaration
    std::ifstream read("Day_5_Input.txt");
    std::string str;
    std::uint16_t total_nice(0), total_nice_modded(0);

    if(!read.is_open()){
        std::cerr << "Failed to open file uccessfully" << std::endl;
        return 1;
    }else{
        std::cout << "File Opened Successfully" << std::endl;
    }

    while (!read.eof()){
        read >> str;
        if(nice_list(str))
            total_nice++;
        if(nice_list_modded(str)){
            total_nice_modded++;
        }
    }
    std::cout << "Total number of strings that are nice are:\t\t" << total_nice << std::endl
        << "Total number of strings that are nice using the modded method are:\t\t" << total_nice_modded << std::endl << std::endl;

    return 0;
}

// Function Definition
bool nice_list(std::string str){
    std::uint16_t count(0);
    if(vowel_crit(str))
        count++;
    if(double_crit(str))
        count++;
    if(!pattern_crit(str))
        count++;
    if(count >=3)
        return true;
    return false;
}
bool vowel_crit(std::string str){
    std::string vowels("aeiou");
    std::uint16_t v_count(0);
    for(auto s:str){
        for(auto v:vowels){
            if(s == v){
                v_count++;
                if(v_count >= 3)
                    return true;
            }
        }
    }
    return false;
}
bool double_crit(std::string str){
    for(std::uint16_t i(0); i < str.length() - 1; i++){
        if(str[i] == str[i + 1])
            return true;
    }
    return false;
}
bool pattern_crit(std::string str){
    // key words: ab, cd, pq, xy
    for(std::uint16_t i(0); i < str.length() - 1; i++){
        if((str[i] == 'a') && (str[i+1] == 'b'))
            return true;
        if((str[i] == 'c') && (str[i+1] == 'd'))
            return true;
        if((str[i] == 'p') && (str[i+1] == 'q'))
            return true;
        if((str[i] == 'x') && (str[i+1] == 'y'))
            return true;
    }
    return false;
}

bool rsl_crit(std::string str){
    for(std::uint16_t i(0); i < str.length() - 2; i++){
        if(str[i] == str[i+2]){
            // std::cout << str << "\t\t met the RSL criteria" << std::endl;
            return true;
        }
    }
    return false;
}
bool pair_crit(std::string str){
    for(std::uint16_t i(0); i < str.length() - 3; i++){
        for(std::uint16_t j(i + 2); j < str.length() - 1; j++){
            if((str[i] == str[j]) && (str[i+1] == str[j+1]))
                return true;
        }
    }
    return false;
}
bool nice_list_modded(std::string str){
    std::uint16_t count(0);
    if(rsl_crit(str))
        count++;
    if(pair_crit(str))
        count++;
    if(count >= 2)
        return true;    
    return false;
}