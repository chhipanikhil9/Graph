// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/?envType=daily-question&envId=2025-06-05
class Solution {
public:
    vector<int> par;
    void build(){
        par.assign(26,-1);
        for(int i=0;i<26;i++){
            par[i] = i;
        }
    }
    int findPar(int u){
        if(u==par[u]) return u;
        return par[u] = findPar(par[u]);
    }

    void uni(int u,int v){
        int pu = findPar(u), pv = findPar(v);
        if(pu==pv) return;
        if(pu>pv){
            swap(pu,pv);
        }
        par[pv] = pu; 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.size(), n = baseStr.size();
        build();
        for(int i=0;i<m;i++){
            int ind1 = s1[i]-'a', ind2 = s2[i]-'a';
            uni(ind1,ind2);
        }

        string ans = "";
        for(int i=0;i<n;i++){
            ans += ('a'+findPar(baseStr[i]-'a'));
        }
        return ans;
    }
};
