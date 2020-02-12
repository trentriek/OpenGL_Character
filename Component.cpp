#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#define TINYOBJLOADER_IMPLEMENTATION
//#include "tiny_obj_loader.h"

//#include "GLSL.h"
#include "MatrixStack.h"
#include "Component.h"
#include <map>


	void Component::draw(MatrixStack &MV, std::map<std::string, GLint>& unifIDs, int& indCount){
		MV.pushMatrix();
		MV.translate(TP);

		MV.rotate(JA.x, XROT);
		MV.rotate(JA.y, YROT);
		MV.rotate(JA.z, ZROT);
		for each ( Component* child in children)
		{
			child->draw(MV, unifIDs, indCount);
		}
		MV.translate(TJ);
		MV.scale(S);
		glUniformMatrix4fv(unifIDs["MV"], 1, GL_FALSE, value_ptr(MV.topMatrix()));
		glDrawArrays(GL_TRIANGLES, 0, indCount);
		MV.popMatrix();

	}

	Component* Component::get_active() {
		Component* temp = nullptr;
		if (isActive == true) return this;
		else {
			for each (Component * child in children) {
				temp = child->get_active();
			}
		}
			return temp;
	}


	Component::Component(std::string Name) {
		name = Name;
		XROT.x = 1.0f; XROT.y = 0.0f; XROT.z = 0.0f;
		YROT.y = 1.0f; YROT.x = 0.0f; YROT.z = 0.0f;
		ZROT.z = 1.0f; ZROT.x = 0.0f; ZROT.y = 0.0f;
		isActive = false;
	}


	Component::Component(Component* P = nullptr, std::string Name = " ") {
		parent = P;
		parent->add_child(this);
		name = Name;
		XROT.x = 1.0f; XROT.y = 0.0f; XROT.z = 0.0f;
		YROT.y = 1.0f; YROT.x = 0.0f; YROT.z = 0.0f;
		ZROT.z = 1.0f; ZROT.x = 0.0f; ZROT.y = 0.0f;
		isActive = false;
	}

	void Component::add_child(Component* TheChild) {
		children.push_back(TheChild);
	}

	Component* Component::get_child(std::string name) {

		for (int i = 0; i < children.size(); i++) {
			if (children[i]->name == name) return children[i];
		}
		return nullptr;
	}
	Component* Component::get_child(int index) {
		return children[index];
	}

	void Component::set_parent(Component* theParent) {
		parent = theParent;
	}

	Component* Component::get_parent() {
		return parent;
	}



