class Solution {
public:
    string intToRoman(int num) {

        // Storing Roman values and their corresponding symbols
        vector<pair<int, string>> romanMap = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
        };

        string res = "";  // This will store the result

        // Loop through every Roman value and symbol
        for (auto [val, sym] : romanMap) {

            // Keep using the current Roman value
            // while num is greater than or equal to it
            while (num >= val) {

                res += sym;   // Add corresponding Roman symbol

                num -= val;   // Subtract value from num
            }

            // If entire number is converted, stop early
            if (num == 0) {
                break;
            }
        }

        return res;
    }
};