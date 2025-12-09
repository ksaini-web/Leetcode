                  class Solution {
     public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()){
            return "";

        } 
        sort(strs.begin(),strs.end());

        string ans="",first=strs.front(),last=strs.back();

        for(int i=0;i<first.size();i++){

            if(first[i]==last[i]){

                ans+=first[i];
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};
