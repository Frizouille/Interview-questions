//
//  Point.cpp
//  Line counter
//
//  Created by Abigail Aldridge on 8/11/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#include <iostream>

#include "Point.h"

using namespace std;


Point::Point(int x, int y){
    setPoint(x, y);
}

void Point::setPoint(int newX, int newY){
    x = newX;
    y = newY;
}

Point Point::add( const Point p){
    
    Point z;
    
    z.x=x+p.x;
    z.y=y+p.y;
    
    return z;
}

Point Point::subtract(const Point p){
    
    Point z;
    
    z.x = x-p.x;
    z.y = y-p.y;
    
    return z;
}

void Point::printPoint(){
    
    cout<<"("<<x<<","<<y<<")";
}

int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

bool operator==(const Point & Pa, const Point & Pb){
    if((Pa.getX() == Pb.getX())&&(Pa.getY()==Pb.getY())){
        return true;
    }else{
        return false;
    }
}