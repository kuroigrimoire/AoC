#include <iostream>
#include <string>
#include <cstdint>
#include <sstream>
#include "md5.cpp"
#include "md5.h"
// #include "C:\git\git_libs\openssl\e_os2.h"
// #include "C:\git\git_libs\openssl\crypto\md5\md5_local.h"

int main(){
    MD5 digestMD5;
    // std::string input("abcdef"), crit("00000"), hash_input, hash_string, result, hash_return, test("609043");
    // std::cout << MD5("Hello World!") << std::endl;
    #if 0
    MD5 digestMD5;
    std::uint32_t input(1048969);
    input++;
    std::string msg1("pqrstuv"), msg2(std::to_string(input)), msg;
    msg = msg1 + msg2;
    std::string hash_return;
    
    digestMD5.add(msg.c_str(), msg.length());
    hash_return = digestMD5.getHash();
    // std::cout << "MD5 Hash of 'Hello World':\t\t" << digestMD5.getHash() << std::endl;
    std::cout << "MD5 Hash of sample msg:\t\t" << msg << "\t\tis:\t\t" << hash_return << std::endl;

    // msg = "abcdef609043";
    // // std::string hash_return;
    
    // digestMD5.add(msg.c_str(), msg.length());
    // hash_return = digestMD5.getHash();
    // // std::cout << "MD5 Hash of 'Hello World':\t\t" << digestMD5.getHash() << std::endl;
    // std::cout << "MD5 Hash of sample msg:\t\t" << msg << "\t\tis:\t\t" << hash_return << std::endl;
    #endif
    #if 1
    std::string input("iwrupvqb"), crit("00000"), hash_string, result, hash_return; /*test("609043");*/
                    //   "iwrupvqb"
    std::uint64_t input_val(0);

    do{
        input_val+=1;
        hash_string = input + std::to_string(input_val);
        digestMD5.add(hash_string.c_str(), hash_string.length());
        hash_return = digestMD5.getHash();
        digestMD5.reset();
        result = hash_return.substr(0, 5);
        // std::cout << "input_val:\t" << input_val << "hash return value:\t" << hash_return << "result:\t" << result<< std::endl;
    }while(result != crit);
    

    // std::cout << "MD5 Hash of 'Hello World':\t\t" << digestMD5.getHash() << std::endl;
    // std::cout << "Lowest number to giver desired hash return is:\t\t" << input_val << std::endl;
    std::cout << "hash input string:\t" << hash_string.c_str() << std::endl;
    std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "result:\t" << result<< std::endl;

    crit = "000000";
    input_val = 0;
    do{
        input_val+=1;
        hash_string = input + std::to_string(input_val);
        digestMD5.add(hash_string.c_str(), hash_string.length());
        hash_return = digestMD5.getHash();
        digestMD5.reset();
        result = hash_return.substr(0, 6);
        // std::cout << "input_val:\t" << input_val << "hash return value:\t" << hash_return << "result:\t" << result<< std::endl;
    }while(result != crit);
    

    // std::cout << "MD5 Hash of 'Hello World':\t\t" << digestMD5.getHash() << std::endl;
    // std::cout << "Lowest number to giver desired hash return is:\t\t" << input_val << std::endl;
    std::cout << "hash input string:\t" << hash_string.c_str() << std::endl;
    std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "result:\t" << result<< std::endl;

    #endif
    #if 0
    // retest
    hash_string = "abcedf609043";
    digestMD5.add(hash_string.c_str(), hash_string.length());
    hash_return = digestMD5.getHash();
    result = hash_return.substr(0, 5);

    std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "result:\t" << result<< std::endl;    
    #endif
    #if 0
    // std::string input("abcdef"), hash_input, hash_return;
    std::uint32_t input_val(609043);
    hash_input = input + std::to_string(input_val);
    digestMD5.add(hash_input.c_str(), hash_input.length());
    hash_return = digestMD5.getHash();
    digestMD5.reset();

    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "Lowest number to giver desired hash return is:\t\t" << input_val << std::endl << std::endl;
    #endif
   #if 0
    std::stringstream ss;
    // input_val(0);
    for(uint32_t i = 1; i < 609044 && crit != result; i ++){
        input_val = i;
        hash_string = input + std::to_string(i);
        digestMD5.add(hash_string.c_str(), hash_string.length());
        hash_return = digestMD5.getHash();
        digestMD5.reset();
        result = hash_return.substr(0, 5);
    }
    // do{
    //     input_val+=1;
    //     hash_string = input + std::to_string(input_val);
    //     digestMD5.add(hash_string.c_str(), hash_string.length());
    //     hash_return = digestMD5.getHash();
    //     result = hash_return.substr(0, 5);
    //     // std::cout << "input_val:\t" << input_val << "hash return value:\t" << hash_return << "result:\t" << result<< std::endl;
    // }while(result != crit);
    

    // std::cout << "MD5 Hash of 'Hello World':\t\t" << digestMD5.getHash() << std::endl;
    // std::cout << "Lowest number to giver desired hash return is:\t\t" << input_val << std::endl;
    std::cout << "hash input string:\t" << hash_string.c_str() << std::endl;
    std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "result:\t" << result<< std::endl << std::endl;

    ss << input << 609043;
    hash_string = ss.str();
    digestMD5.add(hash_string.c_str(), hash_string.length());
    hash_return = digestMD5.getHash();
    digestMD5.reset();
    result = hash_return.substr(0, 5);

    std::cout << "hash input string:\t" << hash_string.c_str() << "\tlength of string:\t" << hash_return.length() << std::endl;
    // std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "result:\t" << result<< std::endl << std::endl;

    // ss << input << 609043;
    hash_string = "abcdef609043";
    digestMD5.add(hash_string.c_str(), hash_string.length());
    hash_return = digestMD5.getHash();
    digestMD5.reset();
    result = hash_return.substr(0, 5);

    std::cout << "hash input string:\t" << hash_string.c_str() << "\tlength of string:\t" << hash_return.length() << std::endl;
    // std::cout << "input_val:\t" << input_val << std::endl;
    std::cout << "hash return value:\t" << hash_return << std::endl;
    std::cout << "result:\t" << result<< std::endl << std::endl;
    #endif

    return 0;
}


