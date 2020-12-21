#include "../includes.h"

// this class is in charge of rendering opengl geometry associated with the player's ship
class playership_class
{
public:
    void init(); // loads a config
    
    // this is to keep track of the verticies associated with the shield bubble around the ship
    // functions
    void shield_bubble_generate_geometry(); // references ship size in the ship config
    void draw_shield_bubble();
    
    // GPU values
    GLuint shield_bubble_num_verts = 0;
    GLuint shield_bubble_vao;
    GLuint shield_bubble_vbo;
    GLuint shield_bubble_shader;


    // this is keeping all the verticies and things assocated with the OBJ model of the ship
    // functions
    void ship_load_model(); // references ship model filename in ship config
    void draw_ship();

    // GPU values
    GLuint player_ship_num_verts = 0;
    GLuint player_ship_vao;
    GLuint player_ship_vbo;
    GLuint player_ship_shader;

    
    // this is for the old school fire effect done in an image texture, and applied to 
    //  some conic or cylindrical geometry located at the thrusters' positions in
    //   order to show the flames - all can draw from the same texture, maybe
    //    different parts of a wide texture
    // functions
    void thruster_generate_geometry(); // tbd, maybe one of those exponential horn type things?
    void thruster_update(); // does one update of the compute shader
    void draw_thrusters(); // references ship config for intensity, location, etc

    // GPU values
    // thruster front image texture
    // thruster back image texture
    // thruster compute shader
    //  how are we keeping track of which thrusters are firing?
    //   retained power state per thruster seems good so that it can come on at some rate based on the input
    //    and the maneuverability characteristics of the ship, and state can be queried at any time for rendering
    GLuint thrusters_num_verts = 0;
    GLuint thrusters_vao;
    GLuint thrusters_vbo;
    GLuint thrusters_shader;

};