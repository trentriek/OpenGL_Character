#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <glm/glm.hpp>
#include "MatrixStack.h"
#include <vector>
#include <map>
#include <string>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

class Component {

	 

public:
	Component(std::string Name);
	Component(Component* P, std::string Name);
	bool isActive;
	std::string name;
	glm::vec3 TP; //translation wrt parent
	glm::vec3 JA; // joint angles
	glm::vec3 TJ; //translation wrt joint 
	glm::vec3 S; //scaling factors

	void draw(MatrixStack& MV, std::map<std::string, GLint>& unifIDs, int& indCount);

	Component* get_active();

	Component* get_child(std::string name);
	Component* get_child(int index);
	void add_child(Component* theChild);

	Component* get_parent();
	void set_parent(Component* theParent);

private:
	std::vector<Component*> children;
	Component* parent;
	glm::vec3 XROT;
	glm::vec3 YROT;
	glm::vec3 ZROT;


};

#endif // !COMPONENT.h
