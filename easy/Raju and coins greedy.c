/*
Raju and coins
greedy  
Raju always like to collect coins. Raju has already managed to collect n different types of coins a1,a2....an . One day he went into the sale and find out that the sale consists of 109 types of coins where i-th type of coin costs i dollars. He decided to buy some more different types of coins given that he does not have that type of coin already. But he has only k dollars to spend.
So help him to choose the type of coins.

 

Input:

The first line will contain test cases T. Then T Test cases follow. Each of the test cases will contain two integers n, k   the number of types of coins that Raju already has and the money he has respectively. The next line contains n distinct integers a1,a2...an the types of coins that Raju already has.


Output:

Print a single integer denoting the number of different types of coins that Raju can buy so that the number of different coins in his collection is maximum. Cost should not exceed k.

Constraints:

1<=T<=27
1<=n<=100000
1<=k<=109
1<=ai<=109

Example:

Input                          
2                               
4 14                           
4 6 12 8                        
3 7                             
1 3 4

Output
4
2
 

Explanation:
For the second test case Raju should buy two coins: one coin of the 2-nd type and one coin of the 5-th type. For any other purchase for 7 dollars(assuming that the coins of types 1, 3 and 4 have already been bought), it is impossible to buy more than two coins.
 

**For More Examples Use Expected Output**/
 
 // The main idea of this problem is to calculate the maximum different types of coins bought less or equal than k
 // Execution Time:0.075



#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        sort(A, A + n);
        int start = 1;
        int types = 0;
        for (int j = 0; j < n; ++j) {
            while (k >= start && A[j] > start) {
                types++;
                k -= start;
                start++;
            }
            start = A[j] + 1;
        }
        while (k >= start) {
            types++;
            k -= start;
            start++;
        }
        cout << types << endl;
    }
}