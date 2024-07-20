// Day 3 - Perfectly Spherical Houses
// Includes
#include<iostream>
#include<fstream>
#include<cstdint>
#include<string>
#include<utility>
#include<unordered_map>

// Hash Function
struct pair_hash{
    template<class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const{
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        if(h1 != h2)
            return h1 ^ h2;
        
        return h1;
    } 
};

int main(){
    // Variable Declaration
    std::ifstream read("Day_3_Input.txt");
    std::pair<std::int16_t, std::int16_t> temp(0,0), santa(0,0), robo_clause(0,0);
    std::unordered_map<std::pair<std::int16_t, std::int16_t>, std::uint16_t, pair_hash> house, santa_pos, robo_clause_pos;
    std::string str;

    if(!read.is_open()){
        std::cerr << "Failed to open file uccessfully" << std::endl;
        return 1;
    }else{
        std::cout << "File Opened Successfully" << std::endl;
    }
    
    while (!read.eof()){
        read >> str;
    }

    house.emplace(temp, 1);
    santa_pos.emplace(temp, 1);
    robo_clause_pos.emplace(temp, 1);

    for(char x: str){
        if(x == '^'){temp.second++;}
        if(x == 'v'){temp.second--;}
        if(x == '<'){temp.first--;}
        if(x == '>'){temp.first++;}

        house.try_emplace(temp, 1);
    }
    std::cout << "Longitude:\t" << temp.first << "\tLatitude:\t" << temp.second << std::endl
        << "Number of houses visited:\t" << house.size() << std::endl;
    
    for(int i=0; i < str.length(); i++){
        if(i % 2 == 0){
            if(str[i] == '^'){santa.second++;}
            if(str[i] == 'v'){santa.second--;}
            if(str[i] == '<'){santa.first--;}
            if(str[i] == '>'){santa.first++;}

            santa_pos.try_emplace(santa, 1);
        }else if(i%2!=0){
            if(str[i] == '^'){robo_clause.second++;}
            if(str[i] == 'v'){robo_clause.second--;}
            if(str[i] == '<'){robo_clause.first--;}
            if(str[i] == '>'){robo_clause.first++;}

            robo_clause_pos.try_emplace(robo_clause, 1);
        }
    }
    std::cout << "Santa Longitude:\t" << santa.first << "\tSanta Latitude:\t" << santa.second << std::endl
        << "Number of houses visited by santa:\t" << santa_pos.size() << std::endl;
    std::cout << "Robo Santa Longitude:\t" << robo_clause.first << "\tRobo Santa Latitude:\t" << robo_clause.second << std::endl
        << "Number of houses visited by santa:\t" << robo_clause_pos.size() << std::endl;

    auto result = santa_pos;
    result.insert(robo_clause_pos.begin(), robo_clause_pos.end());
    std::cout << "Number of houses visited by both santa and the robot:\t" << result.size() << std::endl;
    return 0;
}