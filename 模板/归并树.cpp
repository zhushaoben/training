#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
#define maxd 20
int n,m,a[maxn],Merge[maxd][maxn];
void build(int deep,int l,int r){//建树 
	if(l==r){Merge[deep][l]=a[l];return;}//叶子节点 
	int mid=(l+r)>>1;
	build(deep+1,l,mid),build(deep+1,mid+1,r);//先构造子节点 
	for(int i=l,j=mid+1,k=l;i<=mid||j<=r;){//归并排序构造当前节点 
		if(j>r)Merge[deep][k++]=Merge[deep+1][i++];
		else if(i>mid||Merge[deep+1][i]>Merge[deep+1][j])Merge[deep][k++]=Merge[deep+1][j++];
		else Merge[deep][k++]=Merge[deep+1][i++];
	}
}
int calc(int deep,int L,int R,int l,int r,int x){//计算[L,R]交[l,r]中小于x的有多少个数 
	if(L>=l&&R<=r){//[L,R]完全被[l,r]包含,直接二分查找返回 
		return lower_bound(Merge[deep]+L,Merge[deep]+R+1,x)-Merge[deep]-L;
	}
	int mid=(L+R)>>1,ans=0;//否则到子节点查找 
	if(mid>=l)ans+=calc(deep+1,L,mid,l,r,x);
	if(mid<r)ans+=calc(deep+1,mid+1,R,l,r,x);
	return ans;
}
int query(int l,int r,int k){
	int L=1,R=n;
	while(L<=R){//二分查找答案 
		int mid=(L+R)>>1,cnt;
		cnt=calc(0,1,n,l,r,Merge[0][mid]);
		if(cnt<=k)L=mid+1;//<mid的肯定不是答案 
		else R=mid-1;//>=mid的肯定不是答案 
	}
	return Merge[0][L-1];//L不是答案(R不是答案,L>=R),L-2也不是答案(L=mid+1,mid-1不是答案)，答案肯定是L-1 
}
void work(){
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	build(0,1,n);
	int l,r,k;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(l,r,k-1));
	}
}
int main(){
	while(~scanf("%d%d",&n,&m))work();
	return 0;
}
