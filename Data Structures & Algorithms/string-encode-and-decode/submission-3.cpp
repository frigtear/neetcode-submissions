class Solution {
public:

    string encode(vector<string>& strs) {
        // First number -> how many strings there are
        // Look at first n based on how many numbers there are
        // Each ones is the length of that next string 
        char delimter = '#';
        std::string encoding;

        for ( const auto& str : strs ) { 
            encoding += (std::to_string(str.size()) + delimter);
            encoding += str;
        }

        return encoding;
        
    }

    vector<string> decode(string s) {
  
        int i = 0;
        std::vector<std::string> decoding;
        std::string length_as_string;
        std::cout << s << " ";
        while ( i < s.size()){
            if (s[i] != '#'){
                length_as_string += s[i];
                i++;
            }
            else {
                i++;
                int length_of_substring = std::stoi(length_as_string);
                length_as_string = "";
                std::string str;
                int curr = i;
                for (; i < (curr + length_of_substring); i++){
                    str += s[i];
                }
                decoding.push_back(str);
            }
        }

       
       return decoding;

    }
};
