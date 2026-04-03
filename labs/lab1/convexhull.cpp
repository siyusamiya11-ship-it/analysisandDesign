#include<iostream>
#include<vector>
using namespace std;
struct point{
    long long x,y;
    bool operator<(const point& p)const{
        return x<p.x||(x==p.x&&y<p.y);
    }
};
int cross(Point A, Point B, Point C)
return(B.x-A.x)*(P.y-A.y)-(B.y-A.y)*(P.x-A.x);
vector <point> convexhull(vector<point>&pts){
int n=pts.size();
if(n<=1)return pts;
sort(pts.begin(),pts.end());
}

