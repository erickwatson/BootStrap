#pragma once
#include <vector>
using namespace std;

class SceneObject
{

public:
	SceneObject();
	virtual ~SceneObject();



	SceneObject* getParent() const { return m_parent; }

	size_t childCount() const { return m_children.size(); }

	SceneObject* getChild(unsigned int index) const {
		return m_children[index];
	}

	void addChild(SceneObject* child);
	void removeChild(SceneObject* child);

protected:

	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;

};

