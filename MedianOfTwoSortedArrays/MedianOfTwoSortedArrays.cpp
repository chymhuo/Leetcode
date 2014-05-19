class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int sum = m + n;
		if (0 == sum % 2) {
			return ((double)findKthNum(A, m, B, n, sum/2) + (double)findKthNum(A, m, B, n, sum/2 + 1)) / 2.0;
		}
		else {
			return findKthNum(A, m, B, n, (sum + 1) / 2);
		}
	}
	int findKthNum(int A[], int m, int B[], int n, int k) {
		if (m > n) return findKthNum(B, n, A, m, k);
		if (0 == m) return B[k-1];
		if (1 == k) {
			return min(A[0], B[0]);
		}
		else if (2 == k) {
			if (A[0] < B[0]) {
				return 1 < m ? min(A[1], B[0]) : B[0];				
			}
			else {
				return 1 < n ? min(A[0], B[1]) : A[0];
			}
		}
		int pa = min(k/2, m), pb = k - pa;
		if (A[pa - 1] < B[pb-1]) {
			return findKthNum(A+pa, m-pa, B, n, k-pa);
		}
		else {
			return findKthNum(A, m, B+pb, n-pb, k-pb);
		}	
	}
};