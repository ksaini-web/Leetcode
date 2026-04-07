class Robot {
public:
int w,h;
int x, y;
int dir;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

vector<string> dirs = {"East","North","West","South"};

int perimeter ;



    Robot(int width, int height) {

        w=width;
        h=height;

        x = 0;
        y=0;
        dir =0;

        perimeter = 2*(w+h)-4;
        
    }
    
    void step(int num) {
        num = num%perimeter;

        if(num == 0 && x == 0 && y == 0){
            dir=3;
            return ;
        }

        while(num--){

            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if(nx<0 || nx>=w || ny <0 || ny>= h){
                dir = (dir+1)%4;

                nx = x+dx[dir];
                ny = y+dy[dir];
            }
            x=nx;
            y=ny;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
        
    }
    
    string getDir() {
        return dirs[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
