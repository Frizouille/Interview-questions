//
//  main.cpp
//  Test_codes
//
//  Created by Abigail Aldridge on 8/11/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//


/*Palindromic numbers: 110011
 the largest palindromic product of any two digit numbers is  91*99= 9009
 find the largest palindromic product of any three digit numbers
 */


#include <iostream>
#include <math.h>

using namespace std;


bool isPalindrome(int num);


int main(int argc, const char * argv[]) {

    int test = 9009, size = 3, ii,jj;
    int max = pow(10,size)-1;
    int result_pal=0;
    
    for(ii = max;ii > max/2;ii--){
        
        for(jj=max; jj > max/2;jj--){
            if(isPalindrome(jj*ii)){
                if((result_pal < jj*ii)){
                    result_pal = jj*ii;
                }
            }
        }
    }
    
    

    cout << isPalindrome(result_pal) << "\n";
    cout << result_pal << "\n";
    
    return 0;
};


int Reverse(int num){
    int rev=0;
    
    
    while(num > 0){
        rev = num%10 + rev*10;
        num = num/10;
    }
    
    
    return rev;
};


bool isPalindrome(int num){
    
    if ( num == Reverse(num)){
        return 1;
    }else{
        return 0;
    }
}





