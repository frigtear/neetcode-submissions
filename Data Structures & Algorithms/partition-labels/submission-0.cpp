class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        // One substring -> 1 letter
        // xaaaxbc ? 
        // We have to know how many of each letter is
        // in string
        // So if there is still this letter left
        // We cant end our substring until 
        // There is no more of every
        // letter in it in the substring
        // Once we hit that state,
        // Simply append our index to the result

        // For our new character, simply check if its in 
        // freqmap
        // But it might be not in but others in substring
        // could still have stuff left
        // We dont want (N*26) do we??
        // Maybe store an int that represents
        // The amount of characters we passed so far
        // and when we remove the final --
        // If we add a new character then increment
        // When it goes to 0 then append to result

        std::map<char, int> freqMap;
        for (const auto& character : s) {
            freqMap[character]++;
        }

        std::vector<int> result;
        std::set<int> seen;
        int numChars = 0;
        int count = 1;
        for (int i = 0; i < s.size(); i++) {
            char character = s[i];
            if (freqMap[character] > 0) {
                freqMap[character] --;

                if (!seen.contains(character)){
                    numChars++;
                    seen.insert(character);
                }
            
                if (freqMap[character] == 0) {
                    numChars --;
                } // weve decremented to 0
            }
            if (numChars == 0){
                result.push_back(count);
                count = 1;
            }
            else{
                count ++;
            }
        }

        return result;
    }
};
