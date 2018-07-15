#pragma once
#include "muduo_bridge.h"
#include "Request.h"

#include <set>
#include <iostream>
class Request;

class Inventory
{
public:
	void add(Request* req);
	void remove(Request* req);
	void printAll() const;
private:
	mutable muduo::MutexLock mutex_;
	std::set<Request*> requests_;
};
