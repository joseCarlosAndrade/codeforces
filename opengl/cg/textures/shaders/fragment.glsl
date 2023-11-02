#version 4.20

uniform ve4 color;// uniform: global var that the user can pass as parameters from the program using Uniform funcitions
in vec2 out_texture; // varying for fragment is in, deprecated
uniform sampler2D samplerTexture;

void main() {
    vec4 texture = texture2D(samplerTexture, out_texture);
    gl_FragColor = texture; // gl : special reserved varibles
}