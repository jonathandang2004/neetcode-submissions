class MedianFinder {
private:
    priority_queue<int> lowerhalf;
    priority_queue<int, vector<int>, greater<int>> upperhalf;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lowerhalf.push(num);
        upperhalf.push(lowerhalf.top());
        lowerhalf.pop();
        if (upperhalf.size() > lowerhalf.size()) {
            lowerhalf.push(upperhalf.top());
            upperhalf.pop();
        }
    }
    
    double findMedian() {
        if (lowerhalf.size() == upperhalf.size()) {
            return ((double) lowerhalf.top() + (double) upperhalf.top()) / 2;
        } 
        return (double) lowerhalf.top();
    }
};
