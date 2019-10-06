#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int Map[20][20];
int isCome[20][20];
int N;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


typedef struct _shark
{
    int pos_x;
    int pos_y;
    int time;
}sharkState;

int sharkSize, sharkEat;

int main()
{
    sharkState refShark, curShark, nextShark;
    int result = 0;
    scanf("%d",&N);
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            scanf("%d", &Map[y][x]);
            if(Map[y][x] == 9)
            {
                sharkSize = 2;
                refShark.pos_x = x;
                refShark.pos_y = y;
                refShark.time = 0;
                Map[y][x] = 0;
            }
        }
    }

    queue<sharkState> q;
    sharkState cand;
    //q.push(curShark);
    bool isUpdate = true;
    while(isUpdate)
    {
        isUpdate = false;
        bool visited[20][20] = {false, };

        q.push(refShark);
        cand.pos_y = 20;
        cand.pos_x = 20;
        cand.time = -1;

        while(!q.empty())
        {
            //printf("count while\n");
            curShark = q.front();
            q.pop();
            //printf("shark info : x(%d) y(%d) time(%d)\n", curShark.pos_x, curShark.pos_y, curShark.time);
            if(cand.time != -1 && curShark.time > cand.time)
            {
                /*printf("Stop loop\n");
                isUpdate = true;
                Map[cand.pos_y][cand.pos_x] = 0;
                //result = result + cand.time;
                refShark.pos_x = cand.pos_x;
                refShark.pos_y = cand.pos_y;
                refShark.time = cand.time;
                while(!q.empty())
                {
                    q.pop();
                }
                break;*/
            }
            else
            {
                if(visited[curShark.pos_y][curShark.pos_x] == false)
                {
                    if(Map[curShark.pos_y][curShark.pos_x] > 0 && Map[curShark.pos_y][curShark.pos_x] < sharkSize)
                    {
                        //printf("find feed\n");
                        if (curShark.pos_y < cand.pos_y || (curShark.pos_y == cand.pos_y && curShark.pos_x < cand.pos_x))
                        {
                            cand.pos_x = curShark.pos_x;
                            cand.pos_y = curShark.pos_y;
                            cand.time = curShark.time;
                        }
                    }
                    else if(Map[curShark.pos_y][curShark.pos_x] == 0 || Map[curShark.pos_y][curShark.pos_x] == sharkSize)
                    {
                        //printf("keep serching \n");
                        visited[curShark.pos_y][curShark.pos_x] = true;
                        for(int dir = 0; dir < 4; dir++)
                        {
                            nextShark.pos_x = curShark.pos_x + dx[dir];
                            nextShark.pos_y = curShark.pos_y + dy[dir];
                            nextShark.time = curShark.time + 1;
                            if (nextShark.pos_x > -1 && nextShark.pos_x < N &&nextShark.pos_y > -1 && nextShark.pos_y < N)
                            {
                                q.push(nextShark);
                            }
                        }
                    }
                }
            }
        }
        if (cand.time != -1)
        {
            //printf("Stop loop\n");
            isUpdate = true;
            Map[cand.pos_y][cand.pos_x] = 0;
            //result = result + cand.time;
            refShark.pos_x = cand.pos_x;
            refShark.pos_y = cand.pos_y;
            refShark.time = cand.time;

            sharkEat = sharkEat + 1;
            if (sharkEat == sharkSize)
            {
                sharkEat = 0;
                sharkSize = sharkSize + 1;
            }
        }
        /*for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                printf("%d ", Map[y][x]);
            }
            printf("\n");
        }*/

    }

    printf("%d\n",refShark.time);

    return 0;
}
