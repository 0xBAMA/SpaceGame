#version 430

in vec3 vPosition;
in vec3 vNormal;
in vec3 vColor;

out vec4 color;
out vec3 vpos;

uniform float theta;
uniform float phi;
uniform float ratio;

uniform vec4 box_color;

uniform float scale;
uniform vec3 offset;

//thanks to Neil Mendoza via http://www.neilmendoza.com/glsl-rotation-about-an-arbitrary-axis/
mat3 rotationMatrix(vec3 axis, float angle)
{
    axis = normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;

    return mat3(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c);
}


void main()
{

	mat3 rotphi = rotationMatrix(vec3(1,0,0), -1.0*phi);
	
	mat3 rottheta = rotationMatrix(vec3(0,1,0), -1.0*theta);

	//color = box_color;
	color = vec4(vec3(0.3125),1.0);
	
	vpos = scale * (rotphi * rottheta * vPosition);
	
	vpos.x /= ratio;
	vpos += offset;
	
	vpos.z *= 0.8;

	gl_Position = vec4(vpos, 1.0);
}
