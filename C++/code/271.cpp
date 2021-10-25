class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string key;
        for (string s: strs) {
            key += s + (char)257;
        }
        return key;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> v;
        istringstream ss(s);
        string temp;
        while (getline(ss, temp, (char)257)) {
            v.push_back(temp);
        }
        return v;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));