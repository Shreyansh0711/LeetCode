class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0;

        boolean[] p = new boolean[n];

        // Java boolean arrays are false by default,
        // so explicitly make everything true
        for (int i = 0; i < n; i++) {
            p[i] = true;
        }

        p[0] = p[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (p[i]) {
                for (int j = i * i; j < n; j += i) {
                    p[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (p[i]) count++;
        }

        return count;
    }
}