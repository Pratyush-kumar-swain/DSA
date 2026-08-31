class Solution {
    public int lengthOfLongestSubstring(String s) {

        StringBuilder sb=new StringBuilder();int maxLen=0;
        HashMap<Character,Integer> hm=new HashMap<>();

        for(int i=0;i<s.length();i++)
        {
            if(!hm.containsKey(s.charAt(i) )|| hm.getOrDefault(s.charAt(i),0)==0)
            {
                hm.put(s.charAt(i),1);
                sb.append(s.charAt(i));
                maxLen=Math.max(maxLen,sb.length());
            }
            else if(hm.containsKey(s.charAt(i)))
            {
                while(sb.charAt(0)!=s.charAt(i))
                {
                    hm.remove(sb.charAt(0));
                    sb.deleteCharAt(0);
                }
                sb.deleteCharAt(0);
                sb.append(s.charAt(i));
            }
        }
        return maxLen;
    }
}