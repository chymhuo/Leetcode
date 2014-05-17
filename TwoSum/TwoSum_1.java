public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n = numbers.length;
        int[] result = new int[2];
        if (n <= 1) return result;
        HashMap<Integer, Integer> indexMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            int num1 = numbers[i];
            int num2 = target - num1;
            if (indexMap.containsKey(num2)) {
                int index1 = indexMap.get(num2);
                result[0] = index1;
                result[1] = i + 1;
                return result;
            }
            else indexMap.put(num1, i+1);
        }
        return result;
    }
}