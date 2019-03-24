class Solution {
    public int candy(int[] ratings) {
        if (ratings.length == 0) {
            return 0;
        }
        int[] candies = new int[ratings.length];
        int total = ratings.length;
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i + 1] + 1, candies[i]);
            }
        }
        for (int candy : candies) {
            total += candy;
        }
        return total;
    }
}