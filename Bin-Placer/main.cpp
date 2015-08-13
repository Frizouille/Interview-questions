//
//  main.cpp
//  Bin Placer
//
//  Created by Abigail Aldridge on 8/13/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#include <iostream>
#include <array>

using namespace std;

array<int,4> bin_placer(array<int,4> ary, int value);


int main(int argc, const char * argv[]) {
    
    array<int,4> test= {10, 15, 25, 50};
    int val = 17;
    
    
    
    test = bin_placer(test, val);
    
    for(int elem : test){
        cout << elem << endl;
    }
    cout << "Hello" <<endl;
    
    return 0;
}


array<int,4> bin_placer(array<int,4> ary, int value){
    
    int temp = 0;
    
    array<int,ary.size()>result;
    

    for(int elem : ary){
        if(value <= elem){
            result[temp] = elem;
            temp = temp +1;
        }
    }
    
    
    return result;
}
