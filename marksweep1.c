#include<stdio.h>
void insert(int size,int adjacencymatrix[size][size])
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
void tricolouralgorithm(int size,int size1,int adjacencymatrix[size][size],int stack[size1],int active[size])
{
    int mark[size];
    for(int i=0;i<size;i++)
    {
        mark[i]=0;
    }
    int black[size],white[size],gray[size];
    for(int i=0;i<size;i++)
    {
        black[i]=white[i]=gray[i]=0;
    }
    for(int i=0;i<size1;i++)
    {
        ++gray[stack[i]];
    }
    for(int i=0;i<size;i++)
    {
        white[i]=!gray[i];
    }
    int j=0;
    while(j<size)
    {
        while(j<size&&gray[j]==0)++j;
        for(int k=0;k<size;k++)
        {
            if(adjacencymatrix[j][k]==1&&white[k]==1)
            {
                white[k]=0;
                gray[k]=1;
            }
        }
        black[j]=1;
        gray[j]=0;
        j++;
        if(j==size)
        {
            int flag=0;
            for(int k=0;k<size&&flag==0;k++)
            {
                if(gray[k]==1)
                {
                    flag=1;
                }
            }
            if(flag==1)j=0;
        }
    }
    for(int i=0;i<size;i++)
    {
        if(white[i]==1&&active[i]==1)
        {
            printf("%d is garbage\n",i);
            for(int j=0;j<size;j++)
            {
                adjacencymatrix[i][j]=0;
            }
            active[i]=0;
            printf("%d freed\n\n",i);
        }
    }
}
void deleteptrstack(int*size,int stack[],int size1,int adj[size1][size1],int active[])
{
    int i,flag=0;
    printf("Enter to which element pointer points to which you want to delete : ");
    scanf("%d",&i);
    for(int j=0;j<*size&&flag==0;j++)
    {
        if(stack[j]==i)
        {
            flag=1;
            for(int k=j;k<*size-1;k++)
            {
                stack[k]=stack[k+1];
            }
            --(*size);
            tricolouralgorithm(size1,*size,adj,stack,active);
        }
    }
}
void main()
{
    int n;
    scanf("%d",&n);
    int adj[n][n],active[n];
    for(int i=0;i<n;i++)
    {
        active[i]=1;
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
    int n1;
    printf("Enter number of pointers on stack : ");
    scanf("%d",&n1);
    int stack[n1];
    printf("Enter two which they point to : ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&stack[i]);
    }
    insert(n,adj);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    tricolouralgorithm(n,n1,adj,stack,active);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    deleteptrstack(&n1,stack,n,adj,active);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    deleteptrstack(&n1,stack,n,adj,active);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    } 
}
/*
8
2
0
3
1
0 3
1
1 3
1
1 4
1
2 4
1
2 7
1
3 5
1
3 6
1
3 7
1
4 6*/