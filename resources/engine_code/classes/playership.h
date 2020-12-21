#include "../includes.h"

// this class is in charge of rendering opengl geometry associated with the player's ship
class playership_class
{
public:
    // this is to keep track of the verticies associated with the shield bubble around the ship
    GLuint shield_bubble_num_verts;
    GLuint shield_bubble_vao;
    GLuint shield_bubble_vbo;
    GLuint shield_bubble_shader;

    

    // this is keeping all the verticies and things assocated with the OBJ model of the ship
    GLuint player_ship_num_verts;
    GLuint player_ship_vao;
    GLuint player_ship_vbo;
    GLuint player_ship_shader;


    
    // this is for the old school fire effect done in a texture, and applied to 
    //  some conic or cylindrical geometry located at the thrusters' positions in
    //   order to show the flames - all can draw from the same texture, maybe
    //    different parts of a wide texture

    //thruster front texture
    //thruster back texture
    //thruster compute shader
    // how are we keeping track of which thrusters are firing?
    // retained power state per thruster seems good so that it can come on at some rate based on the input
    // and the maneuverability characteristics of the ship
    GLuint thrusters_num_verts;
    GLuint thrusters_vao;
    GLuint thrusters_vbo;
    GLuint thrusters_shader;

};
