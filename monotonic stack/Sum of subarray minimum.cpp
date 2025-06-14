// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1
#define mod (int)(1e9+7)
class Solution {
  public:
    int sumSubarrayMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> pre(n,-1),next(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){ // removing the duplicate from left side
                st.pop();
            }
            if(!st.empty()){
                pre[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){ // here > to include the duplicate on right side only we only need to take the duplicate from one side so
                st.pop();
            }
            if(!st.empty()){
                next[i] = st.top();
            }
            st.push(i);
        }
        long long sum = 0;
        for(int i=0;i<n;i++){
            int left = (i-pre[i]);
            int right = (next[i]-i);
            sum = (sum+1ll*arr[i]*left*right)%mod;
        }
        return (int)sum;
    }
};
