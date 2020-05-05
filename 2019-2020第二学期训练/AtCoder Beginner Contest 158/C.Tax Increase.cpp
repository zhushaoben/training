#include<bits/stdc++.h>
using namespace std;
inline int calc(int x){
	return x*12+(x>>1)+(x&1);
}
int main(){
	int a,b,l1,r1,l2,r2;scanf("%d%d",&a,&b);
	l1=calc(a),r1=calc(a+1)-1,l2=b*10,r2=(b+1)*10-1;
	if(l1>r2||l2>r1)return puts("-1"),0;
	printf("%d",max(l1,l2));
	return 0;
}
