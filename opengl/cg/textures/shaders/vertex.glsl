#version 4.20

in vec3 position; // attribute is deprecated
in vec2 texture_coord; // texel coordinate
out vec2 out_texture; // varying is deprecated

uniform mat4 mat_transform; // matrix that will handle geometric transformations

void main() {
    gl_Position = mat_transform * vec4(position, 1.0); // vertice position (homogeneous)
    // gl : special reserved varibles

    out_texture = vec2(texture_coord);
}  

