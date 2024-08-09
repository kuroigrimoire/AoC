#ifndef _EQUATION_H_
#define _EQUATION_H_

#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <bitset>
// #include 
// #include <vector>

// Class Definition
class Eq{
private:
    std::string first_in, second_in, op, output;
    std::bitset<16> out_val{0b0000};
    bool solved{false};
public:
    // Constructors
    Eq();
    Eq(std::bitset<16> value, std::string output);
    Eq(std::string input, std::string output);
    Eq(std::string operation, std::string input, std::string output);
    Eq(std::string left_in, std::string operation, std::string right_in, std::string output);
    // Eq(std::uint16_t input, std::uint16_t operation, std::uint16_t mod, std::string output);
    Eq(const Eq &source);
    // Destructor
    ~Eq();
    
    // Methods
    bool solution();    //  Check to see if a sulution is present in the equation
    void set_solved();
    void reset_solved();
    void set_bit_value(std::bitset<16> bit_value);
    std::string get_output();
    std::string get_left_in();
    std::string get_right_in();
    std::string get_operation();
    std::bitset<16> get_out_val();
    friend std::ostream & operator <<(std::ostream &os, const Eq &eq);
    // void solve_eq();

    // return left input
    // return right input
    // return operation
    // return output string
    // return solution value 
    // set solution value
    // void solve
};
// #endif
#endif //_EQUATION_H_