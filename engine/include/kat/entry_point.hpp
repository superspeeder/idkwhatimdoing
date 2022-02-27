#ifdef KAT_ENTRY_POINT_DEFINED
#error Entry point already defined, this is bad
#endif

#define KAT_ENTRY_POINT_DEFINED

#ifndef KAT_APP_CLASS
#error "Application class not defined. Cannot generate an entry point"
#endif

#include "kat/exec_context.hpp"

/**
 * 
 * The generated entry point has 1 required configuration macro.
 * 
 * Required: The KAT_APP_CLASS macro must be defined as the name of the class the generated entry point should run.
 * 
 * Applications will make use of various virtual functions for configuration during the App::run function.
 * 
 * An outline of the generated entry point:
 *	1. Create ExecutionContext, passing in command line arguments
 *  2. call ExecutionContext::setupEngine(ExecutionContext)
 *  3. call Engine::launch_app<KAT_APP_CLASS>();
 */



int main(int argc, char** argv) {

	
}