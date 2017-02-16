//
// Created by sooglejay on 17/1/12.
//

// A recursive program to print all possible
// partitions of a given string into dictionary
// words




//http://www.geeksforgeeks.org/word-break-problem-using-backtracking/
//http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
//        http://www.practice.geeksforgeeks.org/problem-page.php?pid=1277

//我觉得这道题非常适合练手！
#include <iostream>

using namespace std;

/* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.  Using array
  of strings for dictionary is definitely not
  a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string &word) {
    string dictionary[] = {"mobile", "samsung", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "love", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

//prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// Prints all possible word breaks of given string
void wordBreak(string str) {
    // last argument is prefix
    wordBreakUtil(str, str.size(), "");
}

// result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result) {
    //Process all prefixes one by one
    for (int i = 1; i <= n; i++) {
        //extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // if dictionary conatins this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(prefix)) {
            // if no more elements are there, print it
            if (i == n) {
                // add this element to previous prefix
                result += prefix;
                cout << result << endl; //print result
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i,
                          result + prefix + " ");
        }
    }      //end for
}//end function

int main() {
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");

    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}