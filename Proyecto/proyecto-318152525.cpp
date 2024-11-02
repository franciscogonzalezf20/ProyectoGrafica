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

//dados
float movdado;
float rotardadoX;
float rotardadoY;
float rotardadoZ;


bool avanza;
bool letrr;
bool let;
bool rot2;
bool rot3;

bool dia, noche, iluminada;
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

Camera camera;

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture AgaveTexture;
//texturas casillas 
Texture mapaTexture;
Texture ATarbolesD;
Texture ATarbolesN;
Texture ATarbolesI;
Texture ATabejaD;
Texture ATabejaN;
Texture ATabejaI;
Texture ATbmoD;
Texture ATbmoN;
Texture ATbmoI;
Texture ATprismoD;
Texture ATprismoN;
Texture ATprismoI;
Texture ATbobertD;
Texture ATbobertN;
Texture ATbobertI;
Texture ATcaballoD;
Texture ATcaballoN;
Texture ATcaballoI;
Texture ATcasaD;
Texture ATcasaN;
Texture ATcasaI;
Texture ATflamaD;
Texture ATflamaN;
Texture ATflamaI;
Texture ATjakeD;
Texture ATjakeN;
Texture ATjakeI;
Texture ATmarceD;
Texture ATmarceN;
Texture ATmarceI;
Texture ATreinoD;
Texture ATreinoN;
Texture ATreinoI;
Texture ATunicornD;
Texture ATunicornN;
Texture ATunicornI;
Texture AThunterD;
Texture AThunterN;
Texture AThunterI;
Texture FGbarD;
Texture FGbarN;
Texture FGbarI;
Texture FGhorseD;
Texture FGhorseN;
Texture FGhorseI;
Texture FGchangoD;
Texture FGchangoN;
Texture FGchangoI;
Texture FGernieD;
Texture FGernieN;
Texture FGernieI;
Texture FGperroD;
Texture FGperroN;
Texture FGperroI;
Texture FGrupertD;
Texture FGrupertN;
Texture FGrupertI;
Texture FGvinieD;
Texture FGvinieN;
Texture FGvinieI;
Texture FGjasperD;
Texture FGjasperN;
Texture FGjasperI;
Texture FGtoroD;
Texture FGtoroN;
Texture FGtoroI;
Texture FGbrayanD;
Texture FGbrayanN;
Texture FGbrayanI;
Texture FGcasaD;
Texture FGcasaN;
Texture FGcasaI;
Texture FGarbolD;
Texture FGarbolN;
Texture FGarbolI;
Texture FGranaD;
Texture FGranaN;
Texture FGranaI;
Texture FGnavidadD;
Texture FGnavidadN;
Texture FGnavidadI;
Texture RMescuelaD;
Texture RMescuelaN;
Texture RMescuelaI;
Texture RMcasaD;
Texture RMcasaN;
Texture RMcasaI;
Texture RMgarageD;
Texture RMgarageN;
Texture RMgarageI;
Texture RMgatoD;
Texture RMgatoN;
Texture RMgatoI;
Texture RMinsectoD;
Texture RMinsectoN;
Texture RMinsectoI;
Texture RMmeeseekD;
Texture RMmeeseekN;
Texture RMmeeseekI;
Texture RMpaisaje1D;
Texture RMpaisaje1N;
Texture RMpaisaje1I;
Texture RMpaisaje2D;
Texture RMpaisaje2N;
Texture RMpaisaje2I;
Texture RMpepinilloD;
Texture RMpepinilloN;
Texture RMpepinilloI;
Texture RMportalD;
Texture RMportalN;
Texture RMportalI;
Texture RMpulpoD;
Texture RMpulpoN;
Texture RMpulpoI;
Texture RMrickD;
Texture RMrickN;
Texture RMrickI;
Texture RMjessicaD;
Texture RMjessicaN;
Texture RMjessicaI;
Texture RMfleebD;
Texture RMfleebN;
Texture RMfleebI;
Texture RMsnowballD;
Texture RMsnowballN;
Texture RMsnowballI;


Model Marceline_M;
Model FlameP_M;


Model Arc_M;
Model Letrero_M;
Model Mapa_M;
Model Dado_M;
Model Arboles_M;
Model Castle_M;
Model Bee_M;
Model BMO_M;
Model Unicorn_M;
Model Hunters_M;
Model CasArbol_M;
Model Bobert_M;
Model Jake_M;
Model Horse_M;
Model Prismo_M;
Model rickpepinillo_M;
Model rick_M;
Model messek_M;
Model jessica_M; 
Model fleeb_M;
Model robo_M;
Model arbol1_M;
Model arbolesDimension35_M;
Model paisaje_M;
Model Buttmouth_M; 
Model dinosaurio_M;
Model gato_M;
Model gromflomite_M;
Model snowball_M;
Model EscuelaMorty_M;
Model garage_M;
Model gun_M;
Model nave_M;
Model vinyFG_M;
Model drunkenclaim_M; 
Model ErnieFG_M;
Model HouseFG_M;
Model monoFG_M;
Model perroFG_M;
Model ruppertFG_M;
Model caballo_M;
Model toro_M;
Model jasper_M;
Model arbolesFG_M;
Model arbolnavidadFG_M;
Model rana_M;
Model dado4_M;

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
		0, 1, 2,
		0, 2, 3
	};

	GLfloat floorVertices[] = {
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 0.0f,		0.0f, -1.0f, 0.0f
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
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 1.0f,
		-0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 1.0f,
		//x,y,z
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f,
		0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f,

		//x,z,-y
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,		0.0f, 1.0f, 0.0f,
		//x,z,y
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, -1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 0.0f,		0.0f, -1.0f, 0.0f,

		//z,y,x
		0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,		0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f,		0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
		//z,y,-x
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f,		1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,		1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,		0.0f, 0.0f,		1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 0.0f,		1.0f, 0.0f, 0.0f,

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

	std::srand(static_cast<unsigned int>(std::time(0))); // Inicializar la semilla para números aleatorios

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/dirt.png");
	pisoTexture.LoadTextureA();
	AgaveTexture = Texture("Textures/Agave.tga");
	AgaveTexture.LoadTextureA();
	mapaTexture = Texture("Textures/mapafon.png");
	mapaTexture.LoadTextureA();
	//Texturas casillas
	ATarbolesD = Texture("Textures/ATarbolesD.png");
	ATarbolesD.LoadTextureA();
	ATarbolesN = Texture("Textures/ATarbolesN.png");
	ATarbolesN.LoadTextureA();
	ATarbolesI = Texture("Textures/ATarbolesI.png");
	ATarbolesI.LoadTextureA();

	ATabejaD = Texture("Textures/ATabejaD.png");
	ATabejaD.LoadTextureA();
	ATabejaN = Texture("Textures/ATabejaN.png");
	ATabejaN.LoadTextureA();
	ATabejaI = Texture("Textures/ATabejaI.png");
	ATabejaI.LoadTextureA();

	ATbmoD = Texture("Textures/ATbmoD.png");
	ATbmoD.LoadTextureA();
	ATbmoN = Texture("Textures/ATbmoN.png");
	ATbmoN.LoadTextureA();
	ATbmoI = Texture("Textures/ATbmoI.png");
	ATbmoI.LoadTextureA();

	ATbobertD = Texture("Textures/ATbobertD.png");
	ATbobertD.LoadTextureA();
	ATbobertN = Texture("Textures/ATbobertN.png");
	ATbobertN.LoadTextureA();
	ATbobertI = Texture("Textures/ATbobertI.png");
	ATbobertI.LoadTextureA();

	ATprismoD = Texture("Textures/ATprismoD.png");
	ATprismoD.LoadTextureA();
	ATprismoN = Texture("Textures/ATprismoN.png");
	ATprismoN.LoadTextureA();
	ATprismoI = Texture("Textures/ATprismoI.png");
	ATprismoI.LoadTextureA();

	AThunterD = Texture("Textures/AThunterD.png");
	AThunterD.LoadTextureA();
	AThunterN = Texture("Textures/AThunterN.png");
	AThunterN.LoadTextureA();
	AThunterI = Texture("Textures/AThunterI.png");
	AThunterI.LoadTextureA();

	ATcaballoD = Texture("Textures/ATcabaD.png");
	ATcaballoD.LoadTextureA();
	ATcaballoN = Texture("Textures/ATcabaN.png");
	ATcaballoN.LoadTextureA();
	ATcaballoI = Texture("Textures/ATcabaI.png");
	ATcaballoI.LoadTextureA();

	ATcasaD = Texture("Textures/ATcasarbolD.png");
	ATcasaD.LoadTextureA();
	ATcasaN = Texture("Textures/ATcasarbolN.png");
	ATcasaN.LoadTextureA();
	ATcasaI = Texture("Textures/ATcasarbolI.png");
	ATcasaI.LoadTextureA();

	ATflamaD = Texture("Textures/ATflamaD.png");
	ATflamaD.LoadTextureA();
	ATflamaN = Texture("Textures/ATflamaN.png");
	ATflamaN.LoadTextureA();
	ATflamaI = Texture("Textures/ATflamaI.png");
	ATflamaI.LoadTextureA();

	ATjakeD = Texture("Textures/ATjakeD.png");
	ATjakeD.LoadTextureA();
	ATjakeN = Texture("Textures/ATjakeN.png");
	ATjakeN.LoadTextureA();
	ATjakeI = Texture("Textures/ATjakeI.png");
	ATjakeI.LoadTextureA();

	ATmarceD = Texture("Textures/ATmarceD.png");
	ATmarceD.LoadTextureA();
	ATmarceN = Texture("Textures/ATmarceN.png");
	ATmarceN.LoadTextureA();
	ATmarceI = Texture("Textures/ATmarceI.png");
	ATmarceI.LoadTextureA();

	ATreinoD = Texture("Textures/ATreiniD.png");
	ATreinoD.LoadTextureA();
	ATreinoN = Texture("Textures/ATreiniN.png");
	ATreinoN.LoadTextureA();
	ATreinoI = Texture("Textures/ATreiniI.png");
	ATreinoI.LoadTextureA();

	ATunicornD = Texture("Textures/ATunicornD.png");
	ATunicornD.LoadTextureA();
	ATunicornN = Texture("Textures/ATunicornN.png");
	ATunicornN.LoadTextureA();
	ATunicornI = Texture("Textures/ATunicornI.png");
	ATunicornI.LoadTextureA();

	FGbarD = Texture("Textures/FGbarD.png");
	FGbarD.LoadTextureA();
	FGbarN = Texture("Textures/FGbarN.png");
	FGbarN.LoadTextureA();
	FGbarI = Texture("Textures/FGbarI.png"); 
	FGbarI.LoadTextureA();

	FGhorseD = Texture("Textures/FGcaballod.png");
	FGhorseD.LoadTextureA();
	FGhorseN = Texture("Textures/FGcaballoN.png");
	FGhorseN.LoadTextureA();
	FGhorseI = Texture("Textures/FGcaballoI.png");
	FGhorseI.LoadTextureA();
	
	FGchangoD = Texture("Textures/FGchangoD.png");
	FGchangoD.LoadTextureA();
	FGchangoN = Texture("Textures/FGchangoN.png");
	FGchangoN.LoadTextureA();
	FGchangoI = Texture("Textures/FGchangoI.png");
	FGchangoI.LoadTextureA();

	FGernieD = Texture("Textures/FGernieD.png");
	FGernieD.LoadTextureA();
	FGernieN = Texture("Textures/FGernieN.png");
	FGernieN.LoadTextureA();
	FGernieI = Texture("Textures/FGernieI.png");
	FGernieI.LoadTextureA();

	FGperroD = Texture("Textures/FGperroD.png");
	FGperroD.LoadTextureA();
	FGperroN = Texture("Textures/FGperroN.png");
	FGperroN.LoadTextureA();
	FGperroI = Texture("Textures/FGperroI.png");
	FGperroI.LoadTextureA();

	FGrupertD = Texture("Textures/FGrupertD.png");
	FGrupertD.LoadTextureA();
	FGrupertN = Texture("Textures/FGrupertN.png");
	FGrupertN.LoadTextureA();
	FGrupertI = Texture("Textures/FGrupertI.png");
	FGrupertI.LoadTextureA();

	FGvinieD = Texture("Textures/FGvinieD.png");
	FGvinieD.LoadTextureA();
	FGvinieN = Texture("Textures/FGvinieN.png");
	FGvinieN.LoadTextureA();
	FGvinieI = Texture("Textures/FGvinieI.png");
	FGvinieI.LoadTextureA();

	FGjasperD = Texture("Textures/FGjasperD.png");
	FGjasperD.LoadTextureA();
	FGjasperN = Texture("Textures/FGjasperN.png");
	FGjasperN.LoadTextureA();
	FGjasperI = Texture("Textures/FGjasperI.png");
	FGjasperI.LoadTextureA();

	FGtoroD = Texture("Textures/FGtoroD.png");
	FGtoroD.LoadTextureA();
	FGtoroN = Texture("Textures/FGtoroN.png");
	FGtoroN.LoadTextureA();
	FGtoroI = Texture("Textures/FGtoroI.png");
	FGtoroI.LoadTextureA();

	FGbrayanD = Texture("Textures/FGbrayanD.png");
	FGbrayanD.LoadTextureA();
	FGbrayanN = Texture("Textures/FGbrayanN.png");
	FGbrayanN.LoadTextureA();
	FGbrayanI = Texture("Textures/FGbrayanI.png");
	FGbrayanI.LoadTextureA();

	FGcasaD = Texture("Textures/FGcasaD.png");
	FGcasaD.LoadTextureA();
	FGcasaN = Texture("Textures/FGcasaN.png");
	FGcasaN.LoadTextureA();
	FGcasaI = Texture("Textures/FGcasaI.png");
	FGcasaI.LoadTextureA();

	FGarbolD = Texture("Textures/FGarbolD.png");
	FGarbolD.LoadTextureA();
	FGarbolN = Texture("Textures/FGarbolN.png");
	FGarbolN.LoadTextureA();
	FGarbolI = Texture("Textures/FGarbolI.png");
	FGarbolI.LoadTextureA();

	FGranaD = Texture("Textures/FGranaD.png");
	FGranaD.LoadTextureA();
	FGranaN = Texture("Textures/FGranaN.png");
	FGranaN.LoadTextureA();
	FGranaI = Texture("Textures/FGranaI.png");
	FGranaI.LoadTextureA();

	FGnavidadD = Texture("Textures/FGnavidadD.png");
	FGnavidadD.LoadTextureA();
	FGnavidadN = Texture("Textures/FGnavidadN.png");
	FGnavidadN.LoadTextureA();
	FGnavidadI = Texture("Textures/FGnavidadI.png");
	FGnavidadI.LoadTextureA();

	RMescuelaD = Texture("Textures/RMescuelaD.png");
	RMescuelaD.LoadTextureA();
	RMescuelaN = Texture("Textures/RMescuelaN.png");
	RMescuelaN.LoadTextureA();
	RMescuelaI = Texture("Textures/RMescuelaI.png");
	RMescuelaI.LoadTextureA();


	RMcasaD = Texture("Textures/RMcasaD.png");
	RMcasaD.LoadTextureA();
	RMcasaN = Texture("Textures/RMcasaN.png");
	RMcasaN.LoadTextureA();
	RMcasaI = Texture("Textures/RMcasaI.png");
	RMcasaI.LoadTextureA();

	RMgarageD = Texture("Textures/RMgarajeD.png");
	RMgarageD.LoadTextureA();
	RMgarageN = Texture("Textures/RMgarajeN.png");
	RMgarageN.LoadTextureA();
	RMgarageI = Texture("Textures/RMgarajeI.png");
	RMgarageI.LoadTextureA();

	RMgatoD = Texture("Textures/RMgatoD.png");
	RMgatoD.LoadTextureA();
	RMgatoN = Texture("Textures/RMgatoN.png");
	RMgatoN.LoadTextureA();
	RMgatoI = Texture("Textures/RMgatoI.png");
	RMgatoI.LoadTextureA();

	RMinsectoD = Texture("Textures/RMinsectoD.png");
	RMinsectoD.LoadTextureA();
	RMinsectoN = Texture("Textures/RMinsectoN.png");
	RMinsectoN.LoadTextureA();
	RMinsectoI = Texture("Textures/RMinsectoI.png");
	RMinsectoI.LoadTextureA();

	RMmeeseekD = Texture("Textures/RMmessekD.png");
	RMmeeseekD.LoadTextureA();
	RMmeeseekN = Texture("Textures/RMmessekN.png");
	RMmeeseekN.LoadTextureA();
	RMmeeseekI = Texture("Textures/RMmessekI.png");
	RMmeeseekI.LoadTextureA();

	RMpaisaje1D = Texture("Textures/RMpaisaje1D.png");
	RMpaisaje1D.LoadTextureA();
	RMpaisaje1N = Texture("Textures/RMpaisaje1N.png");
	RMpaisaje1N.LoadTextureA();
	RMpaisaje1I = Texture("Textures/RMpaisaje1I.png");
	RMpaisaje1I.LoadTextureA();

	RMpaisaje2D = Texture("Textures/RMpaisaje3D.png");
	RMpaisaje2D.LoadTextureA();
	RMpaisaje2N = Texture("Textures/RMpaisaje3N.png");
	RMpaisaje2N.LoadTextureA();
	RMpaisaje2I = Texture("Textures/RMpaisaje3I.png");
	RMpaisaje2I.LoadTextureA();

	RMpepinilloD = Texture("Textures/RMpepinilloD.png");
	RMpepinilloD.LoadTextureA();
	RMpepinilloN = Texture("Textures/RMpepinilloN.png");
	RMpepinilloN.LoadTextureA();
	RMpepinilloI = Texture("Textures/RMpepinilloI.png");
	RMpepinilloI.LoadTextureA();

	RMpulpoD = Texture("Textures/RMpulpoD.png");
	RMpulpoD.LoadTextureA();
	RMpulpoN = Texture("Textures/RMpulpoN.png");
	RMpulpoN.LoadTextureA();
	RMpulpoI = Texture("Textures/RMpulpoI.png");
	RMpulpoI.LoadTextureA();

	RMrickD = Texture("Textures/RMrickD.png");
	RMrickD.LoadTextureA();
	RMrickN = Texture("Textures/RMrickN.png");
	RMrickN.LoadTextureA();
	RMrickI = Texture("Textures/RMrickI.png");
	RMrickI.LoadTextureA();

	RMsnowballD = Texture("Textures/RMsnowballD.png");
	RMsnowballD.LoadTextureA();
	RMsnowballN = Texture("Textures/RMsnowballN.png");
	RMsnowballN.LoadTextureA();
	RMsnowballI = Texture("Textures/RMsnowballI.png");
	RMsnowballI.LoadTextureA();

	RMjessicaD = Texture("Textures/RMjessicaD.png");
	RMjessicaD.LoadTextureA();
	RMjessicaN = Texture("Textures/RMjessicaN.png");
	RMjessicaN.LoadTextureA();
	RMjessicaI = Texture("Textures/RMjessicaI.png");
	RMjessicaI.LoadTextureA();

	RMfleebD = Texture("Textures/RMfleebD.png");
	RMfleebD.LoadTextureA();
	RMfleebN = Texture("Textures/RMfleebN.png");
	RMfleebN.LoadTextureA();
	RMfleebI = Texture("Textures/RMfleebI.png");
	RMfleebI.LoadTextureA();


	//Dado_M = Model();
	//Dado_M.LoadModel("Models/dadobest.obj");
	
	Mapa_M = Model();
	Mapa_M.LoadModel("Models/mapa.obj");

	Arc_M = Model();
	Arc_M.LoadModel("Models/arc.obj");
	Arc_M = Model();
	Arc_M.LoadModel("Models/arc.obj");
	Letrero_M = Model();
	Letrero_M.LoadModel("Models/letrero.obj");
	
	Marceline_M = Model();
	Marceline_M.LoadModel("Models/marceline.obj");
	FlameP_M = Model();
	FlameP_M.LoadModel("Models/fameprinces.obj");
	Arboles_M = Model();
	Arboles_M.LoadModel("Models/todo.obj");
	Castle_M = Model();
	Castle_M.LoadModel("Models/castlecandy.obj");
	Bee_M = Model();
	Bee_M.LoadModel("Models/bee.obj");
	BMO_M = Model();
	BMO_M.LoadModel("Models/bmo.obj");
	Unicorn_M = Model();
	Unicorn_M.LoadModel("Models/unicorn.obj");
	Hunters_M = Model();
	Hunters_M.LoadModel("Models/hunters.obj");
	CasArbol_M = Model();
	CasArbol_M.LoadModel("Models/casaarbolAT.obj");
	Bobert_M = Model();
	Bobert_M.LoadModel("Models/Bobert.obj");
	Jake_M = Model();
	Jake_M.LoadModel("Models/jake.obj");
	Horse_M = Model();
	Horse_M.LoadModel("Models/horse.obj");
	Prismo_M = Model();
	Prismo_M.LoadModel("Models/prismo.obj");
	rickpepinillo_M = Model();
	rickpepinillo_M.LoadModel("Models/rickpepinillo.obj");

	rick_M = Model();
	rick_M.LoadModel("Models/rick.obj");

	messek_M = Model();
	messek_M.LoadModel("Models/meseek.obj");

	jessica_M = Model();
	jessica_M.LoadModel("Models/jessica.obj");

	fleeb_M = Model();
	fleeb_M.LoadModel("Models/fleeb.obj");

	robo_M = Model();
	robo_M.LoadModel("Models/robo.obj");

	arbol1_M = Model();
	arbol1_M.LoadModel("Models/arbol1.obj");

	arbolesDimension35_M = Model();
	arbolesDimension35_M.LoadModel("Models/arbolesDimension35C.obj");

	paisaje_M = Model();
	paisaje_M.LoadModel("Models/paisaje.obj");

	Buttmouth_M = Model();
	Buttmouth_M.LoadModel("Models/Buttmouth.obj");

	dinosaurio_M = Model();
	dinosaurio_M.LoadModel("Models/dinosaurio.obj");

	gato_M = Model();
	gato_M.LoadModel("Models/gato.obj");

	gromflomite_M = Model();
	gromflomite_M.LoadModel("Models/gromflomite.obj");
	
	snowball_M = Model();
	snowball_M.LoadModel("Models/snowball.obj");


	EscuelaMorty_M = Model();
	EscuelaMorty_M.LoadModel("Models/escuela.obj");

	garage_M = Model();
	garage_M.LoadModel("Models/garage.obj");

	gun_M = Model();
	gun_M.LoadModel("Models/gun.obj");

	nave_M = Model();
	nave_M.LoadModel("Models/nave esp.obj");


	vinyFG_M = Model();
	vinyFG_M.LoadModel("Models/vinyFG.obj");

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

	caballo_M = Model();
	caballo_M.LoadModel("Models/caballo.obj");

	toro_M = Model();
	toro_M.LoadModel("Models/toro.obj");

	jasper_M = Model();
	jasper_M.LoadModel("Models/jasper.obj");

	arbolesFG_M = Model();
	arbolesFG_M.LoadModel("Models/arbolesFG.obj");

	arbolnavidadFG_M = Model();
	arbolnavidadFG_M.LoadModel("Models/arbolnavidadFG.obj");

	rana_M = Model();
	rana_M.LoadModel("Models/rana.obj");

	dado4_M = Model();
	dado4_M.LoadModel("Models/dado4.obj");

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cara_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cara_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cara_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cara_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cara_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cara_ft.tga");

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
	pointLights[0] = PointLight(0.5f, 0.5f, 0.5f,
		0.0f, 1.0f,
		145.0f, 8.5f, 145.0f,
		0.05f, 0.005f, 0.001f);
	pointLightCount++;

	pointLights[1] = PointLight(0.5f, 0.5f, 0.5f,
		0.0f, 1.0f,
		-145.0f, 8.5f, -145.0f,
		0.05f, 0.005f, 0.001f);
	pointLightCount++;

	pointLights[2] = PointLight(0.5f, 0.5f, 0.5f,
		0.0f, 1.0f,
		145.0f, 8.5f, -145.0f,
		0.05f, 0.005f, 0.001f);
	pointLightCount++;

	unsigned int spotLightCount = 2;

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
	movdado = 100.0f;
	rotardadoX = 0.0f;
	rotardadoY = 0.0f;
	rotardadoZ = 0.0f;
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
	static int dadoResultado = 4;
	float prevTime = glfwGetTime();
	glfwSetTime(0);
	////Loop mientras no se cierra la ventana
	


	 

	while (!mainWindow.getShouldClose())
	{
		
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;
		dia = true;

		if (mainWindow.getsKeys()[GLFW_KEY_I]){
			dia = true;
			noche = false;
			iluminada = false;
		}
		if (mainWindow.getsKeys()[GLFW_KEY_N]) {
			dia = false;
			noche = true;
			iluminada = false;
		}

		if (mainWindow.getsKeys()[GLFW_KEY_H]) {
			dadoResultado =  4; // Genera un número entre 1 y 10
			rotardadoX = 0.0f; // Reiniciar la rotación
			rotardadoY = 0.0f; // Reiniciar la rotación
			rotardadoZ = 0.0f; // Reiniciar la rotación
			movdado = 100.0f;
		}

		if (movdado > 6.3f) {
			movdado -= 0.2f * deltaTime;

			// Rotación según el resultado del dado
			switch (dadoResultado) {
			case 1:
				rotardadoX += 6.15f * deltaTime;
				break;
			case 2:
				rotardadoZ += 6.38f * deltaTime;
				break;
			case 3:
				rotardadoX += 1.0f * deltaTime;
				rotardadoY += 2.0f * deltaTime;

				break;
			case 4:
				rotardadoX += 5.6f * deltaTime;
				rotardadoZ += 2.7f * deltaTime;
				rotardadoY += 4.8f * deltaTime;


				break;
			
			}

		}
		
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
		
		//piso
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(300.0f, 1.0f, 300.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		mapaTexture.UseTexture();
		meshList[2]->RenderMesh();

		//piso2
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.05f, 0.0f));
		model = glm::scale(model, glm::vec3(450.0f, 1.0f, 450.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		pisoTexture.UseTexture();
		meshList[2]->RenderMesh();

		//c1
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(94.5f, 1.0f, -129.2f));
		model = glm::scale(model, glm::vec3(22.5f, 1.0f, 41.5f));
		modelaux = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		if (dia) {
			ATarbolesD.UseTexture();
		}
		if (noche) {
			ATarbolesN.UseTexture();
		}
		if (iluminada) {
			ATarbolesI.UseTexture();
		}
		//ATarbolesD.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c2
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		if (dia) {
			RMgarageD.UseTexture();
		}
		if (noche) {
			RMgarageN.UseTexture();
		}
		if (iluminada) {
			RMgarageI.UseTexture();
		}
		//RMgarageD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c3
		model = modelaux;
		model = glm::translate(model, glm::vec3(-2.1f, 0.0f, 0.0f));
		if (dia) {
			RMfleebD.UseTexture();
		}
		if (noche) {
			RMfleebN.UseTexture();
		}
		if (iluminada) {
			RMfleebI.UseTexture();
		}
		//RMfleebD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c4
		model = modelaux;
		model = glm::translate(model, glm::vec3(-3.15f, 0.0f, 0.0f));
		if (dia) {
			RMjessicaD.UseTexture();
		}
		if (noche) {
			RMjessicaN.UseTexture();
		}
		if (iluminada) {
			RMjessicaI.UseTexture();
		}
		//RMjessicaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c5
		model = modelaux;
		model = glm::translate(model, glm::vec3(-4.20f, 0.0f, 0.0f));
		if (dia) {
			RMmeeseekD.UseTexture();
		}
		if (noche) {
			RMmeeseekN.UseTexture();
		}
		if (iluminada) {
			RMmeeseekI.UseTexture();
		}
		//RMmeeseekD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c6
		model = modelaux;
		model = glm::translate(model, glm::vec3(-5.25f, 0.0f, 0.0f));
		if (dia) {
			RMrickD.UseTexture();
		}
		if (noche) {
			RMrickN.UseTexture();
		}
		if (iluminada) {
			RMrickI.UseTexture();
		}
		//RMrickD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c7
		model = modelaux;
		model = glm::translate(model, glm::vec3(-6.3f, 0.0f, 0.0f));
		if (dia) {
			RMpepinilloD.UseTexture();
		}
		if (noche) {
			RMpepinilloN.UseTexture();
		}
		if (iluminada) {
			RMpepinilloI.UseTexture();
		}
		//RMpepinilloD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c8
		model = modelaux;
		model = glm::translate(model, glm::vec3(-7.35f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		if (dia) {
			ATprismoD.UseTexture();
		}
		if (noche) {
			ATprismoN.UseTexture();
		}
		if (iluminada) {
			ATprismoI.UseTexture();
		}
		//ATprismoD.UseTexture();
		meshList[4]->RenderMesh();

		//c9
		model = modelaux;
		model = glm::translate(model, glm::vec3(-8.40f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATcaballoD.UseTexture();
		}
		if (noche) {
			ATcaballoN.UseTexture();
		}
		if (iluminada) {
			ATcaballoI.UseTexture();
		}
		//ATcaballoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c10
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.535f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.86f, 1.0f, 1.0f));
		if (dia) {
			ATjakeD.UseTexture();
		}
		if (noche) {
			ATjakeN.UseTexture();
		}
		if (iluminada) {
			ATjakeI.UseTexture();
		}
		//ATjakeD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c11
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-129.2f, 1.0f, -94.5f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(22.5f, 1.0f, 41.5f));
		modelaux = model;
		if (dia) {
			ATbobertD.UseTexture();
		}
		if (noche) {
			ATbobertN.UseTexture();
		}
		if (iluminada) {
			ATbobertI.UseTexture();
		}
		//ATbobertD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c12
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATcasaD.UseTexture();
		}
		if (noche) {
			ATcasaN.UseTexture();
		}
		if (iluminada) {
			ATcasaI.UseTexture();
		}
		//ATcasaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c13
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			AThunterD.UseTexture();
		}
		if (noche) {
			AThunterN.UseTexture();
		}
		if (iluminada) {
			AThunterI.UseTexture();
		}
		//AThunterD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c14
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATunicornD.UseTexture();
		}
		if (noche) {
			ATunicornN.UseTexture();
		}
		if (iluminada) {
			ATunicornI.UseTexture();
		}
		//ATunicornD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c15
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATbmoD.UseTexture();
		}
		if (noche) {
			ATbmoN.UseTexture();
		}
		if (iluminada) {
			ATbmoI.UseTexture();
		}
		//ATbmoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c16
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATabejaD.UseTexture();
		}
		if (noche) {
			ATabejaN.UseTexture();
		}
		if (iluminada) {
			ATabejaI.UseTexture();
		}
		//ATabejaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c17
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATreinoD.UseTexture();
		}
		if (noche) {
			ATreinoN.UseTexture();
		}
		if (iluminada) {
			ATreinoI.UseTexture();
		}
		//ATreinoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c18
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATflamaD.UseTexture();
		}
		if (noche) {
			ATflamaN.UseTexture();
		}
		if (iluminada) {
			ATflamaI.UseTexture();
		}
		//ATflamaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c19
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			ATmarceD.UseTexture();
		}
		if (noche) {
			ATmarceN.UseTexture();
		}
		if (iluminada) {
			ATmarceI.UseTexture();
		}
		//ATmarceD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c20
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.535f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.86f, 1.0f, 1.0f));
		if (dia) {
			ATmarceD.UseTexture();
		}
		if (noche) {
			ATmarceN.UseTexture();
		}
		if (iluminada) {
			ATmarceI.UseTexture();
		}
		//ATmarceD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c21
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-94.5f, 1.0f, 129.2f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(22.5f, 1.0f, 41.5f));
		modelaux = model;
		if (dia) {
			FGjasperD.UseTexture();
		}
		if (noche) {
			FGjasperN.UseTexture();
		}
		if (iluminada) {
			FGjasperI.UseTexture();
		}
		//FGjasperD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c22
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGtoroD.UseTexture();
		}
		if (noche) {
			FGtoroN.UseTexture();
		}
		if (iluminada) {
			FGtoroI.UseTexture();
		}
		//FGtoroD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c23
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGhorseD.UseTexture();
		}
		if (noche) {
			FGhorseN.UseTexture();
		}
		if (iluminada) {
			FGhorseI.UseTexture();
		}
		//FGhorseD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c24
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGrupertD.UseTexture();
		}
		if (noche) {
			FGrupertN.UseTexture();
		}
		if (iluminada) {
			FGrupertI.UseTexture();
		}
		//FGrupertD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c25
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGbrayanD.UseTexture();
		}
		if (noche) {
			FGbrayanN.UseTexture();
		}
		if (iluminada) {
			FGbrayanI.UseTexture();
		}
		//FGbrayanD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c26
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGchangoD.UseTexture();
		}
		if (noche) {
			FGchangoN.UseTexture();
		}
		if (iluminada) {
			FGchangoI.UseTexture();
		}
		//FGchangoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c27
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGcasaD.UseTexture();
		}
		if (noche) {
			FGcasaN.UseTexture();
		}
		if (iluminada) {
			FGcasaI.UseTexture();
		}
		//FGcasaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c28
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGernieD.UseTexture();
		}
		if (noche) {
			FGernieN.UseTexture();
		}
		if (iluminada) {
			FGernieI.UseTexture();
		}
		//FGernieD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c29
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGbarD.UseTexture();
		}
		if (noche) {
			FGbarN.UseTexture();
		}
		if (iluminada) {
			FGbarI.UseTexture();
		}
		//FGbarD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c30
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.535f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.86f, 1.0f, 1.0f));
		if (dia) {
			FGvinieD.UseTexture();
		}
		if (noche) {
			FGvinieN.UseTexture();
		}
		if (iluminada) {
			FGvinieI.UseTexture();
		}
		//FGvinieD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c31
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(129.2f, 1.0f, 94.5f));
		model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(22.5f, 1.0f, 41.5f));
		modelaux = model;
		if (dia) {
			FGarbolD.UseTexture();
		}
		if (noche) {
			FGarbolN.UseTexture();
		}
		if (iluminada) {
			FGarbolI.UseTexture();
		}
		//FGarbolD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c32
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGranaD.UseTexture();
		}
		if (noche) {
			FGranaN.UseTexture();
		}
		if (iluminada) {
			FGranaI.UseTexture();
		}
		//FGranaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c33
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			FGnavidadD.UseTexture();
		}
		if (noche) {
			FGnavidadN.UseTexture();
		}
		if (iluminada) {
			FGnavidadI.UseTexture();
		}
		//FGnavidadD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();


		//c34
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			RMsnowballD.UseTexture();
		}
		if (noche) {
			RMsnowballN.UseTexture();
		}
		if (iluminada) {
			RMsnowballI.UseTexture();
		}
		//RMsnowballD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c35
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			RMinsectoD.UseTexture();
		}
		if (noche) {
			RMinsectoN.UseTexture();
		}
		if (iluminada) {
			RMinsectoI.UseTexture();
		}
		//RMinsectoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c36
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			RMgatoD.UseTexture();
		}
		if (noche) {
			RMgatoN.UseTexture();
		}
		if (iluminada) {
			RMgatoI.UseTexture();
		}
		//RMgatoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c37
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			RMescuelaD.UseTexture();
		}
		if (noche) {
			RMescuelaN.UseTexture();
		}
		if (iluminada) {
			RMescuelaI.UseTexture();
		}
		//RMescuelaD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c38
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			RMpulpoD.UseTexture();
		}
		if (noche) {
			RMpulpoN.UseTexture();
		}
		if (iluminada) {
			RMpulpoI.UseTexture();
		}
		//RMpulpoD.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c39
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.05f, 0.0f, 0.0f));
		modelaux = model;
		if (dia) {
			RMpaisaje1D.UseTexture();
		}
		if (noche) {
			RMpaisaje1N.UseTexture();
		}
		if (iluminada) {
			RMpaisaje1I.UseTexture();
		}
		//RMpaisaje1D.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//c40
		model = modelaux;
		model = glm::translate(model, glm::vec3(-1.535f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.86f, 1.0f, 1.0f));
		if (dia) {
			RMpaisaje2D.UseTexture();
		}
		if (noche) {
			RMpaisaje2N.UseTexture();
		}
		if (iluminada) {
			RMpaisaje2I.UseTexture();
		}
		//RMpaisaje2D.UseTexture();
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[4]->RenderMesh();

		//Instancia de arboles
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(96.0f, -13.0f, -165.0));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//modelaux = model;
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Arboles_M.RenderModel();

		//marceline
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -33.0f, 100.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		color = glm::vec3(0.5f, 0.5f, 0.5f);//llanta con color gris
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Marceline_M.RenderModel();


		//princesa flama
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -33.0f, 70.0f));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		FlameP_M.RenderModel();

		//castillo
		model = modelaux;
		model = glm::translate(model, glm::vec3(-170.0f, -15.0f, 50.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Castle_M.RenderModel();


		//abeja
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -10.0f, 30.0));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		//model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bee_M.RenderModel();

		//bmo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -30.0f, 0.0));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		BMO_M.RenderModel();

		//unicorn
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -25.0f, -27.0));
		model = glm::scale(model, glm::vec3(15.0f, 15.0f, 15.0f));
		model = glm::rotate(model, -180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Unicorn_M.RenderModel();

		//cazadora
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -36.0f, -50.0));
		model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Hunters_M.RenderModel();

		//casa del arbol
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-175.0f, -28.0f, -70.0));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//CasArbol_M.RenderModel();

		//bobert
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -23.0f, -98.0));
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Bobert_M.RenderModel();

		//jake
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-170.0f, -22.0f, -123.0));
		model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Jake_M.RenderModel();

		//Horse
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-98.0f, -20.0f, -167.0));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Horse_M.RenderModel();

		//prismo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-73.0f, -20.0f, -185.0));
		model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
		model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Prismo_M.RenderModel();

		//rickpepinillo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-50.0f, -20.0f, -160.0));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		rickpepinillo_M.RenderModel();

		//rick
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-25.0f, -33.0f, -160.0));
		model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
		model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		rick_M.RenderModel();

		//messek
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(2.0f, -38.0f, -160.0));
		model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
		model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		messek_M.RenderModel();

		//jessica
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, -38.0f, -160.0));
		model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		model = glm::rotate(model, -2 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		jessica_M.RenderModel();

		//fleeb
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(50.0f, -20.0f, -160.0));
		model = glm::scale(model, glm::vec3(90.0f, 90.0f, 90.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		fleeb_M.RenderModel();

		////robo
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(75.0f, -34.0f, -160.0));
		//model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//robo_M.RenderModel();

		//arbol1
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(100.0f, -34.0f, -160.0));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol1_M.RenderModel();

		//arbolesDimension35
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, -130.0));
		model = glm::scale(model, glm::vec3(35.0f, 35.0f, 35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbolesDimension35_M.RenderModel();

		//paisaje
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, -95.0));
		model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		paisaje_M.RenderModel();

		//Buttmouth
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, -70.0));
		model = glm::scale(model, glm::vec3(80.0f, 80.0f, 80.0f));
		model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Buttmouth_M.RenderModel();

		////dinosaurio
		//model = glm::mat4(1.0);
		//model = glm::translate(model, glm::vec3(175.0f, -30.0f, -50.0));
		//model = glm::scale(model, glm::vec3(25.0f, 25.0f, 25.0f));
		//model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//dinosaurio_M.RenderModel();

		//gato
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, -25.0));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		gato_M.RenderModel();

		//gromflomite
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -35.0f, 0.0));
		model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
		model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		gromflomite_M.RenderModel();


		//snowball
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -40.0f, 25.0));
		model = glm::scale(model, glm::vec3(35.0f, 35.0f, 35.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		snowball_M.RenderModel();

		//escuela
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -15.0f, -50.0));
		model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		EscuelaMorty_M.RenderModel();

		//garage
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(75.0f, -15.0f, -160.0));
		model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));
		model = glm::rotate(model, 270 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		garage_M.RenderModel();

		//arboles family guy
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, 97.0));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbolesFG_M.RenderModel();


		//arbol navidad
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, 50.0));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbolnavidadFG_M.RenderModel();

		//rana
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(175.0f, -23.0f, 70.0));
		model = glm::scale(model, glm::vec3(30.0f, 30.0f, 30.0f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		rana_M.RenderModel();


		//viny
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(135.0f, -23.0f, 160.0));
		model = glm::scale(model, glm::vec3(9.0f, 9.0f, 9.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		vinyFG_M.RenderModel();

		//drunkenclaim
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(96.0f, -15.0f, 170.0));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		drunkenclaim_M.RenderModel();

		//Ernie
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(72.0f, -23.0f, 170.0));
		model = glm::scale(model, glm::vec3(12.0f, 12.0f, 12.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		ErnieFG_M.RenderModel();

		//Casa gryfin
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(56.0f, -23.0f, 170.0));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		HouseFG_M.RenderModel();

		//mono malvado
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(25.0f, -25.0f, 170.0));
		model = glm::scale(model, glm::vec3(8.0f, 8.0f, 8.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		monoFG_M.RenderModel();

		//perro
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -28.0f, 170.0));
		model = glm::scale(model, glm::vec3(25.0f, 25.0f, 25.0f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		perroFG_M.RenderModel();

		//ruppert
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-30.0f, -33.0f, 170.0));
		model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		ruppertFG_M.RenderModel();

		//caballo
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-50.0f, -20.0f, 174.0));
		model = glm::scale(model, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		caballo_M.RenderModel();

		//toro
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-75.0f, -20.0f, 170.0));
		model = glm::scale(model, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		toro_M.RenderModel();

		//jasper
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-95.0f, -20.0f, 170.0));
		model = glm::scale(model, glm::vec3(40.0f, 40.0f, 40.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		jasper_M.RenderModel();

		//dado4
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, movdado, 0.0f));
		model = glm::rotate(model, rotardadoX * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, rotardadoY * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, rotardadoZ * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		dado4_M.RenderModel();


		  




		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
