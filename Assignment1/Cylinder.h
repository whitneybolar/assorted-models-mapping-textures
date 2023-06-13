#include <stdio.h>
#include <GL/glew.h>


#define GLM_FORCE_RADIANS 

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

using namespace glm;

/*#define NumTriangles  3
#define NumVertices   3*NumTriangles*/ //from cone
// From Example
// NumIndices = NumTriangles*3
// NumVertices = NumTriangles + 1

//Fun fact
// Numvertices -1 = NumTriangles

#define STEP 10
#define NumVertices 2*STEP + 2
#define NumTriangles 2*STEP
#define NumIndices 3*NumTriangles

void createCylinder();
void drawCylinder();

extern	unsigned int cylinder_vao;

