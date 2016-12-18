//
// Created by sooglejay on 16/12/18.
//*

/**
Given two numbers, the task is to find the number of carry operations required when two numbers are added as below..
1234
+
5678
--------
6912
--------
4+8 = 2 and carry 1
carry+3+7 = carry 1
carry+2+6 = 9, carry 0
carry+1+5 = 6

We need two carry operations in this example.

Input:
        First line of input consists of an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains two unsigned integers(n1,n2) less than 10 digits.

Output:
        For each test case in a new line print the number of carry operations that would be required while adding n1 and n2.

Constraints:
1<=T<=50
1<=n1, n2 <= 9*10^10

Example:
        Input:
3
123 456
555 555
123 594


Output:
0
3
1

**For More Examples Use Expected Output*
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>


#include <stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

//统计位数，然后构造 一个与最大数 相同位数的temp数组，不足位数的temp该位 补数值0
int main() {
    int t;
    cin >> t;
    while (t--) {
        char a[11],b[11],temp[11];//19 位没问题
        cin >>a>>b;
        int lenA = strlen(a);
        int lenB = strlen(b);

        int culLen;

        if(lenA<lenB){
            for (int i = 0; i < lenB-lenA; ++i) {
                temp[i] = '0';
            }
            for (int j = lenB-lenA; j <lenB; ++j) {
                temp[j] = a[j-lenB+lenA];
            }
            culLen = lenB;

            int car = 0;
            int sumCount = 0,sum=0 ;
            for (int i = culLen-1; i>=0; --i) {
                int A = temp[i]-'0';
                int B = b[i]-'0';
                sum = A + B+ car;
                sumCount += car;
                if(sum>=10){
                    car = 1;
                }else{
                    car = 0;
                }
            }
            sumCount += car;
            cout<<sumCount<<endl;


        }else if(lenA>lenB){
            for (int i = 0; i < lenA-lenB; ++i) {
                temp[i] = '0';
            }
            for (int j = lenA-lenB; j <lenA; ++j) {
                temp[j] = b[j-lenA+lenB];
            }
            culLen = lenA;

            int car = 0;
            int sumCount = 0,sum=0 ;
            for (int i = culLen-1; i>=0; --i) {
                int A = a[i]-'0';
                int B = temp[i]-'0';
                sum = A + B+ car;
                sumCount += car;
                if(sum>=10){
                    car = 1;
                }else{
                    car = 0;
                }
            }
            sumCount += car;
            cout<<sumCount<<endl;
        }else{
            culLen = lenA;
            int car = 0;
            int sumCount = 0,sum=0 ;
            for (int i = culLen-1; i>=0; --i) {
                int A = a[i]-'0';
                int B = b[i]-'0';
                sum = A + B+ car;
                sumCount += car;
                if(sum>=10){
                    car = 1;
                }else{
                    car = 0;
                }
            }
            sumCount += car;
            cout<<sumCount<<endl;


        }


    }
    return 0;
}


