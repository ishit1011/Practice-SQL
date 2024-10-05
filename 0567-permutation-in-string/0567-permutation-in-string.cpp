class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;  // s1 cannot be a permutation if it is longer than s2
        int l = 0, r = n - 1;  // Window size of `n` (same as s1's length)

        // Sliding window through s2
        while (r < m) {
            bool check = true;
            vector<int> freq(26, 0);  // Frequency array to count characters
            
            // Count frequency of characters in the current window of s2
            for (int i = l; i <= r; i++) {
                freq[s2[i] - 'a']++;
            }

            // Check if the frequencies match with s1's frequency
            for (char c : s1) {
                if (--freq[c - 'a'] < 0) {
                    check = false;
                    break;
                }
            }

            if (check) {
                return true;  // Found a valid permutation
            }

            l++;  // Move the window
            r++;
        }

        return false;
    }
};
