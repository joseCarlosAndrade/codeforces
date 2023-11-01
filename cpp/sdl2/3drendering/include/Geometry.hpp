#ifndef GEOMETRY_H
#define GEOMETRY_H

#include"Object.hpp"
#include<iostream>
#include<cmath>

namespace Geometry {
    /* # Basic geometric shape generation functions. They are shared among the geometry objects down below. */

    /* Appends a line to the vector passed as argument. Note: It does not clear the element, so if you intend 
    that, just call the clear() method from the Object */
    void create_line(float x1, float y1, float z1, float x2, float y2, float z2, std::vector<F3DPoint>& vec) {
        float dx = x2 - x1;
        float dy = y2 - y1;
        float dz = z2 - z1;

        float length = std::sqrt(dx*dx + dy*dy + dz*dz);

        float vector[3] = {(x2-x1)/length, (y2-y1)/length, (z2-z1)/length };

        // std::vector<F3DPoint> points;

        for (float i = 0; i < length ; i++) {
            F3DPoint point = {x1 + vector[0]*i, y1 + vector[1]*i, z1 + vector[2]*i};
            // pixel(x1 + vector[0]*i, y1 + vector[1]*i, z1 + vector[2]*i, current_buffer);
            vec.push_back(point);
            
        }

        // return points;
    }

    void create_cube(int arest_size, std::vector<F3DPoint> &vec) {
            // creating a cube
            int vertice = arest_size/2;

            // cube creating routine
            create_line(-vertice, -vertice, -vertice, vertice, -vertice, -vertice, vec);
            create_line(vertice, -vertice, -vertice, vertice, vertice, -vertice, vec);
            create_line(vertice, vertice, -vertice, -vertice, vertice, -vertice, vec);
            create_line(-vertice, vertice, -vertice, -vertice, -vertice, -vertice, vec);

            create_line(vertice, vertice, vertice, vertice, vertice, -vertice, vec);
            create_line(-vertice, vertice, vertice, -vertice, vertice, -vertice, vec);
            create_line(-vertice, -vertice, vertice, -vertice, -vertice, -vertice, vec);
            create_line(vertice, -vertice, vertice, vertice, -vertice, -vertice, vec);

            create_line(-vertice, -vertice, vertice, vertice, -vertice, vertice, vec);
            create_line(vertice, -vertice, vertice, vertice, vertice, vertice, vec);
            create_line(vertice, vertice, vertice, -vertice, vertice, vertice, vec);
            create_line(-vertice, vertice, vertice, -vertice, -vertice, vertice, vec);

            
        }

    /* ## Line Object */
    class Line : public Object {
        public:
            /* Creates a Line object from the specified parameters. By default, its center is the first point passed
            as argument. It's possible to change that using Object::setCenter(x, y, z). */
            Line(float x1, float y1, float z1, float x2, float y2, float z2) {
                create_line(x1, y1,z1, x2,y2,z2, getPoints());
                setCenter(x1, y1, z1);
            }
    };

    class Square : public Object {

    };

    class Cube : public Object {
        /* Creates a Cube object from the specified arest parameter. By default, the cube is centered on (0, 0, 0). */
        Cube(float arest) {
            create_cube(arest, getPoints());
            setCenter(0,0, 0);
        }
    };

    class Circle : public Object {

    };

    class Torus : public Object {

    };

}
#endif