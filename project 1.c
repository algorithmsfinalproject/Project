#include<stdio.h>
#include<stdlib.h>
#define S 20
int N,Q,i,j,Ti[S],Si[S],K[S],T[S],total;
void Rec(int f,int l,int Ti[],int Si[]);
void merge(int left,int mid,int right,int Ti[],int Si[]);

int main()
{
    printf("Enter the number of questions(N) Number of queries(Q): ");
    scanf("%d %d",&N,&Q);
    printf("Enter the time of N questions:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&Ti[i]);
    }
    printf("Enter the scores of N questions:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&Si[i]);
    }
    Rec(0,N-1,Ti,Si);
    printf("Enter the number of Questions She wants to solve(K):\n");
    for(i=0;i<Q;i++)
    {
        scanf("%d",&K[i]);
        total=0;
        for(j=0;j<K[i];j++)
        {
            total=total+Ti[j];
        }
        T[i]=total;
    }
    printf("Number of time required:\n");
    for(i=0;i<Q;i++)
    {
        printf("%d\n",T[i]);
    }
    return 0;
}

void Rec(int f,int l,int Ti[],int Si[])
{
    int m;
    if(f<l)
    {
        m=(f+l)/2;
        Rec(f,m,Ti,Si);
        Rec(m+1,l,Ti,Si);
        merge(f,m,l,Ti,Si);
    }
}

void merge(int left,int mid,int right,int Ti[],int Si[])
{
    int a,b,c,s1,s2,x,y;
    s1=mid-left+1;
    s2=right-mid;
    int l_tree[s1],r_tree[s2],l1_tree[s1],r1_tree[s2];
    for(x=0;x<s1;x++)
    {
        l_tree[x] = Ti[left+x];
        l1_tree[x] = Si[left+x];
    }
    for(y=0;y<s2;y++)
    {
        r_tree[y] = Ti[mid+y+1];
        r1_tree[y] = Si[mid+y+1];
    }
    for(a=0,b=0,c=left;a<s1 && b<s2;c++)
    {
        if(l1_tree[a]>r1_tree[b])
        {
            Si[c]=l1_tree[a];
            Ti[c]=l_tree[a];
            a++;
        }
        else
        {
            Si[c]=r1_tree[b];
            Ti[c]=r_tree[b];
            b++;
        }
    }
    while(a<s1)
    {
            Ti[c]=l_tree[a];
            Si[c]=l1_tree[a];
            a++;
            c++;
    }
    while(b<s2)
    {
            Ti[c]=r_tree[b];
            Si[c]=r1_tree[b];
            b++;
            c++;
    }

}
