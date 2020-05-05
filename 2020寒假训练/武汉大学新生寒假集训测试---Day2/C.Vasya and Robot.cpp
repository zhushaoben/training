#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
char s[maxn],u,d,l,r;
bool check(int n,int x,int y){
	return n>=(abs(x)+abs(y))&&(n-abs(x)-abs(y))%2==0;
}
int main(){
	int n,x,y,x1=0,y1=0,l=0,r;scanf("%d%s%d%d",&n,s,&x,&y),r=n-1;
	if(!check(n,x,y))return printf("-1"),0;
	while(check(r-l+1,x-x1,y-y1)&&l<=r){
		switch(s[l]){
			case 'U':y1++;break;
			case 'D':y1--;break;
			case 'L':x1--;break;
			case 'R':x1++;break;
		}
		l++;
	}
	int ans=n;
	for(int i=l-1;~i;i--){
		switch(s[i]){
			case 'U':y1--;break;
			case 'D':y1++;break;
			case 'L':x1++;break;
			case 'R':x1--;break;
		}
		while(r>=i-1&&check(r-i+1,x-x1,y-y1)){
			switch(s[r]){
				case 'U':y1++;break;
				case 'D':y1--;break;
				case 'L':x1--;break;
				case 'R':x1++;break;
			}
			r--;
		}
		ans=min(ans,r-i+2);
	}
	printf("%d",ans);
	return 0;
}
