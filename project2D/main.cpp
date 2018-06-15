#include "My2DApp.h"

int main() {
	
	// allocation
	auto app = new My2DApp();
	// change to Myapp2d

	// initialise and loop
	app->run("AIE", 1280, 720, false);
		
	// deallocation
	delete app;

	return 0;
}