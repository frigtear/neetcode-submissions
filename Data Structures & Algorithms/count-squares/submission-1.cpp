class CountSquares {

private:
    std::vector<std::vector<int>> points;
    std::map<std::vector<int>, int> pointsMap;

public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        pointsMap[point] += 1;
    }
    
    int count(vector<int> point) {
        int result = 0;

        for (const auto& other : points) {

            if (std::abs(other[0] - point[0]) == std::abs(other[1] - point[1]) && other[0] != point[0]) {
                vector<int> p1 = {point[0], other[1]};
                vector<int> p2 = {other[0], point[1]};

                auto it1 = pointsMap.find(p1);
                auto it2 = pointsMap.find(p2);

                if (it1 != pointsMap.end() &&
                    it2 != pointsMap.end()) {
                    result += it1->second * it2->second;
                }
            }
        }

        return result;
    }
    // Square
    // Two points are 90 degrees from each other
    // Search all points that has the same x value and same y value
    // If we find two that match and are same distance from eachother,
    // Then compute the location of the final point
    // Which should be just subtracting 
};
