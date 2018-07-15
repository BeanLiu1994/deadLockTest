#pragma once

#include <thread>
#include <mutex>
// 暂时还没下muduo库 用stl代替一下

namespace muduo
{
	typedef std::unique_lock<std::mutex> MutexLockGuard;
	typedef std::mutex MutexLock;
	class Thread :public std::thread
	{
	public:
		template<typename T, typename ...Args>
		explicit Thread(T&& t, Args&&... args) :std::thread(std::forward<T>(t), std::forward<Args>(args)...) {}

		void start() {}//这里接不上，所以没实际作用
	};
}
#define sleep(x) std::this_thread::sleep_for(std::chrono::seconds(x))
#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))
