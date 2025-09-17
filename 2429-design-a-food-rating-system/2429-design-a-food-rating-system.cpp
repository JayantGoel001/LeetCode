class FoodRatings {
    // Map food with its rating.
    unordered_map<string, int> foodRatingMap;
    // Map food with cuisine it belongs to.
    unordered_map<string, string> foodCuisineMap;

    // Store all food of a cusine in set (to sort them on ratings/name)
    // Set element -> Pair: (-1 * foodRating, foodName)
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(-1 * rating, name)' element in current cuisine's set.
            cuisineFoodMap[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    } 

    void changeRating(string food, int newRating) {
        // Fetch cuisine name for food.
        auto cuisineName = foodCuisineMap[food];

        // Find and delete the element from the respective cuisine's set.
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);

        // Update food's rating in 'foodRating' map.
        foodRatingMap[food] = newRating;
        // Insert the '(-1 * new rating, name)' element in respective cuisine's set.
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.second;
    }
};