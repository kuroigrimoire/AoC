#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>
#include <regex>

// Function Declaration

int main(){
    // Variable Declaration
    bool light_grid[999][999] = {false};
    std::uint32_t lights(0);
    std::string input, direction;
    std::vector<std::uint16_t> numbers;
    std::regex reg_num(R"(\d+)");
    std::smatch match;

    std::ifstream read("Day_6_input.txt");
    if(!read.is_open()){
        std::cerr << "Failed to open file uccessfully" << std::endl;
        return 1;
    }else{
        std::cout << "File Opened Successfully" << std::endl;
    }

    while(!read.eof()){
        getline(read, input);
        direction = input;
        std::regex_search(input, match, reg_num);
        while(std::regex_search(input, match, reg_num)){
            numbers.push_back(std::stoi(match.str()));
            input = match.suffix();
        }
        for(auto n:numbers)
            std::cout << n << " ";
        std::cout << std::endl;
        for(uint16_t i(numbers[0]); i <= numbers[2]; i++){
            for (uint16_t j(numbers[1]); j <= numbers[3]; j++){
                if(direction.find("turn off") !=std::string::npos)
                    light_grid[i][j] = false;
                if(direction.find("turn on") !=std::string::npos){
                    light_grid[i][j] = true;
            }
                if(direction.find("toggle") !=std::string::npos)
                    light_grid[i][j] = !light_grid[i][j];
            }
        }
        numbers.clear();
    }
    for(uint16_t i(0); i < 999; i++){
        for (uint16_t j(0); j < 999; j++){
            if(light_grid[i][j] == true)
                lights++;
        }
    }
    std::cout << "The total number of lights turned on:\t\t" << lights << std::endl;
    return 0;
}
#if 0
#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>
#include <regex>

// Function Declaration

int main(){
    // Variable Declaration
    std::uint16_t light_grid[1000][1000] = {0};
    // std::uint16_t dummy(0);
    std::uint64_t lights(0);
    // std::stringstream ss;
    std::string input, direction;
    std::vector<std::uint16_t> numbers;
    std::regex reg_num(R"(\d+)");
    std::smatch match;

    std::ifstream read("Day_6_input.txt");
    if(!read.is_open()){
        std::cerr << "Failed to open file uccessfully" << std::endl;
        return 1;
    }else{
        std::cout << "File Opened Successfully" << std::endl;
    }

    while(!read.eof()){
        getline(read, input);
        direction = input;
        std::regex_search(input, match, reg_num);
        while(std::regex_search(input, match, reg_num)){
            numbers.push_back(std::stoi(match.str()));
            input = match.suffix();
        }
        for(uint16_t i(numbers[0]); i <= numbers[2]; i++){
            for (uint16_t j(numbers[1]); j <= numbers[3]; j++){
                if((direction.find("turn off") !=std::string::npos) && light_grid[i][j] > 0)
                    light_grid[i][j]--;
                if((direction.find("turn on") !=std::string::npos))
                    light_grid[i][j]++;
                if((direction.find("toggle") !=std::string::npos))
                    light_grid[i][j] += 2;
            }
        }
        numbers.clear();
    }
    for(uint16_t i(0); i < 1000; i++){
        for (uint16_t j(0); j < 1000; j++){
                lights += light_grid[i][j];
        }
    }
    std::cout << "The total number of lights turned on:\t\t" << lights << std::endl;
    return 0;
}
#endif