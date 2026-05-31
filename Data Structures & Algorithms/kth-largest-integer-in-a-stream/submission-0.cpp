class KthLargest {
private:
    vector<int> numbers;
    int k = 0;
public:
    KthLargest(int k, vector<int>& nums) : numbers(nums), k(k){
        // numbers = nums;
        // this.k = k;
    }
    
    int add(int val) {
        numbers.push_back(val);
        priority_queue<int> pq(numbers.begin(), numbers.end());
        int num = 0;
        for (int i = 0; i < k; ++i) {
            num = pq.top();
            pq.pop();
        }
        return num;
    }
};
