#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define S 100
int N,i,j,X[S],H[S],key,key1,L=0,l,a,b;
void activity(int X[],int H[]);
int main()
{
    printf("Enter the Number of trees(N): ");
    scanf("%d",&N);
    printf("Enter coordinate(X) and Height(H):\n");
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&X[i],&H[i]);
    }
    activity(X,H);

}
void activity(int X[],int H[])
{
    for(i=1;i<N;i++)
    {
        key=H[i];
        key1=X[i];
        for(j=i-1;j>=0 && key<H[j];j--)
        {
            H[j+1]=H[j];
            X[j+1]=X[j];
        }
        H[j+1]= key;
        X[j+1]=key1;
    }
    for(a=0,b=1,i=0;i<N-1;i++)
    {
        if((b>a) && ((H[b]-H[a]) < (X[b]-X[a])))
        {
            l=(pow((X[b]-X[a]),2)+pow((H[b]-H[a]),2));
            if(l>L)
            {
                L=l;
            }
            a=b;
            b++;
        }
        else
        {
            b++;
        }
    }
    if(a==N-1)
    {
        printf("Length of the rope: %d\n",L);
    }
    else
    {
        printf("-1\n");
    }
}
