#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
#define maxd 20
int n,m,a[maxn],Merge[maxd][maxn];
void build(int deep,int l,int r){//���� 
	if(l==r){Merge[deep][l]=a[l];return;}//Ҷ�ӽڵ� 
	int mid=(l+r)>>1;
	build(deep+1,l,mid),build(deep+1,mid+1,r);//�ȹ����ӽڵ� 
	for(int i=l,j=mid+1,k=l;i<=mid||j<=r;){//�鲢�����쵱ǰ�ڵ� 
		if(j>r)Merge[deep][k++]=Merge[deep+1][i++];
		else if(i>mid||Merge[deep+1][i]>Merge[deep+1][j])Merge[deep][k++]=Merge[deep+1][j++];
		else Merge[deep][k++]=Merge[deep+1][i++];
	}
}
int calc(int deep,int L,int R,int l,int r,int x){//����[L,R]��[l,r]��С��x���ж��ٸ��� 
	if(L>=l&&R<=r){//[L,R]��ȫ��[l,r]����,ֱ�Ӷ��ֲ��ҷ��� 
		return lower_bound(Merge[deep]+L,Merge[deep]+R+1,x)-Merge[deep]-L;
	}
	int mid=(L+R)>>1,ans=0;//�����ӽڵ���� 
	if(mid>=l)ans+=calc(deep+1,L,mid,l,r,x);
	if(mid<r)ans+=calc(deep+1,mid+1,R,l,r,x);
	return ans;
}
int query(int l,int r,int k){
	int L=1,R=n;
	while(L<=R){//���ֲ��Ҵ� 
		int mid=(L+R)>>1,cnt;
		cnt=calc(0,1,n,l,r,Merge[0][mid]);
		if(cnt<=k)L=mid+1;//<mid�Ŀ϶����Ǵ� 
		else R=mid-1;//>=mid�Ŀ϶����Ǵ� 
	}
	return Merge[0][L-1];//L���Ǵ�(R���Ǵ�,L>=R),L-2Ҳ���Ǵ�(L=mid+1,mid-1���Ǵ�)���𰸿϶���L-1 
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
