// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each 
// character in this substring is greater than or equal to k.

 

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.




class Solution {
public:
  
    int longestSubstring(string s, int k) {
        
        int i=0,j=s.length()-1;
        
        int count[26]={0};
        
        for(int k=0;k<j+1;k++)
        {
            count[s[k]-'a']++;
        }
        
           if(s.size() == 0 || k > s.size())   return 0;
        if(k == 0)  return s.size();
        
        while((i<s.size())&&count[s[i]-'a']>=k)
        {
            i++;
        }
            if(i == s.size()) return s.size();
        int left=longestSubstring(s.substr(0 , i),k);
        int right=longestSubstring(s.substr(i+1),k);
        
        return max(left,right);
    }
};
