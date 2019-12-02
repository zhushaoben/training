/*
莫队分块
首先从根dfs整棵树，如果某棵子树剩余大小大于B，就将它单独成一块，并将它移除(即不再记录它的大小)
如果最后树的节点个数不足B，就把它加入上一块。

这样分块每块大小为[B,3B)(只有一块，剩下的块直径不超过2B),直径不超过3B、但不保证连通。
*/
#include<cstdio>
#define maxn 1005
struct Edge{
    int next,to;
}edge[maxn*2];
int fi[maxn],se,n,b,stack[maxn],t,belong[maxn],size,head[maxn];
inline void add_edge(int u,int v){
    edge[++se].next=fi[u],edge[se].to=v,fi[u]=se,
    edge[++se].next=fi[v],edge[se].to=u,fi[v]=se;
}
void out(int s){
    size++;
    while(t>s)belong[stack[--t]]=size;
} 
void dfs(int x,int s,int fa){
    for(int i=fi[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,t,x); 
        if(t-s>=b)out(s),head[size]=x;//如果当前子树栈中节点>=B,就自成一块 
    }
    stack[t++]=x;
}
int main(){
    scanf("%d%d",&n,&b);
    int u,v;
    for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v);
    dfs(1,0,0);
    while(t)belong[stack[--t]]=size;//将最后剩下的节点加入最后一个块 
    printf("%d\n",size);
    for(int i=1;i<=n;i++)printf("%d ",belong[i]);printf("\n");
    for(int i=1;i<=size;i++)printf("%d ",head[i]);
    return 0;
} 
/*
解决链上询问 

设$size=\sqrt{n}$,对于每个节点x，如果$depth[x]\%size==1$则称它是关键点。
于是这棵树就被这些关键点分成了若干块(关键点属于它下面的块)，如果某一块的大小小于size，就把它和上一个块合并。
这棵树的每个块大小就$\ge size$,块的个数就$\le size$,并且每个块的直径$\le size*4$

这种分块方式可以保证块的个数、块的直径，但不能保证块的大小
*/ 
int dfs(int x){//深度分块 
    int si=1;
    stack[top++]=x;//将x加入栈中 
    for(int i=fi[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa[x])continue;
        dis[v]=edge[i].w,fa[v]=x,depth[v]=depth[x]+1,si+=dfs(v);
    }
    int k; 
    if(depth[x]%size==0&&si>=size){//如果当前点深度%size==0且子树大小>=size，则要和它的父亲分开 
        k=++s;block[x]=k;key[k]=x;//栈中x的子树中的节点和x一个块 
        while(stack[--top]!=x){
            block[stack[top]]=k;
        }
    }
    //否则和它的父亲一个块 
    return si;
}
/*
解决以祖先关系为基础的询问

设$size=\sqrt{n}$,对于每个节点x，如果$depth[x]%size==1$则称它是关键点。
对于任意两个关键点的最近公共祖先也设成关键点，可证明新加关键点数不会超过原关键点数。
将这些关键点建成一棵虚树，虚树上每个节点是一个块。
这些关键点之间的路径上的点都属于靠下的关键点所在的块
不在路径上的点都加入到最近的关键点(一定是自己的祖先)(与路径上的点分开保存)。
可证明每个块中路径上的点都是它子树的块中所有节点(在和不在路径上的点)和它自己块中不在路径上的点的祖先

这种分块可以保证块的直径和个数，不保证块的大小
*/ 
int dfs(int x,int depth){
    int si=1,ma=0;//ma记录他有几个儿子的子树有关键点 
    for(int i=fi[x];i;i=edge[i].next){
        int v=edge[i].to;
        fa[v]=x,si+=dfs(v,depth+1);
        if(k[v])ma++;//k==1表示v子树中存在关键点 
    }
    if((depth%size==0&&si>=size)||ma>1){ 
        k[x]=key[x]=1;//如果它本身是关键点 或 有2个及以上的儿子的子树有关键点，则它是关键点 
    }
    else if(ma)k[x]=1;//它的子树有关键点
    return si;
}
void dfs1(int x){
    if(key[x])block[x]=++s;
    for(int i=fi[x];i;i=edge[i].next){
        dfs1(edge[i].to);
    }
    int v=x;
    if(key[x]){
        v=x;while(!key[fa[v]])v=fa[v],block[v]=block[x];//将路径上的点加入当前块 
        v=fa[v];add_road(block[v],block[x]);//构建虚树中的边 
    }
    else if(!block[x]){
        while(!key[fa[v]])v=fa[v];
        v=fa[v],block[x]=-block[v];//不在路径上的点属于它最近关键点所在块(分开保存，所以存成负数)
    } 
}

