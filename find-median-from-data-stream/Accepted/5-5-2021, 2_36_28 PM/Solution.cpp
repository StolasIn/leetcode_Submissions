// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> arr;
    MedianFinder() {
    }
    
    void addNum(int num) {
        arr.emplace_back(num);
        for(int i=arr.size()-1;i>=1;i--){
            if(arr[i]<arr[i-1]){
                swap(arr[i],arr[i-1]);
            }
        }
    }
    
    double findMedian() {
        int t=arr.size();
        if(t%2==0){
            t/=2;
            return (arr[t]+arr[t-1])/2.0;
        }
        else{
            t/=2;
            return arr[t];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */