#include "Inventory.h"

#include <set>
#include <iostream>

void Inventory::add(Request* req)
{
	muduo::MutexLockGuard lock(mutex_);
	requests_.insert(req);
}
void Inventory::remove(Request* req)
{
	muduo::MutexLockGuard lock(mutex_);
	requests_.erase(req);
}
void Inventory::printAll() const
{
	muduo::MutexLockGuard lock(mutex_);
	sleep(1);
	for (auto&m : requests_)
		m->print();
	std::cout << "Inventory::printAll() unlocked" << std::endl;
}