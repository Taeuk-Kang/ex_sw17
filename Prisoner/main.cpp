#include <iostream>

using namespace std;
int L, N, M, R, C;
int Map[50*50];
int Res[50*50];
int serchPrisoner()
{
    int val = Map[M*R+C];
    switch (val);
    {
	case 

    }
}
int main()
{
    int numTest, result;
    scanf("%d",numTest);

    for (int curTest = 0; curTest<numTest; curTest++)
    {
        scanf("%d", &N);
        scanf("%d", &M);
        scanf("%d", &L);
        scanf("%d", &C);
        scanf("%d", &L);
	for (int input = 0; input < N*M; input ++)
	{
	    scanf("%d", &Map[input]);
	}

        result = serchPrisoner();

        printf("#%d %d", curTest, result);
	for (int reset = 0; reset < N*M; reset++)
	{
	    Map[reset] = 0;
	    Res[reset] = 0;
	}
    }
    return 0;
}
