#include <iostream>

using namespace std;
int L, N, M, R, C;
int serchPrisoner()
{

}
int main()
{
    int numTest, result;
    int Map[50*50];
    scanf("%d",numTest);

    for (int curTest = 0; curTest<numTest; curTest++)
    {
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &L);
        scanf("%d", &C);
        scanf("%d", &L);


        result = serchPrisoner();

        printf("#%d %d", curTest, result);
    }
    return 0;
}
