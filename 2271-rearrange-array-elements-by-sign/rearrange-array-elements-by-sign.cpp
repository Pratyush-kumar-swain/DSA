class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pos=0,neg=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                ans[pos]=nums[i];
                pos+=2;
            }
            else
            {
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};

 // queue<int> p;
        // queue<int> n;

        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]>=0)
        //     p.push(nums[i]);
        //     else
        //     n.push(nums[i]);
        // }

        // int k=1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(k==1)
        //     {
        //         nums[i]=p.front();
        //         p.pop();
        //     }
        //     else
        //     {
        //         nums[i]=n.front();
        //         n.pop();
        //     }
        //     k=k*-1;
        // }