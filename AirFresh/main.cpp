#include <iostream>
#include <stdio.h>
using namespace std;

int Map[50][50];
int Stat[50][50];
int Pos[2];
int R,C,T;
void Diffuse()
{
    int val, countVal;
    /*for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            if (Map[countR][countC] > 0)
                Stat[countR][countC] = 1;
        }
    }*/

    for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            if(Map[countR][countC] > 0)
            {
                countVal = 0;
                val = Map[countR][countC]/5;
                if(countR - 1 > -1 && Map[countR-1][countC]>-1)
                {
                    //Map[countR-1][countC]=Map[countR-1][countC] + val;
                    Stat[countR-1][countC] = Stat[countR-1][countC] + val;
                    countVal++;
                }
                if(countC - 1 > -1 && Map[countR][countC-1]>-1){
                    //Map[countR][countC-1]=Map[countR][countC-1] + val;
                    Stat[countR][countC-1] = Stat[countR][countC-1] + val;
                    countVal++;
                }
                if(countR + 1 < R && Map[countR+1][countC]>-1){
                    //Map[countR+1][countC]=Map[countR+1][countC] + val;
                    Stat[countR+1][countC] = Stat[countR+1][countC] + val;
                    countVal++;
                }
                if(countC + 1 < C && Map[countR][countC+1]>-1){
                    //Map[countR][countC+1]=Map[countR][countC+1] + val;
                    Stat[countR][countC+1] = Stat[countR][countC+1] + val;
                    countVal++;
                }
                Map[countR][countC] = Map[countR][countC] - val*countVal;
                if (Map[countR][countC] <0)
                    Map[countR][countC] = 0;
            }
        }
    }
    for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            Map[countR][countC] = Map[countR][countC] + Stat[countR][countC];
            Stat[countR][countC] = 0;
        }
    }

}
void Circle()
{
    for (int countC = 0; countC < C-1; countC++)
    {
        Stat[0][countC] = (-1)*Map[0][countC] + Map[0][countC+1];
        Stat[R-1][countC] = (-1)*Map[R-1][countC] + Map[R-1][countC+1];
        Stat[Pos[0]][countC+1] = (-1)*Map[Pos[0]][countC+1] + Map[Pos[0]][countC];
        Stat[Pos[1]][countC+1] = (-1)*Map[Pos[1]][countC+1] + Map[Pos[1]][countC];
    }

    Stat[Pos[0]][1] = (-1)*Map[Pos[0]][1];
    Stat[Pos[1]][1] = (-1)*Map[Pos[1]][1];

    for (int countR = 0; countR < Pos[0]; countR++)
    {
        Stat[countR+1][0] = (-1)*Map[countR+1][0] + Map[countR][0];
        Stat[countR][C-1] = (-1)*Map[countR][C-1] + Map[countR+1][C-1];
    }
    for (int countR = Pos[1]; countR < R-1; countR++)
    {
        Stat[countR][0] = (-1)*Map[countR][0] + Map[countR+1][0];
        Stat[countR+1][C-1] = (-1)*Map[countR+1][C-1] + Map[countR][C-1];
    }
    Stat[Pos[0]][0] = 0;
    Stat[Pos[1]][0] = 0;
    for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            Map[countR][countC] = Map[countR][countC] + Stat[countR][countC];
            Stat[countR][countC] = 0;
        }
    }

}

int cal_res()
{
    int sum = 0;
    for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            if (Map[countR][countC] != -1)
                sum = sum + Map[countR][countC];
        }
    }
    return sum;
}

int main()
{
    int result, position = 0;
    scanf("%d",&R);
    scanf("%d",&C);
    scanf("%d",&T);

    for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            scanf("%d",&Map[countR][countC]);
            if (Map[countR][countC] == -1)
            {
                Pos[position++] = countR;
            }
        }
    }
    for (int countT = 0; countT<T; countT++)
    {
        Diffuse();
        Circle();
    }
    result = cal_res();
    printf("Result : %d\n",result);

    /*for(int countR = 0; countR<R; countR++)
    {
        for(int countC = 0; countC<C; countC++)
        {
            printf(" %d ",Map[countR][countC]);
        }
        printf("\n");
    }*/
}
