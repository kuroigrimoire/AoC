// #include <iostream>
#include "equation.h"
// Class Definition
    // Constructors
Eq::Eq()
    {
        std::cout << "Equation has been written with no arguments" << std::endl;

}
Eq::Eq(/*std::uint16_t input,*/ std::bitset<16> value, std::string output)
    : /*out_val(input),*/out_val(value), output(output){
    solved = true;
    op = "ASSIGN";
}
Eq::Eq(std::string input, /*std::bitset<16> value,*/ std::string output)
    : first_in(input),/*out_val(value),*/ output(output){
    // solved = ;
    op = "ASSIGN";
}
Eq::Eq(std::string operation, std::string input, std::string output)
    : op(operation), first_in(input), output(output){

}
Eq::Eq(std::string left_in, std::string operation, std::string right_in, std::string output)
    : first_in(left_in), op(operation), second_in(right_in), output(output){

}
// Eq(std::uint16_t input, std::uint16_t operation, std::uint16_t mod, std::string output)
//     : first_in(input), op(ioeration), second_in(mod), output(output){

// }
Eq::Eq(const Eq &source)
    :first_in(source.first_in), second_in(source.second_in), op(source.op), output(source.output), out_val(source.out_val), solved(source.solved){
        // std::cout << "Copy Constructor called" << std::endl;
}
Eq::~Eq(){
    // std::cout << "Destructor Called" << std::endl;
}
bool Eq::solution(){
    return solved;
}
std::bitset<16> Eq::get_out_val(){
    return out_val;
}
void Eq::set_solved(){
    solved = true;
}
void Eq::reset_solved(){
    solved = false;
}
std::string Eq::get_left_in(){
    return first_in;
}
std::string Eq::get_right_in(){
    return second_in;
}
std::string Eq::get_output(){
    return output;
}
std::string Eq::get_operation(){
    return op;
}
void Eq::set_bit_value(std::bitset<16> bit_value){
    out_val = bit_value;
}

std::ostream & operator <<(std::ostream &os, const Eq &eq){
    if((eq.op != "ASSIGN") && (eq.op != "not"))
        os << "bitwise operation performing: " << eq.op << " with left input: \"" << eq.first_in << " and right input: \""
            << eq.second_in << " resulting in an output of: \"" << eq.output << "\" which is equal to: " << eq.out_val << std::endl;
    else{
        os << "bitwise operation performing: " << eq.op << " with left input: \"" << eq.first_in 
            << " resulting in an output of: \"" << eq.output << "\" which is equal to: " << eq.out_val << std::endl;
    }
    return os;
}
// void Eq::solve_eq(){
//     if()
// }
// #endif