//
// Created by sooglejay on 16/12/18.
//

//
//Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
//
//Input:
//        The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string str .
//
//Output:
//        For each test case in a new line output will be an integer denoting the converted integer, if the input string is not a numerical string then output will be -1.
//
//Constraints:
//1<=T<=100
//1<=length of (s,x)<=10
//
//Example(To be used only for expected output) :
//Input:
//2
//123
//21a
//
//Output:
//123
//-1



/*You are required to complete this method */
int atoi(string str)
{


    int len = str.size();
    int minus='-';//48-57
    int sum = 0 ;
    int count = 0;
    for (int i = len-1; i>=1; --i) {
        int num = str[i]-'0';

        if(num<=9&&num>=0){
            sum += num*(int)pow(10,count);
        }else{
            return -1;
        }
        count++;
    }
    if(str[0]=='-'){
        return sum*-1;
    }else {
        int num = str[0]-'0';
        if(num<=9&&num>=0){
            sum += num*(int)pow(10,count);
        }else{
            return -1;
        }
    }
    return sum;

}
