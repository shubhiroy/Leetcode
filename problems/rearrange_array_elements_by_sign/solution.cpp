class Solution{
    public:
    vector<int> rearrangeArray(vector<int> &nums){
        int pos=0, neg=0, size = nums.size();
        vector<int> result;
        while(pos<size && neg < size){
            while(pos < size && nums[pos]<0){
                pos++;
            }
            while(neg < size && nums[neg]>0){
                neg++;
            }
            result.push_back(nums[pos]);
            result.push_back(nums[neg]);
            pos++;
            neg++;
        }
        return result;
    }
};

// TC-O(N), SC-O(2N)
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> pos, neg;
//         for(int i = 0; i<nums.size(); i++){
//             if(nums[i]>0){
//                 pos.push_back(nums[i]);
//             }else{
//                 neg.push_back(nums[i]);
//             }
//         }
//         vector<int> res;
//         for(int i=0;i<pos.size() && i<neg.size();i++){
//             res.push_back(pos[i]);
//             res.push_back(neg[i]);
//         }
//         if(pos.size()>neg.size()){
//             res.push_back(pos[pos.size()-1]);
//         }else if(pos.size()<neg.size()){            
//             res.push_back(neg[neg.size()-1]);
//         }
//         return res;
//     }
// };