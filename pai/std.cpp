#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,l,k,v[N];
struct nodeG
{
    int num,pos;
    nodeG() {}
    nodeG(int x,int y)
    {
        num=x;pos=y;
    }
    bool operator <(const nodeG& x) const
    {
        return num<x.num;
    }
};
struct nodeS
{
    int num,pos;
    nodeS() {}
    nodeS(int x,int y)
    {
        num=x;pos=y;
    }
    bool operator <(const nodeS& x) const
    {
        return num>x.num;
    }
};
template<typename node> class Heap
{
private:
    priority_queue<node> q;
    int size;
    bool in[N];
public:
    Heap()
    {
        memset(in,0,sizeof(in));
        size=0;
    }
    void Push(int num,int pos)
    {
        if (!in[pos])
        {
            q.push(node(num,pos));
            in[pos]=true;
            size++;
        }
    }
    node Top()
    {
        node res;
        while (in[(res=q.top()).pos]==false)
            q.pop();
        return res;
    }
    node Pop()
    {
        node res;
        while (in[(res=q.top()).pos]==false)
            q.pop();
        q.pop();
        size--;
        in[res.pos]=false;
        return res;
    }
    void Del(int x)
    {
        if (in[x]) size--;
        in[x]=false;
    }
    int Size()
    {
        return size;
    }
    bool Exist(int x)
    {
        return in[x];
    }
};
int c[N];
ll calc()
{
	Heap<nodeS> rh;
	Heap<nodeG> bh;
	for (int i=1;i<=l;i++)
    {
        rh.Push(v[i],i);
        if (rh.Size()>k)
        {
            nodeS pp=rh.Pop();
            bh.Push(pp.num,pp.pos);
        }
    }
    ll ans=rh.Top().num;
//    printf("%d ",rh.Top().num);
    for (int i=l+1;i<=n;i++)
    {
        int pout=i-l;
        if (rh.Exist(pout))
        {
            rh.Del(pout);
            if (bh.Size()==0 || v[i]>bh.Top().num)
                rh.Push(v[i],i);
            else
            {
                bh.Push(v[i],i);
                nodeG pp=bh.Pop();
                rh.Push(pp.num,pp.pos);
            }
        }
        else
        {
            bh.Del(pout);
            if (v[i]<rh.Top().num)
                bh.Push(v[i],i);
            else
            {
                rh.Push(v[i],i);
                nodeS pp=rh.Pop();
                bh.Push(pp.num,pp.pos);
            }
        }
        ans+=rh.Top().num;
//        printf("%d ",rh.Top().num);
    }
    return ans;
}
int id[N];
void calc2(bool f)
{
	for(int i=1; i<=n; i++) id[i]=i;
	ll res=0;
	if(!f) res=1e18;
	do {
		for(int i=1; i<=n; i++) v[i]=c[id[i]];
		if(f)res=max(res, calc());
		else res=min(res, calc());
	}while(next_permutation(id+1, id+n+1));
	printf("%lld\n",res);
}
void solve()
{
	
	scanf("%d%d%d",&n,&l,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    sort(c+1, c+n+1);
    for(int i=1; i<=(n>>1); i++) {
    	v[i]=c[i*2-1];
    	v[n-i+1]=c[i*2];
	}
	if(n&1) v[n/2+1]=c[n];
//	printf("%lld ",calc());
	calc2(1);
    sort(c+1, c+n+1,greater<int>());
    for(int i=1; i<=(n>>1); i++) {
    	v[i]=c[i*2-1];
    	v[n-i+1]=c[i*2];
	}
	if(n&1) v[n/2+1]=c[n];
//	printf("%lld ", calc());
	calc2(0);
}
int main()
{
    int T; scanf("%d",&T);
	while(T--) solve(); 
    return 0;
}
