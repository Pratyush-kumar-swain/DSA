class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        vector<int> v;

        int i = pos - 1;
        int j = pos;

        while(k > 0)
        {
            // No elements on the left
            if(i < 0)
            {
                v.push_back(arr[j]);
                j++;
            }

            // No elements on the right
            else if(j >= arr.size())
            {
                v.insert(v.begin(), arr[i]);
                i--;
            }

            // Left is closer or equally close
            else if(abs(arr[i] - x) <= abs(arr[j] - x))
            {
                v.insert(v.begin(), arr[i]);
                i--;
            }

            // Right is closer
            else
            {
                v.push_back(arr[j]);
                j++;
            }

            k--;
        }

        return v;
    }
};