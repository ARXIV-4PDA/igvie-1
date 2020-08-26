#version 330 core
out vec4 color;
in vec3 TexCoords;
uniform samplerCube skybox0;

void main(){
    color = texture(skybox0, TexCoords);
    };

