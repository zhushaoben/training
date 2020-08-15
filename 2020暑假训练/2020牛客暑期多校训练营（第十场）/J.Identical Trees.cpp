#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1100;
typedef unsigned long long uLint;
const int oo=100000000;//
 
int n;
int rx[maxn],ry[maxn];
int mi[maxn],ming[maxn];
 
int cntedge=0;
int head[maxn]={0},head1[maxn];
int to[maxn<<1],nex[maxn<<1],to1[maxn<<1],nex1[maxn<<1];
void Addedge(int x,int y,int head[]=head,int to[]=to,int nex[]=nex){
    nex[++cntedge]=head[x];
    to[cntedge]=y;
    head[x]=cntedge;
}
 
int root1=0,root2=0;
 
uLint hh[maxn],hh1[maxn];
int dep[maxn];
int father[maxn];
void Gethash(int x,int fa,int head[]=head,int to[]=to,int nex[]=nex,uLint hh[]=hh){
    hh[x]=666;
    father[x]=fa;
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=nex[i]){
        if(to[i]==fa)continue;
        Gethash(to[i],x,head,to,nex,hh);
        hh[x]+=hh[to[i]];
    }
    hh[x]=hh[x]*hh[x];
}
 
int a[maxn];
bool cmp(const int &rhs1,const int &rhs2){
    if(dep[rhs1]==dep[rhs2])return hh[rhs1]<hh[rhs2];
    else return dep[rhs1]>dep[rhs2];
}
 
struct NetworkFlow{
    int totn,s,t;
     
    struct Edge{
        int from,to,cap,flow,cost;
    };
    vector<int>G[maxn];
    vector<Edge>edges;
    void Addedge(int x,int y,int z,int w){
        Edge e;
        e.from=x;e.to=y;e.cap=z;e.flow=0;e.cost=w;
        edges.push_back(e);
        e.from=y;e.to=x;e.cap=0;e.flow=0;e.cost=-w;
        edges.push_back(e);
        int c=edges.size();
        G[x].push_back(c-2);
        G[y].push_back(c-1);
    }
     
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    queue<int>q;
    int Spfa(int &nowflow,int &nowcost){
        for(int i=1;i<=totn;++i){
            d[i]=oo;inq[i]=0;
        }
        d[s]=0;inq[s]=1;q.push(s);
        while(!q.empty()){
            int x=q.front();q.pop();inq[x]=0;
            for(int i=0;i<G[x].size();++i){
                Edge e=edges[G[x][i]];
                if((e.cap>e.flow)&&(d[x]+e.cost<d[e.to])){
                    d[e.to]=d[x]+e.cost;
                    p[e.to]=G[x][i];
                    if(!inq[e.to]){
                        q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
         
        if(d[t]==oo)return 0;
         
        int f=oo,x=t;
        while(x!=s){
            Edge e=edges[p[x]];
            f=min(f,e.cap-e.flow);
            x=e.from;
        }
        nowflow+=f;nowcost+=f*d[t];
        x=t;
        while(x!=s){
            edges[p[x]].flow+=f;
            edges[p[x]^1].flow-=f;
            x=edges[p[x]].from;
        }
        return 1;
    }
     
    int Mincost(){
        int flow=0,cost=0;
        while(Spfa(flow,cost)){
        }
        return cost;
    }
    void MCMFinit(){
        totn=n+n+2;s=n+n+1;t=s+1;
        edges.clear();
        G[s].clear();G[t].clear();
    }
}W;
int fa[maxn],fa1[maxn];
int f[maxn][maxn];
bool vis[maxn];
void pre(int x,int x1){
	int w;
	if(!x1)for(int v=1;v<=n;v++){
		if(vis[v]||hh1[x]!=hh[v])continue;
		vis[v]=1,mi[v]=x,w=v;break;
	}
	else for(int i=head[x1];i;i=nex[i]){
		int v=to[i];
		if(vis[v]||hh1[x]!=hh[v])continue;
		vis[v]=1,mi[v]=x,w=v;break;
	}
	for(int i=head1[x];i;i=nex1[i])pre(to1[i],w);
}
int main(){
    scanf("%d",&n);
    int rt,rt1;
    for(int i=1;i<=n;++i){
    	scanf("%d",fa+i);
    	if(fa[i])Addedge(fa[i],i);
    	else rt=i;
    }
    for(int i=1;i<=n;i++){
    	scanf("%d",fa1+i);
    	if(fa1[i])Addedge(fa1[i],i,head1,to1,nex1);
    	else rt1=i;
	}
    for(int i=1;i<=n;++i)ming[i]=i;
	Gethash(rt1,0,head1,to1,nex1,hh1);
    Gethash(rt,0);
    pre(rt1,0);
     
     root1=rt;
    for(int i=1;i<=n;++i)a[i]=i;
    sort(a+1,a+1+n,cmp);
     
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x=a[i];
            int y=a[j];
            if(hh[x]!=hh[y]){
                f[x][y]=oo;
                continue;
            }
            W.MCMFinit();
            for(int ii=head[x];ii;ii=nex[ii]){
                if(to[ii]==father[x])continue;
                W.G[to[ii]].clear();
            }
            for(int ii=head[y];ii;ii=nex[ii]){
                if(to[ii]==father[y])continue;
                W.G[to[ii]+n].clear();
            }
            for(int ii=head[x];ii;ii=nex[ii]){
                if(to[ii]==father[x])continue;
                for(int jj=head[y];jj;jj=nex[jj]){
                    if(to[jj]==father[y])continue;
                    if(hh[to[ii]]!=hh[to[jj]])continue;
                    W.Addedge(to[ii],to[jj]+n,1,f[to[ii]][to[jj]]);
                }
            }
            for(int ii=head[x];ii;ii=nex[ii]){
                if(to[ii]==father[x])continue;
                W.Addedge(W.s,to[ii],1,0);
            }
            for(int ii=head[y];ii;ii=nex[ii]){
                if(to[ii]==father[y])continue;
                W.Addedge(to[ii]+n,W.t,1,0);
            }
            f[x][y]=(ming[x]!=mi[y])+W.Mincost();
        }
    }
     
    printf("%d\n",f[root1][root1]);
    return 0;
}
