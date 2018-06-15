#include "SceneObject.h"
#include <assert.h>
#include <iostream>
//#include <algorithm>



SceneObject::SceneObject()
{
}


SceneObject::~SceneObject()
{
	// Detatch from parent
	if (m_parent != nullptr)
		m_parent->removeChild(this);

	// Remove all children
	for (auto child : m_children)
		child->m_parent = nullptr;
}

void SceneObject::addChild(SceneObject* child) {
	// Make sure it doesn't have a parent already
	assert(child->m_parent == nullptr);
	// Assign "this" as parent
	child->m_parent = this;
	// Add new child to collection
	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject* child) {
	// Find the child in the collection
	auto iter = std::find(m_children.begin(),
					m_children.end(), child);

	// If found, remove it
	if (iter != m_children.end()) {
		m_children.erase(iter);
		// Also unassaign parent
		child->m_parent = nullptr;
	}

}