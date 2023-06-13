#include <stdio.h>
#include <GL/glew.h>


#define GLM_FORCE_RADIANS 

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

using namespace glm;

#define NumTriangles  30
#define NumVertices   3*NumTriangles
// From Example
// NumIndices = NumTriangles*3
// NumVertices = NumTriangles + 1

//Fun fact
// Numvertices -1 = NumTriangles
void createDisk();
void drawDisk();

extern	unsigned int disk_vao;

