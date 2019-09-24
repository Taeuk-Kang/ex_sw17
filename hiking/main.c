#include <stdio.h>
#include <stdlib.h>

int N,K;
int max_arr(int * arr)
{
    int i=0, max_val=arr[0];
    int sizeArr = sizeof(arr)/sizeof(int);
    printf("Comp arr size:%d\n",sizeArr);
    for(int i = 0;i<sizeArr;i++)
    {
        if(arr[i]>max_val)
            max_val = arr[i];
        i++;
    }
    printf("temporal max value:%d\n",max_val);
    return max_val;
}

int route(int *map, int x, int y, bool isDug) //, int *length)
{
    int temp[4]={0};
    int max_val;
    //printf("current length: %d\n", *length);
    printf("current position: x=%d, y=%d, val=%d \n",x,y,map[N*x+y]);
    if((N*(x-1)+y > 0) && (N*(x-1)+y < N*N))
    {

        if ((map[N*x+y] > map[N*(x-1)+y]))
            temp[0]=route(map,x-1,y,false)+1;
        else if(!isDug && (map[N*x+y] > map[N*(x-1)+y]))
            temp[0]=route(map,x-1,y)+1
        else
            temp[0]=1; //*length;
    }
    if ((N*(x+1)+y > 0) && (N*(x+1)+y < N*N) )
    {
        if ((map[N*x+y] > map[N*(x+1)+y]))
            temp[1]=route(map,x+1,y)+1;
        else
            temp[1]=1; //*length;
    }
    if((N*x+y+1 > 0) && (N*x+y+1 < N*N) )
    {
        if ((map[N*x+y] > map[N*x+y+1]))
            temp[2]=route(map,x,y+1)+1;
        else
            temp[2]=1; //*length;
    }
    if((N*x+y-1 > 0) && (N*x+y-1 < N*N) )
    {
        if ((map[N*x+y] > map[N*x+y-1]))
            temp[3]=route(map,x,y-1)+1;
        else
            temp[3]=1; //*length;
    }
    printf("temp value : %d\n",temp[0]);
    printf("temp value : %d\n",temp[1]);
    printf("temp value : %d\n",temp[2]);
    printf("temp value : %d\n",temp[3]);
    if(temp[0]+temp[1]+temp[2]+temp[3] < 1)
    {
        return 0;
    }
    else
    {
        max_val=temp[0];
        for(int i =0; i<3; i++)
        {
            if(max_val<temp[i])
                max_val = temp[i];
        }
        //(*length) = max_arr(temp);
        printf("return value : %d\n",max_val);
        return max_val;//(*length);
    }
}

int main()
{
    int length=0;
    N = 5;
    K = 1;
    int Map[25]={9, 3, 2, 3, 2, 6, 3, 1, 7, 5, 3, 4, 8, 9, 9, 2, 3, 7, 7, 7, 7, 6, 5, 5, 8};

    printf("best case: %d", route(Map,2,3));
    return 0;
}
