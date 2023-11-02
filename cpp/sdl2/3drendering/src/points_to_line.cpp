#include"../include/screen.h"

int main() {
    Screen screen;

    
    // line on buffer 0
    Object line = Geometry::Line(-100, 100, 0, 100, 100, 0);
    line.setCenter(0, 100, 0);
    screen.addObjectToScene(&line, 0); 

    // cube on buffer 1
    Object cube = Geometry::Cube(100);
    screen.addObjectToScene(&cube, 1);
    screen.translate_points(0, 200, 0, cube);

    // torus on buffer 2
    Object torus = Geometry::Torus(150, 50);
    screen.addObjectToScene(&torus, 2);
    screen.translate_points(0,0,50, torus);

    // point cloud on buffer 5
    std::vector<float> pointCloud;
    for ( int i=0; i < 100; i++) {
        pointCloud.push_back(rand()%WIDTH-WIDTH/2);
        pointCloud.push_back(rand()%HEIGHT-HEIGHT/2);
        pointCloud.push_back(rand()%500 -250 );
    }
    Object pointcloud = Geometry::PointCloud(pointCloud);
    screen.addObjectToScene(&pointcloud, 5);


    while(1) {
        screen.input();


        /* LINE */
        // centralized operations (rotating around its own center, even if the object is not centralized)
            screen.centralize(line);
            screen.rotate_points_z(0.1, line);
            screen.back_to_last_position(line);

            // rotate around world center
            screen.rotate_points_z(0.01, 0);

        /* CUBE */
            screen.centralize(cube);
            screen.rotate_points_z(0.04, cube); // NEEDED: so the world rotation doesnt flip the cube

            screen.rotate_points_y(0.08, cube);
            screen.rotate_points_x(0.08, cube);
            screen.rotate_points_z(0.08, cube);
            
            screen.back_to_last_position(cube); 

            screen.rotate_points_z(-0.04, cube);

        /* TORUS */
            screen.centralize(torus);
                screen.rotate_points_x(0.05, torus);
                screen.rotate_points_y(0.05, torus);
                screen.rotate_points_z(0.05, torus);
            screen.back_to_last_position(torus);
            // screen.translate_points(0, 0, 5, torus);

        /* POINT CLOUD */
            screen.rotate_points_x(0.05, pointcloud);

        screen.show();
        screen.sleep_rate(30);

    }   
}