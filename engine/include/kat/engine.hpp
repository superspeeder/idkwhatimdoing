#pragma once

#include "kat/fwd.hpp"

#include "kat/exec_context.hpp"


#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <eventpp/eventdispatcher.h>
#include <eventpp/utilities/argumentadapter.h>

namespace kat {

	class BaseEvent {
	};

	using KatEventDispatcher = eventpp::EventDispatcher<std::type_index, void(const BaseEvent&)>;

	template<typename T>
	concept applike = std::is_base_of_v<App, T> && std::is_constructible_v<T,Engine*>;

	class Engine {
	private:

		KatEventDispatcher m_Dispatcher;

	public:

		Engine(const std::shared_ptr<ExecutionContext>& context);
		~Engine();

		template<applike A>
		inline void launch() {
			std::shared_ptr<A> app_ = std::make_shared<A>(this);
			launch(std::dynamic_pointer_cast<App>(app_));
		};

		void launch(std::shared_ptr<App> app);

		template<typename T>
		inline void addListener(void(*func)(const T&)) {
			m_Dispatcher.appendListener(std::type_index(typeid(T)), eventpp::argumentAdapter(func));
		};

		template<typename T, typename C>
		inline void addListener(C& object, void(C::* func)(const T&)) {
			m_Dispatcher.appendListener(std::type_index(typeid(T)), eventpp::argumentAdapter([&](const T& a) { std::invoke(func, object, a); }));
		};

		template<typename T>
		inline void addListener(std::function<void(const T&)> func) {
			m_Dispatcher.appendListener(std::type_index(typeid(T)), eventpp::argumentAdapter(func));
		};

		template<typename T>
		inline void dispatch(const T& event) {
			m_Dispatcher.dispatch(std::type_index(typeid(T)), event);
		};

	private:

		void init();
		void cleanup();

		std::shared_ptr<App> m_RunnningApp;

		std::shared_ptr<ExecutionContext> m_ExecContext;

		std::shared_ptr<spdlog::logger> m_Logger;

	};


	extern Engine* s_Engine;

	inline Engine& engine() {
		return *s_Engine;
	};

	std::string getGlfwErrorString();
	std::string getGlfwErrorCodeName(int code);
}