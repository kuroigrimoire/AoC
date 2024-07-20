#include "Points.h"

//   Constructor
Points::Points(){
     std::cout << "New point created at origin: { 0,0 }" << std::endl;
}
Points::Points(int x, int y)
     :X(x), Y(y){
     std::cout << "New point at coordinate: { " << X << ", " << Y << " } created." << std::endl;
}

//   Destructor
Points::~Points(){
     std::cout << "Point being erased from memory" << std::endl;
}

//   Copy Assignment
Points &Points::operator=(const Points &rhs){
     this->X = rhs.X;
     this->Y = rhs.Y;
     return *this;
}

std::ostream &operator<<(std::ostream &os, const Points &points){
     os << "X-coordinate: " << points.X << "\tY-coordinate: " << points.Y;
     return os;
}
// /*
std::pair<int, char> operator-(const Points &lhs, const Points &rhs){
     char direc{'a'};
     int dist{0}, distx{0}, disty{0};
     if(lhs.X == rhs.X){
          dist = lhs.Y - rhs.Y;
          direc = 'V';
     }else if(lhs.Y == rhs.Y){
          dist = lhs.X - rhs.X;
          direc = 'H';
     }else{
          distx = lhs.X - lhs.X;
          disty = lhs.Y - rhs.Y;
          if(distx == disty){
               dist = distx;
               direc = 'D';
          }else{
               dist = 0;
               direc = 'N';
          }
     }
     std::pair<int, char> ret;
     ret = std::make_pair(dist,direc);
     return ret;
}

bool Points::operator==(const Points &rhs)const{
     return ((X == rhs.X)&&(Y == rhs.Y) == 0);
}
// */