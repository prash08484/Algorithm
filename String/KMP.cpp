// Knuth-Morris-Pratt [ KMP ] - ALGORITHM
// Function to compute the LPS (Longest Prefix Suffix) array for the patternstring `pattern`. 
   

        vector<int> computeLPSArray(string &pattern) {
        vector<int> lps(pattern.size(), 0);  // Initialize the LPS array with 0.
        int currentIndex = 1;            // Start from the second character.
        // Length of the current longest prefix which is also a suffix.
        int len = 0;

        while (currentIndex < pattern.size()) {
            if (pattern[currentIndex] == pattern[len]) {
                len++;  // If the current characters match, extend the prefix.
                lps[currentIndex] = len;  // Store the length of the prefix.
                currentIndex++;
            } 
            else {
                if (len > 0) {
                    len = lps[len - 1];  // Backtrack using LPS array to find a
                   // shorter match.
                } 
                else {
                    currentIndex++;
                }
            }
        }
        return lps;
    }


    // Function to check if `pattern` is a patternstring of `text` using the KMP algorithm.

    bool ispatternstringOf(string &pattern, string &text, vector<int> &lps) {
        int textIndex = 0;  // Pointer for `text`.
        int patternIndex = 0;   // Pointer for `pattern`.

        while (textIndex < text.size()) {
            if(text[textIndex] == pattern[patternIndex]) {
                patternIndex++;
                textIndex++;
                if (patternIndex == pattern.size()) return true;  // Found a match.
            }
             else {
                if (patternIndex > 0) {
                    // Use the LPS to skip unnecessary comparisons.
                    patternIndex = lps[patternIndex - 1];
                }
                 else {
                    textIndex++;
                }
            }
        }
        return false;  // No match found.
    }
