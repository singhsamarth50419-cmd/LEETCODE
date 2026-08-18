class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0,rp=height.size()-1;
        int maxwater=0;
        
        while(lp<rp){
           int wd = rp-lp;
           int ht = min(height[rp],height[lp]);
           int currentwater = wd * ht;
            maxwater = max(maxwater, currentwater); 

            height[lp]<height[rp] ? lp++ : rp--;
        }
        return maxwater;
    }
};