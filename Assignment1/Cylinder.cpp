//
//  Cylinder.cpp
//  CSCD470_Another
//
//  Created by Whitney Bolar on 4/11/22.
//

#include "Cylinder.h"

unsigned int cylinder_vao;

void createCylinder()
{
    int i, index = 0;
    float theta;
    //float thetaOne;
    //vec4 p1, p2, p3;

    vec4 points[NumVertices];
    vec4 colors[NumVertices];
    vec3 normals[NumVertices];
    GLuint indices[NumIndices];
    vec2 textures[NumVertices];

    GLfloat steps = 360.0 / STEP;
    for (int i = 0; i <= STEP; ++i) {
        theta = radians(i * steps);
        points[i] = vec4(sin(theta), 1.0, cos(theta), 1.0f);
        points[i + STEP + 1] = vec4(sin(theta), 0.0, cos(theta), 1.0f);
        normals[i] = normalize(vec3(points[i].x, 0, points[i].z));
        normals[i + STEP + 1] = normalize(vec3(points[i + STEP + 1].x, 0, points[i + STEP + 1].z));
        textures[i] = vec2((float)(i) / STEP, 1.0);
        textures[i + STEP + 1] = vec2((float)(i) / STEP, 0.0);
    }

    for (i = 0; i < STEP; ++i) {
        indices[index++] = i;
        indices[index++] = i + STEP + 1;
        indices[index++] = i + 1;
        
        indices[index++] = i + 1;
        indices[index++] = i + STEP + 1;
        indices[index++] = i + STEP + 2;
    }
    
    glGenVertexArrays(1, &cylinder_vao);
    glBindVertexArray(cylinder_vao);

    unsigned int handle[4];
    glGenBuffers(4, handle);

    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);  // Vertex position

    glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);  // Vertex normal

    glBindBuffer(GL_ARRAY_BUFFER, handle[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textures), textures, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)2, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(2);  // Vertex texture

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindVertexArray(0);

}

void drawCylinder() {
    glBindVertexArray(cylinder_vao);
    glDrawElements(GL_TRIANGLES, NumIndices, GL_UNSIGNED_INT, 0);
}



