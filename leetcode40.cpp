class Solution {
public:



void getallcombintion(vector<int>& candidates,int target,int idx,vector<vector<int>>&ans,vector<int>&combin){
  
//   if(idx==candidates.size()||target<0){

//     return;

  //}
  if(target==0){

   
        ans.push_back(combin);
       
    
    return;
  }

for(int i =idx;i<candidates.size();i++){

    if(i>idx&&candidates[i]==candidates[i-1]){
        
        continue;
    }
    if(candidates[i]>target){
        break;
    }


    combin.push_back(candidates[i]);


    getallcombintion(candidates,target-candidates[i],i+1,ans,combin);

    combin.pop_back();
}

    
    


    
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

sort(candidates.begin(),candidates.end());
vector<vector<int>>ans;
vector<int>combin;
getallcombintion(candidates,target,0,ans,combin);
return ans;
    }
    
};
