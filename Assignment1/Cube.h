#include <stdio.h>
#include <GL/glew.h>


#define GLM_FORCE_RADIANS 

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

using namespace glm;

void createCube();
void drawCube();

extern	unsigned int cube_vao;

