// https://leetcode.com/problems/fruits-into-baskets-iii/description/?slug=choose-k-elements-with-maximum-sum&region=global_v2
class Solution {
public:
    vector<int> tree;
    void build(int ind,int start,int end,vector<int> &arr){
        if(start==end){
            tree[ind] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*ind,start,mid,arr);
        build(2*ind+1,mid+1,end,arr);
        tree[ind] = max(tree[2*ind],tree[2*ind+1]);
    }
    int query(int ind,int start,int end,int x){
        if(tree[ind]<x) return -1;
        if(start==end){
            tree[ind] = -1;
            return start;
        }
        int mid = (start+end)/2;
        int pos = -1;
        if(tree[2*ind]>=x){
            pos = query(2*ind,start,mid,x);
        }
        else{
            pos = query(2*ind+1,mid+1,end,x);
        }
        tree[ind] = max(tree[2*ind],tree[2*ind+1]);
        return pos;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        tree.assign(4*n+5,-1);
        build(1,0,n-1,baskets);
        int cnt = 0;
        for(int f:fruits){
            if(query(1,0,n-1,f)==-1){
                cnt++;
            }
        }
        return cnt;
    }
};
