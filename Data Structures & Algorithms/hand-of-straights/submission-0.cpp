class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int>mp;
        for(int i =0;i<n;i++){
            mp[hand[i]]++;
        }

        for(auto it:mp){
            int currentcard = it.first;
            int count = it.second;

            if(count ==0) continue;

            for(int i =0;i<groupSize;i++){
                int nextcard= currentcard+i;
                if(mp[nextcard]<count) return false;
                mp[nextcard]-= count;
            }
        }
        return true;
    }
};
