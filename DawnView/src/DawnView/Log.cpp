#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DawnView {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	// Creates the two loggers
	void Log::Init()
	{
		// Set the logging format, see more in the spdlog repo
		// %T: timestamp
		// %n: name of the log
		// %v: actual log message
		// %^ %$: start and end color range
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// create color multi threaded logger
		s_CoreLogger = spdlog::stdout_color_mt("DAWNVIEW");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
