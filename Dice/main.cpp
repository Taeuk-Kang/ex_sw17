#include <stdio.h>

int N,M,x,y,K;
int Dx[4] = {0,};
int Dy[4] = {0,};
int Map[20][20];
int order[1000];

void swap_dice(int val)
{
    int temp;
    switch(val){
    case 1:
        {
            Dy[1] = Dx[0];
            Dy[3] = Dx[2];
            temp = Dx[3];
            for(int i = 0; i < 3; i++){
                Dx[3-i] = Dx[2-i];
            }
            Dx[0] = temp;
            break;
        }
    case 2:
        {
            Dy[1] = Dx[2];
            Dy[3] = Dx[0];
            temp = Dx[0];
            for (int i = 0; i<3;i++){
                Dx[i] = Dx[i+1];
            }
            Dx[3] = temp;
            break;
        }
    case 3:
        {
            Dx[1] = Dy[2];
            Dx[3] = Dy[0];
            temp = Dy[0];
            for (int i = 0; i<3; i++){
                Dy[i]=Dy[i+1];
            }
            Dy[3] = temp;
            break;
        }
    case 4:
        {
            Dx[1] = Dy[0];
            Dx[3] = Dy[2];
            temp = Dy[3];
            for (int i = 0; i < 3; i++){
                Dy[3-i] = Dy[2-i];
            }
            Dy[0] = temp;
            break;
        }
    }
}

int main()
{
    int val;
    //x<N-1, y<M-1
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d",&Map[j][i]);
        }
    }

    for (int i = 0; i < K; i++){
        scanf("%d",&order[i]);
    }
    //Dx[1],Dy[1] = current pos

    for (int i = 0; i < K; i++){
        val = order[i];
        switch(val){
        case 1:
            {
                if(y < M - 1){
                    swap_dice(val);
                    printf("%d\n",Dx[1]);
                    y++;
                    if(Map[y][x] != 0){
                        Dx[3] = Map[y][x];
                        Dy[3] = Map[y][x];
                        Map[y][x] = 0;
                    }
                    else{
                        Map[y][x] = Dx[3];
                    }
                    //printf("Dx stat %d %d %d %d\n", Dx[0], Dx[1], Dx[2], Dx[3]);
                    //printf("Dy stat %d %d %d %d\n", Dy[0], Dy[1], Dy[2], Dy[3]);
                }
                break;
            }
        case 2:
            {
                if(y > 0){
                    swap_dice(val);
                    printf("%d\n",Dx[1]);
                    y--;
                    if(Map[y][x] != 0){
                        Dx[3] = Map[y][x];
                        Dy[3] = Map[y][x];
                        Map[y][x] = 0;
                    }
                    else{
                        Map[y][x] = Dx[3];
                    }
                }
                break;
            }
        case 3:
            {
                if (x > 0){
                    swap_dice(val);
                    printf("%d\n",Dy[1]);
                    x--;
                    if(Map[y][x] != 0){
                        Dx[3] = Map[y][x];
                        Dy[3] = Map[y][x];
                        Map[y][x] = 0;
                    }
                    else{
                        Map[y][x] = Dx[3];
                    }
                }
                break;
            }
        case 4:
            {
                if (x < N - 1){
                    swap_dice(val);
                    printf("%d\n",Dy[1]);
                    x++;
                    if(Map[y][x] != 0){
                        Dx[3] = Map[y][x];
                        Dy[3] = Map[y][x];
                        Map[y][x] = 0;
                    }
                    else{
                        Map[y][x] = Dx[3];
                    }
                }
                break;
            }
        }
    }

    return 0;
}
