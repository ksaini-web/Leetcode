class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int blank=0;
        int count  = 0;

        for(int i = 0;i<moves.length();i++){
     
         if(moves[i] == 'L' ){
            count++;
         }
        else if(moves[i] == 'R'){
        count--;
        }else{
           blank++; 
        }

     
        }
        return abs(count)+blank;
        
    }
};
