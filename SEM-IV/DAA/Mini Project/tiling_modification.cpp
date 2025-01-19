#include<iostream>
#include<cmath>
#include<vector>
#include <time.h>



int matrix[16][16] = {{0},{0}};
int tilenumcell = 0;
int tileblock = 0;
int count = 0;
int colors[4] = {1,2,3,4};

class position{
    public:
    int x;
    int y;

    position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

position tiling(int x, int y, int n, int b1, int b2)
{
    // static int tilenum{0}; //tilenum will not be re-initialized when tiling is called recursively

    position pos(x, y);
    std::vector<position> posvector;
    if(n!=0)
    {
        int m = pow(2,n-1);
        if((b1>=(m)) && (b2<(m)))//Bill is in quadrant 1
        {   
            position pos2 = tiling(x, y, n-1, m - 1, m - 1);
            pos = tiling(x + m, y, n-1, b1 - m, b2);
            position pos3 = tiling(x, y + m, n-1, m - 1, 0);
            position pos4 = tiling(x + m, y + m, n-1, 0, 0);
            //position pos1 = tiling(x + m, y, n-1, m, m - 1);
            posvector.push_back(pos2);
            posvector.push_back(pos3);
            posvector.push_back(pos4);
            //posvector.push_back(pos);
        }else if((b1<(m)) && (b2<(m)))//Bill is in quadrant 2
        {
            //position pos2 = tiling(x, y, n-1, m - 1, m - 1);
            position pos4 = tiling(x + m, y + m, n-1, 0, 0);
            position pos3 = tiling(x, y + m, n-1, m - 1, 0);
            position pos1 = tiling(x + m, y, n-1, 0, m - 1);
            pos = tiling(x, y, n-1, b1, b2);
            posvector.push_back(pos3);
            posvector.push_back(pos4);
            posvector.push_back(pos1);
            //posvector.push_back(pos);
        }else if((b1<(m)) && (b2>=(m)))//Bill is in quadrant 3
        {
            position pos2 = tiling(x, y, n-1, m - 1, m - 1);
            position pos1 = tiling(x + m, y, n-1, 0, m - 1);
            pos = tiling(x, y + m, n-1, b1, b2-(m));
            position pos4 = tiling(x + m, y + m, n-1, 0, 0);
            //position pos3 = tiling(x, y + m, n-1, m - 1, m);
            posvector.push_back(pos2);
            posvector.push_back(pos4);
            posvector.push_back(pos1);
            //posvector.push_back(pos);
        }else if((b1>=(m)) && (b2>=(m)))
        {//Bill is in quadrant 4
            position pos2 = tiling(x, y, n-1, m - 1, m - 1);
            position pos3 = tiling(x, y + m, n-1, m - 1, 0);
            position pos1 = tiling(x + m, y, n-1, 0, m - 1);
            //position pos4 = tiling(x + m, y + m, n-1, m, m);
            pos = tiling(x + m, y + m, n-1, b1- m, b2 - m);
            posvector.push_back(pos2);
            posvector.push_back(pos3);
            posvector.push_back(pos1);
            //posvector.push_back(pos);
        }

        // tilenumcell
        if(count == 4){
            tileblock = (tileblock + 1) % 4;
        }
        count = (count + 1) % 5;
        for(int i=0; i<3; i++)
        {
            matrix[(posvector[i]).y][(posvector[i]).x] = colors[tilenumcell];
        }
        if(count != 2){
            tilenumcell = (tilenumcell + 1) % 4;
        }


    }

    return pos;

}

int main()
{
    position posBill = tiling(0, 0, 4, 2, 2);
    matrix[(posBill).y][(posBill).x] = 100;
 
    int n=8;
    for(int i=0; i<16; i++)
    {
        for(int j=0; j<16; j++)
        {
            std::cout<<matrix[i][j]<<'\t';
        }
        std::cout<<"\n\n\n";
    }

    // std::cout << "\n Time taken:" << timeinmicros << "us \n";


}
