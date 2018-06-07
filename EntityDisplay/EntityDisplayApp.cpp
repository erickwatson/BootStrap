#include "EntityDisplayApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Windows.h>

EntityDisplayApp::EntityDisplayApp() {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	setBackgroundColour(1, 1, 1);

	// In application 2 - A user of the named shared memory
	// gain access to a named shared memory block that already exists
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

	m_entities.resize(10);
	return true;
}

void EntityDisplayApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	
	CloseHandle(m_fileHandle);
}

void EntityDisplayApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// map the memory from the shared block to a pointer we can manipulate
	Entity* data = (Entity*)MapViewOfFile(m_fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * 10);
	for (int i = 0; i < 10; i++)
		m_entities[i] = data[i];
}

void EntityDisplayApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw entities
	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}