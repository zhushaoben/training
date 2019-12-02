#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 50005
int block[maxn],si;
int ans[maxn];
struct Q{
	int l,r,id;
	bool operator <(const Q& a)const{//排序时以左端点所在块为第一关键字，以右端点为第二关键字 
		if(block[l]!=block[a.l])return l<a.l;
		return r<a.r;
	}
}a[maxn];
void revise(int l,int add){
}
int main(){
	int n,m;scanf("%d%d",&n,&m);si=sqrt(n);//si为每个块的大小 
	for(int i=1;i<=n;i++)block[i]=i/si;//算出每个块包含的区间 
	for(int i=0;i<m;i++)scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;//读入所有询问 
	sort(a,a+m);//按照询问左端点所在块和右端点排序 
	int l=1,r=0;
	for(int i=0;i<m;i++){//对于每个询问由上一个询问的区间转移到当前询问区间 
		while(l<a[i].l)revise(l++,-1);
		while(l>a[i].l)revise(--l,1);
		while(r<a[i].r)revise(++r,1);
		while(r>a[i].r)revise(r--,-1);
		ans[a[i].id]=？;
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);//输出每个询问 
	return 0;
} 
