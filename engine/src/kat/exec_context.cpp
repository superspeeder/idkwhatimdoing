#include "kat/exec_context.hpp"

namespace kat {
	ExecutionContext::ExecutionContext(int argc, char** argv) {

	}

	ExecutionContext::~ExecutionContext() {

	}

	int ExecutionContext::getExitCode() {
		return m_ExitCode;
	}
}