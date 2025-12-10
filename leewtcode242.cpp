class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin(),s.end());

          sort(t.begin(),t.end());

    string lenght =max(t,s);

    for(int i=0;i<lenght.size();i++){

        if(s[i]!=t[i]){

            return false;
        }
    }

    return true;
        
    }
};
