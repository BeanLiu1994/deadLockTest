#include <iostream>
#include "Inventory.h"
#include "Request.h"
using namespace std;


void threadFunc(Inventory& inventory)
{
	Request* req = new Request;
	req->process(inventory);
	delete req;
}
int main()
{
	Inventory inventory;
	muduo::Thread t([&]() {threadFunc(inventory); });
	t.start();
	usleep(100 * 1000);
	inventory.printAll();
	t.join();
	return 0;
}