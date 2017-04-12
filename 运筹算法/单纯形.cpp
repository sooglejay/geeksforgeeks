//
// Created by sooglejay on 17/3/26.
//



#include <iostream>
#include <vector>
#include <cmath>
#include "deploy.h"
using namespace std;
static const double DOUBLE_MIN=1e-8;

/**
该函数利用单纯形法来求解线性规划，并且目前只考虑“≤约束条件”（加入松弛变量即形成可行基），不考虑
“≥约束条件”（加入非负人工变量）。
matrixA：这是一个矩阵的，前面各列保存各个x对应的系数矩阵，最后的一列则保存b。另外，将松弛变量
	对应的系数放在最前面，所以该矩阵的最前面是一个m*m的方阵（假设该线性规划共有m个约束条件不等式）。
*/
LinearProgrammingResult linearProgrammingSimplexMethodInteger(vector<vector<double> >& matrixA,vector<double>& vectorC){
    int m=matrixA.size();//方程的个数
    int n=vectorC.size();
    LinearProgrammingResult result(n-m);
    if(m<=0||n<=0||matrixA.at(0).size()-1!=n){
        result.kind=LinearProgrammingResultKind::NO_FEASIBLE_ANSWER;
        return result;
    }

    int optimalValue=0;
    vector<int> positionList(n);
    for(int i=0;i<n;i++)
        positionList.at(i)=i;
    while(true){
        //1. 检测检验数，判断该线性规划的解的情况;
        vector<int> checkAboveZeroList;
        for(int i=m;i<n;i++){
            if(vectorC.at(i)>0)
                checkAboveZeroList.push_back(i);
        }
        if(checkAboveZeroList.size()==0){
            bool isUnique=true;
            for(int i=m;i<n;i++)
                if(fabs(vectorC.at(i))<DOUBLE_MIN){
                    isUnique=false;
                    break;
                }

            if(isUnique){ //存在唯一解
                result.kind=LinearProgrammingResultKind::UNIQUE_OPITMAL_ANSWER;
                result.cost=optimalValue;
                //根据positionList中存储的系数与系数直接的对应关系，设置变量的真实系数，
                //	系数值要么是矩阵A的最后一列b中的某一个（基量），要么就是0（非基量）。
                for(int i=0;i<n;i++){
                    if(positionList.at(i)>=m){
                        result.valueList.at(positionList.at(i)-m)=(i<m?matrixA[i][n]:0);
                    }
                }
            }else{//存在无穷多解
                result.kind=LinearProgrammingResultKind::INFINITE_ANSWER;
            }
            return result;
        }else{
            int inI,outI;
            double max;
            bool isLimited;
            for(int i=0;i<checkAboveZeroList.size();i++){
                double min=0;
                bool isFound=false;
                isLimited=false;
                if(i==0){//为了给max进行初始化
                    max=vectorC.at(checkAboveZeroList.at(i));
                    //寻找需要换入和换出的基量
                    for(int j=0;j<m;j++){
                        if(!isFound&&matrixA[j][checkAboveZeroList.at(i)]>0&&matrixA[j][n]>=0){
                            isFound=true;
                            isLimited=true;
                            inI=checkAboveZeroList.at(i);
                            outI=j;
                            min=matrixA[j][n]/matrixA[j][checkAboveZeroList.at(i)];
                            continue;
                        }
                        if(isFound&&matrixA[j][checkAboveZeroList.at(i)]>0&&matrixA[j][n]>=0&&
                           matrixA[j][n]/matrixA[j][checkAboveZeroList.at(i)]<min){
                            inI=checkAboveZeroList.at(i);
                            outI=j;
                            min=matrixA[j][n]/matrixA[j][checkAboveZeroList.at(i)];
                        }
                    }

                }else{//处理剩余的满足检验条件的列
                    if(vectorC.at(checkAboveZeroList.at(i))<=max){//因为该检验数比最大值小，所以只做是否无界检测
                        for(int j=0;j<m;j++){
                            if(!isFound&&matrixA[j][checkAboveZeroList.at(i)]>0&&matrixA[j][n]>=0){
                                isLimited=true;
                                break;
                            }
                        }
                    }else{
                        max=vectorC.at(checkAboveZeroList.at(i));
                        for(int j=0;j<m;j++){
                            if(!isFound&&matrixA[j][checkAboveZeroList.at(i)]>0&&matrixA[j][n]>=0){
                                isFound=true;
                                isLimited=true;
                                inI=checkAboveZeroList.at(i);
                                outI=j;
                                min=matrixA[j][n]/matrixA[j][checkAboveZeroList.at(i)];
                                continue;
                            }
                            if(isFound&&matrixA[j][checkAboveZeroList.at(i)]>0&&matrixA[j][n]>=0&&
                               matrixA[j][n]/matrixA[j][checkAboveZeroList.at(i)]<min){
                                inI=checkAboveZeroList.at(i);
                                outI=j;
                                min=matrixA[j][n]/matrixA[j][checkAboveZeroList.at(i)];
                            }
                        }
                    }
                }
                if(!isLimited)
                    break;
            }
            if(!isLimited){//无界解
                result.kind=LinearProgrammingResultKind::NO_BOUNDED_ANSWER;
                return result;
            }
                //2. 将相应的基量和非基量交换
            else{
                //2.1 更新A：利用矩阵行变换将第inI列变为第outI列的内容，即变为一个单位列向量，第outI个元素为1
                if(fabs(matrixA[outI][inI])>DOUBLE_MIN){
                    for(int i=0;i<m;i++){
                        if(i==outI||fabs(matrixA[i][inI])<DOUBLE_MIN)
                            continue;
                        double div=matrixA[i][inI]/matrixA[outI][inI];
                        for(int j=0;j<=n;j++){//根据矩阵行变换，更新该行
                            matrixA[i][j]-=(div*matrixA[outI][j]);
                        }
                    }
                    //根据矩阵行变换将第outI行的第inI列元素置为1
                    if(fabs(matrixA[outI][inI]-1)>DOUBLE_MIN){
                        for(int j=0;j<=n;j++){//根据矩阵行变换，更新该行
                            if(j==inI)
                                continue;
                            matrixA[outI][j]/=matrixA[outI][inI];
                        }
                        matrixA[outI][inI]=1;
                    }
                }
                //2.2 更新费用
                optimalValue+=(vectorC.at(inI)*matrixA[outI][n]);
                //2.3 更新向量c
                if(fabs(vectorC.at(inI))>DOUBLE_MIN){
                    for(int i=0;i<n;i++){
                        if(i==inI)
                            continue;
                        vectorC.at(i)-=(vectorC.at(inI)*matrixA[outI][i]);
                    }
                    vectorC.at(inI)=0;
                }
                //2.4 交换矩阵A：第inI列与第outI列交换
                for(int i=0;i<m;i++){
                    double tmp=matrixA[i][inI];
                    matrixA[i][inI]=matrixA[i][outI];
                    matrixA[i][outI]=tmp;
                }
                //2.5 交换向量c：第inI元素与第outI元素交换
                double tmp=vectorC.at(inI);
                vectorC.at(inI)=vectorC.at(outI);
                vectorC.at(outI)=tmp;
                //2.6 保存原序列顺序
                int t=positionList.at(inI);
                positionList.at(inI)=positionList.at(outI);
                positionList.at(outI)=t;
            }
        }
    }
}

void testLinearProgrammingSimplexMethodInteger(){
    vector<vector<double> > matrix;
    vector<double> row;
    ////////////////////////////////////////////////
    /*
    案例真实结果：最优值为14，x1=4，x2=2。
    该案例取自《单纯形法原理讲解.ppt》(http://wenku.baidu.com/link?url=2RU-il2OGzmhDo8a9-J8wf_MAN_toNk3UKZhCVwSTa_g0BRWU32qWW_uddN7rsLuQImwbocK8QzoCpX9AYwWk3fTnSVAs1_-cl55OxBGHOG)
    */
    matrix.clear();
    row.clear();
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    row.push_back(-2);
    row.push_back(2);
    row.push_back(12);
    matrix.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(1);
    row.push_back(0);
    row.push_back(-2);
    row.push_back(0);
    row.push_back(1);
    matrix.push_back(row);
    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    row.push_back(-4);
    row.push_back(3);
    row.push_back(27);
    matrix.push_back(row);
    row.clear();

    vector<double> c;
    c.push_back(3);
    c.push_back(-3);
    c.push_back(-1);
    c.push_back(-3);
    c.push_back(5);

    LinearProgrammingResult result=linearProgrammingSimplexMethodInteger(matrix,c);
    result.print();
}




//main.cpp

#if 1

#include "deploy.h"
int main(){
    testLinearProgrammingSimplexMethodInteger();
}

#endif



//header


#ifndef JLU_CCST_LINEAR_PROGRAMING_H
#define JLU_CCST_LINEAR_PROGRAMING_H
#include <iostream>
#include <vector>
enum LinearProgrammingResultKind{
    NO_FEASIBLE_ANSWER=0,
    NO_BOUNDED_ANSWER,
    INFINITE_ANSWER,
    UNIQUE_OPITMAL_ANSWER
} ;
struct LinearProgrammingResult{
    double cost;
    std::vector<double> valueList;
    LinearProgrammingResultKind kind;
    LinearProgrammingResult(int n=0){
        if(n<0)
            n=0;
        valueList.resize(n);
    }
    void print(){
        std::cout<<"Optimal Cost:"<<cost<<std::endl;
        std::cout<<"Value of each variable:"<<std::endl;
        for(int i=0;i<valueList.size();i++){
            std::cout<<"x"<<(i+1)<<"="<<valueList.at(i)<<std::endl;
        }
    }
};
extern LinearProgrammingResult linearProgrammingSimplexMethodInteger(std::vector<std::vector<double> >& matrixA,
                                                                     std::vector<double>& vectorC);
extern void testLinearProgrammingSimplexMethodInteger();

#endif//JLU_CCST_LINEAR_PROGRAMING_H