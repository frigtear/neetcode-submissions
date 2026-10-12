class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        char first_char = 'd';
        char second_char = 'd';

        std::priority_queue<std::pair<int, char>> max_heap;
        if (a > 0) {
            max_heap.push({a, 'a'});
        }
        if (b > 0){
            max_heap.push({b, 'b'});
        }
        if (c > 0){
            max_heap.push({c, 'c'});
        }

        std::string result;
        result.reserve(a + b + c);

        while (!max_heap.empty()){
            auto most_frequent = max_heap.top();
            max_heap.pop();
            int frequency = most_frequent.first;
            char first_id = most_frequent.second;

            if (first_id == second_char && first_id == first_char){
                // we need second largest 
                if (max_heap.empty()){
                    return result;
                }

                auto second_most_frequent = max_heap.top();
                int second_frequency = second_most_frequent.first;
                char second_id = second_most_frequent.second;

                max_heap.pop();
                result.push_back(second_id);

                if (second_frequency > 1){
                    max_heap.push({second_frequency - 1, second_id});
                }

                max_heap.push(most_frequent);

                second_char = first_char;
                first_char = second_id;
            }
            else {
                result.push_back(first_id);
                
                if (frequency > 1){
                    max_heap.push({frequency - 1, first_id});
                }

                second_char = first_char;
                first_char = first_id;
            }

        }

        return result;

    }
};