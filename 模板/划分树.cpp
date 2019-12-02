#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int a[maxn],sorted[maxn],partition_tree[20][maxn],num[20][maxn],n,m;
void build(int deep,int l,int r){//�����deep��,����Ϊ[l,r]���ӽڵ� 
	if(l==r)return;
	int mid=(l+r)>>1,x=1;//x��¼�ж��ٺ�sorted[mid](��ǰ�ڵ�Ԫ�ص���λ��)һ��������������ӽڵ� 
	for(int i=mid-1;i>=l;i--,x++){
		if(sorted[i]<sorted[mid])break;//sorted���ź�������� 
	}
	for(int i=l,j=l,k=mid+1;i<=r;i++){
		num[deep][i]=(i==l)?0:num[deep][i-1];
		if(partition_tree[deep][i]<sorted[mid]||(partition_tree[deep][i]==sorted[mid]&&(x--)>0)){//�������ӽڵ� 
			partition_tree[deep+1][j++]=partition_tree[deep][i],num[deep][i]++;
		}
		else partition_tree[deep+1][k++]=partition_tree[deep][i];//�������ӽڵ� 
	} 
	build(deep+1,l,mid);//�����ӽڵ� 
	build(deep+1,mid+1,r);
}
int query(int deep,int L,int R,int l,int r,int k){//ѯ��[l,r]�е�k�����,L,RΪ��ǰ�ڵ�����䷶Χ 
	if(L==R)return partition_tree[deep][L];//Ҷ�ӽڵ��ֱ�ӷ��� 
	int mid=(L+R)>>1,x1=(L==l)?0:num[deep][l-1],x2=num[deep][r]-x1;//x1��ʾ��ǰ�ڵ�����l֮ǰ�ж��ٵ������������,x2��ʾ��ǰ�ڵ���[l,r]���ж��ٵ���������� 
	if(x2>=k)return query(deep+1,L,mid,x1+L,L+num[deep][r]-1,k);//����������
	else return query(deep+1,mid+1,R,l-L-x1+mid+1,mid+r-L-num[deep][r]+1,k-x2);//���������� 
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
