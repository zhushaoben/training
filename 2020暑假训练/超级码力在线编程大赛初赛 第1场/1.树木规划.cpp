class Solution {
public:
    /**
     * @param trees: the positions of trees.
     * @param d: the minimum beautiful interval.
     * @return: the minimum number of trees to remove to make trees beautiful.
     */
    int treePlanning(vector<int> &trees, int d) {
    	int ans=0,pre=-d;
        for(auto x:trees){
        	if(x-pre<d)ans++;
        	else pre=x;
		}
		return ans;
        // write your code here.
    }
};
