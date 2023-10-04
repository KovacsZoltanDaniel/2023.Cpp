//
// Created by Dani on 2023. 10. 04..
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H


class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);



#endif //CPP_2022_POINT_H
