class Solution {
public:
    /**
     * @param lengths: the lengths of sticks at the beginning.
     * @return: return the minimum number of cuts.
     */
    int makeEquilateralTriangle(vector<int> &lengths) {
    	map<int,int>mp;int ma=0;
    	for(auto x:lengths){
			if(++mp[x]==3)return 0;
			ma=max(ma,x);
		}
    	for(auto x:lengths){
    		if(mp[x]==2&&ma!=x)return 1;
    		if(x%2==0&&mp[x/2])return 1;
		}
		return 2;
        // write your code here.
    }
};
