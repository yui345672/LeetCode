class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // 用海伦公式来计算三角形面积
        double marea=0.0;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                for(int k=j+1; k<points.size(); k++){
                    double x1=points[i][0], x2=points[j][0], x3=points[k][0];
                    double y1=points[i][1], y2=points[j][1], y3=points[k][1];
                    double a1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                    double a2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
                    double a3=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
                    double halfparam=(a1+a2+a3)/2.0;
                    double area=sqrt(halfparam*(halfparam-a1)*(halfparam-a2)*(halfparam-a3));
                    marea=max(marea, area);
                }
            }
        }
        return marea;
    }
};