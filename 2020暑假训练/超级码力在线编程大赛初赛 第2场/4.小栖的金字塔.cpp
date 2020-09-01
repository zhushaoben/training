#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	/**
	 * @param n: The number of pyramid levels n
	 * @param k: Possible coordinates k
	 * @return: Find the sum of the number of plans
	 */
	static const int mo=1e9+7,N=1e7+5;
	int inv[N],f[N];
	void Inverse(int n){//线性求<=n的数%p意义下的逆元 
		inv[1]=1;
		for(int i=2;i<=n;i++)
			inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	}
	int pyramid(int n, vector<int> &k) {
		// write your code here
		int ans=0;
		Inverse(n);
		f[0]=f[1]=1;
		for(int i=2;i<n;i++)
			f[i]=(1ll*(6*i-3)*f[i-1]-1ll*(i-2)*f[i-2])%mo*inv[i+1]%mo;
		f[0]=inv[2];
		for(auto x:k)
			(ans+=f[n-x]*2%mo)%=mo;
		return (ans+mo)%mo;
	}
}x;
vector<int> v{1,2,3};
int main(){
	printf("%d",x.pyramid(3,v));
	return 0;
}
