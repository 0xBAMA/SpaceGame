#version 430 core

in vec4 color;
in vec3 vpos;

out vec4 fragment_output;

void main()
{
	vec4 pixcol = color;
	
	pixcol *= 1-(0.5*gl_FragCoord.z);
	fragment_output = pixcol;
}
