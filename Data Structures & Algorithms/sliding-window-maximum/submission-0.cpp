class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq;

        int l = 0;
        int r = 0;

        std::vector<int> result;

        while (r < nums.size()) {

            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            r++;

            if ((r - l) == k) {
                result.push_back(nums[dq.front()]);

                l++;

                if (!dq.empty() && dq.front() < l) {
                    dq.pop_front();
                }
            }

            //std::cout << r << " " << l << " ";
        }

        return result;
    }
};