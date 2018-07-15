#pragma once

#include <thread>
#include <mutex>
// ��ʱ��û��muduo�� ��stl����һ��

namespace muduo
{
	typedef std::unique_lock<std::mutex> MutexLockGuard;
	typedef std::mutex MutexLock;
	class Thread :public std::thread
	{
	public:
		template<typename T, typename ...Args>
		explicit Thread(T&& t, Args&&... args) :std::thread(std::forward<T>(t), std::forward<Args>(args)...) {}

		void start() {}//����Ӳ��ϣ�����ûʵ������
	};
}
#define sleep(x) std::this_thread::sleep_for(std::chrono::seconds(x))
#define usleep(x) std::this_thread::sleep_for(std::chrono::microseconds(x))
