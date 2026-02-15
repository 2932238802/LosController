#pragma once

#include<string>
#include<fstream>
#include<mutex>
#include<sstream>
#include <iomanip>
#include <chrono>
#include <iostream>

enum class LogLevel {
	DEBUG,
	INFO,
	WARN,
	ERROR
};



class LosLog {
public:
	static LosLog& instance();

	void log(
		LogLevel level,
		const std::string& file,
		int line,
		const std::string& msg
		);
private:
	LosLog();
	~LosLog();
	LosLog(const LosLog& str) = delete;
	LosLog(LosLog&& str) = delete;

	std::fstream LOS_read;
	std::mutex mtx;
};

#define LOGI(msg) LosLog::instance().log(LogLevel::INFO,__FILE__,__LINE__,msg);
#define LOGE(msg) LosLog::instance().log(LogLevel::ERROR,__FILE__,__LINE__,msg);
#define LOGD(msg) LosLog::instance().log(LogLevel::DEBUG,__FILE__,__LINE__,msg);
#define LOGW(msg) LosLog::instance().log(LogLevel::WARN,__FILE__,__LINE__,msg);