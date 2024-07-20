// Trebuchet
// Includes
#include<iostream>
#include<fstream>
#include<string>
#include<cstdint>

// Main Function
int main(){
    // Variables
    std::ifstream read_f("Day_1_input.txt");
    // std::ifstream read_f("Day_1_input_test.txt");
    std::ifstream read_f("Day_1_input_test2.txt");
    std::string input, LandR;
    std::uint16_t count(0), left(0), right(0);
    std::uint32_t sum(0);
    bool e_ex(false);

    // Open File and check
    if(!read_f.is_open()){
        std::cerr << "Problem occured opening file!!" << std::endl;
        return 1;
    }else{
        std::cout << "File opened successfully!" << std::endl;
    }

    // File Manip
    while(!read_f.eof()){
        read_f >> input;
        for(int i = 0; i < input.length() && e_ex == false; i++){
            if(isdigit(input[i])){
                left = i;
                e_ex = true;
            }
        }
        e_ex = false;
        for(int i = input.length()-1; i >= 0 && e_ex == false; i--){
            if(isdigit(input[i])){
                right = i;
                e_ex = true;
            }
        }
        e_ex = false;
    
        LandR = input[left];
        LandR += input[right];
        sum += stoi(LandR);
        // std::cout << "Line: " << ++count << "\tValue: " << input << "\tLeft Digit: " << input[left] << "\tRight Digit: "
        // << input[right] << "\tcombined digits: " << LandR << std::endl;
    }

    std::cout << "Final sum = " << sum;

    read_f.close();
    return 0;
}