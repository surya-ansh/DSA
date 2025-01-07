class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];  
        for(auto num : nums){
            sum = max(num, sum + num);
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};




Kadane's Algorithm is a widely used method to solve the Maximum Subarray Sum Problem, which involves finding the contiguous subarray within a given array of integers that has the largest sum. This algorithm is efficient, operating in 
𝑂
(
𝑛
)
O(n) time complexity.

How It Works
The algorithm maintains two variables while traversing the array:

Current Sum (currentSum):
Tracks the sum of the current subarray being considered.
If the current subarray's sum becomes negative, it's discarded, and a new subarray starts from the next element.
Maximum Sum (maxSum):
Tracks the largest sum encountered so far.
Steps of Kadane's Algorithm
Initialize:

currentSum = 0
maxSum = INT_MIN (or the smallest possible value).
Iterate through the array:

Add the current element to currentSum.
If currentSum exceeds maxSum, update maxSum.
If currentSum drops below zero, reset it to 0 (discard the current subarray).
Result:

At the end of the iteration, maxSum contains the maximum sum of any contiguous subarray.



