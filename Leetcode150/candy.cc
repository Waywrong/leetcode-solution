//  Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int kids = ratings.size();
        vector<int> candies(kids, 1);
        
        for (int kid = 1; kid < kids; ++kid) {
            if (ratings[kid] > ratings[kid-1])
                candies[kid] = candies[kid-1] + 1;
        }
        
        for (int kid = kids-2; kid >= 0; --kid) {
            if (ratings[kid] > ratings[kid+1] && candies[kid] <= candies[kid+1])
                candies[kid] = candies[kid+1] + 1;
        }
        
        int total_candies = 0;
        for (int kid = 0; kid < kids; ++kid)
            total_candies += candies[kid];
        
        return total_candies;
    }
};
