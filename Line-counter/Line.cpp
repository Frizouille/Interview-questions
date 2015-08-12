//
//  Line.cpp
//  Line counter
//
//  Created by Abigail Aldridge on 8/11/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#include <iostream>

#include "Line.h"

using namespace std;


Line::Line(int a, int b){
    setLine(a , b);
}

void Line::setLine(int newA, int newB){
    a = newA;
    b = newB;
}

void Line::setLine(Point A, Point B){
    
    if(A == B){
        a = -100000;
        b = -100000;
    }else{
        a = (B.getY()-A.getY())/(B.getX()-A.getX());
        b = A.getY() - a*A.getX();
    }
}


void Line::printLine(){
    
    cout<<"("<<a<<","<<b<<")";
}

bool operator==(const Line & La, const Line & Lb){
    if((La.getA() == Lb.getA())&&(La.getB()==Lb.getB())){
        return true;
    }else{
        return false;
    }
}

int Line::getA() const{
    return a;
}

int Line::getB() const{
    return b;
}