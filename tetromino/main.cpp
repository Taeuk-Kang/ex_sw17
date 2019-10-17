#include <iostream>
#include <stdio.h>

int Map[500][500];
int visit[500][500];
int Max = 0;
int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int findmax(int *arr)
{
    int Max = 0;
    for (int i = 0; i<4; i++){
        if(Max<arr[i]){
            Max = arr[i];
        }
    }
    return Max;
}

int findroid(int x, int y, int cnt, int s)
{
    int candi[4] = {0,};
    int temp;
    visit[y][x] = 1;
    cnt++;
    if (cnt >= 4){
        //init visit
        visit[y][x] = 0;
        return Map[y][x];
    }

    for (int i = 0; i < 4; i++){
        if ((visit[y+dy[i]][x+dx[i]] == 0 )&& x+dx[i] > -1 && x+dx[i] < N && y+dy[i] > -1 && y+dy[i] < M){
            candi[i] = findroid(x+dx[i],y+dy[i],cnt,s);
        }
    }
    s += findmax(candi);
    s += Map[y][x];
    visit[y][x] = 0;
    if (cnt == 1){
        for (int j = 0; j < 4; j++){
            candi[j] = Map[y][x];
            for (int i = 0; i < 4; i++){
                if((i != j )&& x+dx[i] > -1 && x+dx[i] < N && y+dy[i] > -1 && y+dy[i] < M){
                    candi[j] += Map[y+dy[i]][x+dx[i]];
                }
            }
        }
        temp = findmax(candi);
        if (s < temp){
            s = temp;
        }
    }
    return s;
}

int main()
{
    int res;
    scanf("%d %d", &N, &M);
    for (int i = 0; i<N; i++){
        for (int j = 0; j<M; j++){
            scanf("%d", &Map[j][i]);
        }
    }
    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            res = findroid(i,j,0,0);
            if (Max < res){
                Max = res;
            }
        }
    }
    printf("%d\n",Max);
    return 0;
}
