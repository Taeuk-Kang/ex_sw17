#include <iostream>
#include <stdio.h>

using namespace std;

int N,M,H;
int pa[2700];
int pb[2700];

int Map[30][10] = {0,};
int candi[30][10] = {0,};
int getRes(int a, int b)
{
    int pos;
    if(a>=H){
        printf("%d\n",b);
        return b;
    }
    else if (b < N-1 && Map[a][b] == 1){
        //printf("count case 1 %d\n",b);
        pos = getRes(a+1,b+1);
    }
    else if (b > 0 && Map[a][b-1] == 1){
        //printf("count case 2 %d\n",b);
        pos = getRes(a+1,b-1);
    }
    else {
        //printf("count case 3 %d\n",b);
        pos = getRes(a+1,b);
    }
    return pos;
}
int main()
{
    int result=0;
    scanf("%d %d %d", &N, &M, &H);
    for (int i = 0; i<M; i++){
        scanf("%d %d",&pa[i],&pb[i]);
        pa[i] -= 1;
        pb[i] -= 1;
    }
    for (int a = 0; a < H; a++){
        for (int b = 0; b<N-1; b++){
            candi[a][b] = 1;
        }
    }
    for (int i = 0; i < M; i++){
        Map[pa[i]][pb[i]] = 1;
        candi[pa[i]][pb[i]] = 0;
        candi[pa[i]][pb[i]+1] = 0;
    }
    while(result < 3){
        for(int b = 0; b<N-1; b++){
            if(b == getRes(0,b)){

                break;
            }
        }
        result++;
    }
    result = getRes(0,0);
    if (result >= 3)    result = -1;
    printf("%d\n", result);
    return 0;
}
