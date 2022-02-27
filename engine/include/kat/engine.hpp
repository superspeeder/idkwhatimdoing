#pragma once

#include "kat/fwd.hpp"

#include "kat/exec_context.hpp"

namespace kat {

	template<typename T>
	concept applike = std::is_base_of_v<App, T> && requires (const std::shared_ptr<Engine>&e) { T::T(e); };

	class Engine {
	public:

		Engine(const std::shared_ptr<ExecutionContext>& context);
		~Engine();

		template<applike A>
		inline void launch() {
			std::shared_ptr<A> app_ = std::make_shared<A>(this);
			launch(std::dynamic_pointer_cast<App>(app_));
		};

		void launch(std::shared_ptr<App> app);


	private:

		void init();
		void cleanup();

		std::shared_ptr<App> m_RunnningApp;

		std::shared_ptr<ExecutionContext> m_ExecContext;


	};
}