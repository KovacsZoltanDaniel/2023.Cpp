//
// Created by Dani on 2023. 10. 04..
//

#include "Point.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cfloat>
#include <queue>
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
    return distance(a,b) == distance(c,d) && distance(a,c) == distance(b,d);
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
Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    return points;
}

void deletePoints(Point *points) {
    if (points != nullptr) {
        delete[] points;
    }
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        points[i].print();
        cout << " ";
    }
    cout << endl;
}

bool comparePoints(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}

bool cmpPointsFromOirigin(const Point &a, const Point &b) {
    return (a.getX() * a.getX() + a.getY() * a.getY()) < (b.getX() * b.getX() + b.getY() * b.getY());
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, comparePoints);
}

void sortPointsDistanceFromOrigin(Point *points, int numPoints) {
    sort(points, points + numPoints, cmpPointsFromOirigin);
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cout << "Need at least 2 points." << endl;
        exit(1);
    }

    pair<Point, Point> closestPair;
    double minDistance = DBL_MAX;

    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                closestPair = make_pair(points[i], points[j]);
                minDistance = dist;
            }
        }
    }

    return closestPair;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cout << "Need at least 2 points." << endl;
        exit(1);
    }

    pair<Point, Point> farthestPair;
    double maxDistance = 0;

    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double dist = distance(points[i], points[j]);
            if (dist > maxDistance) {
                farthestPair = make_pair(points[i], points[j]);
                maxDistance = dist;
            }
        }
    }

    return farthestPair;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    if (numPoints <= 10) {
        return points;
    }

    sortPointsDistanceFromOrigin(points, numPoints);

    Point *farthestPoints = new Point[10];

    for (int i = 0; i < 10; i++) {
        farthestPoints[i] = points[i];
    }

    return farthestPoints;
}
