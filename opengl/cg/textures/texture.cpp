
// extern "C" {
    #include<GL/glew.h>

    #define STBI_NO_FAILURE_STRINGS
    #define STB_IMAGE_IMPLEMENTATION
    // #include"include/stb_image.h"
    #include"include/stb_image.h"
// }
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>

// to read images
// #include<opencv2/opencv.hpp>
// #include<opencv2/core/core.hpp>
// #include<opencv2/highgui/highgui.hpp>
// #include<opencv2/imgcodecs.hpp>

#define WIDTH 1200
#define HEIGHT 1600

typedef struct face {
    std::vector<int> face;
    std::vector<int> face_texture;
    std::string material;
} Face;

typedef struct model {
    std::vector<float> vertices;
    std::vector<float> texture_coords;
    std::vector<Face> faces;
} Model;

GLuint shaders_handler();
std::string read_shader(std::string file_name, std::string * target_string);
Model read_wavefront_file(std::string file_name);
void load_texture_from_file(int texture_id, std::string file_name);
void draw_box();

int main() {

    // glfw window creation and configuration
    glfwInit();
    glfwWindowHint( GLFW_VISIBLE, GLFW_FALSE);
    GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "malhas e texturas", NULL, NULL);
    glfwMakeContextCurrent(window);

    GLint GlewInitResult = glewInit();
	printf("Status of Glew initialization: %s\n", glewGetErrorString(GlewInitResult));

    
    // // shaders handling
    std::cout << "shader handling" << std::endl;
    GLuint program = shaders_handler();

    std::cout << "nao sei oq ta rolando";
    glEnable(GL_TEXTURE_2D);
    int qt_textures = 10;
    GLuint textures;
    glGenTextures(qt_textures, &textures);

    // reading model
    std::cout << "reading";
    Model model = read_wavefront_file("caixa.obj");
    std::cout << "wavefront read." << std::endl;

    std::vector<float> vertices_list;
    std::vector<float> textures_coord_list;

    for (auto face : model.faces) {
        for (auto vertice_id : face.face) {
            vertices_list.push_back(model.vertices[vertice_id-1]);
        }

        for (auto texture_id : face.face_texture) {
            textures_coord_list.push_back(model.texture_coords[texture_id-1]);
        }
    }

    load_texture_from_file(0, "caixa2.jpg");


    GLuint buffer;
    glGenBuffers(2, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, vertices_list.size()*4, vertices_list.data(), GL_STATIC_DRAW);
    int stride = 3*4;
    GLuint loc_vertices = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(loc_vertices);
    glVertexAttribPointer(loc_vertices, 3, GL_FLOAT, false, stride, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, textures_coord_list.size()*4, textures_coord_list.data(), GL_STATIC_DRAW);
    stride = 3*4;
    GLuint loc_textures_coord = glGetAttribLocation(program, "texture_coord");
    glEnableVertexAttribArray(loc_vertices);
    glVertexAttribPointer(loc_textures_coord, 3, GL_FLOAT, false, stride, nullptr);


    glfwShowWindow(window);
    glEnable(GL_DEPTH_TEST);
    
    float mat[16] {
        1, 0, 0, 0,
        0, 1, 0 ,0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);

        GLuint mat_transform = glGetUniformLocation(program, "mat_transform");
        glUniformMatrix4fv(mat_transform, 1, GL_FALSE, mat);

        draw_box();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
}

void draw_box() {
    glBindTexture(GL_TEXTURE_2D, 0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void load_texture_from_file(int texture_id, std::string file_name) {
    glBindTexture(GL_TEXTURE_2D, texture_id);
    
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // cv::Mat image = cv::imread(file_name);

    // int width = image.cols;
    // int height = image.rows;
    int width, height, nr_channels;
    uint8_t *data = stbi_load(file_name.c_str(), &width, &height, &nr_channels, 0);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
}

// Reading shaders from file
std::string read_shader(std::string file_name, std::string * target_string) {
    std::cout << "read ....";
    std::cout <<"OPASFADSPFADS;";

    for ( int i = 0; i < 10; i++) {
        std::cout << "eita" << i << std::endl;
    }

    std::string line, sfinal = "";
    std::ifstream file(file_name);
    std::stringstream buffer;

    if (file.is_open()) {
        // while (file >> line) {
        //     // std::cout << "line: " << line <<std::endl;
        //     sfinal.append(line);
        // }
        
        buffer << file.rdbuf();
        sfinal = buffer.str();
        file.close();
    }
    else {
        std::cerr << "Unable to open file " << file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "final file: \n" << sfinal;
    *target_string = sfinal;
    return sfinal;
}

// Compiling, attaching and linking shaders
GLuint shaders_handler() {


    // const GLchar * vertex_code =
	// "attribute vec2 position;\n"
	// "void main()\n"
	// "{\n"
	// "	gl_Position = vec4(position, 0.0, 1.0);\n"
	// "}\n";
    std::cout << "startintritn" ;
    std::string vertex_code = ""; 
    read_shader("shaders/vertex.glsl", &vertex_code);
    std::cout << "read ....";
    std::string fragment_code = "";
    read_shader("shaders/fragment.glsl", &fragment_code);
    const GLchar * v_code = vertex_code.c_str();
    const GLchar * f_code = fragment_code.c_str();

    std::cout << "read ....";
	// const GLchar* fragment_code =
	// "uniform vec4 color;\n"
	// "void main() {\n"
	// "	gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);\n"
	// "}\n"; //rgba normalized

	// requiring gpu slots
    for (int i = 0; i < 10 ; i++) {
        std::cout <<"ja comílou" << i << std::endl;
        // std::cout << fragment_code << std::endl;
    } 
	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    

	// associating shader sources with glsl code
	glShaderSource(vertex, 1, &v_code, NULL);
	glShaderSource(fragment, 1, &f_code, NULL);

	glCompileShader(vertex); // compiling

	// error handling
	GLint isCompiled = 0;

    for (int i = 0; i < 10 ; i++) {
        std::cout <<"   aaaaAAAAAAAAAAAAAAAAAAA" << i << std::endl;
        // std::cout << fragment_code << std::endl;
    } 
                

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &isCompiled);
	if(isCompiled == GL_FALSE)
	{
		int infoLength = 512;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &infoLength);

		char info[infoLength];
		glGetShaderInfoLog(vertex, infoLength, NULL, info);

		std::cerr << "Error on vertex shader: " << info << std::endl;
	}
	glCompileShader(fragment);

    isCompiled = 0;
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE){

        //descobrindo o tamanho do log de erro
        int infoLength = 512;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &infoLength);

        //recuperando o log de erro e imprimindo na tela
        char info[infoLength];                                        
        glGetShaderInfoLog(fragment, infoLength, NULL, info);         
                                                                      
        std::cerr << "Error on Fragment Shader.\n" ;           
        std::cerr <<  info <<std::endl;                                     
                                                                      
    }    

    

	// associating the created programns to main code
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	// linking
	glLinkProgram(program);
	glUseProgram(program);

    return program;
}

std::vector<std::string> split_string(std::string s, char delimiter) {
    std::vector<std::string> s_v;

    std::stringstream iss(s);
    std::string word;

    while(!iss.eof()) {
        std::getline(iss, word, delimiter);
        s_v.push_back(word);
    }

    return s_v;
}

Model read_wavefront_file(std::string file_name) {
    Model model;

    std::ifstream file(file_name);
    std::string line;

    std::vector<float> vertices;
    std::vector<float> texture_coords;
    std::vector<Face> faces;

    std::string material;


    if (file.is_open()) {
        while (std::getline(file, line)) {

            std::stringstream iss(line);
            std::string part;
            // std::cout << line << "\n";
            while(iss >> part) {
                // std::cout << part <<"\n";

                if(!part.compare("#")) {
                    // std::cout << "breaking\n"; 
                    break; // quits line loop and goes to the next line
                }

                if(!part.compare("v")) {
                    for (int i = 0; i <3; i++) { // pushes back 3 float values to vertices
                        std::string v;
                        iss >> v;
                        // std::cout << "pushing vertice value: "<< v << std::endl;
                        vertices.push_back(std::atof(v.c_str()));
                    }
                }

                else if(!part.compare("vt")) {
                    for (int i = 0; i <3; i++) { // pushes back 3 float values to texture coords
                        std::string v;
                        iss >> v;
                        texture_coords.push_back(std::atof(v.c_str()));
                    }
                }
                else if (!part.compare("usemtl") || !part.compare("usemat")) {
                    iss >> material;
                }

                else if(!part.compare("f")) {
                    // f 5/1/1 1/2/1 4/3/1
                    Face face_it;
                    std::string v;
                    while(iss >>  v) { // v=5/1/1
                        std::vector<std::string> w= split_string(v, '/'); // w = {5, 1, 1}

                        face_it.face.push_back(std::atoi(w[0].c_str()));
                        
                        if (w.size() >=2 && w[1].length()>0) {
                            face_it.face_texture.push_back(std::atoi(w[1].c_str()));
                        }
                        else {
                            face_it.face_texture.push_back(0);
                        }
                    }

                    faces.push_back(face_it);
                }
            }

            
            model.vertices = vertices;
            model.texture_coords = texture_coords;
            model.faces = faces;


        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file " << file_name << std::endl;
        exit(EXIT_FAILURE);
    }


    return model;
}