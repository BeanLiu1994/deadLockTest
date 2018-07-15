#pragma once

#include "muduo_bridge.h"
#include "Inventory.h"

class Inventory;

class Request
{
public:
	void process(Inventory& inventory);
	~Request();
	void print() const;
private:
	Inventory * recent_inventory;
	mutable muduo::MutexLock mutex_;
};
