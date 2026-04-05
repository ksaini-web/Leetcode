class Solution {
public:
    bool judgeCircle(string moves) {
       
         int x = 0;
         int y = 0;
        for(auto ch : moves){
          
          if( ch == 'R'){
            x++;
          }
          else if(ch == 'L'){
            x--;
          }
           else if(ch=='U'){
            y--;
           }
           else{
            y++;
           }

        
         

        }
           return x==0 && y==0;
        
    }
};
