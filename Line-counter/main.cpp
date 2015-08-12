//
//  main.cpp
//  Line counter
//
//  Created by Abigail Aldridge on 8/11/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

/*
 You have a pair of point A(x,y) and B(xx,yy) on a grid of size NxN.
 Find the fastest way to get all the unique line AB
 */


#include <iostream>
#include <math.h>
#include <vector>

#include "Point.h"
#include "Line.h"

using namespace std;




int main(int argc, const char * argv[]) {
    
    Point A,B;
    Line L;
    
    //Point resultP [2][] = {};
    
    vector<Line> resultL;
    
    int ii, jj, kk, N=4;
    
    bool equal;
    
    cout << resultL.empty() << "tt" << resultL.size() << "\n";
    
    for(ii = 0;ii < pow(N,2) ;ii++){
        
        A.setPoint(ii/N, ii%N);
        
        for(jj=N; jj < pow(N,2);jj++){
            
            if(jj/N != ii/N){
                
                B.setPoint(jj/N, jj%N);
                equal = false;
                L.setLine(A,B);
                
                for (kk = 0; kk < resultL.size(); kk++){
                    if(resultL[kk]==L){
                        equal = true;
                        break;
                    }
                }
            
                if(!equal){
                    resultL.push_back(L);
                }
            }
            
            
            
        }
    }
    
    
    for (kk = 0; kk < resultL.size(); kk++){
        L = resultL[kk];
        L.printLine();
        cout << "  ";

    }
    
    cout << endl;
    cout << "size: "<< resultL.size() << "\n";
    
    return 0;
};