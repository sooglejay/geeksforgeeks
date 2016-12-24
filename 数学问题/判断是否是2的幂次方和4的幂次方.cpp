//
// Created by sooglejay on 16/12/24.
//

#include <iostream>

using namespace std;
bool isPowerOfTwo(int n) {
    int bits=0;
    while(n>0){
        bits++;
        n &=(n-1);
    }
    return bits==1;
}
bool isPowerOfFour(int num) {
    if(num<4){
        return false;
    }
    while(num>4){
        num>>=2;
    }
    return num==4;
}
//二进制反转
uint32_t hammingWeight(uint32_t n) {
    char array[33];
    uint32_t res = 0;
    int tem = 0;
    for (int i = 31; i >= 0; --i) {
        tem = 0;
        if (n > 0) {
            tem = n & 1;
            n >>= 1;
        }
        array[i] = tem + '0';
    }
    int base = 1;
    for (int j = 0; j < 32; ++j) {
        if (array[j] == '1') {
            res += base * 1;
        }
        base *= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        uint32_t a;
        cin >> a;
        cout << isPowerOfFour(a) << endl;
    }
}
