#include "kat/engine.hpp"
#include "kat/app.hpp"

namespace kat {
	Engine::Engine(const std::shared_ptr<ExecutionContext>& context) : m_ExecContext(context) {
		
	}

	Engine::~Engine() {

	}

	void Engine::launch(std::shared_ptr<App> app) {
		m_RunnningApp = app;

		init();

		app->run();

		cleanup();
	}


}