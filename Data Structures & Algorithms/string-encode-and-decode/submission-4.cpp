class Solution {

private:
    void fast_string_generic(std::string& output, size_t size) {
    if (size == 0) {
        output.push_back('0');
        return;
    }

    char buffer[20];
    int i = 20;

    while (size > 0) {
        buffer[--i] = '0' + (size % 10);
        size /= 10;
    }

    output.append(&buffer[i], 20 - i);
}


public:

    string encode(vector<string>& strs) {
        // to encode we do number delimeter then character
        constexpr char delimeter = '/';
        // for absolute max performance, we are going to predetermine the size of the string so we can use .reserve
        size_t maximum_size = 0;
        for (const auto& str : strs){
            maximum_size += str.size() + 4;
        }

        std::string result;
        result.reserve(maximum_size);
        // now that we dont have to worry about costly
        // copying into different buffers and heap allocations
        // we can continue
        // we need to convert ourself for speed

        for (const auto& str : strs){
            fast_string_generic(result, str.size());
            result.push_back(delimeter);
            result.append(str);
        }

        return result;
    }

    vector<string> decode(string s) {
        std::string_view sv = s;
        size_t index = 0;
        std::vector<string> result;

        while (index < sv.size()) {

            size_t length_of_string = 0;

            while (index < sv.size() && sv[index] != '/') {
                length_of_string *= 10;
                length_of_string += (sv[index] - '0');
                index++;
            }

            // delimiter was never found
            if (index >= sv.size()) {
                return {};
            }

            index++; // skip '/'

            // make sure enough characters remain
            if (length_of_string > sv.size() - index) {
                return {};
            }

            std::string str;
            str.reserve(length_of_string);

            for (size_t i = 0; i < length_of_string; i++) {
                str.push_back(sv[index]);
                index++;
            }

            result.push_back(std::move(str));
        }

        return result;
    }
};
