// I_Was_Told_There_Would_Be_No_Math
// Includes
#include<iostream>
#include<fstream>
#include<cstdint>
#include<string>
#include<vector>
#include<sstream>

// Function Declaration
std::uint16_t calc_surf_a(std::uint16_t length, std::uint16_t width, std::uint16_t height);
void find_dim(const std::string input, std::uint16_t& length, std::uint16_t& width, std::uint16_t& height);
std::uint16_t smallest_perim(std::uint16_t length, std::uint16_t width, std::uint16_t height);
std::uint16_t calc_bow(std::uint16_t length, std::uint16_t width, std::uint16_t height);
std::uint16_t calc_ribbon_length(std::uint16_t length, std::uint16_t width, std::uint16_t height);

// Main Function
int main(){
    // Variable Declaration
    std::ifstream read("Day_2_Input.txt");
    std::string input;
    std::uint16_t length(0), width(0), height(0);
    std::uint32_t surface_area(0), total_ribbon_length(0);

    if(!read.is_open()){
        std::cerr << "Failed to open file successfully" << std::endl;
        return 1;
    }else{
        std::cout << "File Opened Successfully!" << std::endl;
    }

    while(!read.eof()){
        read >> input;
        // std::cout << input << std::endl;
        find_dim(input, length, width, height);
        surface_area += calc_surf_a(length, width, height);
        total_ribbon_length += calc_ribbon_length(length, width, height);
    }
    std::cout << "Total surface area needed to wrap all gifts:\t" << surface_area << std::endl
        << "Total length of ribbon needed to wrap all gifts:\t" << total_ribbon_length << std::endl;
    return 0;
}

// Funciton Definition

std::uint16_t calc_surf_a(std::uint16_t length, std::uint16_t width, std::uint16_t height){
    std::uint16_t lxw(0), wxh(0), lxh(0), min(0), sum(0);
    lxw = length * width;
    wxh = width * height;
    lxh = length * height;
    min = lxw;
    if(min >= wxh)
        min = wxh;
    if(min >= lxh)
        min = lxh;
    sum = 2 * lxw + 2 * wxh + 2 * lxh + min;
    return sum;
}
void find_dim(const std::string input, std::uint16_t& length, std::uint16_t& width, std::uint16_t& height){
    // std::uint16_t first_x(0), second_x(0);
    char del('x');
    std::vector<std::string> temp_str;
    std::string str;
    std::stringstream ss(input);

    while(std::getline(ss, str, del)){
        temp_str.push_back(str);
    }

    length = std::stoi(temp_str[0]);
    width = std::stoi(temp_str[1]);\
    height = std::stoi(temp_str[2]);
}
std::uint16_t smallest_perim(std::uint16_t length, std::uint16_t width, std::uint16_t height){
    std::uint16_t min(length), mid(width), sum(0);
    if(min > width){
        min = width;
    }
    if(min > height){
        min = height;
    }
    if(min == length){
        mid = width;
        if(mid > height)
            mid = height;
    }else if(min == width){
        mid = length;
        if(mid > height)
            mid = height;
    }else if(min == height){
        mid = length;
        if(mid > width)
            mid = width;
    }
    sum =  2 * min + 2 * mid;
    return sum;
}
std::uint16_t calc_bow(std::uint16_t length, std::uint16_t width, std::uint16_t height){
    return length * width * height;
}
std::uint16_t calc_ribbon_length(std::uint16_t length, std::uint16_t width, std::uint16_t height){
    return smallest_perim(length, width, height) + calc_bow(length, width, height);
}