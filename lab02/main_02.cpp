#include <iostream>
#include "Point.h"
using namespace std;

int main(int argc, char** argv) {
    //2 - 3
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
    cout << endl;
    //4
    cout << "p1: ";
    p1.print();
    cout << "p2: ";
    p2.print();
    cout << "The distance between the given two points: " << distance(p1,p2);
    cout << endl;
    //5
    Point p4(1,0);
    Point p5(2,0);
    Point p6(2,1);
    Point p7(1,1);
    cout << endl << "IsSquare: " << isSquare(p4,p5,p6,p7) << endl;
    cout << endl;
    //6
    testIsSquare("points.txt");
//    // 7. 8. 11.
//   srand(time(NULL));
//
//    int numPoints;
//    cout<<"Enter the number of points: ";
//    cin>>numPoints;
//
//    Point * points = createArray(numPoints);
//
//    for (int j = 0; j < numPoints; j++) {
//        points[j] = Point(rand() % 2001, rand() % 2001);
//    }
//
//    cout << "Before sorting:" << endl;
//    printArray(points, numPoints);
//
//    cout << "After sorting:" << endl;
//    sortPoints(points, numPoints);
//    printArray(points, numPoints);

     //9. 10.
    int numPoints = 10;
    Point *points = createArray(numPoints);

    srand(time(NULL));

    for (int j = 0; j < numPoints; j++) {
        points[j] = Point(rand() % 100, rand() % 100);
    }

    pair<Point, Point> closest = closestPoints(points, numPoints);

    cout << "Closest points: (" << closest.first.getX() << ", " << closest.first.getY() << ") and ("
         << closest.second.getX() << ", " << closest.second.getY() << ")" << endl;

    pair<Point, Point> farthest = farthestPoints(points, numPoints);

    cout << "Farthest points: (" << farthest.first.getX() << ", " << farthest.first.getY() << ") and ("
         << farthest.second.getX() << ", " << farthest.second.getY() << ")" << endl;

    deletePoints(points);

//     //12.
//    int numPoints = 20;
//    Point* points = new Point[numPoints];
//
//    // Initialize points with some values
//    for (int i = 0; i < numPoints; ++i) {
//        points[i] = Point(rand() % 100, rand() % 100);
//    }
//
//    Point* farthest = farthestPointsFromOrigin(points, numPoints);
//
//    cout << "The 10 farthest points from the origin are:" << endl;
//    for (int i = 0; i < 10; ++i) {
//        cout << "(" << farthest[i].getX() << ", " << farthest[i].getY() << ")" << endl;
//    }
//
//    deletePoints(points);
//    deletePoints(farthest);
    return 0;
}
