#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int N;
int A[1000000];
int B,C;

int main()
{
    double int res = 0;
    int div;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    scanf("%d %d", &B, &C);

    for(int i = 0; i < N; i++){
        res += 1;
        A[i] -= B;
        if(A[i] > 0){
            if(A[i]%C == 0){
                div = A[i]/C;
            }
            else{
                div = A[i]/C + 1;
            }
            res += div;
        }

    }
    printf("%d\n", res);
    return 0;
}
