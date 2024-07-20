// Day 1 - Not Quite Lisp
// Includes
#include<iostream>
#include<fstream>
#include<string>
#include<cstdint>

// Main Function
int main(){
    // Variable Decalration
    std::ifstream read("Day_1_Input.txt");
    std::int16_t floor(0);
    std::uint16_t  pos(0);
    std::string input;
    char up('('), down(')');

    // Open File and check
    if(!read.is_open()){
        std::cerr << "Problem occured opening file!!" << std::endl;
        return 1;
    }else{
        std::cout << "File opened successfully!" << std::endl;
    }

    while(!read.eof()){
        read >> input;
        // std::cout << input << std::endl;
    }

    for(char x: input){
        pos++;
        if(x == up)
            floor++;
        else if(x == down)
            floor--;
        if(floor < 0){
            std::cout << "Character psosition:\t" <<pos << "\t resulted in Santa entering basement floor 1" << std::endl;
            return 0;
        }
        // std::cout << pos << ";\t" << floor << std::endl;
    }

    std::cout << "Santa lands on floor:\t" << floor << std::endl;

    return 0;
}