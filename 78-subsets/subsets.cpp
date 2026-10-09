class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> v;int k=pow(2,nums.size());
        for(int i=0;i<k;i++)
        {
            int a=i;int count=nums.size()-1;
            vector<int> v1;
            while(count>=0)
            {
                if((a&1)!=0)
                v1.push_back(nums[count]);

                count--;a=a>>1;
            }
            v.push_back(v1);
        }
        return v;
    }
};