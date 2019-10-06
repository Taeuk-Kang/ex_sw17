#include <iostream>
#include <list>

using namespace std;

typedef struct
{
    int x,y,age;
    bool isDead;
}woodState;
int A[10][10];
//woodState Wood[100];
int N,M,K;
int dx[8] = {-1,1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};
list<woodState> masterWood;

int main()
{
    int result;
    woodState Wood;
    scanf("%d",N);
    scanf("%d",M);
    scanf("%d",M);
    for (int i = 0; i<N; i++)
    {
        for (int j = 0; j<N; j++)
        {
            A[i][j] = 5;
        }
    }

    for (int numWood =0; numWood < M; numWood++)
    {
        scanf("%d", Wood.x);
        scanf("%d", Wood.y);
        scanf("%d", Wood.age);
        masterWood.insert(numWood,Wood);
        printf("Wood State: x(%d) y(%d) z(%d)", masterWood);
    }


    for (int year = 0; year < K; year++)
    {
        //Spring

        //Summer

        //Fall

        //Winter

    }


    return 0;
}
