#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 50005
int block[maxn],si;
int ans[maxn];
struct Q{
	int l,r,id;
	bool operator <(const Q& a)const{//����ʱ����˵����ڿ�Ϊ��һ�ؼ��֣����Ҷ˵�Ϊ�ڶ��ؼ��� 
		if(block[l]!=block[a.l])return l<a.l;
		return r<a.r;
	}
}a[maxn];
void revise(int l,int add){
}
int main(){
	int n,m;scanf("%d%d",&n,&m);si=sqrt(n);//siΪÿ����Ĵ�С 
	for(int i=1;i<=n;i++)block[i]=i/si;//���ÿ������������� 
	for(int i=0;i<m;i++)scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;//��������ѯ�� 
	sort(a,a+m);//����ѯ����˵����ڿ���Ҷ˵����� 
	int l=1,r=0;
	for(int i=0;i<m;i++){//����ÿ��ѯ������һ��ѯ�ʵ�����ת�Ƶ���ǰѯ������ 
		while(l<a[i].l)revise(l++,-1);
		while(l>a[i].l)revise(--l,1);
		while(r<a[i].r)revise(++r,1);
		while(r>a[i].r)revise(r--,-1);
		ans[a[i].id]=��;
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);//���ÿ��ѯ�� 
	return 0;
} 
