#pragma once

namespace kat {

	/**
	 * @brief Context of the current instance of KatEngine
	 * 
	 * This will contain all the "global" state for the engine which is appropriate to place in the instance of the Engine class.
	 * Only create <b>one</b> of these, as creating multiple most likely will break all engine-objects created using this execution context,
	 * as well as causing undefined behavior or crashes/seg faults.
	 * 
	 * An execution context <b>will</b> be created by the generated entry point, which will instantiate your application.
	*/
	class ExecutionContext {

	};
}