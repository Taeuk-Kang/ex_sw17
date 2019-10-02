#include <iostream>
#include <stdio.h>

using namespace std;
int L, N, M, R, C;
int Map[50*50];
int Res[50*50];
bool getConnected(int i1,int j1, int i2, int j2)
{
    bool isConnected;
    if (i2<0 || j2<0 || i2>N || j2>M)
    {
	isConnected = false;
	return isConnected;
    }

    if (Res[M*i2+j2] == 1 || Map[M*i2+j2] == 0)
    {
	isConnected = false;
        return isConnected;
    }
    if (
    if (i1-i2 == 1)
    {

    }
    if (i2-i1 == 1)
    {

    }
    if (j1-j2 == 1)
    {
    }
    if (j2-j1 == 1)
    {
    }
}

int serchPrisoner(int i, int j, int count_loop)
{
    count_loop++;
    printf("count_loop out of if=%d\n", count_loop);
    if (count_loop>L)
    {
        printf("count_loop in if=%d\n", count_loop);
        return 0;
    }
    int val = Map[M*i+j];
    Res[M*i+j]=1;
    printf("Map[%d][%d] = %d\n", i,j,val);
    switch (val)
    {
    case 1:
        serchPrisoner(i,j-1,count_loop);
        serchPrisoner(i,j+1,count_loop);
        serchPrisoner(i-1,j,count_loop);
        serchPrisoner(i+1,j,count_loop);
        break;
    case 2:
        serchPrisoner(i-1,j,count_loop);
        serchPrisoner(i+1,j,count_loop);
        break;
    case 3:
        serchPrisoner(i,j-1,count_loop);
        serchPrisoner(i,j+1,count_loop);
        break;
    case 4:
        serchPrisoner(i-1,j,count_loop);
        serchPrisoner(i,j+1,count_loop);
        break;
    case 5:
        serchPrisoner(i+1,j,count_loop);
        serchPrisoner(i,j+1,count_loop);
        break;
    case 6:
        serchPrisoner(i+1,j,count_loop);
        serchPrisoner(i,j-1,count_loop);
        break;
    case 7:
        serchPrisoner(i-1,j,count_loop);
        serchPrisoner(i,j-1,count_loop);
        break;
    }
    return 0;
}
int cal_res()
{
    int res = 0;
    for(int i=0;i<N*M;i++)
    {
        res=res+Res[i];
    }
    return res;
}
int main()
{
    int numTest, result;
    scanf("%d",&numTest);
    for (int temp = 0; temp < 50*50; temp++)
    {
        Map[temp]=0;
        Res[temp]=0;
    }

    for (int curTest = 0; curTest<numTest; curTest++)
    {
        printf("start loop\n");
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &R);
        scanf("%d", &C);
        scanf("%d", &L);
        printf("%d %d %d %d %d\n", N, M, R, C, L);
        for (int input = 0; input < N*M; input ++)
        {
            scanf("%d", &Map[input]);
        }

        result = serchPrisoner(R,C,0);

        result = cal_res();

        printf("#%d %d\n", curTest+1, result);
        for (int reset = 0; reset < N*M; reset++)
        {
            printf("%d ", Map[reset]);
            Map[reset] = 0;
            //Res[reset] = 0;
            if ((reset%M)==M-1)
                printf("\n");

        }
        printf("\n");
        for (int reset = 0; reset < N*M; reset++)
        {
            printf("%d ", Res[reset]);
            //Map[reset] = 0;
            Res[reset] = 0;
            if ((reset%M)==M-1)
                printf("\n");

        }
    }
    return 0;
}
