// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <unordered_set>

// using namespace std;

// class Solution {
// private:
//     unordered_map<char, int> charToDigit;
//     unordered_set<char> leadingChars;
//     bool solved;

//     long long calculateValue(const vector<string>& words) {
//         long long sum = 0;
//         for (const string& word : words) {
//             long long num = 0;
//             for (char ch : word) num = num * 10 + charToDigit[ch];
//             sum += num;
//         }
//         return sum;
//     }

//     bool isSolutionValid(const vector<string>& words, const string& result) {
//         long long leftSum = calculateValue(words);
//         long long rightSum = calculateValue({result});
//         return leftSum == rightSum;
//     }

//     bool solve(vector<string>& words, const string& result, const vector<char>& chars, int idx) {
//         if (idx == chars.size()) {
//             solved = isSolutionValid(words, result);
//             return solved;
//         }

//         char currentChar = chars[idx];
//         for (int digit = (leadingChars.count(currentChar) ? 1 : 0); digit <= 9; ++digit) {
//             if (!solved) {
//                 charToDigit[currentChar] = digit;
//                 solve(words, result, chars, idx + 1);
//             }
//         }

//         return solved;
//     }

// public:
//     bool isSolvable(vector<string>& words, string result) {
//         for (const string& word : words) {
//             leadingChars.insert(word.front());
//         }
//         leadingChars.insert(result.front());

//         vector<char> chars;
//         for (const string& word : words) {
//             for (char ch : word) {
//                 chars.push_back(ch);
//             }
//         }
//         for (char ch : result) {
//             chars.push_back(ch);
//         }
//         sort(chars.begin(), chars.end());
//         chars.erase(unique(chars.begin(), chars.end()), chars.end());

//         solve(words, result, chars, 0);
//         return solved;
//     }
// };

// int main() {
//     Solution solution;
//     vector<string> words = {"ELM", "ALDER", "MAPLE", "ELDER"};
//     string result = "MONEY";

//     bool solvable = solution.isSolvable(words, result);
//     if (solvable) {
//         cout << "Valid assignment found!" << endl;
//     } else {
//         cout << "No valid assignment found." << endl;
//     }

//     return 0;
// }
