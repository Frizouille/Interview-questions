//
//  main.cpp
//  RomanToEnglishnumbers
//
//  Created by Abigail Aldridge on 8/17/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int digitValue(char);

int main() {
    
    char roman_num[1000];
    int i=0;
    long int num =0;
    
    cout << "Enter any roman number: \n";
    cin >> roman_num;
    
    
    while(roman_num[i]){
        
        if(digitValue(roman_num[i])<0){
            cout<<"Invalid Roman Number: "<< roman_num[i];
            return 0;
        }
        
        if((strlen(roman_num)-i)>2){
            if(digitValue(roman_num[i]) < digitValue(roman_num[i+2])){
                cout << "Invalid Roman Number";
                return 0;
            }
        }
        
        if(digitValue(roman_num[i]) >= digitValue(roman_num[i+1])){
            num = num + digitValue(roman_num[i]);
        }else{
            num = num +(digitValue(roman_num[i+1])- digitValue(roman_num[i]));
            i++;
        }
        i++;
    }
    
    
    cout << "The Roman numer value: " << num << endl;
           
    return 0;
}

int digitValue(char c){
    int value;
    
    switch (c) {
        case 'I':
            value = 1;
            break;
            
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
        case '\0':
            value = 0;
            break;
        default:
            value = -1;
            break;
    }
    
    return value;
}