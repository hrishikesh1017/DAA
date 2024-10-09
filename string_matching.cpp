#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find all occurrences of a pattern in a string
vector<size_t> findAllOccurrences(const string& text, const string& pattern) {
    vector<size_t> positions; // Store the positions of all occurrences
    size_t pos = text.find(pattern); // First occurrence

    while (pos != string::npos) {
        positions.push_back(pos); // Add the found position to the vector
        // Search for the next occurrence starting from the next position
        pos = text.find(pattern, pos + 1);
    }

    return positions;
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";

    // Get all occurrences of the pattern in the text
    vector<size_t> occurrences = findAllOccurrences(text, pattern);

    // Print the occurrences
    cout << "Pattern found at positions: ";
    for (size_t pos : occurrences) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
