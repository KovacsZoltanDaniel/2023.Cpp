//
// Created by Dani on 2023. 10. 04..
//

#include "Point.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "(" << x << "," << y << ")" << endl;
}

double distance(const Point &a, const Point &b) {
    int dx = a.getX() - b.getX();
    int dy = a.getY() - b.getY();
    return sqrt(dx*dx + dy*dy);
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double D[6] = {
            distance(a, b),
            distance(a, c),
            distance(a, d),
            distance(b, c),
            distance(b, d),
            distance(d, c),
    };
    sort(D, D + 6);
    return (D[0] == D[3] && D[4] == D[5] && D[3] < D[4]);
}

void testIsSquare(const char *filename) {
    ifstream f(filename);
    if(!f){
        cout << "File not found" << endl;
        return;
    }
    int x, y;
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        ss >> x >> y;
        Point p1(x, y);
        ss >> x >> y;
        Point p2(x,y);
        ss >> x >> y;
        Point p3(x,y);
        ss >> x >> y;
        Point p4(x,y);
        if(isSquare(p1,p2,p3,p4)){
            cout << "Square" << endl;
            cout << "p1: (" << p1.getX() << " " << p1.getY() << ")" << endl;
            cout << "p2: (" << p2.getX() << " " << p2.getY() << ")" << endl;
            cout << "p3: (" << p3.getX() << " " << p3.getY() << ")" << endl;
            cout << "p4: (" << p4.getX() << " " << p4.getY() << ")" << endl;
        } else{
            cout << "Not square" << endl;
            cout << "p1: (" << p1.getX() << " " << p1.getY() << ")" << endl;
            cout << "p2: (" << p2.getX() << " " << p2.getY() << ")" << endl;
            cout << "p3: (" << p3.getX() << " " << p3.getY() << ")" << endl;
            cout << "p4: (" << p4.getX() << " " << p4.getY() << ")" << endl;
        }


    }
}
