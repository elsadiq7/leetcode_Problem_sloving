#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        // Sort the hand to process the smallest element first
        sort(hand.begin(), hand.end());

        // Use a frequency map to count occurrences
        unordered_map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }
        // Iterate through the sorted hand and try to form groups
        for (int i = 0; i < hand.size(); i++) {
            if (countMap[hand[i]] == 0) continue; // If already used, skip

            // Try forming a valid group starting from hand[i]
            for (int j = 0; j < groupSize; j++) {
                int currentCard = hand[i] + j;

                if (countMap[currentCard] == 0) return false; // Missing card in sequence

                countMap[currentCard]--; // Use this card
            }
        }

        return true;
    }
};
