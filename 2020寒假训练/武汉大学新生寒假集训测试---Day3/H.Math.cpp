#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,n1,ans=1,w,w1,ma=-1,fl=0;scanf("%d",&n),n1=n;
	if(n==1)return puts("1 0"),0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			ans*=i;w1=w=0;
			while(n%i==0)n/=i,w++;
			while((1<<w1)<w){if(w&(1<<w1))fl=1;w1++;}
			if(ma>=0&&w1!=ma)fl=1;
			ma=max(ma,w1);
		}
	}
	if(n>1)ans*=n,fl=(ma!=0);
	printf("%d %d",ans,ma+fl);
	return 0;
}
