#pragma once
#include "Texture.h"
#include "Renderer2D.h"
#include "SceneObject.h"

class SpriteObject : public SceneObject
{
public:
	SpriteObject();
	SpriteObject(const char* filename) { load(filename); }
	virtual ~SpriteObject() { delete m_texture; }

	//virtual void onDraw(aie::Renderer2D* renderer) {}

	bool load(const char* filename);
	
	// Not sure where this goes?
	virtual void SpriteObject::onDraw(aie::Renderer2D* renderer);

	//virtual void onDraw(aie::Renderer2D* renderer);


protected:

	aie::Texture* m_texture = nullptr;
	// Transforms
	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;

};

