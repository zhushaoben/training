#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,mo=1e9+7,mul=1e7+19; 
struct Trie{
	Trie *son[2],*fa;
	int w,w1;
	vector<int>v;
	Trie(){
		memset(son,0,sizeof(son)),fa=0,w=w1=0;
	} 
}*root,*x;
void node_free(Trie* x){//节点释放 
	for(int i=0;i<2;i++){
		if(x->son[i]!=NULL)node_free(x->son[i]);//先释放子节点 
	}
	delete x;
}
int r[N],si;
void tr(Trie *x){
	if(x->son[0])tr(x->son[0]);
	for(auto i:x->v)r[i]=si++; 
	if(x->son[1])tr(x->son[1]);
}
int p[N],d[N],n;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
void gen()
{
	int ps=read(),pa=read(),pb=read(),pm=read(),ds=read(),da=read(),db=read(),dm=read();
	for(int i=0; i<n; i++) {
		d[i]=ds%10; p[i]=i;
		ds=(ds*da+db)%dm;
	}
	for(int i=1; i<n; i++) {
		swap(p[i], p[ps%(i+1)]);
		ps=(ps*pa+pb)%pm;
	}
}
void work(){
	root=new Trie;si=0;
	scanf("%d",&n);gen();
	x=root->son[0]=new Trie;
	x->v.push_back(0),x->fa=root,x->w=n+1;
	for(int i=0;i<n;i++){
		if(d[i]==(p[i]%10)){x->v.push_back(i+1);continue;}
		while(x->fa->w>p[i])x=x->fa;
		Trie *y=new Trie;
		
		y->w=p[i],y->w1=d[i]>(p[i]%10),y->v.push_back(i+1);
		if(x->son[0]){
			y->son[y->w1]=x->son[0],x->son[0]->fa=y;
			x->son[0]=y,y->fa=x;
		}
		else if(x->son[1]){
			y->son[y->w1]=x->son[1],x->son[1]->fa=y;
			x->son[1]=y,y->fa=x;
		}
		else{
			x->son[x->w1]=y,y->fa=x;
		}
		x=y;
	}
	tr(root);
	long long ans=0,w=1;
	for(int i=0;i<=n;i++)(ans+=w*r[i])%=mo,(w*=mul)%=mo;
	printf("%d\n",ans);
	node_free(root);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
