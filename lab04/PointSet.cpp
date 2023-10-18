//
// Created by Dani on 2023. 10. 18..
//

#include <random>
#include <algorithm>
#include "PointSet.h"
#include <iostream>
using namespace std;

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

PointSet::PointSet(int n) {
    this->n = n;
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range
    while (points.size() < n){
        int x = dist(mt);
        int y = dist(mt);
        bool talalt = false;
        for( Point p : points){
            if(p.getX() == x && p.getY() == y){
                talalt = true;
                break;
            }
        }
        if(!talalt){
            points.push_back(Point(x, y));
        }
    }
        computeDistances();
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for(const Point &p : points){
        cout << p.getX() << " " << p.getY() << endl;
    }
}

void PointSet::printDistances() const {
    cout << "distances:" << endl;
    for(const double &d : distances){
        cout << d << endl;
    }
}
bool lessX( Point p1,  Point p2){
    return p1.getX() < p2.getX();
}
void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), lessX);
}

bool lessY( Point p1,  Point p2){
    return p1.getY() < p2.getY();
}
void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), lessY);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    vector<double> distances_copy(distances.begin(), distances.end());
    sort(distances_copy.begin(), distances_copy.end());
    auto uni = std::unique(distances_copy.begin(), distances_copy.end());
    return uni - distances_copy.begin();
}
