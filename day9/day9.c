#include<stdio.h>

//面试题 17.04. 消失的数字
//代码：

int missingNumber(int* nums, int numsSize){
    
    int i,sum=0;


    //边加边减，差是多少就少谁
    for(i=1;i<=numsSize;++i)
    {
        sum+=i-nums[i-1];
    }
    return sum;
}