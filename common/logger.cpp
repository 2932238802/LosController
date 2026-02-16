#include "logger.h"

/// <summary>
/// 26_2_15
/// 单例模式的开启
/// </summary>
/// <returns></returns>
LosLog& LosLog::instance()
{
	static LosLog log;
	return log;
}



/// <summary>
/// 26_2_15
/// - 日志输出的一般函数
/// </summary>
/// <param name="level"></param>
/// <param name="file"></param>
/// <param name="line"></param>
/// <param name="msg"></param>
void LosLog::log(
	LogLevel level,
	const std::string& file,
	int line,
	const std::string& msg
	) 
{
	std::lock_guard<std::mutex> lockGuard(mtx);

	// 初始化 levelToStr 字符串
	std::string levelToStr; 
	switch (level)
	{
	case(LogLevel::DEBUG):
	{
		levelToStr = "DEBUG";
		break;

	}
	case(LogLevel::ERROR):
	{
		levelToStr = "ERROR";
		break;
	}
	case(LogLevel::INFO):
	{
		levelToStr = "INFO";
		break;
	}
	case(LogLevel::WARN):
	{
		levelToStr = "WARN";
		break;
	}
	}

	std::string fileName(file);
	size_t pos = fileName.find_last_of("\\/");
	if (pos != std::string::npos)
	{
		fileName = file.substr(pos+1, -1);
	}

	std::string fullMsg = "[" + fileName + ":" + std::to_string(line) + "]" +
		"[" + levelToStr + "]: " +
		msg;

	std::cout << fullMsg << std::endl;
	if (LOS_read.is_open())
	{
		LOS_read << fullMsg;
		LOS_read.flush();
	}
}




/// <summary>
/// 26_2_15
/// - 默认构造函数
/// </summary>
LosLog::LosLog() {
	LOS_read.open("app.log", std::ios::app);
}



/// <summary>
/// 26_2_15
/// - 析构函数
/// </summary>
LosLog::~LosLog()
{
	if(LOS_read.is_open())
		LOS_read.close();
}
