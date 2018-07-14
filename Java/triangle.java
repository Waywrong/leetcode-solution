//  Triangle

// Time O(N^2), Space O(1)
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int row=triangle.size()-2; row>=0; row--) {
            for (int col=0; col<triangle.get(row).size(); col++) {
                int temp = triangle.get(row).get(col);
                temp += Math.min(triangle.get(row+1).get(col), triangle.get(row+1).get(col+1));
                triangle.get(row).set(col, temp);
            }
        }
        return triangle.get(0).get(0);
    }
}