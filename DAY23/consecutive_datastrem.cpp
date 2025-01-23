// 2526. Find Consecutive Integers from a Data Stream
// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
class DataStream {
public:
    queue<int> q;      // Queue to store the last k integers
    int val;           // Target value to check against
    int k;             // Number of consecutive integers to check
    int count;         // Counter for how many integers in the queue equal val

    DataStream(int value, int k) {
        val = value;
        this->k = k;
        count = 0; // Initialize count to 0
    }
    
    bool consec(int num) {
        // Add the new number to the stream
        q.push(num);
        // Increment the count if num equals the target value
        if (num == val) {
            count++;
        }
        // If the queue size exceeds k, remove the oldest element
        if (q.size() > k) {
            int removed = q.front();
            q.pop();
            // Decrement the count if the removed element equals val
            if (removed == val) {
                count--;
            }
        }
        // Return true if the count equals k (all last k elements are val)
        return (q.size() == k && count == k);
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
