// TC: O(M+N)-> m = pattern size, and n = text size
// here we try not to do the redundent work by just going to the last matched prefix and continuing from there
// example: text: aaaaaaaaaaaab, pattern: aaab
// here if we go naive we will each time when not match the character 'b' come to the i+1 in the text and start from 0 in the pattern. TC: O(m*n)
// but using kmp we store the "Longest prfix that is also a suffix length"(lps)
// here pre_ind = lps[i-1] that represent the longest lps upto i-1 so two cases accur
// it goes to the last index where it matched this by pre_ind = lps[i-1] and check weather it matched with the current i or not? 
// 1. if match we will increase the lps[i] by previous lps 
// 2. if not we go to its parent or last index and than check.

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        string s = pat + "#" + txt;
        int m = s.size();
        vector<int> lps(m,0);
        // pre_ind = previous index and also the lenght of the longest 
        // matched prefix that is also suffix
        for(int i=1;i<m;i++){
            int pre_ind = lps[i-1];
            while(pre_ind > 0 && s[pre_ind]!=s[i]){
                pre_ind = lps[pre_ind-1];
            }
            lps[i] = pre_ind + (s[pre_ind]==s[i]?1:0);
        }
        int n = pat.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            
            if(lps[i]==n){
                int bigining = i-2*n; // (pat#-> n) (pat in txt->n) so 2N
                if(bigining>=0){
                    ans.push_back(bigining+1); // 1-based indexing
                }
            }
        }
        return ans;
    }
};
