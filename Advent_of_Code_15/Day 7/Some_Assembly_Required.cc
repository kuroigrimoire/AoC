#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <cctype>
#include <bitset>
#include <string>
#include <vector>

#include "equation.cpp"

// Function Declaration
bool isNumeric(const std::string& str);
void build_equation(std::vector<Eq> &equations, std::vector<std::string> &str);
void reset(std::vector<Eq> &equations, std::string mod, std::bitset<16> solution);
std::bitset<16> solve_equations(std::vector<Eq> &equations, std::string out);
std::bitset<16> re_solve_equations(std::vector<Eq> &equations, std::string out, std::string mod, std::bitset<16> solution);

int main(){
    // Variable Declaration
    std::string temp, token, test{"a"};
    std::stringstream line;
    std::vector<Eq> equations;
    std::vector<std::string> input;
    std::ifstream read("Day_7_Input.txt");
    std::bitset<16> result;

    #if 1
    if(!read.is_open()){
        std::cerr << "Failed to open file. Try Again" << std::endl;
        return 1;
    }std::cout << "Filed opened. Continue processing" << std::endl;

    while(!read.eof()){
        getline(read, temp);
        line << temp;
        while(getline(line, token, ' ')){
            input.emplace_back(token);
        }
        #if 1
        // std::cout << "size of vector:\t" << input.size() << "\t\tvector contains:\t\t";

        // for(std::uint16_t i(0); i < input.size(); i++){
        //     if(isNumeric(input[i]) && i != 2){
        //         std::cout << std::bitset<16>(stoi(input[i])) << "\t";
        //     }else{
        //         std::cout << input[i] << "\t";
        //     }
        // }
        build_equation(equations, input);
        // std::cout << std::endl << std::endl;
        #endif
        input.clear(); line.clear();
    }
    #endif
    // std::bitset<16> solution = solve_equations(equations, "h");
    // std::cout << solve_equations(equations, "d");
    // std::cout << solve_equations(equations, "e");
    // std::cout << solve_equations(equations, "f");
    // std::cout << solve_equations(equations, "g");
    // std::cout << solve_equations(equations, "h");
    // std::cout << solve_equations(equations, "i");
    for(auto i:equations){
        if(i.get_operation() == "ASSIGN")
            std::cout << "Current Solution Status for: " << i.get_output() << " is: " << i.solution() << " " << i;
    }

    result = solve_equations(equations, test);
    std::cout << std::endl << "the result of all these wires is:\t" << (int)result.to_ulong() << std::endl;
    
    reset(equations, "b", result);

    // result = solve_equations(equations, test, "b", result);
    // std::cout << std::endl << "the result of all these wires is:\t" << (int)result.to_ulong();
    result = solve_equations(equations, test);
    std::cout << std::endl << "the result of all these wires is:\t" << (int)result.to_ulong();
   
    equations.clear();
    read.close();
    return 0;
}
// Function Definition
bool isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}
void build_equation(std::vector<Eq> &equations, std::vector<std::string> &str){
    if(str.size() == 3){
        if(isNumeric(str[0])){
            Eq temp_eq(std::bitset<16>(stoi(str[0])), str[2]);
            equations.push_back(temp_eq);
        }else{
            Eq temp_eq(str[0], str[2]);
            equations.push_back(temp_eq);
        }
    }else if(str.size() == 4){
        Eq temp_eq(str[0], str[1], str[3]);
        equations.push_back(temp_eq);
    }else if(str.size() == 5){
        Eq temp_eq(str[0], str[1], str[2], str[4]);
        equations.push_back(temp_eq);
    }
    // equations.push_back(temp_eq);
}
void reset(std::vector<Eq> &equations, std::string mod, std::bitset<16> solution){
    for(auto i:equations){
        if(i.get_output() == mod){
            i.set_bit_value(solution);
            i.set_solved();
        }else{
            i.reset_solved();
        }
    }
}
std::bitset<16> solve_equations(std::vector<Eq> &equations, std::string out){
    std::string operation;
    for(std::uint16_t i(0); i < equations.size(); i++){
        if(equations[i].get_output() == out){
            if(equations[i].solution() == true)
                return equations[i].get_out_val();
            operation = equations[i].get_operation();
            if(operation == "AND"){
                // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t(" << equations[i].get_left_in()
                //     << ")\t& right input:\t" << equations[i].get_right_in() << " bitwise AND operation should yield:\t" <<std::endl;
                    // << (int)(solve_equations(equations, equations[i].get_left_in()) & solve_equations(equations, equations[i].get_right_in())).to_ulong() << std::endl;
                if(isNumeric(equations[i].get_left_in())){
                    // std::cout << "Left input was a numerical value\t" << equations[i].get_left_in() << "\tconverted to binary as:\t" << (std::bitset<16>)stoi(equations[i].get_left_in()) <<std::endl;
                    equations[i].set_bit_value((std::bitset<16>)stoi(equations[i].get_left_in()) & solve_equations(equations, equations[i].get_right_in()));    
                }else if(isNumeric(equations[i].get_right_in())){
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in())) & (std::bitset<16>)stoi(equations[i].get_right_in()));    
                }else{
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) & solve_equations(equations, equations[i].get_right_in())));
                }
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "OR"){
                // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                //     << "\t& right input:\t" << equations[i].get_right_in() << " bitwise OR operation should yield:\t" << std::endl
                    // << (solve_equations(equations, equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in())).to_ulong() << std::endl;
                if(isNumeric(equations[i].get_left_in())){
                    equations[i].set_bit_value((std::bitset<16>)stoi(equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in()));    
                }else if(isNumeric(equations[i].get_right_in())){
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in())) | (std::bitset<16>)stoi(equations[i].get_right_in()));    
                }else{
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in())));
                }
                // equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in())));
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "NOT"){
                // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                //     << "bitwise NOT operation should yield:\t" << std::endl
                //     << (~solve_equations(equations, equations[i].get_left_in())).to_ulong() << std::endl;
                equations[i].set_bit_value(~solve_equations(equations, equations[i].get_left_in()));
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "LSHIFT"){
                // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                //     << "\t& right input:\t" << equations[i].get_right_in() << " bitwise << operation should yield:\t" << std::endl
                //     << (solve_equations(equations, equations[i].get_left_in()) << stoi(equations[i].get_right_in())).to_ulong() << std::endl;
                equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) << stoi(equations[i].get_right_in()))); 
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "RSHIFT"){
                // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                //     << "\t& right input:\t" << equations[i].get_right_in() << " bitwise >> operation should yield:\t" << std::endl
                //     << (solve_equations(equations, equations[i].get_left_in()) >> stoi(equations[i].get_right_in())).to_ulong() << std::endl;
                equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) >> stoi(equations[i].get_right_in()))); 
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "ASSIGN"){
                if(equations[i].solution() == true){
                    // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_out_val()
                        // << " bitwise ASSIGN operation should yield:\t" 
                        // << equations[i].get_out_val() << std::endl;
                    return equations[i].get_out_val();
                }else{
                    // std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                    //     << " bitwise ASSIGN operation should yield:\t" << std::endl
                    //     << (solve_equations(equations, equations[i].get_left_in())).to_ulong() << std::endl;
                    equations[i].set_solved();
                    return solve_equations(equations, equations[i].get_left_in());
                }
            }else{
                std::cerr << "Operation could not be performed..... Couldn't find matching string in object" << std::endl;
                return 1;
            }
        }
    }
}
std::bitset<16> re_solve_equations(std::vector<Eq> &equations, std::string out, std::string mod, std::bitset<16> solution){
    std::string operation;
    // for(auto i:equations){
    //     // if(!((i.get_operation() == "ASSIGN") && (isNumeric(i.get_left_in()))))
    //     // if(!(i.get_operation() == "ASSIGN" || (isNumeric(i.get_left_in()))))
    //     //     i.reset_solved();
    //     if(i.get_output() == mod){
    //         i.set_bit_value(solution);
    //         i.set_solved();
    //     }else{
    //         i.reset_solved();
    //     }
    //     // if(i.get_operation() == "ASSIGN")
    //     //     std::cout << "Current Solution Status for: " << i.get_output() << " is: " << i.solution() << " " << i;
    // }
    for(std::uint16_t i(0); i < equations.size(); i++){
        if(equations[i].get_output() == out){
            if(equations[i].solution() == true)
                return equations[i].get_out_val();
            operation = equations[i].get_operation();
            if(operation == "AND"){
                std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t(" << equations[i].get_left_in()
                    << ")\t& right input:\t" << equations[i].get_right_in() << " bitwise AND operation should yield:\t" <<std::endl;
                    // << (int)(solve_equations(equations, equations[i].get_left_in()) & solve_equations(equations, equations[i].get_right_in())).to_ulong() << std::endl;
                if(isNumeric(equations[i].get_left_in())){
                    std::cout << "Left input was a numerical value\t" << equations[i].get_left_in() << "\tconverted to binary as:\t" << (std::bitset<16>)stoi(equations[i].get_left_in()) <<std::endl;
                    equations[i].set_bit_value((std::bitset<16>)stoi(equations[i].get_left_in()) & solve_equations(equations, equations[i].get_right_in()));    
                }else if(isNumeric(equations[i].get_right_in())){
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in())) & (std::bitset<16>)stoi(equations[i].get_right_in()));    
                }else{
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) & solve_equations(equations, equations[i].get_right_in())));
                }
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "OR"){
                std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                    << "\t& right input:\t" << equations[i].get_right_in() << " bitwise OR operation should yield:\t" << std::endl
                    << (solve_equations(equations, equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in())).to_ulong() << std::endl;
                if(isNumeric(equations[i].get_left_in())){
                    equations[i].set_bit_value((std::bitset<16>)stoi(equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in()));    
                }else if(isNumeric(equations[i].get_right_in())){
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in())) | (std::bitset<16>)stoi(equations[i].get_right_in()));    
                }else{
                    equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in())));
                }
                // equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) | solve_equations(equations, equations[i].get_right_in())));
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "NOT"){
                std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                    << "bitwise NOT operation should yield:\t" << std::endl
                    << (~solve_equations(equations, equations[i].get_left_in())).to_ulong() << std::endl;
                equations[i].set_bit_value(~solve_equations(equations, equations[i].get_left_in()));
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "LSHIFT"){
                std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                    << "\t& right input:\t" << equations[i].get_right_in() << " bitwise << operation should yield:\t" << std::endl
                    << (solve_equations(equations, equations[i].get_left_in()) << stoi(equations[i].get_right_in())).to_ulong() << std::endl;
                equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) << stoi(equations[i].get_right_in()))); 
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "RSHIFT"){
                std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                    << "\t& right input:\t" << equations[i].get_right_in() << " bitwise >> operation should yield:\t" << std::endl
                    << (solve_equations(equations, equations[i].get_left_in()) >> stoi(equations[i].get_right_in())).to_ulong() << std::endl;
                equations[i].set_bit_value((solve_equations(equations, equations[i].get_left_in()) >> stoi(equations[i].get_right_in()))); 
                equations[i].set_solved();
                return equations[i].get_out_val();
            }else if(operation == "ASSIGN"){
                if(equations[i].solution() == true){
                    std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_out_val()
                        << " bitwise ASSIGN operation should yield:\t" 
                        << equations[i].get_out_val() << std::endl;
                    return equations[i].get_out_val();
                }else{
                    std::cout << "calling " << equations[i].get_operation() << " operation on left input:\t" << equations[i].get_left_in()
                        << " bitwise ASSIGN operation should yield:\t" << std::endl
                        << (solve_equations(equations, equations[i].get_left_in())).to_ulong() << std::endl;
                    equations[i].set_solved();
                    return solve_equations(equations, equations[i].get_left_in());
                }
            }else{
                std::cerr << "Operation could not be performed..... Couldn't find matching string in object" << std::endl;
                return 1;
            }
        }
    }

}