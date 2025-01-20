#include"screen.h"
#include"Geometry.hpp"

#define BODY_HEIGHT 170
#define BODY_RADIUS 70
#define ARM_LENGTH 90
#define ARM_RADIUS 10
#define LEG_LENGTH 50
#define LEG_RADIUS 15
#define LEG_DISTANCE 50
#define HAND_RADIUS 15
#define EYE_RADIUS 20

#define MINION_BUFFER 0X00

int main() {

    Screen screen;

    // body
    Object body = Geometry::Cilinder(BODY_RADIUS, BODY_HEIGHT, false);
    screen.addObjectToScene(&body, MINION_BUFFER);
    screen.rotate_points_x(PI/2, body);

    // lower body
    Object body_lower = Geometry::Circle(0, 0, BODY_RADIUS, true);
    screen.addObjectToScene(&body_lower, MINION_BUFFER);
    screen.rotate_points_x(PI/2, body_lower);
    screen.translate_points(0, -BODY_HEIGHT/2, 0, body_lower);

    // head
    Object head = Geometry::Sphere(BODY_RADIUS, true);
    screen.addObjectToScene(&head, MINION_BUFFER);
    screen.rotate_points_x(-PI/2, head);
    screen.translate_points(0, BODY_HEIGHT/2, 0, head);

    // arms
    Object right_arm = Geometry::Cilinder(ARM_RADIUS, ARM_LENGTH, false);
    Object left_arm = Geometry::Cilinder(ARM_RADIUS, ARM_LENGTH, false);
    screen.addObjectToScene(&right_arm, MINION_BUFFER);
    screen.addObjectToScene(&left_arm, MINION_BUFFER);

    screen.rotate_points_y(PI/2, right_arm);
    screen.rotate_points_y(PI/2, left_arm);

    screen.translate_points(BODY_RADIUS+ARM_LENGTH/2, 0, 0, left_arm);
    screen.translate_points(-BODY_RADIUS-ARM_LENGTH/2, 0, 0, right_arm);

    // hands
    Object right_hand = Geometry::Sphere(HAND_RADIUS);
    Object left_hand = Geometry::Sphere(HAND_RADIUS);
    screen.addObjectToScene(&right_hand, MINION_BUFFER);
    screen.addObjectToScene(&left_hand, MINION_BUFFER);
    
    screen.translate_points(BODY_RADIUS+ARM_LENGTH, 0, 0, left_hand);
    screen.translate_points(-BODY_RADIUS-ARM_LENGTH, 0, 0, right_hand);

    // eyes
    Object eye = Geometry::Sphere(2*EYE_RADIUS, true);
    screen.addObjectToScene(&eye, MINION_BUFFER);

    screen.translate_points(0, BODY_HEIGHT/2, BODY_RADIUS+5, eye);

    Object int_eye = Geometry::Sphere(2*(EYE_RADIUS-10), true);
    screen.addObjectToScene(&int_eye, MINION_BUFFER);
    screen.rotate_points_x(PI, int_eye);
    screen.translate_points(0, BODY_HEIGHT/2, BODY_RADIUS, int_eye);

    // legs
    Object left_leg = Geometry::Cilinder(LEG_RADIUS, LEG_LENGTH, false);
    Object right_leg = Geometry::Cilinder(LEG_RADIUS, LEG_LENGTH, false);
    screen.addObjectToScene(&right_leg, MINION_BUFFER);
    screen.addObjectToScene(&left_leg, MINION_BUFFER);

    screen.rotate_points_x(PI/2, right_leg);
    screen.rotate_points_x(PI/2, left_leg);

    screen.translate_points(LEG_DISTANCE/2, -BODY_HEIGHT/2-LEG_LENGTH/2,0, left_leg);
    screen.translate_points(-LEG_DISTANCE/2, -BODY_HEIGHT/2-LEG_LENGTH/2,0, right_leg);

    // foot
    Object left_foot = Geometry::Sphere(LEG_RADIUS+5);
    Object right_foot = Geometry::Sphere(LEG_RADIUS+5);
    screen.addObjectToScene(&left_foot, MINION_BUFFER);
    screen.addObjectToScene(&right_foot, MINION_BUFFER);

    screen.rotate_points_x(PI, left_foot);
    screen.rotate_points_x(PI, right_foot);

    screen.translate_points(LEG_DISTANCE/2, -BODY_HEIGHT/2-LEG_LENGTH , 0, left_foot);
    screen.translate_points(-LEG_DISTANCE/2, -BODY_HEIGHT/2-LEG_LENGTH , 0, right_foot);




    for (;;) {
        screen.input();

        screen.rotate_points_y(0.05, MINION_BUFFER);

        screen.show();
        screen.sleep_rate(30);
    }
}