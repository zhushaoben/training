/*
˼���� 
ɭ�֣��㵼����ͼ����������ͨ�飩������ = �ܶ����� - �ܱ���
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n,u,v;scanf("%d",&n);
	LL ans=1ll*(n+1)*n*(n+2)/6;//1*2+2*3+��+n*(n+1)/2���ܶ����� 
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		ans-=1ll*u*(n-v+1);//��ȥ�ߵĹ��� 
	}
	printf("%lld",ans);
	return 0;
} 
