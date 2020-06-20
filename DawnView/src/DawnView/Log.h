#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace DawnView {

	class DV_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define DV_CORE_TRACE(...) ::DawnView::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DV_CORE_INFO(...)  ::DawnView::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DV_CORE_WARN(...)  ::DawnView::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DV_CORE_ERROR(...) ::DawnView::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DV_CORE_FATAL(...) ::DawnView::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core log macros
#define DV_TRACE(...) ::DawnView::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DV_INFO(...)  ::DawnView::Log::GetClientLogger()->info(__VA_ARGS__)
#define DV_WARN(...)  ::DawnView::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DV_ERROR(...) ::DawnView::Log::GetClientLogger()->error(__VA_ARGS__)
#define DV_FATAL(...) ::DawnView::Log::GetClientLogger()->fatal(__VA_ARGS__)