#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include <vector>
using namespace std;

class SceneObject
{

public:
	SceneObject();
	virtual ~SceneObject();

	// onFunctions
	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw(aie::Renderer2D* renderer) {}
	
	// Draw and Update
	void draw(aie::Renderer2D* renderer);
	void update(float deltaTime);

	// Parents and Children
	SceneObject* getParent() const { return m_parent; }
	size_t childCount() const { return m_children.size(); }
	SceneObject* getChild(unsigned int index) const {
		return m_children[index];
	}
	void addChild(SceneObject* child);
	void removeChild(SceneObject* child);

	// Transforms
	const Matrix3& getLocalTransform() const {
		return m_localTransform;
	}
	const Matrix3& getGlobalTransform() {
		return m_globalTransform;
	}
	void updateTransform();

	void setPosition(float x, float y);
	void setRotate(float radians);
	void setScale(float width, float height);
	void translate(float x, float y);
	void rotate(float radians);
	void scale(float width, float height);

protected:
	
	// Parents and Children
	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;

	// Transforms
	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;

};

