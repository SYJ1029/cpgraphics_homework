#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "3DDiagram.cpp"
#include <fstream>
#include <sstream>


void make_vertexShaders();
void make_fragmentShaders();
void make_shaderProgram();
GLvoid drawScene();
GLvoid Reshape(int w, int h);
//--- 필요한변수선언
GLint width, height;
GLuint shaderProgramID; //--- 세이더 프로그램이름
GLuint vertexShader;
GLuint fragmentShader; //--- 프래그먼트 세이더객체

//--- 세이더코드저장할문자열
//--- 버텍스세이더읽어저장하고컴파일하기
//--- filetobuf: 사용자정의함수로텍스트를읽어서문자열에저장하는함수

GLint result;
GLchar errorLog[512];
GLuint vao, vbo[3], EBO[2];
GLchar* vertexSource;
GLchar* fragmentSource;

int index[1000];
int nindex[1000];

GLfloat triShape[3][3] = {
 { -0.5, -0.5, 0.0 }, { 0.0, -0.5, 0.0 }, { -0.25, 0.5, 0.0} };

float triShape2[] = {
	0.5f,  0.5f, 0.0f,  // 우측 상단
	0.5f, -0.5f, 0.0f,  
	-0.5f, -0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f   // 좌측 상단
};

GLfloat triShape3[3][3] = {
 { 0.5, -0.5, 0.0 }, { 1.0, -0.5, 0.0 }, { 0.75, 0.5, 0.0} };

GLfloat alltriShape[6][3] = {
{ -0.5, -0.5, 0.0 }, { 0.0, -0.5, 0.0 }, { -0.25, 0.5, 0.0},
{ 0.0, -0.5, 0.0 }, { 0.5, -0.5, 0.0 }, { 0.25, 0.5, 0.0}

};


float vertices[] = {
	//--- 버텍스 속성: 좌표값(FragPos), 노말값 (Normal)
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
	0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};



const GLfloat colors[3][3] = {
   {  1.0,  0.0,  0.0  }, {  0.0,  1.0,  0.0  }, {  0.0,  0.0,  1.0  } 
};


GLchar* filetobuf(const char* vertexSource) {
	FILE* fptr;
	long length;
	char* buf;
	fptr = fopen(vertexSource, "rb");
	if (!fptr)
		return NULL;
	fseek(fptr, 0, SEEK_END);
	length = ftell(fptr);
	buf = (char*)malloc(length + 1);
	fseek(fptr, 0, SEEK_SET);
	fread(buf, length, 1, fptr);
	fclose(fptr);
	buf[length] = 0;
	return buf;
}


void make_vertexShaders() {

	vertexSource = filetobuf("Shader/vertex.glsl");
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, (const GLchar**) & vertexSource, NULL);
	glCompileShader(vertexShader);

	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	if(!result)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader 컴파일 실패\n" << errorLog << std::endl;
		return;
	}

	
}

void make_fragmentShaders() 
{
	fragmentSource = filetobuf("Shader/fragment.glsl");    // 프래그세이더 읽어오기
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, (const GLchar**)&fragmentSource, NULL);
	glCompileShader(fragmentShader);

	GLint result;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{

		glGetShaderInfoLog(fragmentShader, 512, NULL, errorLog);
		std::cerr << "ERROR: frag_shader 컴파일 실패\n" << errorLog << std::endl;
		return;
	}
}

void make_shaderProgram()
{

	/*make_vertexShaders();
	make_fragmentShaders();*/

	shaderProgramID = glCreateProgram();

	glAttachShader(shaderProgramID, vertexShader);
	glAttachShader(shaderProgramID, fragmentShader);
	glLinkProgram(shaderProgramID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glUseProgram(shaderProgramID);

}





GLvoid InitBuffer() {

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(3, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	/*glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), NULL, GL_DYNAMIC_DRAW);*/
	glBufferData(GL_ARRAY_BUFFER, 100 * sizeof(GLfloat), NULL, GL_DYNAMIC_DRAW);

	glGenBuffers(2, EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);




	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(GLfloat), NULL, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(nindex), NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);


	glEnableVertexAttribArray(1);



	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(GLfloat), NULL, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 9 * sizeof(GLfloat), colors);
	glBufferSubData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), 9 * sizeof(GLfloat), colors);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);



}



GLvoid UpdateBuffer() {
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	//glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), NULL, GL_DYNAMIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, 18 * sizeof(GLfloat), alltriShape);
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	//glBufferSubData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), 9 * sizeof(GLfloat), triShape2);
	//glDrawArrays(GL_TRIANGLES, 3, 3);


	glEnableVertexAttribArray(0);
}



// 구체 데이터 생성
void generateSphere(float radius, int sectors, int stacks,
	std::vector<float>& vertices,
	std::vector<float>& normals,
	std::vector<float>& texCoords,
	std::vector<unsigned int>& indices) {
	const float PI = 3.14159265359f;

	for (int i = 0; i <= stacks; ++i) {
		float stackAngle = PI / 2 - i * (PI / stacks); // 위에서 아래로
		float xy = radius * cosf(stackAngle);          // x-y 평면 반지름
		float z = radius * sinf(stackAngle);           // z 좌표

		for (int j = 0; j <= sectors; ++j) {
			float sectorAngle = j * (2 * PI / sectors); // 동쪽에서 서쪽으로

			float x = xy * cosf(sectorAngle); // x 좌표
			float y = xy * sinf(sectorAngle); // y 좌표

			// 정점 좌표
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			// 노멀 벡터 (구의 중심에서 정점으로 향하는 벡터)
			normals.push_back(x / radius);
			normals.push_back(y / radius);
			normals.push_back(z / radius);

			// 텍스처 좌표
			texCoords.push_back((float)j / sectors);
			texCoords.push_back((float)i / stacks);
		}
	}

	// 삼각형 인덱스 계산
	for (int i = 0; i < stacks; ++i) {
		for (int j = 0; j < sectors; ++j) {
			int first = i * (sectors + 1) + j;
			int second = first + sectors + 1;

			indices.push_back(first);
			indices.push_back(second);
			indices.push_back(first + 1);

			indices.push_back(second);
			indices.push_back(second + 1);
			indices.push_back(first + 1);
		}
	}
}
