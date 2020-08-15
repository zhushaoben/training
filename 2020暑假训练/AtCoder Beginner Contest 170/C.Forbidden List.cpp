#include<bits/stdc++.h>
using namespace std;
bool a[205];
int main(){
	int x,n,y;scanf("%d%d",&x,&n);
	for(int i=0;i<n;i++)scanf("%d",&y),a[y]=1;
	for(int i=0;;i++){
		if(!a[x-i])return printf("%d",x-i),0;
		if(!a[x+i])return printf("%d",x+i),0;
	}
	return 0;
}
