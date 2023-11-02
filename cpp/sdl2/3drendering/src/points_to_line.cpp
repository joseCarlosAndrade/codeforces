#include"../include/screen.h"

int main() {
    Screen screen;

    // point cloud on buffer 3
    for ( int i=0; i < 100; i++) {
        screen.pixel(rand()%WIDTH-WIDTH/2, rand()%HEIGHT-HEIGHT/2, rand()%150 -75 , 3);
    }

    // drawing a cube on buffer 3
    // screen.cube(WIDTH/2, 3);
    screen.rotate_points_y(0.2, 3);
    screen.rotate_points_x(0.4, 3);

    // circles on buffer 2 and 1
    screen.circle(100, 30, 100, 2);
    screen.circle(200, 40, 100, 1);

    // torus on buffer 0
    screen.torus(0);

    // change the system::

    // dont change the points in translation, but always leave them as  0.0.0

    // new tests:
    // Geometry::Line line(0, 0, 0, 100, 100, 0);
    Object line = Geometry::Line(-100, 100, 0, 100, 100, 0);
    line.setCenter(0, 100, 0);
    screen.addObjectToScene(&line, 0); // adding the line object to the scene on object buffer map 0
    // screen.rotate_points_x(line, 0.01);

    // Object line2 = Geometry::Line(-100, -100, 0, -100, 100, 0);
    // screen.addObjectToScene(&line2, 0);

    Object cube = Geometry::Cube(100);
    screen.addObjectToScene(&cube, 1);
    screen.translate_points(0, 200, 0, cube);


    while(1) {
        screen.input();

        // screen.translate_points(0, 0, -3, 0);
        // screen.rotate_points_y(0.01);

        // rotating cube
        // screen.rotate_points_y(0.02, 3);
        // screen.rotate_points_x(0.02, 3);

        //rotating circles
        // screen.rotate_points_x(0.01, 2);
        // screen.rotate_points_y(0.05, 1);
        // screen.rotate_points_z(0.05, 1);
        // screen.rotate_points_z(0.01, 2);
        // screen.translate_points(+WIDTH/2, +HEIGHT/2);


        // rotating torus
        /*a*/
        // screen.rotate_points_x(0.03, 0);
        // screen.rotate_points_y(0.05, 0);
        // screen.rotate_points_z(0.02, 0);


        // rotating objects
        // screen.rotate_points_x(0.01, line);
        // screen.rotate_points_y(line, 0.06);
        // screen.rotate_points_z(line, 0.06);
        // screen.rotate_points_y(0.05, 8);
        // screen.rotate_points_x(0.1);

        // screen.translate_points(0.5, -1, 0, line);
        // screen.translate_points(1, 1, 0);

        // centralized operations (rotating around its own center, even if the object is not centralized)
        screen.centralize(line);
        screen.rotate_points_z(0.1, line);
        screen.back_to_last_position(line);

        // rotate around world center
        screen.rotate_points_z(0.01, 0);

        // rotating cube
        screen.centralize(cube);
        screen.rotate_points_z(0.04, cube);
        screen.back_to_last_position(cube);
        screen.rotate_points_z(-0.04, cube);

        screen.show();
        screen.sleep_rate(30);

    }   
}