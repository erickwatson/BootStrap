#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <string>
#include <Vector2.h>
#include "SpriteObject.h"
#include "Timer.h"

using namespace std;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	//float m_timer;

	Timer m_start;

	string m_playerName;
	float m_reactionTime = 0;
	float m_timer = 0; // Required to be Float to track fractions of a second
	const unsigned int timerMin = 2;
	const unsigned int timerMax = 6;

	

	int m_gameState; // Game States: Starting (Enter Name), Counting Down, "Fire" (Counting reaction time), Game Over (Win or Lose)

	//m_timer -= deltaTime;
	//if (m_timer <= 0);// Do stuff

	SpriteObject m_tank, m_turret;
	
};