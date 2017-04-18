//
// Created by sooglejay on 17/4/15.
//


//http://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number/0

//        Input  : N = “1234”
//        Output : 1670
//        Sum = 1 + 2 + 3 + 4 + 12 + 23 +
//              34 + 123 + 234 + 1234
//                      = 1670
//
//        Input  : N = “421”
//        Output : 491
//        Sum = 4 + 2 + 1 + 42 + 21 + 421
//                      = 491

//此题做了40分钟，后来发现是basic 等级，伤
//http://www.geeksforgeeks.org/sum-of-all-substrings-of-a-string-representing-a-number/
//

//        Where sumofdigit[i] stores sum of all substring ending at ith index digit, in above example,
//
//    Example : num = "1234"
//        sumofdigit[0] = 1 = 1
//        sumofdigit[1] = 2 + 12  = 14
//        sumofdigit[2] = 3 + 23  + 123 = 149
//        sumofdigit[3] = 4 + 34  + 234 + 1234  = 1506
//        Result = 1670
//        Now we can get the relation between sumofdigit values and can solve the question iteratively. Each sumofdigit can be represented in terms of previous value as shown below,
//
//    For above example,
//        sumofdigit[3] = 4 + 34 + 234 + 1234
//        = 4 + 30 + 4 + 230 + 4 + 1230 + 4
//        = 4*4 + 10*(3 + 23 +123)
//        = 4*4 + 10*(sumofdigit[2])
//        In general,
//                sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]

#include <iostream>

#include <string.h>
using namespace std;
int doDp(int i, int j, int *arr) {
    //计算数组[i,...,j]这段数字组成的数值
    int s = 0;
    for (int k = i; k <= j; ++k) {
        s = s * 10 + arr[k];
    }
    return s;
}

int func(int n) {
    int arr[7];
    memset(arr, 0, sizeof(arr));
    int i = 0;
    //将一个数值 存入数组
    while (n) {
        arr[i++] = n % 10;
        n /= 10;
    }
    int left = 0;
    int right = i - 1;
    //需要将数组反转，因为arr目前是 倒着的。比如n是4129，arr目前是9,2,1,4
    while (left < right && left < i && right >= 0) {
        swap(arr[left++], arr[right--]);
    }
    int dp[7];//动归，dp[i]表示从i开始的sum，所以结果只需返回dp[0]
    memset(dp, 0, sizeof(dp));
    for (int l = 0; l < i; ++l) {
        dp[l] = arr[l];//初始化，这是可选的，
        // 不这样做就需要修改下面的for循环
    }
    for (int k = i - 2; k >= 0; --k) {
        int sum = 0;
        //从加数组中[k,...,j]的数值，比如4129，i＝4，
        // k＝1时，需要加129+12
        for (int j = i - 1; j > k; --j) {
            sum += doDp(k, j, arr);
        }
        dp[k] += sum + dp[k + 1];
    }
    return dp[0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        cout << func(p) << endl;
    }
    return 0;
}


//下面是牛逼的 代码

//  C++ program to print sum of all substring of
// a number represented as a string
#include <bits/stdc++.h>
using namespace std;

// Utility method to covert character digit to
// integer digit
int toDigit(char ch)
{
    return (ch - '0');
}

// Returns sum of all substring of num
int sumOfSubstrings(string num)
{
    int n = num.length();

    //  allocate memory equal to length of string
    int sumofdigit[n];

    //  initialize first value with first digit
    sumofdigit[0] = toDigit(num[0]);
    int res = sumofdigit[0];

    //  loop over all digits of string
    for (int i=1; i<n; i++)
    {
        int numi = toDigit(num[i]);

        // update each sumofdigit from previous value
        sumofdigit[i] = (i+1) * numi +
                        10 * sumofdigit[i-1];

        // add current value to the result
        res += sumofdigit[i];
    }

    return res;
}

//  Driver code to test above methods
int main()
{
    string num = "1234";
    cout << sumOfSubstrings(num) << endl;
    return 0;
}
