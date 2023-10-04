#include <iostream>
#include "Point.h"
using namespace std;

int main(int argc, char** argv) {
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;
    cout << "p1: ";
    p1.print();
    cout << "distance: " << distance(p1,p2);
    Point p4(1,0);
    Point p5(2,0);
    Point p6(2,1);
    Point p7(1,1);
    cout << endl << "isSquare: " << isSquare(p4,p5,p6,p7) << endl;
    testIsSquare("points.txt");
    return 0;
}
