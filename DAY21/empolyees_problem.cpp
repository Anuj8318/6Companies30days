// 2933. High-Access Employees
// https://leetcode.com/problems/high-access-employees/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> freq; // Map to store employee and their access times
        vector<string> result;

        // Populate the frequency map
        for (auto& entry : access_times) {
            freq[entry[0]].push_back(entry[1]); // entry[0] = employee ID, entry[1] = access time
        }

        // Identify employees with high access (e.g., more than 3 accesses in one hour)
        for (auto& [employee, times] : freq) {
            // Sort times for the employee
            sort(times.begin(), times.end());

            // Check if any 3 consecutive times are within 1 hour
            for (int i = 0; i + 2 < times.size(); i++) {
                string t1 = times[i], t2 = times[i + 1], t3 = times[i + 2];
                if (withinOneHour(t1, t3)) { // Helper function checks 1-hour condition
                    result.push_back(employee);
                    break; // No need to check further for this employee
                }
            }
        }

        return result;
    }

private:
    // Helper function to check if two times are within one hour
    bool withinOneHour(const string& start, const string& end) {
        int startHour = stoi(start.substr(0, 2));
        int startMinute = stoi(start.substr(2, 4));
        int endHour = stoi(end.substr(0, 2));
        int endMinute = stoi(end.substr(2, 4));

        int startTimeInMinutes = startHour * 60 + startMinute;
        int endTimeInMinutes = endHour * 60 + endMinute;

        return (endTimeInMinutes - startTimeInMinutes) < 60;
    }
};
