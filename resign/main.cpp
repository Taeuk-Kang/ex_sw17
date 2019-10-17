#include <iostream>
#include <stdio.h>

using namespace std;
int n;
int T[15],P[15];
int candi[15];

int findMax(int num1, int num2)
{
    int ret = num2;
    if(num1>num2){
        ret = num1;
    }
    return ret;
}

int funcMax(int i)
{
    int res = 0;
    if (i >= n){
        return 0;
    }
    if (i + T[i] > n){
        P[i] = 0;
    }
    res = findMax(funcMax(i+1),(funcMax(i+T[i]) + P[i]));
    return res;
}

int main()
{
    int result;
    scanf("%d",&n);
    for(int i =0; i<n; i++){
        scanf("%d %d",&T[i],&P[i]);
    }
    result = funcMax(0);
    printf("%d\n",result);

    return 0;
}
