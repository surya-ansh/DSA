// in array questions where we have to move elements->>>>>take first element and do the operations by comparing elements
// int index = 0;

283. Move Zeroes
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


// lesson
How the Map (std::map) Works
A map is a container that:

Stores elements as key-value pairs: // Each key is unique, 
and every key is associated with a value.
// Maintains sorted order: Keys are always stored in sorted order (ascending by default).
Allows efficient operations:
Insertion, deletion, and access take 
O(logN) time because map is implemented as a balanced binary search tree (e.g., Red-Black Tree).

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        map<int, int> mapping;

        for(int num : nums){
            mapping[num]++;
        }

        for(auto num : mapping){
            if(num.second == 1)
                ans = num.first;
        }
        return ans;
    }
};

