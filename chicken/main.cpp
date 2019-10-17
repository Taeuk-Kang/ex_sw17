#include <iostream>

using namespace std;
int N, M, minPath;
int Map[50][50];
void check()
{

}
void dfs(int numC, int i, int j)
{
    if (numC < M){return;}

    for (int x = i; x<N; x++){
        for (int y = j; y<N; y++){
            if (Map[x][y] == 2){
                dfs(numC-1,x,y);
            }
        }
    }
}
int main()
{
    int numC = 0;
    scanf("%d %d", N, M);
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            scanf("%d",&Map[i][j]);
            if (Map[i][j] == 2){
                numC++;
            }
        }
    }

    dfs(numC,0,0);
    return 0;
}
