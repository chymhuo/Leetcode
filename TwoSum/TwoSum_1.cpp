// Since this question is asking for the original index
// So we could not use the "sort + two pointers" solution
// Use unordered_map as hash_map

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        vector<int> result;
        if (1 >= n) return result;
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) {
        	int num1 = numbers[i];
        	int num2 = target - num1;
        	if (indexMap.find(num2) != indexMap.end()) {
        		int index1 = indexMap[num2];
        		result.push_back(index1);
        		result.push_back(i + 1);
        		return result;
        	}
        	else indexMap[num1] = i + 1; 
        }
    }
};