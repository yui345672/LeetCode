class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // 用Shoelace公式来计算三角形面积
        double marea=0.0;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                for(int k=j+1; k<points.size(); k++){
                    double x1=points[i][0], x2=points[j][0], x3=points[k][0];
                    double y1=points[i][1], y2=points[j][1], y3=points[k][1];
                    double area=calArea(x1,x2,x3,y1,y2,y3);
                    marea=max(marea, area);
                }
            }
        }
        return marea;
    }
    double calArea(double x1, double x2, double x3, double y1, double y2, double y3){
        return 0.5*fabs(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 -x1*y3);
    }
};