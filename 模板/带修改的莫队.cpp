#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 10005
#define maxt 1005
int ans[maxn],col[maxn],block[maxn],si,st=-1,apper[maxn*100],ans1,l=1,r=0,now[maxn];
struct Q{//询问 
	int l,r,t,id;
	bool operator < (const Q &a)const{//排序的第一关键字为l所在块，第二关键字为r所在块，第三关键字为询问之前的修改次数t 
		return (block[l]!=block[a.l])?l<a.l:(block[a.r]!=block[r])?r<a.r:t<a.t;
	}
}a[maxn];
struct C{//修改 
	int pos,New,old;
}op[maxt];
void change(int x,int y){
	if(x>=l&&x<=r){
		apper[col[x]]--;
		if(!apper[col[x]])ans1--;
		if(!apper[y])ans1++;
		apper[y]++;
	}
	col[x]=y;
}
void revise(int x,int add){
	apper[col[x]]+=add;
	if(add>0)ans1+=apper[col[x]]==1;
	else ans1-=!apper[col[x]];
}
int main(){
	int n,m,size=0;scanf("%d%d",&n,&m);size=pow(n,2/3.0);//每块范围大小为n^(2/3)
	char s[2];
	for(int i=1;i<=n;i++)scanf("%d",col+i),now[i]=col[i],block[i]=i/size;//读入原始序列并计算出每个块所包含的区间 
	for(int i=0;i<m;i++){
		scanf("%s",s);
		if(s[0]=='Q'){
			scanf("%d%d",&a[si].l,&a[si].r);
			a[si].t=st,a[si].id=si++;
		}
		else{
			scanf("%d%d",&op[st].pos,&op[++st].New);
			op[st].old=now[op[st].pos];
			now[op[st].pos]=op[st].New;
		}
	}
	sort(a,a+si);
	int t=-1;
	for(int i=0;i<si;i++){
		while(t<a[i].t)change(op[t].pos,op[++t].New);
		while(t>a[i].t)change(op[t--].pos,op[t].old);
		while(l<a[i].l)revise(l++,-1);
		while(l>a[i].l)revise(--l,1);
		while(r<a[i].r)revise(++r,1);
		while(r>a[i].r)revise(r--,-1);
		ans[a[i].id]=ans1;
	}
	for(int i=0;i<si;i++)printf("%d\n",ans[i]);
	return 0;
} 
