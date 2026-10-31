class Solution {
public:
    string countAndSay(int n) {
        
        // Base case: if n == 1, return "1"
        // Because the first term of count-and-say sequence is always "1"
        if(n==1) return "1";
        
        // Recursive call: get the previous term (n-1)
        // We need previous result to generate current result
        string say = countAndSay(n-1);

        // This will store the final answer for current n
        string result ="";

        

        // Loop through each character of previous string
        for(int i =0; i<say.length();i++){
            
            // Store current character
            char ch = say[i];
            
            // Start count as 1 (we already have one occurrence)
            int count =1;

            // Check how many times the same character repeats continuously
            // Keep moving forward while next character is same
            while(i < say.length()-1 && say[i] == say[i+1]){
                count++;   // Increase count
                i++;       // Move to next character
            }

            // Add count and character to result
            // Example: if count=3 and ch='1' → add "31"
            result += to_string(count) + string(1,ch);
        }

        // Return the final constructed string
        return result ;
    }
};