#include <iostream>
#include <string>
#include <cstdint>
#include <sstream>
#include "md5.cpp"
#include "md5.h"

int main(){
    MD5 digestMD5;
    std::string input("iwrupvqb"), crit("00000"), hash_string, result, hash_return; 
    std::uint64_t input_val(0);

    // Part 1 Solution
    std::cout << "Solution to part 1" << std::endl << std::endl;
    do{
        input_val+=1;
        hash_string = input + std::to_string(input_val);
        digestMD5.add(hash_string.c_str(), hash_string.length());
        hash_return = digestMD5.getHash();
        digestMD5.reset();
        result = hash_return.substr(0, 5);
    }while(result != crit);
    
    std::cout << "hash input string:\t" << hash_string.substr(0,input.length()) << ' ' << hash_string.substr(input.length(), hash_string.length()) << std::endl;
    // std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return.substr(0,5) << ' ' << hash_return.substr(5, hash_return.length()) << std::endl;
    // std::cout << "result:\t" << result<< std::endl;

    // Part 2 Solution
    std::cout << "Solution to part 2" << std::endl << std::endl;
    crit = "000000";
    input_val = 0;
    do{
        input_val+=1;
        hash_string = input + std::to_string(input_val);
        digestMD5.add(hash_string.c_str(), hash_string.length());
        hash_return = digestMD5.getHash();
        digestMD5.reset();
        result = hash_return.substr(0, 6);
    }while(result != crit);
    
    std::cout << "hash input string:\t" << hash_string.substr(0,input.length()) << ' ' << hash_string.substr(input.length(), hash_string.length()) << std::endl;
    // std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return.substr(0,6) << ' ' << hash_return.substr(6, hash_return.length()) << std::endl;
    // std::cout << "result:\t" << result<< std::endl;

    return 0;
}


