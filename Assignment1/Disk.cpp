//
// Disk.cpp
//  CSCD470_Another
//
//  Created by Whitney Bolar on 4/11/22.
//

#include "Disk.h"

unsigned int disk_vao;

void createDisk()
{
    
    int i, index = 0;
    float theta;
    float thetaOne;
    vec4 p1, p2, p3;

    vec4 points[NumVertices];
    vec4 colors[NumVertices];
    vec3 normals[NumVertices];
    vec2 textures[NumVertices];
    vec2 center(0.5, 0.5);

    GLfloat steps = 360.0 / NumTriangles;

    vec4 red(1.0, 0.0, 0.0, 1.0);

    for (i = 0; i < NumTriangles; ++i) {

        theta = i * steps;
        thetaOne = (i + 1)*steps;

        p1 = vec4(0.0, -1.0, 0.0, 1.0);
        p2 = vec4(cos(radians(theta)), -1.0, sin(radians(theta)), 1.0);
        p3 = vec4(cos(radians(thetaOne)), -1.0, sin(radians(thetaOne)), 1.0);

        vec3 normal = normalize(vec3((cross(vec3(p1 - p3), vec3(p1 - p2)))));

        points[index] = p1; normals[index] = normal;  textures[index] = center; index++;
        points[index] = p2; normals[index] = normal;  textures[index] = vec2((1 + cos(theta)) / 2.0, (1 + sin(theta)) / 2.0); index++;
        points[index] = p3; normals[index] = normal;  textures[index] = vec2((1 + cos(thetaOne)) / 2.0, (1 + sin(thetaOne)) / 2.0); index++;
        
    }
    
    for (i = 0; i < NumVertices; i++) {
        normals[i] = normalize(vec3(normals[i]));
    }


    glGenVertexArrays(1, &disk_vao);
    glBindVertexArray(disk_vao);

    unsigned int handle[3];
    glGenBuffers(3, handle);

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
    
    glBindVertexArray(0);

}

void drawDisk() {
    glBindVertexArray(disk_vao);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);
}


