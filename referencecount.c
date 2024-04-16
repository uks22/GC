#include<stdio.h>
void insert(int size,int adjacencymatrix[size][size],int ref[])
{
    char c='1';
    while(c!='0')
    {
        fflush(stdin);
        printf("Enter 1 to add edge in graph of %d vertex\nEnter 0 to exit : ",size);
        scanf("%c",&c);
        if(c=='1')
        {
            printf("Enter i and j = ");
            int i,j;
            scanf("%d %d",&i,&j);
            if(i<size&&j<size)
            {
                if(adjacencymatrix[i][j]==0)
                {
                    ++adjacencymatrix[i][j];
                    ++ref[j];
                }
                else
                {
                    printf("Graph already has an edge from %d to %d\n",i,j);
                }
            }
            else
            {
                printf("Out of scope\n");
            }
        }
    }
}
void referencecount(int size,int adjacencymatrix[size][size],int refcount[],int visited[])
{
    for(int i=0;i<size;i++)
    {
        if(refcount[i]==0)
        {
            for(int j=0;j<size;j++)
            {
                if(adjacencymatrix[i][j])
                {
                    --refcount[j];
                }
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        if(refcount[i]==0&&visited[i]==0)
        {
            visited[i]=1;
            printf("%d is garabge\n",i);
        }
    }
}
void deletepointer(int size,int size1,int adjacencymatrix[size][size],int stck[],int refcount[],int visited[])
{
    int k;
    printf("Enter pointer onto the stack you want to delete : ");
    scanf("%d",&k);
    int flag=-1;
    for(int i=0;i<size1&&flag==-1;i++)
    {
        if(stck[i]==k)
        {
            flag=i;
        }
    }
    if(flag!=-1)
    {
        --refcount[flag];
        referencecount(size,adjacencymatrix,refcount,visited);
    }
    else
    {
        printf("No such element exist on the stack\n");
    }
}
void main()
{
    int n;
    printf("Enter number of pointers in heap : ");
    scanf("%d",&n);
    int m;
    printf("Enter number of pointers outside heap pointing to heap elements : " );
    scanf("%d",&m);
    int stck[m];
    int arr[n][n];
    int refcount[n];
    for(int i=0;i<m;i++)
    {
        stck[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
        refcount[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&stck[i]);
        refcount[stck[i]]=1;
    }
    insert(n,arr,refcount);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    referencecount(n,arr,refcount,visited);
    deletepointer(n,m,arr,stck,refcount,visited);
}
/*
6
2
0
3
1
0 1
1
1 2
1
1 5
1
2 5
1
1 4
1
3 2
1
3 4
0
0
*/