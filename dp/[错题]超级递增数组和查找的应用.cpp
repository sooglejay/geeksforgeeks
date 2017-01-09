//
// Created by sooglejay on 17/1/8.
//

#include<iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long int lli;

//此题很神奇，因为下面的B数组本身 很有特点，它叫做超级递增数组，
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1588


//Tricky Subset Problem [Editorial]
//
//
//
//This is a simple subset sum problem in which we have to pick up numbers from an array such that it sums up to X. For the basic subset sum look into this link : http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
//
//But in this problem we won't be able to use the above method because we can not create an array of one of the dimension as 10^18. So we have to look in a different way.
//
// On looking closer we see that there is a special feature in this sequence.
// Here every number is greater than the sum of the previous numbers. This is known as a Super Increasing sequence.
// So, the basic logic behind this is that find the number X, if it is there in the sequence then we print "yes".
// If it is not present then we find the number just less than X and subtract it from X and update the X to this new value.
// We do this because if we do not use the number just less than X for making X, then all the numbers less than X also cannot make it to X ( Property of Super Increasing Sequence ).
// By continuing this if X>0 after all the numbers exhaust then we print "no".
//
//
//
//As the sequence is sorted in Increasing order, searching takes O ( log N ) time and for N numbers maximum it has to do N searches. So the overall complexity reduces to O ( N log N ).


int main() {
    int t;
    cin >> t;
    while (t--) {
        lli S, N, X;
        cin >> S >> N >> X;
        lli A[100001];
        lli B[100001];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        B[0] = S;
        for (lli i = 0; i < N; ++i) {
            cin >> A[i];
        }
        lli cur = S;
        lli j = 0;
        for (j = 0; j < N; ++j) {
            B[j + 1] = A[j] + cur;
            if (cur > X) {
                break;
            }
            cur = cur + B[j + 1];
            if (cur > X) {
                break;
            }
        }
        j += 2;
        int flag = 0;
        while (X) {
            if (find(B, B + j, X) != B + j) {
                flag = 1;
                break;
            }
            lli index = lower_bound(B, B + j, X) - B;
            if (index < 1) {
                break;
            }
            // index-1 的原因是 查找算法都是从1开始的。
            X = X - B[index - 1];
            if (X < 0) {
                break;
            } else if (X == 0) {
                flag = 1;
            }
        }
        (flag == 1) ? cout << "yes\n" : cout << "no\n";
    }
}
