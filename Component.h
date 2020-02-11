#pragma once
#ifndef COMPONENT.h
#define COMPONENT.h

#include <glm/glm.hpp>
#include "MatrixStack.h"
#include <list>
//#include <vector>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

class Component {

public:
	Component() {}
	Component(Component* P);
	bool isActive;
	glm::vec3 TP; //translation wrt parent
	glm::vec3 JA; // joint angles
	glm::vec3 TJ; //translation wrt joint 
	glm::vec3 S; //scaling factors
	void draw(MatrixStack &MV);
	Component* get_child();
	void add_child(Component* theChild);

	Component* get_parent();
	void set_parent(Component* theParent);

private:
	std::list<Component*> children;
	Component* parent;


};

#endif // !COMPONENT.h
