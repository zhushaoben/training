/*
Ī�ӷֿ�
���ȴӸ�dfs�����������ĳ������ʣ���С����B���ͽ���������һ�飬�������Ƴ�(�����ټ�¼���Ĵ�С)
���������Ľڵ��������B���Ͱ���������һ�顣

�����ֿ�ÿ���СΪ[B,3B)(ֻ��һ�飬ʣ�µĿ�ֱ��������2B),ֱ��������3B��������֤��ͨ��
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
        if(t-s>=b)out(s),head[size]=x;//�����ǰ����ջ�нڵ�>=B,���Գ�һ�� 
    }
    stack[t++]=x;
}
int main(){
    scanf("%d%d",&n,&b);
    int u,v;
    for(int i=1;i<n;i++)scanf("%d%d",&u,&v),add_edge(u,v);
    dfs(1,0,0);
    while(t)belong[stack[--t]]=size;//�����ʣ�µĽڵ�������һ���� 
    printf("%d\n",size);
    for(int i=1;i<=n;i++)printf("%d ",belong[i]);printf("\n");
    for(int i=1;i<=size;i++)printf("%d ",head[i]);
    return 0;
} 
/*
�������ѯ�� 

��$size=\sqrt{n}$,����ÿ���ڵ�x�����$depth[x]\%size==1$������ǹؼ��㡣
����������ͱ���Щ�ؼ���ֳ������ɿ�(�ؼ�������������Ŀ�)�����ĳһ��Ĵ�СС��size���Ͱ�������һ����ϲ���
�������ÿ�����С��$\ge size$,��ĸ�����$\le size$,����ÿ�����ֱ��$\le size*4$

���ַֿ鷽ʽ���Ա�֤��ĸ��������ֱ���������ܱ�֤��Ĵ�С
*/ 
int dfs(int x){//��ȷֿ� 
    int si=1;
    stack[top++]=x;//��x����ջ�� 
    for(int i=fi[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa[x])continue;
        dis[v]=edge[i].w,fa[v]=x,depth[v]=depth[x]+1,si+=dfs(v);
    }
    int k; 
    if(depth[x]%size==0&&si>=size){//�����ǰ�����%size==0��������С>=size����Ҫ�����ĸ��׷ֿ� 
        k=++s;block[x]=k;key[k]=x;//ջ��x�������еĽڵ��xһ���� 
        while(stack[--top]!=x){
            block[stack[top]]=k;
        }
    }
    //��������ĸ���һ���� 
    return si;
}
/*
��������ȹ�ϵΪ������ѯ��

��$size=\sqrt{n}$,����ÿ���ڵ�x�����$depth[x]%size==1$������ǹؼ��㡣
�������������ؼ���������������Ҳ��ɹؼ��㣬��֤���¼ӹؼ��������ᳬ��ԭ�ؼ�������
����Щ�ؼ��㽨��һ��������������ÿ���ڵ���һ���顣
��Щ�ؼ���֮���·���ϵĵ㶼���ڿ��µĹؼ������ڵĿ�
����·���ϵĵ㶼���뵽����Ĺؼ���(һ�����Լ�������)(��·���ϵĵ�ֿ�����)��
��֤��ÿ������·���ϵĵ㶼���������Ŀ������нڵ�(�ںͲ���·���ϵĵ�)�����Լ����в���·���ϵĵ������

���ַֿ���Ա�֤���ֱ���͸���������֤��Ĵ�С
*/ 
int dfs(int x,int depth){
    int si=1,ma=0;//ma��¼���м������ӵ������йؼ��� 
    for(int i=fi[x];i;i=edge[i].next){
        int v=edge[i].to;
        fa[v]=x,si+=dfs(v,depth+1);
        if(k[v])ma++;//k==1��ʾv�����д��ڹؼ��� 
    }
    if((depth%size==0&&si>=size)||ma>1){ 
        k[x]=key[x]=1;//����������ǹؼ��� �� ��2�������ϵĶ��ӵ������йؼ��㣬�����ǹؼ��� 
    }
    else if(ma)k[x]=1;//���������йؼ���
    return si;
}
void dfs1(int x){
    if(key[x])block[x]=++s;
    for(int i=fi[x];i;i=edge[i].next){
        dfs1(edge[i].to);
    }
    int v=x;
    if(key[x]){
        v=x;while(!key[fa[v]])v=fa[v],block[v]=block[x];//��·���ϵĵ���뵱ǰ�� 
        v=fa[v];add_road(block[v],block[x]);//���������еı� 
    }
    else if(!block[x]){
        while(!key[fa[v]])v=fa[v];
        v=fa[v],block[x]=-block[v];//����·���ϵĵ�����������ؼ������ڿ�(�ֿ����棬���Դ�ɸ���)
    } 
}

