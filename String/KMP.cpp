
// Knuth-Morris-Pratt [ KMP ] - ALGORITHM
// T.C. : O(n)
// Function to compute the LPS (Longest Prefix Suffix) array for the target-string `target` 
   
vector<int> computeLPS(string &target) {
    
    vector<int> lps(target.size(), 0);  // Initialize the LPS array with 0
    
    int currentIndex = 1;   // Start from the second character
    int len = 0;           // Length of the current longest prefix which is also a suffix
    
    while (currentIndex < target.size()) {

        if (target[currentIndex] == target[len]) {
            len++;                     // If the current characters match, extend the prefix
            lps[currentIndex] = len;  // Store the length of the prefix
            currentIndex++;
        } 
        else {
            if (len > 0) {
                len = lps[len - 1];  // Backtrack using LPS array to find a shorter match
            } 
            else {
                currentIndex++;
            }
        }
    }
    return lps;
}


// Function to check if `target` is substring of `text` using the KMP algorithm

bool find_substring(string &target, string &text, vector<int> &lps) {

    int textIndex = 0;     // Pointer for `text`
    int targetIndex = 0;   // Pointer for `target`

    while (textIndex < text.size()) {

        if(text[textIndex] == target[targetIndex]) {
            targetIndex++;
            textIndex++;
            if (targetIndex == target.size()) return true;  // Found a match
        }
        else {
            if (targetIndex > 0) {
                targetIndex = lps[targetIndex - 1];  // Use the LPS to skip unnecessary comparisons
            }
            else {
                textIndex++;
            }
        }
    }
    return false;  // No match found.
}
