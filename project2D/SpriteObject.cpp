#include "SpriteObject.h"




SpriteObject::SpriteObject()
{
}


//SpriteObject::~SpriteObject()
//{
//}

bool SpriteObject::load(const char* filename) {
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	return m_texture != nullptr;
}

// Not sure where this goes?
void SpriteObject::onDraw(aie::Renderer2D* renderer) {
	renderer->drawSpriteTransformed3x3(m_texture,
		(float*)&m_globalTransform);
}

