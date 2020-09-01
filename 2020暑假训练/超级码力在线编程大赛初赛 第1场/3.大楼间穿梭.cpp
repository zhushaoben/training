#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param heights: the heights of buildings.
     * @param k: the vision.
     * @param x: the energy to spend of the first action.
     * @param y: the energy to spend of the second action.
     * @return: the minimal energy to spend.
     */
     static const int N=1e5+5;
     long long f[N];int st[N],top,nex[N];
    long long shuttleInBuildings(vector<int> &heights, int k, int x, int y) {
    	int n=heights.size();
    	top=0;
    	for(int i=0;i<n;i++){
    		f[i]=1e17,nex[i]=0;
    		while(top&&heights[st[top]]<=heights[i])nex[st[top]]=i,top--;
    		st[++top]=i;
		}
		f[0]=0;
		for(int i=0;i<n;i++){
			int j=nex[i];
			if(j>i&&j-i<=k)f[j]=min(f[j],f[i]+x);
			f[i+1]=min(f[i+1],f[i]+y);
			f[i+2]=min(f[i+2],f[i]+y);
		}
		return f[n-1];
        // write your code here.
    }
};
Solution ss;
int a[]={1,5,4,3,3,5};
int main(){
	vector<int> s(a, a+6);
	long long ret = ss.shuttleInBuildings(s, 3, 10, 6);
	printf("%lld\n",ret);
	return 0;
}
