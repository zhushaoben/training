#include<bits/stdc++.h>
using namespace std;
#define maxn 2000
#define LL long long
int l[maxn+5];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",l+i);
	sort(l,l+n);l[n]=maxn;
	int L,R;LL ans=0;
	for(int i=0;i<n;i++){
		L=0,R=0;
		for(int j=i+1;j<n;j++){
			while(l[L]<=l[j]-l[i])L++;
			while(l[R]<l[j]+l[i])R++;
			ans+=R-L-(L<=i)-(R>j);
		}
	}
	printf("%d",ans/3);
	return 0;
}
