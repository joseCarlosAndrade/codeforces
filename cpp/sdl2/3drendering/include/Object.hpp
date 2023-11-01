#ifndef OBJECT_H
#define OBJECT_H

#include<iostream>
#include<vector>

typedef struct _3dPoint {
    float x;
    float y;
    float z;
} F3DPoint;


class Object {
    private:
        std::vector<F3DPoint> points;
        F3DPoint center;

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

    F3DPoint getCenter() {
        return center;
    }

};

/* its possible to inherit this class to make your own object and implement its specific funcionalities */

#endif