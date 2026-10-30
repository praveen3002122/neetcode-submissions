class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int corder[26];
        for(int i =0;i<order.length();i++){
            corder[order[i]-'a']=i;
        }

        for(int i =0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];
            bool match = false;
            for(int j =0;j< min(w1.length(), w2.length());j++){
                if(w1[j]!=w2[j]){
                    if(corder[w1[j]-'a']> corder[w2[j]-'a']) return false;
                    match = true;
                    break;
                }
            }
            if(!match && w1.length()>w2.length()) return false;
        }
        return true;
    }
};