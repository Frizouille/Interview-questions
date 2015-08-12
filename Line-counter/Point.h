//
//  Point.h
//  Line counter
//
//  Created by Abigail Aldridge on 8/11/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#ifndef __Line_counter__Point__
#define __Line_counter__Point__

#include <stdio.h>

class Point
{
public:
    
    Point(int x = 0,int y = 0);
    void setPoint(int newX,int newY);
    Point add (const Point otherPoint);
    Point subtract (const Point otherPoint);
    void printPoint();
    int getX() const;
    int getY() const;
    friend bool operator==(const Point & Pa, const Point & Pb);
private:
    int x,y;
};


#endif /* defined(__Line_counter__Point__) */
