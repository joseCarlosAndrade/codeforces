#ifndef SCREEN_H
#define SCREEN_H

#include<SDL2/SDL.h>
#include<vector>
#include<map>
#include<numeric>

#include"Matrices.hpp"

#define WIDTH 640
#define HEIGHT 480
#define RESOLUTION_SCALE 1

typedef struct _3dPoint {
    float x;
    float y;
    float z;
} F3DPoint;

class Screen {
    private:
        SDL_Event e;
        SDL_Window *window;
        SDL_Renderer * renderer;
        // std::vector<F3DPoint> points; // vector thar stores everypoint to be drawn

        std::map<int, std::vector<F3DPoint>> point_map;

        int rate;

        std::string window_title;

        int current_buffer;

        MatrixRotationX _rotation_matrix_x;
        MatrixRotationY _rotation_matrix_y;
        MatrixRotationZ _rotation_matrix_z;

        MatrixTranslation _translation_matrix;

        MatrixScale _scale_matrix;

    public:
        Screen() {
            SDL_Init(SDL_INIT_VIDEO);
            SDL_CreateWindowAndRenderer(WIDTH*RESOLUTION_SCALE, HEIGHT*RESOLUTION_SCALE, 0, &window, &renderer);
            SDL_RenderSetScale(renderer, RESOLUTION_SCALE, RESOLUTION_SCALE);
            window_title = "desenho!";
            SDL_SetWindowTitle(window, window_title.c_str());

            // main point list

            current_buffer = 0;

            _rotation_matrix_x.rot(0);
            _rotation_matrix_y.rot(0);
            _rotation_matrix_z.rot(0);

            _translation_matrix.x(0);
            _translation_matrix.y(0);
            _translation_matrix.z(0);

            _scale_matrix.x(1);
            _scale_matrix.y(1);
            _scale_matrix.z(1);
        }
        /* Handles input events. */
        void input() {
            while(SDL_PollEvent(&e)) {

                // handles exit function
                if(e.type == SDL_QUIT) {
                    SDL_Quit();
                    exit(EXIT_SUCCESS);
                }
            }
        }

        /* Actually renders everything.*/
        void show() {
            /* Correlating the coordinate system so that it gets easier to rotate them 
            
            ""
                          ^y
                        (0,0) ->x
            
                                           ""
            
            to:

            ""
                (0,0)->x
                  V y

                                            ""
            
            X = X'+WIDTH/2
            Y = -Y'+HEIGHT/2
            */
            // x = x + WIDTH/2;
            // y = -y + HEIGHT/2;

            SDL_SetRenderDrawColor(renderer, 0, 0 ,0, 255); // draw color: black, to clean the screen
            SDL_RenderClear(renderer);
            // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white, drawing pixels
            
            for ( auto& cpoints : point_map) {

                for (auto &point : cpoints.second) {
                    if(point.x < -WIDTH/2 || point.x > WIDTH/2 || point.y < -HEIGHT/2 || point.y > HEIGHT/2) continue; 
                   
                    int depth = (uint)255-(point.z);
                    if (depth < 0) depth = 0;

                    else if(depth >255) depth = 255;

                    SDL_SetRenderDrawColor(renderer, depth, depth, depth, 255);
                    // std::cout<< (uint)255-point.z << " " ;
                    SDL_RenderDrawPointF(renderer, point.x+WIDTH/2, -point.y+HEIGHT/2);
                }
                

            }
            SDL_RenderPresent(renderer); // actually draws
        }

        /* Appends to the point list the pixel coordinates (on the range of WIDTH and HEIGHT).*/
        void pixel(float x, float y, float z=0, int buffer=0) {
            

            F3DPoint point = {x,y,z};
            point_map[buffer].emplace_back(point);

        }

        /* Erase points list. */
        void clear_points() {
            for (auto& points : point_map) {
                points.second.clear();
            }
            
        }

        /* Get the line properties from 2 points (start and end)*/
        void line(float x1, float y1, float z1, float x2, float y2, float z2) {
            float dx = x2 - x1;
            float dy = y2 - y1;
            float dz = z2 - z1;

            float length = std::sqrt(dx*dx + dy*dy + dz*dz);

            // float angle = std::atan2(dy, dx); // getting the line angle
            // float angle2 = std::atan2(dy, dz); // getting the line angle

            // (z1+ ((z2-z1)/length) *i )
            // for ( float i = 0; i < length; i++) {
            //     pixel( x1 + std::cos(angle)*i , y1 + std::sin(angle)*i, z1+std::cos(angle2)*i);
            // }   
            // float dt = length;
            float vector[3] = {(x2-x1)/length, (y2-y1)/length, (z2-z1)/length };
            // while (dt > 0.01) {
                // 
            // }

            for (float i = 0; i < length ; i++) {
                pixel(x1 + vector[0]*i, y1 + vector[1]*i, z1 + vector[2]*i, current_buffer);
            }

        }

        void rotate_points_x(float angle, int buffer =-1) {
            
            _rotation_matrix_x.rot(angle);

            if (buffer < 0) {
                for ( auto & points : point_map) {

                    for (auto &point : points.second ) {
                        GenMatrix4x4f pt(point.x, point.y, point.z);
                        pt = _rotation_matrix_x * pt;
                        point.x = pt(0, 0);
                        point.y = pt(1, 0);
                        point.z = pt(2, 0);

                    }    
                }
            }

            else {
                for (auto &point : point_map[buffer] ) {
                    GenMatrix4x4f pt(point.x, point.y, point.z);
                    pt = _rotation_matrix_x * pt;
                    point.x = pt(0, 0);
                    point.y = pt(1, 0);
                    point.z = pt(2, 0);

                }    
            }
            
        }

        void rotate_points_y(float angle, int buffer=-1) {

            _rotation_matrix_y.rot(angle);

            if (buffer < 0) {
                for ( auto & points : point_map) {

                    for (auto &point : points.second ) {
                        GenMatrix4x4f pt(point.x, point.y, point.z);
                        pt = _rotation_matrix_y * pt;
                        point.x = pt(0, 0);
                        point.y = pt(1, 0);
                        point.z = pt(2, 0);

                    }    
                }
            }

            else {
                for (auto &point : point_map[buffer] ) {
                    GenMatrix4x4f pt(point.x, point.y, point.z);
                    pt = _rotation_matrix_y * pt;
                    point.x = pt(0, 0);
                    point.y = pt(1, 0);
                    point.z = pt(2, 0);

                }    
            }
        }

        void rotate_points_z(float angle, int buffer=-1) {

            _rotation_matrix_z.rot(angle);

            if (buffer < 0) {
                for ( auto & points : point_map) {

                    for (auto &point : points.second ) {
                        GenMatrix4x4f pt(point.x, point.y, point.z);
                        pt = _rotation_matrix_z * pt;
                        point.x = pt(0, 0);
                        point.y = pt(1, 0);
                        point.z = pt(2, 0);

                    }    
                }
            }

            else {
                for (auto &point : point_map[buffer] ) {
                    GenMatrix4x4f pt(point.x, point.y, point.z);
                    pt = _rotation_matrix_z * pt;
                    point.x = pt(0, 0);
                    point.y = pt(1, 0);
                    point.z = pt(2, 0);

                }    
            }
        }

        void translate_points(float tx, float ty, float tz, int buffer= -1) {
            /*
            1 0 tx
            0 1 ty
            0 0 1
            */
            _translation_matrix.x(tx);
            _translation_matrix.y(ty);
            _translation_matrix.z(tz);
            
            if (buffer < 0) {       
                for ( auto & points : point_map) {
                    for (auto &point : points.second ) {
                        GenMatrix4x4f pt(point.x, point.y, point.z);

                        pt = _translation_matrix * pt;
                        point.x = pt(0, 0);
                        point.y = pt(1, 0);
                        point.z = pt(2, 0);

                    }        
                }   
            }
            else {
                for (auto &point : point_map[buffer] ) {
                        GenMatrix4x4f pt(point.x, point.y, point.z);

                        pt = _translation_matrix * pt;
                        point.x = pt(0, 0);
                        point.y = pt(1, 0);
                        point.z = pt(2, 0);


                    } 
            }
        }

        void sleep_rate(int r = -1) {
            if (r > 0) SDL_Delay(1000/r);

            else SDL_Delay(1000);
        }

        void cube(int arest_size, int buffer = 0) {
            // creating a cube
            int vertice = arest_size/2;

            current_buffer = buffer;

            // front face
            line(-vertice, -vertice, -vertice, vertice, -vertice, -vertice);
            line(vertice, -vertice, -vertice, vertice, vertice, -vertice);
            line(vertice, vertice, -vertice, -vertice, vertice, -vertice);
            line(-vertice, vertice, -vertice, -vertice, -vertice, -vertice);

            // back face
            // screen.line(-vertice, -vertice, vertice, vertice, -vertice, -vertice);
            // screen.line(vertice, -vertice, vertice, vertice, vertice, -vertice);
            // screen.line(vertice, vertice, vertice, -vertice, vertice, -vertice);
            // screen.line(-vertice, vertice, vertice, -vertice, -vertice, -vertice);
            
            line(vertice, vertice, vertice, vertice, vertice, -vertice);
            line(-vertice, vertice, vertice, -vertice, vertice, -vertice);
            line(-vertice, -vertice, vertice, -vertice, -vertice, -vertice);
            line(vertice, -vertice, vertice, vertice, -vertice, -vertice);

            line(-vertice, -vertice, vertice, vertice, -vertice, vertice);
            line(vertice, -vertice, vertice, vertice, vertice, vertice);
            line(vertice, vertice, vertice, -vertice, vertice, vertice);
            line(-vertice, vertice, vertice, -vertice, -vertice, vertice);

            current_buffer = 0;
        }

        void circle( int xo , int yo , int radius, int buffer) {
            
 
            for ( float i = 0; i < 2*3.14159; i+=3.14159/360) {
                pixel(xo + radius*std::cos(i), yo + radius*std::sin(i), 0, buffer);
            }
        }

        void torus (int buffer =0) {
            int t_radius = 100;
            int c_radius = 50;

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

                    pixel(p(0,0),  p(1,0), p(2,0), buffer);
                }
            }
            

        }
};

#endif