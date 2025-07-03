#pragma once

#include <Core/Base.h>
#include <Platform/PlatformAPI.h>

#include <string>
#include <format>
#include <chrono>


namespace MUE
{
	enum class LogLevel
	{
		FATAL,
		ERR,
        WARN,
		INFO,
		DEBUG,
		TRACE
	};

	class Logger
	{
	public:
		template<typename ...Args>
        inline static void Log(LogLevel level, const std::string& SidePrefix, const std::string& msg, Args&&... arguments)
        {

            const std::string Colors[6] =
            {
                "\033[1;31m",
                "\033[1;91m",
                "\033[1;35m",
                "\033[1;32m",
                "\033[1;33m",
                "\033[1;36m" 
            };

            const std::string Prefix[6] =
            {
                "FATAL",
                "ERR",
                "WARN",
                "INFO",
                "DEBUG",
                "TRACE"
            };

            const std::string Reset = "\033[0m"; 

            auto now = std::chrono::system_clock::now();
            auto time_t = std::chrono::system_clock::to_time_t(now);
            auto tm = *std::localtime(&time_t);

            std::string timeString = std::format("{:02d}:{:02d}:{:02d}", tm.tm_hour, tm.tm_min, tm.tm_sec);

            std::string formattedMessage;
            if constexpr (sizeof...(arguments) > 0)
                formattedMessage = std::vformat(msg, std::make_format_args(arguments...));
            else
                formattedMessage = msg;

            std::string finalMessage = Colors[(int)level] + "[" + timeString + " " + Prefix[(int)level] + " " + SidePrefix + "] " + Reset + formattedMessage + "\n";
            PlatformAPI::WriteToConsole(finalMessage);
        }
	};
}

#define MFATAL_CORE(msg,...) MUE::Logger::Log(MUE::LogLevel::FATAL,"Core",msg,##__VA_ARGS__) 
#define MERROR_CORE(msg,...) MUE::Logger::Log(MUE::LogLevel::ERR,"Core",msg,##__VA_ARGS__) 
#define MWARN_CORE(msg,...) MUE::Logger::Log(MUE::LogLevel::WARN,"Core",msg,##__VA_ARGS__) 
#define MINFO_CORE(msg,...) MUE::Logger::Log(MUE::LogLevel::INFO,"Core",msg,##__VA_ARGS__) 

#define MFATAL_APP(msg,...) MUE::Logger::Log(MUE::LogLevel::FATAL,"App",msg,##__VA_ARGS__) 
#define MERROR_APP(msg,...) MUE::Logger::Log(MUE::LogLevel::ERR,"App",msg,##__VA_ARGS__) 
#define MWARN_APP(msg,...)  MUE::Logger::Log(MUE::LogLevel::WARN,"App",msg,##__VA_ARGS__) 
#define MINFO_APP(msg,...)  MUE::Logger::Log(MUE::LogLevel::INFO,"App",msg,##__VA_ARGS__) 

#ifdef MUE_DEBUG
#define MDEBUG_CORE(msg,...) MUE::Logger::Log(MUE::LogLevel::DEBUG,"App",msg,##__VA_ARGS__) 
#define MTRACE_CORE(msg,...) MUE::Logger::Log(MUE::LogLevel::TRACE,"App",msg,##__VA_ARGS__) 

#define MDEBUG_APP(msg,...) MUE::Logger::Log(MUE::LogLevel::DEBUG,"App",msg,##__VA_ARGS__) 
#define MTRACE_APP(msg,...) MUE::Logger::Log(MUE::LogLevel::TRACE,"App",msg,##__VA_ARGS__) 
#else
#define MWARN_CORE(msg,...) 
#define MINFO_CORE(msg,...) 
#define MDEBUG_APP(msg,...)  
#define MTRACE_APP(msg,...)  
#endif