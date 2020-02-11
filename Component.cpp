#include "Component.h"



	void Component::draw(MatrixStack &MV){
		
	}

	Component::Component(Component* P) {
		parent = P;
		parent->add_child(this);
	}

	void Component::add_child(Component* TheChild) {
		//Component* i = children.begin();
		//std::iterator<Component*> h = children.begin();
	}



