#include "Engine.h"

int main() {
	Engine* engine = new Engine();

	int exitcode = engine->run();

	delete engine;

	return 0;
}