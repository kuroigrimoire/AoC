#ifndef _POINTS_H_
#define _POINTS_H_
#include<iostream>

class Points{
     friend std::ostream &operator<<(std::ostream &os, const Points &points);
     friend std::pair<int, char> operator-(const Points &lhs, const Points &rhs);
     
private:
     //   attributes
     int X = 0;
     int Y = 0;
     
public:
     //   Constructors
     Points();
     Points(int x, int y);
     ~Points();
     
     Points &operator=(const Points &rhs);
     bool operator==(const Points &rhs)const;
     //   Members
};

namespace std{
     template<>
     struct Points_Hasher{
          size_t operator()(const Points& Input) const{
               return std::hash<int>{}(Input.X) ^ (std::hash<int>{}(Input.Y) + 0xbeef);
          }
     };     
}

#endif // _POINTS_H_










