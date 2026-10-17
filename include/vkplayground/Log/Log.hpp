#ifndef VK_PLAYGROUND_LOG_LOG_HPP
#define VK_PLAYGROUND_LOG_LOG_HPP

#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#define LOG_TRACE(...)                                                                                                 \
  spdlog::log(spdlog::source_loc{__FILE__, __LINE__, static_cast<const char*>(__FUNCTION__)}, spdlog::level::trace,    \
              __VA_ARGS__)
#define LOG_DEBUG(...)                                                                                                 \
  spdlog::log(spdlog::source_loc{__FILE__, __LINE__, static_cast<const char*>(__FUNCTION__)}, spdlog::level::debug,    \
              __VA_ARGS__)
#define LOG_INFO(...)                                                                                                  \
  spdlog::log(spdlog::source_loc{__FILE__, __LINE__, static_cast<const char*>(__FUNCTION__)}, spdlog::level::info,     \
              __VA_ARGS__)
#define LOG_WARN(...)                                                                                                  \
  spdlog::log(spdlog::source_loc{__FILE__, __LINE__, static_cast<const char*>(__FUNCTION__)}, spdlog::level::warn,     \
              __VA_ARGS__)
#define LOG_ERROR(...)                                                                                                 \
  spdlog::log(spdlog::source_loc{__FILE__, __LINE__, static_cast<const char*>(__FUNCTION__)}, spdlog::level::err,      \
              __VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::log(spdlog::source_loc{__FILE__, __LINE__, static_cast<const

#endif
