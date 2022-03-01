#pragma once

#include <memory>

#include "kat/engine.hpp"
#include "kat/window.hpp"

namespace kat {
	class App {
	public:

		App(Engine* engine);

		void run();

	private:

		Engine* m_Engine;
	};
}