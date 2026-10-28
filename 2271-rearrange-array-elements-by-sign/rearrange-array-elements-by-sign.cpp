class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        queue<int> p;
        queue<int> n;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            p.push(nums[i]);
            else
            n.push(nums[i]);
        }

        int k=1;
        for(int i=0;i<nums.size();i++)
        {
            if(k==1)
            {
                nums[i]=p.front();
                p.pop();
            }
            else
            {
                nums[i]=n.front();
                n.pop();
            }
            k=k*-1;
        }
        return nums;
    }
};