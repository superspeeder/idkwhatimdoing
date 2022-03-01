#include "kat/engine.hpp"
#include "kat/app.hpp"

namespace kat {

	Engine* s_Engine;

	Engine::Engine(const std::shared_ptr<ExecutionContext>& context) : m_ExecContext(context) {
		s_Engine = this;
	}

	Engine::~Engine() {
		s_Engine = nullptr;
	}

	void Engine::launch(std::shared_ptr<App> app) {
		m_RunnningApp = app;

		init();

		app->run();

		cleanup();
	}

	void Engine::init() {
		m_Logger = spdlog::stdout_color_mt("main");
		m_Logger->set_level(spdlog::level::debug);
		spdlog::set_default_logger(m_Logger);

		if (glfwInit()) {
			spdlog::info("Initialized GLFW {}", glfwGetVersionString());
		}
		else {
			spdlog::critical("Failed to initialize GLFW: {}", kat::getGlfwErrorString());
		}



		glfwSetMonitorCallback(kat::glfwcbks::monitor);
		glfwSetJoystickCallback(kat::glfwcbks::joystick);
	}

	void Engine::cleanup() {
		glfwTerminate();
		spdlog::info("Goodbye!");
		spdlog::shutdown();
	}

	std::string getGlfwErrorString() {
		const char* desc;
		int code = glfwGetError(&desc);

		if (code == GLFW_NO_ERROR) {
			return "No Error";
		}

		std::stringstream sstream;
		sstream << getGlfwErrorCodeName(code) << " (" << code << "): " << desc;
		return sstream.str();
	}

	std::string getGlfwErrorCodeName(int code) {
		switch (code) {
		case GLFW_NO_ERROR:
			return "No Error";
		case GLFW_NOT_INITIALIZED:
			return "Not Initialized";
		case GLFW_NO_CURRENT_CONTEXT:
			return "No Current Context";
		case GLFW_INVALID_ENUM:
			return "Invalid Enum";
		case GLFW_INVALID_VALUE:
			return "Invalid Value";
		case GLFW_OUT_OF_MEMORY:
			return "Out of Memory";
		case GLFW_API_UNAVAILABLE:
			return "API Unavailable";
		case GLFW_VERSION_UNAVAILABLE:
			return "Version Unavailable";
		case GLFW_PLATFORM_ERROR:
			return "Platform Error";
		case GLFW_FORMAT_UNAVAILABLE:
			return "Format Unavailable";
		case GLFW_NO_WINDOW_CONTEXT:
			return "No Window Context";
		default:
			return "Invalid Error Code";
		}
	}

}