class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            // Store: Length + Delimiter + String
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            // 1. Find the delimiter to get the length
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            // 2. Extract the length
            int length = stoi(s.substr(i, j - i));
            
            // 3. Move i to the start of the actual string
            i = j + 1;
            
            // 4. Extract the string using the length
            decoded.push_back(s.substr(i, length));
            
            // 5. Move i to the start of the next encoded chunk
            i += length;
        }
        
        return decoded;
    }
};