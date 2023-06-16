//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    unordered_map<int, int> minPositionMap, maxPositionMap;

// Helper function to calculate minimum time
long long calculateMinTime(int currentPosition, int index, vector<int>& orderedTypes, vector<vector<long long>>& dp, int previousDirection) {
    // Base case: If all locations have been visited, return 0
    if (index == orderedTypes.size()) {
        return 0;
    }

    // If the result for the current state has already been computed, return it
    if (dp[index][previousDirection] != -1) {
        return dp[index][previousDirection];
    }

    long long option1 = 0, option2 = 0;
    int leftmostPosition = minPositionMap[orderedTypes[index]];
    int rightmostPosition = maxPositionMap[orderedTypes[index]];

    // Calculate time taken if the next location is visited by moving right
    option1 = abs(currentPosition - leftmostPosition) + abs(leftmostPosition - rightmostPosition) + calculateMinTime(rightmostPosition, index + 1, orderedTypes, dp, 1);

    // If it is the last index, add the time taken to return from the last location to position 0
    if (index == orderedTypes.size() - 1) {
        option1 += abs(rightmostPosition - 0);
    }

    // Calculate time taken if the next location is visited by moving left
    option2 = abs(currentPosition - rightmostPosition) + abs(leftmostPosition - rightmostPosition) + calculateMinTime(leftmostPosition, index + 1, orderedTypes, dp, 0);

    // If it is the last index, add the time taken to return from the last location to position 0
    if (index == orderedTypes.size() - 1) {
        option2 += abs(leftmostPosition - 0);
    }

    // Store the minimum time in the dp table for memoization and return it
    return dp[index][previousDirection] = min(option1, option2);
}

// Main function to find the minimum time
long long minTime(int totalLocations, vector<int>& locations, vector<int>& types) {
    int maxType = *max_element(types.begin(), types.end());
    vector<int> typePresence(maxType + 1, 0);

    // Iterate over the locations to find the minimum and maximum positions for each type
    for (int i = 0; i < totalLocations; i++) {
        typePresence[types[i]] = 1;
        if (minPositionMap.find(types[i]) == minPositionMap.end()) {
            minPositionMap[types[i]] = locations[i];
            maxPositionMap[types[i]] = locations[i];
        }
        else {
            minPositionMap[types[i]] = min(minPositionMap[types[i]], locations[i]);
            maxPositionMap[types[i]] = max(maxPositionMap[types[i]], locations[i]);
        }
    }

    vector<int> orderedTypes;
    // Create a temporary vector with types present in typePresence vector
    for (int i = 0; i <= maxType; i++) {
        if (typePresence[i] == 1) {
            orderedTypes.push_back(i);
        }
    }

    vector<vector<long long>> dp(orderedTypes.size(), vector<long long>(2, -1));
    // Call the helper function with initial position 0, initial index 0, and necessary parameters
    return calculateMinTime(0, 0, orderedTypes, dp, 0);
}
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends