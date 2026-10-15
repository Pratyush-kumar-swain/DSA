class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long a=nums[0];
        for(int i=1;i<nums.size();i++)
        a=a^nums[i];

        long x=(a&(a-1))^a;
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&x)!=0)
            b1=b1^nums[i];
            else
            b2=b2^nums[i];
        }

        vector<int> v(2,0);v[0]=b1;v[1]=b2;
        return v;
    }
};