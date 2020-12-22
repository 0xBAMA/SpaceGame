#ifndef ENGINE
#define ENGINE

#include "includes.h"




//  ╔═╗┬  ┌─┐┬ ┬┌─┐┬─┐  ╔═╗┬ ┬┬┌─┐
//  ╠═╝│  ├─┤└┬┘├┤ ├┬┘  ╚═╗├─┤│├─┘
//  ╩  ┴─┘┴ ┴ ┴ └─┘┴└─  ╚═╝┴ ┴┴┴  

// this class is in charge of rendering opengl geometry associated with the player's ship
class playership_class
{
	public:
		// loads a config and calls the geometry functions
		void init();
    
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


//  ╦ ╦  ╦
//  ║ ║  ║
//  ╚═╝  ╩

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

		// box params
		glm::vec3 box_offset = glm::vec3(-0.23, 0.155, 0.0);
		float box_theta = 3.447, box_phi = -0.167, box_scale = 1.386f;

		
		// directional indicator arrows
		// functions
		void draw_arrows();

		// GPU values
		GLuint arrows_num_verts = 0;
		GLuint arrows_vao;
		GLuint arrows_vbo;
		GLuint arrows_shader;
    
};






class engine
{
public:

	engine();
	~engine();

private:

	SDL_Window * window;
	SDL_GLContext GLcontext;

	ImVec4 clear_color;


	GLuint display_texture;
	GLuint display_shader;
	GLuint display_vao;
	GLuint display_vbo;

	int total_screen_width, total_screen_height;

	void create_window();
	void gl_setup();
	void draw_everything();

	// my classes
	playership_class ship;
	UI_class ui;
		
	void load_OBJ(std::string filename);

	void quit();
	void quit_conf(bool *open);
		
	bool quitconfirm = false;
	bool pquit = false;

public:
//placeholder - this moves to the classes now
// OBJ data (per mesh)	
	// this may vary in length
	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> texcoords;

	// these should all be the same length, the number of triangles
	std::vector<glm::ivec3> triangle_indices;
	std::vector<glm::ivec3> normal_indices;
	std::vector<glm::ivec3> texcoord_indices;
		
};

#endif
