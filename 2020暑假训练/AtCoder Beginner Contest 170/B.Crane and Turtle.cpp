#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;scanf("%d%d",&x,&y);
	if(y%2||y<x*2||y>x*4)puts("No");
	else puts("Yes");
	return 0;
}
