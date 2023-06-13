//
//  Sphere.cpp
//  CSCD470_Another
//
//  Created by Whitney Bolar on 4/11/22.
//

#include "Sphere.h"

unsigned int sphere_vao;

void createSphere()
{

    int i = 0, index = 0;
    float theta, phi;
    float PI = pi<double>();
    //float thetaOne;
    //vec4 p1, p2, p3;

    vec4 vertex[NumVertices];
    vec3 normals[NumVertices];
    GLuint sphere_index[NumIndices];
    vec2 textures[NumVertices];

    for (double b = (-STEP / 2.0); b <= (STEP / 2.0); b++) {
        for (int a = 0; a <= STEP; a++) {
           
            phi = (a*1.0 / STEP) * 2.0 * PI;
            theta = (b*1.0 / STEP) * PI;

            vertex[i].x = cos(theta) * sin(phi);
            vertex[i].y = sin(theta);
            vertex[i].z = cos(theta) * cos(phi);
            vertex[i].w = 1.0f;

            normals[i] = normalize(vec3(vertex[i]));

            textures[i].x = 1.0 * a / STEP;
            textures[i].y = (1.0 * b / STEP) + 0.5;
            i++;
        }
    }

    for (int i = 0; i < (NumVertices - STEP); i += STEP + 1) {
        for (int j = i; j < (i + STEP); j++) {
            int indexOne = j;
            int indexTwo = j + STEP + 1;
            int indexThree = j + STEP + 2;
            int indexFour = j + 1;

            sphere_index[index++] = indexOne;
            sphere_index[index++] = indexTwo;
            sphere_index[index++] = indexFour;  

            sphere_index[index++] = indexThree;
            sphere_index[index++] = indexFour;
            sphere_index[index++] = indexTwo;
        }
    }


    glGenVertexArrays(1, &sphere_vao);
    glBindVertexArray(sphere_vao);

    unsigned int handle[4];
    glGenBuffers(4, handle);

    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sphere_index), sphere_index, GL_STATIC_DRAW);

    glBindVertexArray(0);

}

void drawSphere() {
    glBindVertexArray(sphere_vao);
    glDrawElements(GL_TRIANGLES, NumIndices, GL_UNSIGNED_INT, 0);
}


