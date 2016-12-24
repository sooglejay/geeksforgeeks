//
// Created by sooglejay on 16/12/24.
//

// O(1) 算法
int fibonacci(int n) {
    // write your code here
    double Phi = 1.61803398874989484820, phi = 0.61803398874989484820;
    return (int) ((pow(Phi, n) - pow((-phi), n)) / pow(5.0, 1.0 / 2.0));
}




