#ifndef OBJECT_H
#define OBJECT_H

#include<iostream>
#include<vector>
#include<stack>

typedef struct _3dPoint {
    float x;
    float y;
    float z;
} F3DPoint;


class Object {
    private:
        std::vector<F3DPoint> points;
        F3DPoint center;
        // float lastx, lasty, lastz;
        std::stack<F3DPoint> point_stack;

    public:
        Object() {}
    
    std::vector<F3DPoint>& getPoints() {
        return points;
    }

    void clearPoints() {
        points.clear();
    }

    void setCenter(float x, float y, float z) {
        center.x = x;
        center.y = y;
        center.z = z;
    }

    F3DPoint& getCenter() {
        return center;
    }

    void pushPosition(F3DPoint point) {
        point_stack.push(point);
    }

    F3DPoint popPosition() {
        F3DPoint point = point_stack.top();
        point_stack.pop();

        return point;
    }

};

/* its possible to inherit this class to make your own object and implement its specific funcionalities */

#endif