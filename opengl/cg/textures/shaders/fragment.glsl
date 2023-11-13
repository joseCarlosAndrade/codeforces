#version 420

uniform vec4 color;// uniform: global var that the user can pass as parameters from the program using Uniform funcitions
in vec2 out_texture; // varying for fragment is in, deprecated
uniform sampler2D samplerTexture;
// out vec4 fragColor;

void main() {
    vec4 texture = texture(samplerTexture, out_texture);
    gl_FragColor = texture; // gl : special reserved varibles
}