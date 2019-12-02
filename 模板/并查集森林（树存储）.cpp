#include <stdio.h>
#define N 10020
int parent[N],rank[N],resex[N];
// 初始化n个元素
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;   // 初始树的高度为0
    }
}

int find(int x)
{
    int k, j, r;
    r = x;
    while(r != parent[r])     //查找根节点
        r = parent[r];      //找到根节点，用r记录下
    k = x;        
    while(k != r)             //非递归路径压缩操作
    {
        j = parent[k];         //用j暂存parent[k]的父节点
        parent[k] = r;        //parent[x]指向根节点
        k = j;                    //k移到父节点
    }
    return r;         //返回根节点的值            
}

// 合并x和y所属的集合
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    if(rank[x]<rank[y])
        parent[x]=y;  // 合并是从rank小的向rank大的连边
    else
    {
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
int main()
{
	int n,m,z,x,y;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)unite(x,y);
		if(z==2){
			x=find(x);
			y=find(y);
			if(x==y)printf("Y\n");
			else printf("N\n");
		}
	}
	
	return 0;
}
