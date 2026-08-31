class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        int n=nums.length;
        int[] ans=new int[n-k+1];int j=0;

        Deque<Integer> deq=new LinkedList<>();
        for(int i=0;i<n;i++)
        {
            while(!deq.isEmpty() && deq.getFirst()<=i-k)
            {
                deq.removeFirst();
            }

            while(!deq.isEmpty() && nums[i]>nums[deq.getLast()])
            {
                deq.removeLast();
            }

            deq.addLast(i);

            if(i>=k-1)
            {
                ans[j++]=nums[deq.getFirst()];
            }
        }

        return ans;
    }
}