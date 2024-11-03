#pragma once
#include "Light.h"

class DirectionalLight :
	public Light
{
public:
	DirectionalLight();
	DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
					GLfloat aIntensity, GLfloat dIntensity,
					GLfloat xDir, GLfloat yDir, GLfloat zDir);

	void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientcolorLocation,
		GLfloat diffuseIntensityLocation, GLfloat directionLocation);
	void SetAmbientIntensity(GLfloat intensity) { ambientIntensity = intensity; }
	void SetDiffuseIntensity(GLfloat intensity) { diffuseIntensity = intensity; }

	GLfloat GetAmbientIntensity() const { return ambientIntensity; }
	GLfloat GetDiffuseIntensity() const { return diffuseIntensity; }
	~DirectionalLight();

private:
	glm::vec3 direction;
};

