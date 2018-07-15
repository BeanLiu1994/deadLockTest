#include "Request.h"


void Request::process(Inventory& inventory)
{
	muduo::MutexLockGuard lock(mutex_);
	recent_inventory = &inventory;
	recent_inventory->add(this);
}
Request::~Request()
{
	muduo::MutexLockGuard lock(mutex_);
	sleep(1);
	recent_inventory->remove(this);
}
void Request::print() const
{
	muduo::MutexLockGuard lock(mutex_);
	// todo: ´òÓ¡ÇëÇóÄÚÈİ
}