class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;  // Use a max heap

        for (char c : s) {
            mp[c]++;
        }

        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if(ans.empty() || temp.second!=ans.back()){
                ans += temp.second;
                if(temp.first-1>0){
                    pq.push({temp.first-1,temp.second});
                }
            }else{
                if(pq.empty()){
                    return "";
                }
                auto temp2 = pq.top();
                pq.pop();
                ans += temp2.second;
                if(temp2.first-1>0){
                    pq.push({temp2.first-1,temp2.second});
                }
                pq.push(temp);
            }
        }
        // for(int i=1;i<n;i++){
        //     if(ans[i]==ans[i-1]) return "";
        // }
        return ans;
    }
};
