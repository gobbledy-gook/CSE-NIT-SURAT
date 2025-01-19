//Solving the skyline question using an iterative method
#include<iostream>
#include<vector>
#include <algorithm>

class point{
    public:
    int x;
    int y;

    bool operator>(point pt)
    {
        int result = false;

        if(this->x > pt.x)
        {
            return true;
        }else if(this->x == pt.x)
        {
            if(this->y > pt.y)
            {
                return true;
            }
        }
        
        return result;
    }

    bool operator<(point pt)
    {
        int result = false;

        if(this->x < pt.x)
        {
            return true;
        }else if(this->x == pt.x)
        {
            if(this->y < pt.y)
            {
                return true;
            }
        }
        
        return result;
    }

    bool operator==(point pt)
    {
        int result = 0;

        if((this->x == pt.x)&&(this->y == pt.y))
        {
            return true;
        }
        
        return result;
    }

    void operator =(point pt)
    {
        this->x = pt.x;
        this->y = pt.y;
    }
};

void insertion_sort(std::vector<std::vector<int>> &b, std::vector<point> &p)
{
    point temp;
    for(int i=0; i<b.size(); i++)
    {
        temp.x = b[i][0];
        temp.y = b[i][2];
        p.push_back(temp);
        temp.x = b[i][1];
        temp.y = 0;
        p.push_back(temp);
    }

    //now we have a vector of points
    //need to sort that vector

    //insertion sort:
    for(int i=1; i<p.size(); i++)
    {
        temp = p[i];
        int j;
        for(j=i-1; j >= 0; j--)
        {
            if(p[j]>temp)
            {
                p[j+1] = p[j];
            }else{
                break;
            }
        }
        p[j+1] = temp;
    }
}

int main()
{
    std::vector<std::vector<int>> buildings = {{33, 41, 5},{4, 9, 21},{30, 36, 9},{14, 18, 11},{2, 12, 14},{34, 43, 19},{23, 25, 8},{14, 21, 16},{32, 37, 12},{7, 16, 7},{24, 27, 10}}; //array of buildings

    for(int i = 1; i<buildings.size(); i++){
        for(int j = i-1; j >= 0; j--){
            if(buildings[j][2] < buildings[j+1][2]){
                swap(buildings[j], buildings[j+1]);
            }
        }
    }

    for(int i{0}; i<buildings.size(); i++)
    {
        for(int j = i+1; j<buildings.size(); j++)
        {
            if(buildings[i][2] > buildings[j][2])
            {
                if((buildings[j][0] > buildings[i][0])&&(buildings[j][1] < buildings[i][1])) //if j is covered by i
                {
                    buildings.erase(buildings.begin() + j); //erase j from the away
                }
                // RHS Cutting
                else if((buildings[j][0] > buildings[i][0])&&(buildings[j][0] < buildings[i][1])&&(buildings[j][1] > buildings[i][1]))
                {
                    buildings[j][0] = buildings[i][1];
                }
                // LHS Cutting
                else if((buildings[j][0] < buildings[i][0])&&(buildings[j][1] < buildings[i][1])&&(buildings[j][1] > buildings[i][0]))
                {
                    buildings[j][1] = buildings[i][0];
                }
                // Inverted T
                else if((buildings[j][0] < buildings[i][0])&&(buildings[j][1] > buildings[i][1]))
                {
                    buildings[j][1] = buildings[i][0];
                    buildings.insert(buildings.end(), {buildings[i][1], buildings[j][1], buildings[j][2]});
                }
            }
            else if(buildings[i][2] == buildings[j][2]){
                // Overlap
                if(buildings[i][0] <= buildings[j][0] && buildings[i][1] > buildings[j][0] && buildings[i][1] >= buildings[j][1]){
                    buildings.erase(buildings.begin() + j);
                }
                // RHS Outing
                else if(buildings[i][0] <= buildings[j][0] && buildings[i][1] > buildings[j][0] && buildings[i][1] < buildings[j][1]){
                    buildings[i][1] = buildings[j][1];
                    buildings.erase(buildings.begin() + j);
                }
                // LHS Outing
                else if(buildings[i][0] > buildings[j][0] && buildings[i][1] > buildings[j][0] && buildings[i][1] > buildings[j][1]){
                    buildings[i][0] = buildings[j][0];
                    buildings.erase(buildings.begin() + j);
                }
                else if(buildings[i][0] > buildings[j][0] && buildings[i][1] < buildings[j][1]){
                    buildings[i][0] = buildings[j][0];
                    buildings[i][1] = buildings[j][1];
                    buildings.erase(buildings.begin() + j);
                }
            }
        }
    }
    std::vector<point> points;
    insertion_sort(buildings, points);

    for(int i=0; i<points.size(); i++)
    {
        if(points[i+1].x != points[i].x)
        {
            if((i==0)|| !((points[i-1].x==points[i].x)&&(points[i-1].y == points[i].y)))
            {
                std::cout<<"("<<points[i].x<<", "<<points[i].y<<")"<<"\n";
            }
        }
    }

}