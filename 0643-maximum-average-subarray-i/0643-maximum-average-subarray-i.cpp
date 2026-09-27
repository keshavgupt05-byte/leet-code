class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        // Calculate sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long long maxSum = sum;

        // Sliding window
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};