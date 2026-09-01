class Solution {
public:
    string minWindow(string s, string t) {

        if(s.length()<t.length())
        return "";

        unordered_map<char,int> mp;
        for(int i=0;i<t.length();i++)
        {
            mp[t[i]]=mp[t[i]]+1;
        }  

        int i=0,j=0,countReq=t.length();int start=0;int minWin=INT_MAX;

        while(j<s.length() && i<=j)
        {
           
                if(mp[s[j]]>0)
                 countReq--;

                mp[s[j]]=mp[s[j]]-1;
                
                while(countReq==0)
            {
                if (j - i + 1 < minWin) {
                     minWin = j - i + 1;
                      start = i;
                   }

                mp[s[i]]=mp[s[i]]+1;
                if(mp[s[i]]>0)
                    countReq++;
                 i++;
            }
            j++;
        }      
        return minWin==INT_MAX ? "":s.substr(start,minWin);
    }
};