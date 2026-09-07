class Solution {
public:
    bool isPalindromic(string s) {
        string k="";int n=s.size();bool palin=true;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            int asc_val=int(c);
            bitset<8> b(asc_val);
            k=k+b.to_string();
        }
        
        for(int i=0;i<4*n;i++)
        {
            if(k[i]!=k[8*n-1-i])
           {
            palin=false;
            break;
           }
            
        }

        return palin;
    }
};