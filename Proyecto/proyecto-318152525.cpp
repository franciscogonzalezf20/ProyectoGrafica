/*
Semestre 2024-1
Animación:
Sesión 1:
Simple o básica:Por banderas y condicionales (más de 1 transforomación geométrica se ve modificada
Sesión 2
Compleja: Por medio de funciones y algoritmos.
Adicional.- ,Textura Animada
*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"

//para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"
const float toRadians = 3.14159265f / 180.0f;

//variables para animación
float movAvion;
float movAvionX;
float movLetrero;
float movOffset;
float movOffset2;
float rothelices;
float rotletrero;
float rothelicesOffset;
float rotletreroOffset;
float rotAvion;
float rotDadoX;
float rotDadoY;
float rotDadoZ;
float movDado;
bool avanza;
bool letrr;
bool let;
bool rot2;
bool rot3;
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

Camera camera;

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture AgaveTexture;


Model Marceline_M;
Model FlameP_M;


Model Arc_M;
Model Letrero_M;
Model Mapa_M;
//Model Dado_M;
//Model Arboles_M;
//Model Castle_M;
//Model Bee_M;
//Model BMO_M;
//Model Unicorn_M;
//Model Hunters_M;
//Model CasArbol_M;
//Model Bobert_M;
//Model Jake_M;
//Model Horse_M;
//Model Prismo_M;
//Model rickpepinillo_M;
//Model rick_M;
//Model messek_M;
//Model jessica_M; 
//Model fleeb_M;
//Model robo_M;
//Model arbol1_M;
//Model arbolesDimension35_M;
//Model paisaje_M;
//Model Buttmouth_M; 
//Model dinosaurio_M;
//Model gato_M;
//Model gromflomite_M;
//Model snowball_M;
//Model escuela_M;
//Model garage_M;
//Model gun_M;
//Model nave_M;
//Model vinyFG_M;
Model drunkenclaim_M; 
Model ErnieFG_M;
Model HouseFG_M;
Model monoFG_M;
Model perroFG_M;
Model ruppertFG_M;













Skybox skybox;

//materiales
Material Material_brillante;
Material Material_opaco;


//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

// luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight
PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];

// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";


//función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}


void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,


	};

	unsigned int casillaI[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4, 5, 6,
	   4, 6, 7,
	   8, 9, 10,
	   8, 10, 11,
	   12, 13, 14,
	   12, 14, 15,
	   16, 17, 18,
	   16, 18, 19,
	   20, 21, 22,
	   20, 22, 23

	};

	GLfloat casillaV[] = {
		//x,y,-z
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,		0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 1.0f,
		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 1.0f,
		//x,y,z
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f,
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f,
		0.5f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, -1.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f,
		//x,z,-y
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
		//x,z,y
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		1.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		//z,y,x
		0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,		1.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,		1.0f, 1.0f,		-1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 1.0f,		-1.0f, 0.0f, 0.0f,
		//z,y,-x
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f,		1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,		1.0f, 1.0f,		1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 1.0f,		1.0f, 0.0f, 0.0f,

	};



	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj4);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);

	Mesh* obj5 = new Mesh();
	obj5->CreateMesh(casillaV, casillaI , 192, 36);
	meshList.push_back(obj5);


}


void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}



int main()
{
	

	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	camera = Camera(glm::vec3(0.0f, 40.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.9f, 0.9f);

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/mapa.png");
	pisoTexture.LoadTextureA();
	AgaveTexture = Texture("Textures/Agave.tga");
	AgaveTexture.LoadTextureA();

	//Dado_M = Model();
	//Dado_M.LoadModel("Models/dadobest.obj");
	
	

	Arc_M = Model();
	Arc_M.LoadModel("Models/arc.obj");
	Arc_M = Model();
	Arc_M.LoadModel("Models/arc.obj");
	Letrero_M = Model();
	Letrero_M.LoadModel("Models/letrero.obj");
	Mapa_M.LoadModel("Models/mapa.obj");
	
	//Marceline_M = Model();
	//Marceline_M.LoadModel("Models/marceline.obj");
	//FlameP_M = Model();
	//FlameP_M.LoadModel("Models/fameprinces.obj");
	//Arboles_M = Model();
	//Arboles_M.LoadModel("Models/todo.obj");
	//Castle_M = Model();
	//Castle_M.LoadModel("Models/castlecandy.obj");
	//Bee_M = Model();
	//Bee_M.LoadModel("Models/bee.obj");
	//BMO_M = Model();
	//BMO_M.LoadModel("Models/bmo.obj");
	//Unicorn_M = Model();
	//Unicorn_M.LoadModel("Models/unicorn.obj");
	//Hunters_M = Model();
	//Hunters_M.LoadModel("Models/hunters.obj");
	//CasArbol_M = Model();
	//CasArbol_M.LoadModel("Models/casaarbolAT.obj");
	//Bobert_M = Model();
	//Bobert_M.LoadModel("Models/Bobert.obj");
	//Jake_M = Model();
	//Jake_M.LoadModel("Models/jake.obj");
	//Horse_M = Model();
	//Horse_M.LoadModel("Models/horse.obj");
	//Prismo_M = Model();
	//Prismo_M.LoadModel("Models/prismo.obj");
	//rickpepinillo_M = Model();
	//rickpepinillo_M.LoadModel("Models/rickpepinillo.obj");

	//rick_M = Model();
	//rick_M.LoadModel("Models/rick.obj");

	//messek_M = Model();
	//messek_M.LoadModel("Models/meseek.obj");

	//jessica_M = Model();
	//jessica_M.LoadModel("Models/jessica.obj");

	//fleeb_M = Model();
	//fleeb_M.LoadModel("Models/fleeb.obj");

	//robo_M = Model();
	//robo_M.LoadModel("Models/robo.obj");

	//arbol1_M = Model();
	//arbol1_M.LoadModel("Models/arbol1.obj");

	//arbolesDimension35_M = Model();
	//arbolesDimension35_M.LoadModel("Models/arbolesDimension35.obj");

	//paisaje_M = Model();
	//paisaje_M.LoadModel("Models/paisaje.obj");

	//Buttmouth_M = Model();
	//Buttmouth_M.LoadModel("Models/Buttmouth.obj");

	//dinosaurio_M = Model();
	//dinosaurio_M.LoadModel("Models/dinosaurio.obj");

	//gato_M = Model();
	//gato_M.LoadModel("Models/gato.obj");

	//gromflomite_M = Model();
	//gromflomite_M.LoadModel("Models/gromflomite.obj");
	//
	//snowball_M = Model();
	//snowball_M.LoadModel("Models/snowball.obj");

	//escuela_M = Model();
	//escuela_M.LoadModel("Models/escuela.obj");

	//garage_M = Model();
	//garage_M.LoadModel("Models/garage.obj");

	//gun_M = Model();
	//gun_M.LoadModel("Models/gun.obj");

	//nave_M = Model();
	//nave_M.LoadModel("Models/nave esp.obj");


	//vinyFG_M = Model();
	//vinyFG_M.LoadModel("Models/vinyFG.obj");

	drunkenclaim_M = Model();
	drunkenclaim_M.LoadModel("Models/drunkenclaim.obj");

	ErnieFG_M = Model();
	ErnieFG_M.LoadModel("Models/ErnieFG.obj");

	HouseFG_M = Model();
	HouseFG_M.LoadModel("Models/House.obj");

	monoFG_M = Model();
	monoFG_M.LoadModel("Models/monoFG.obj");

	perroFG_M = Model();
	perroFG_M.LoadModel("Models/perroFG.obj");

	ruppertFG_M = Model();
	ruppertFG_M.LoadModel("Models/ruppertFG.obj");

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_ft.tga");

	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);


	//luz direccional, sólo 1 y siempre debe de existir
	mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
		0.3f, 0.3f,
		0.0f, 0.0f, -1.0f);
	//contador de luces puntuales
	unsigned int pointLightCount = 0;
	//Declaración de primer luz puntual
	pointLights[0] = PointLight(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f,
		-6.0f, 1.5f, 1.5f,
		0.3f, 0.2f, 0.1f);
	pointLightCount++;

	unsigned int spotLightCount = 0;
	//linterna
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,
		1.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.8f, 0.0f, 0.0f,
		30.0f);
	spotLightCount++;

	//luz fija
	spotLights[1] = SpotLight(0.0f, 1.0f, 0.0f,
		1.0f, 2.0f,
		5.0f, 10.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		15.0f);
	spotLightCount++;

	//se crean mas luces puntuales y spotlight 

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
	movAvion = 3.0f;
	movAvionX = 3.0f;
	movDado = 1.0f;
	rotDadoX = 1.0f;
	rotDadoY = 1.0f;
	rotDadoZ = 1.0f;
	movOffset = 3.0f;
	movOffset2 = 0.2f;
	rothelices = 2.0f;
	rothelicesOffset = 9.0f;
	rotletreroOffset = 4.0f;
	movLetrero = 0.0f;
	rotletrero = 1.0f;
	avanza = true;
	letrr = true;
	rot2 = false;
	rot3 = false;
	let = true;
	int cont=2.0;
	static int numeroAleatorio=0;
	float prevTime = glfwGetTime();
	glfwSetTime(0);
	////Loop mientras no se cierra la ventana
	




	while (!mainWindow.getShouldClose())
	{
		
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;
		
		if (glfwGetTime() > 15) {
			if (avanza) {
				if (movAvion > -240) {
					movAvion -= movOffset * deltaTime;
					rothelices += rothelicesOffset * deltaTime;
					
					if (movAvion < -239.0f)
					{
						rotAvion = -90;
						if (movAvionX < 239.0f) {
							movAvionX += movOffset * deltaTime;
						}
						else {
							avanza = !avanza;
						}
						/*movAvion = 0;*/
					}
					else {
						avanza = !avanza;
					}
				}
			}
			//else if(movAvionX > 240) {
			//	movAvionX += movOffset * deltaTime;
			//	//printf("avanza%f \n ",movAvion);
			//	rothelices += rothelicesOffset * deltaTime;

			//	if (movAvionX < -239.0f)
			//	{
			//		rotAvion = -90;
			//		//movAvion = 0;

			//	}
			//	else {
			//		avanza = !avanza;
			//	}
			//}
			else
			{
				//if (movAvion < 260.0f)
				//{
				//	movAvion += movOffset * deltaTime;
				//	//printf("avanza%f \n ",movAvion);
				//	rothelices -= rothelicesOffset * deltaTime;
				//}
				//else {
				//	avanza = !avanza;
				//}
				avanza = !avanza;
			}
		}
		/*
		if (glfwGetTime() > 5) {
			if (letrr) {
				if (movLetrero > -90.0f)
				{
					rotletrero += 4.0 * deltaTime;
					movLetrero -= 1.0 * deltaTime;
				}
				else {
					letrr = !letrr;
				}
			}
			else
			{
				if (movLetrero < -0.1f)
				{
					rotletrero += 4.0 * deltaTime;
					movLetrero += 1.0 * deltaTime;
				}
				else {
					letrr = !letrr;
				}
			}*/

			/*if (glfwGetTime() > 5) {
				if (letrr) {
					movLetrero = movOffset2 * deltaTime;

					if (movLetrero < 0.0f && movLetrero > -1.0)
					{
						rotletrero += rotletreroOffset * deltaTime;
						if (glfwGetTime() > 2) {
							movLetrero = movOffset2 * deltaTime;
						}
					}
					else if (movLetrero < -1.1f && movLetrero > -89.0) {
						movLetrero=movOffset2*deltaTime;
					}
					else if (movLetrero <-89.1 && movLetrero > -90.0){
						rotletrero += rotletreroOffset * deltaTime;
						if (glfwGetTime() > 2) {
							movLetrero = movOffset2 * deltaTime;
						}
					}
					else {
						letrr = !letrr;
					}
				}
				else{
						letrr = !letrr;
				}

			}*/

			/*
			if (glfwGetTime() > 5) {
				//traslacion
				if (letrr) {
					if (glfwGetTime() == 5 + cont) {
						movLetrero -= movOffset2 * deltaTime;
						letrr = !letrr;
						cont += 2;
					}
				}

				else {
					if (movLetrero < 0.0f) {
						movLetrero += movOffset2 * deltaTime;
					}
					else letrr = !letrr;
				}


			}

			printf("%.3f, %d \n", glfwGetTime(), cont);
			if (glfwGetTime() > 5) {
				//movLetrero = movOffset2 * deltaTime;
				if (letrr) {
					//movLetrero = movOffset2 * deltaTime;
					if (movLetrero < 1.0f && movLetrero > -2.0) {
						movLetrero += movOffset2 * deltaTime;   // Rotar
						if (glfwGetTime() > 2 * cont) {
								rotletrero += rotletreroOffset * deltaTime;
								movLetrero -= movOffset2 * deltaTime;// Continuar movimiento
								cont++;
						}
					}
					else if (movLetrero <= -2.1f && movLetrero > -89.0) {
						if (glfwGetTime() > 2*cont) {
							movLetrero -= movOffset2 * deltaTime;// Continuar movimiento
							cont++;
						}
					}
					else if (movLetrero <= -89.1 && movLetrero > -91.0) {
						 movLetrero = movOffset2 * deltaTime;  // Rotar
						if (glfwGetTime() > 2*cont) {
							rotletrero += rotletreroOffset * deltaTime;
							movLetrero += movOffset2 * deltaTime;// Continuar movimiento
							cont++;
						}
					}
					else {
						letrr = !letrr;  // Invertir la variable
						  // Reiniciar el tiempo previo
					}
				}
				else {
					letrr = !letrr;  // Invertir la variable para repetir el proceso
					 // Reiniciar el tiempo previo
				}
			}
			*/
	

		//Recibir eventos del usuario
		glfwPollEvents();
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();
		
		//información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		// luz ligada a la cámara de tipo flash
		//sirve para que en tiempo de ejecución (dentro del while) se cambien propiedades de la luz
			glm::vec3 lowerLight = camera.getCameraPosition();
		lowerLight.y -= 0.3f;
		spotLights[0].SetFlash(lowerLight, camera.getCameraDirection());

		//información al shader de fuentes de iluminación
		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);
		shaderList[0].SetSpotLights(spotLights, spotLightCount);



		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(115.0f, 0.5f, 130.0f));
		model = glm::scale(model, glm::vec3(21.0f, 1.0f, 42.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);

		meshList[4]->RenderMesh();
		
		//piso
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(10.0f, 1.0f, 10.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Mapa_M.RenderModel();

		////Instancia de arboles
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -10.0f, 125.0f));
		//model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		////modelaux = model;
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Arboles_M.RenderModel();	

		////marceline
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -33.0f, 100.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		//color = glm::vec3(0.5f, 0.5f, 0.5f);//llanta con color gris
		//glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Marceline_M.RenderModel();


		////princesa flama
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -33.0f, 70.0f));
		//model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//FlameP_M.RenderModel();

		////castillo
		//model = modelaux;
		//model = glm::translate(model, glm::vec3(-170.0f, -15.0f, 50.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Castle_M.RenderModel();

		////abeja
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -10.0f, 30.0));
		//model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		////model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Bee_M.RenderModel();

		////bmo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -30.0f, 0.0));
		//model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//BMO_M.RenderModel();

		////unicorn
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -25.0f, -27.0));
		//model = glm::scale(model, glm::vec3(15.0f, 15.0f, 15.0f));
		//model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Unicorn_M.RenderModel();

		////cazadora
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -36.0f, -50.0));
		//model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Hunters_M.RenderModel();

		////casa del arbol
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-175.0f, -28.0f, -70.0));
		//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//CasArbol_M.RenderModel();

		////bobert
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -23.0f, -98.0));
		//model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Bobert_M.RenderModel();

		////jake
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-170.0f, -22.0f, -123.0));
		//model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Jake_M.RenderModel();

		////Horse
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-98.0f, -20.0f, -167.0));
		//model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Horse_M.RenderModel();

		////prismo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-73.0f, -20.0f, -185.0));
		//model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
		//model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Prismo_M.RenderModel();

		////rickpepinillo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-50.0f, -20.0f, -160.0));
		//model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		//model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//rickpepinillo_M.RenderModel();

		////rick
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(-25.0f, -33.0f, -160.0));
		//model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
		//model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//rick_M.RenderModel();

		////messek
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(2.0f, -38.0f, -160.0));
		//model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		//model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//messek_M.RenderModel();

		////jessica
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(25.0f, -38.0f, -160.0));
		//model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		//model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//jessica_M.RenderModel();

		////fleeb
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(50.0f, -20.0f, -160.0));
		//model = glm::scale(model, glm::vec3(90.0f, 90.0f, 90.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//fleeb_M.RenderModel();

		////robo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(75.0f, -34.0f, -160.0));
		//model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//robo_M.RenderModel();

		////arbol1
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(100.0f, -34.0f, -160.0));
		//model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//arbol1_M.RenderModel();

		////arbolesDimension35
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, -130.0));
		//model = glm::scale(model, glm::vec3(35.0f, 35.0f, 35.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//arbolesDimension35_M.RenderModel();

		////paisaje
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, -95.0));
		//model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//paisaje_M.RenderModel();

		////Buttmouth
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, -70.0));
		//model = glm::scale(model, glm::vec3(80.0f, 80.0f, 80.0f));
		//model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//Buttmouth_M.RenderModel();

		////dinosaurio
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -30.0f, -50.0));
		//model = glm::scale(model, glm::vec3(25.0f, 25.0f, 25.0f));
		//model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//dinosaurio_M.RenderModel();

		////gato
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, -25.0));
		//model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//gato_M.RenderModel();

		////gromflomite
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -35.0f, 0.0));
		//model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		//model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//gromflomite_M.RenderModel();


		////snowball
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -40.0f, 25.0));
		//model = glm::scale(model, glm::vec3(35.0f, 35.0f, 35.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//snowball_M.RenderModel();

		////escuela
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -15.0f, 48.0));
		//model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//escuela_M.RenderModel();

		////garage
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, 73.0));
		//model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		//model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//garage_M.RenderModel();

		////gun
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, 97.0));
		//model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//gun_M.RenderModel();

		////nave
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -23.0f, 135.0));
		//model = glm::scale(model, glm::vec3(9.0f, 9.0f, 9.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//nave_M.RenderModel();

		////viny
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(135.0f, -23.0f, 160.0));
		//model = glm::scale(model, glm::vec3(9.0f, 9.0f, 9.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));

		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//vinyFG_M.RenderModel();

		////drunkenclaim
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(96.0f, -15.0f, 170.0));
		//model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//drunkenclaim_M.RenderModel();

		////Ernie
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(72.0f, -23.0f, 170.0));
		//model = glm::scale(model, glm::vec3(12.0f, 12.0f, 12.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//ErnieFG_M.RenderModel();

		////Casa gryfin
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(56.0f, -23.0f, 170.0));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//HouseFG_M.RenderModel();

		////mono malvado
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(25.0f, -25.0f, 170.0));
		//model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//monoFG_M.RenderModel();

		////perro
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(0.0f, -28.0f, 170.0));
		//model = glm::scale(model, glm::vec3(25.0f, 25.0f, 25.0f));
		//model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//perroFG_M.RenderModel();

		//ruppert
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-30.0f, -33.0f, 170.0));
		model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		ruppertFG_M.RenderModel();





		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
