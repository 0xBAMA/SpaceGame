#include "../includes.h"

// this class is in charge of rendering opengl geometry associated with the UI
class UI_class
{
public:
    // generates the geometry for the box and arrow indicators, compiles shaders
    void init();
    
    // light grey box surrounding visible area
    // function
    void draw_box();
    // GPU values
    GLuint box_num_verts = 0;
    GLuint box_vao;
    GLuint box_vbo;
    GLuint box_shader;

    // directional indicator arrows
    // functions
    void draw_indicators();
    // GPU values
    GLuint arrows_num_verts = 0;
    GLuint arrows_vao;
    GLuint arrows_vbo;
    GLuint arrows_shader;
    
};

void UI_class::generate_geometry()
{
    //box
    // compile shaders
    // verticies for the box
    // buffering

    //arrow - only keeping one model and drawing each individual one with shader params
    // compile shaders
    // verticies
    // buffering
}

void UI_class:draw_box()
{
    // use shader
    // draw num_verts
}

void UI_class:draw_arrows()
{
    // use shader

    //for each of the arrows needed
    // set params
    // draw num_verts
}

