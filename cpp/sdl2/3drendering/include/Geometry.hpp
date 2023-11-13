#ifndef GEOMETRY_H
#define GEOMETRY_H

#include"Object.hpp"
#include"Matrices.hpp"
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

    /* Cube creation routine */
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

    /* Torus creation routine */
    void create_torus (float t_radius, int c_radius, std::vector<F3DPoint> &vec) {
        // int t_radius = 100;
        // int c_radius = 50;

        for ( float phi = 0 ; phi < 2*3.1415; phi+=3.1415/50) {
            
            MatrixRotationY rotation_y(phi);
            
            for ( float i = 0; i < 2*3.14159; i+=3.14159/100) {
                
                // creating first circle
                float xf =t_radius + c_radius*std::cos(i);
                float yf = c_radius*std::sin(i);
                float zf = 0;

                // rotating it arround y axis
                GenMatrix4x4f p(xf, yf,zf);
                p = rotation_y * p;

                // pixel(p(0,0),  p(1,0), p(2,0), buffer);
                vec.push_back({p(0,0),  p(1,0), p(2,0)});
            }
        }
        

    }

    /* ## Simple point cloud */
    class PointCloud : public Object {
        public:
            /* Creates a point cloud from a raw sequence of coodinates on an unidimensional vector on the format:
            {x1, y1, z1, x2, y2, z2, ... , xn, yn, zn} */
            PointCloud(std::vector<float> points) {
                if (points.size()%3) {
                    std::cerr << "Error: passing not divisible by 3 data on point vector: Creationg of point cloud\n";
                }
                int n_points = points.size()/3;

                float xc = 0;
                float yc = 0;
                float zc = 0;

                for ( int i = 0 ; i < n_points; i ++) {
                    F3DPoint p = { points[3*i], points[3*i + 1], points[ 3*i + 2]};
                    getPoints().push_back(p);
                    xc += p.x;
                    yc += p.y;
                    zc += p.z;
                }

                setCenter(xc/n_points, yc/n_points, zc/n_points);

            }

            /* Creates a point cloud from a raw sequence of coodinates on an unidimensional `n_points` size array on the format:
            {x1, y1, z1, x2, y2, z2, ... , xn, yn, zn} */
            PointCloud(float points[], int n_points) {
                float xc = 0;
                float yc = 0;
                float zc = 0;

                for ( int i = 0 ; i < n_points; i ++) {
                    F3DPoint p = { points[3*i], points[3*i + 1], points[ 3*i + 2]};
                    getPoints().push_back(p);
                    xc += p.x;
                    yc += p.y;
                    zc += p.z;
                }

                setCenter(xc/n_points, yc/n_points, zc/n_points);
            }

            /* Creates a point cloud from a point vector in the format:
            {{x1, y1, z1}, {x2, y2, z2}, ... , {xn, yn, zn}} */
            PointCloud(std::vector<F3DPoint> points) {
                float xc = 0;
                float yc = 0;
                float zc = 0;
                int n_points = points.size();

                for ( int i = 0 ; i < n_points; i ++) {
                    
                    getPoints().push_back(points[i]);
                    xc += points[i].x;
                    yc += points[i].y;
                    zc += points[i].z;
                }

                setCenter(xc/n_points, yc/n_points, zc/n_points);
            }
    };

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
        public:
            /* Creates a Cube object from the specified arest parameter. By default, the cube is centered on (0, 0, 0). */
            Cube(float arest) {
                create_cube(arest, getPoints());
                setCenter(0,0, 0);
            }
    };

    class Circle : public Object {

    };

    class Torus : public Object {
        public:
            /* Creates a Torus object centralized at the world origin with `torus_radius` and `circle_radius` parameters. */
            Torus(float torus_radius, float circle_radius) {
                create_torus(torus_radius, circle_radius, getPoints());
                setCenter(0,0, 0);
            }
    };

}
#endif