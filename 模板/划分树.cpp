#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int a[maxn],sorted[maxn],partition_tree[20][maxn],num[20][maxn],n,m;
void build(int deep,int l,int r){//构造第deep层,区间为[l,r]的子节点 
	if(l==r)return;
	int mid=(l+r)>>1,x=1;//x记录有多少和sorted[mid](当前节点元素的中位数)一样大的数进入左子节点 
	for(int i=mid-1;i>=l;i--,x++){
		if(sorted[i]<sorted[mid])break;//sorted是排好序的数组 
	}
	for(int i=l,j=l,k=mid+1;i<=r;i++){
		num[deep][i]=(i==l)?0:num[deep][i-1];
		if(partition_tree[deep][i]<sorted[mid]||(partition_tree[deep][i]==sorted[mid]&&(x--)>0)){//进入左子节点 
			partition_tree[deep+1][j++]=partition_tree[deep][i],num[deep][i]++;
		}
		else partition_tree[deep+1][k++]=partition_tree[deep][i];//进入右子节点 
	} 
	build(deep+1,l,mid);//构建子节点 
	build(deep+1,mid+1,r);
}
int query(int deep,int L,int R,int l,int r,int k){//询问[l,r]中第k大的数,L,R为当前节点的区间范围 
	if(L==R)return partition_tree[deep][L];//叶子节点就直接返回 
	int mid=(L+R)>>1,x1=(L==l)?0:num[deep][l-1],x2=num[deep][r]-x1;//x1表示当前节点中在l之前有多少点进入了左子树,x2表示当前节点在[l,r]中有多少点进入左子树 
	if(x2>=k)return query(deep+1,L,mid,x1+L,L+num[deep][r]-1,k);//在左子树中
	else return query(deep+1,mid+1,R,l-L-x1+mid+1,mid+r-L-num[deep][r]+1,k-x2);//在右子树中 
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i),partition_tree[0][i]=sorted[i]=a[i];
	sort(sorted+1,sorted+1+n);
	build(0,1,n);
	int l,r,k;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(0,1,n,l,r,k));
	}
	return 0; 
}
