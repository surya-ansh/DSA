// in array questions where we have to move elements->>>>>take first element and do the operations   
// int index = 0;

// 283. Move Zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[index] = nums[i];
                index++;
            }
        }
        for(int i = index; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};




// Lesson


// use set when we need to make an array with no duplicates
// as set removes all the duplicates automatically
// use this example to understand
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Using a set to automatically handle duplicates
    set<int> s;
    
    for(int num : a){
        s.insert(num);
    }
    
    for(int mun : b){
        s.insert(mun);
    }
    
    vector<int> ans(s.begin(), s.end());
    
    return ans;

   }