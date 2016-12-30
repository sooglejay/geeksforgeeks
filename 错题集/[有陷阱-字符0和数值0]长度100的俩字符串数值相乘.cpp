//
// Created by sooglejay on 16/12/30.
//

/**
 * Multiply two strings
maths  string      Microsoft    Adobe    Facebook    Flipkart
Given two numbers as stings s1 and s2 your task is to multiply them. You are required to complete the function multiplyStrings which takes two strings s1 and s2 as its only argument and returns their product as strings.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow . Each test case contains two strings s1 and s2 .

Output:
For each test case in a new line the output will be a string denoting the product of the two strings s1 and s2.

Constraints:
1<=T<=100
1<=length of s1 and s2 <=100

Example(To be used only for expected output) :
Input:
2
33 2
11 23
Output:
66
253


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

**For More Examples Use Expected Output**


 * @param s1
 * @param s2
 * @return
 */
/*You are required to complete below function */
string multiplyStrings(string s1, string s2) {
    //Your code here
    int s1Size = int(s1.size());
    int s2Size = int(s2.size());
    int Size = s1Size + s2Size;
    char res[Size + 1];
    char temRes[Size + 1];
    memset(res, 0, sizeof(res));
    res[Size] = '\0';
    int a, b, cal, c, pro;
    int index = 0, k;
    for (int i = s1Size - 1; i >= 0; --i) {
        a = s1[i] - '0';
        cal = 0;
        if (a == 0)continue;

        memset(temRes, 0, sizeof(temRes));
        temRes[Size] = '\0';
        index = Size - 1 - (s1Size - 1 - i);

        for (int j = s2Size - 1; j >= 0; --j) {
            b = s2[j] - '0';
            pro = a * b + cal;
            cal = pro / 10;
            temRes[index--] = (char) (pro % 10 + '0');
        }
        if (cal > 0) {
            temRes[index--] = (char) (cal + '0');
        }


        c = 0;

        for (k = Size - 1; k >= index; --k) {
            char cha = temRes[k];
            char chb = res[k];
            a = cha == 0 ? 0 : cha - '0';
            b = chb == 0 ? 0 : chb - '0';
            pro = a + b + c;
            c = pro / 10;
            res[k] = (char) (pro % 10 + '0');
        }
        while (c > 0) {
            int pp = res[k] - '0' + c;
            if (pp < 10) {
                res[k] = (char) (pp + '0');
                c = 0;
            } else {
                res[k] = (char) (pp % 10 + '0');
                c = pp / 10;
            }
            k--;
        }
    }
    string buf;
    index = 0;
    while (res[index] - '0' <= 0) {
        index++;
    }
    while (index < Size) {
        buf += res[index++];
    }
    return buf;
}

//别人的牛逼代码
/*You are required to complete below function */
string multiplyStrings2(string s1, string s2) {
    int i, j, c, k, n1, n2, carry;
    string str = "";
    int a[10000];
    memset(a, 0, sizeof(a));
    n1 = s1.length();
    n2 = s2.length();
    for (i = n1 - 1; i >= 0; i--) {
        k = n1 - 1 - i;
        carry = 0;
        for (j = n2 - 1; j >= 0; j--) {
            c = (s2[j] - '0') * (s1[i] - '0') + a[k] + carry;
            a[k] = c % 10;
            carry = c / 10;
            k++;
        }
        a[k] = carry;
    }
    c = 1;
    for (i = k; i >= 0; i--) {
        if (c && a[i] == 0) {
            c = 1;
        } else {
            c = 0;
            str += (a[i] + '0');
        }
    }
    return str;
}



/*Complete the given function
 *
 使用这个函数 虽然很简单，但是不是自己实现的算法，感觉很虚

BigInteger 任意大的整数，原则上是，只要你的计算机的内存足够大，可以有无限位的

BigInteger 任意大的实数，可以处理小数精度问题。

class GfG{
public static String multiply(String num1, String num2) {
//add code here.
        java.math.BigInteger n1 = new java.math.BigInteger(num1);
        java.math.BigInteger n2 = new java.math.BigInteger(num2);
        java.math.BigInteger n3 = n1.multiply(n2);
        return n3+"";
    }
}

*/

