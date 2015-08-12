//
//  Line.h
//  Line counter
//
//  Created by Abigail Aldridge on 8/11/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#ifndef __Line_counter__Line__
#define __Line_counter__Line__

#include "Point.h"
#include <stdio.h>

class Line
{
public:
    
    Line(int a = 0,int b = 0);
    void setLine(int newA,int newB);
    void setLine(Point A, Point B);
    void printLine();
    Line getLine(Line L);
    int getA() const;
    int getB() const;
    friend bool operator==(const Line & La, const Line & Lb);
private:
    int a,b;
};

#endif /* defined(__Line_counter__Line__) */
