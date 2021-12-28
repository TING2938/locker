#pragma once

#include <libipc/ipc.h>
#include <atomic>
#include <iostream>
#include <thread>

class MyIPC 
{
public:
	MyIPC(std::string name, unsigned mode) : channel(name.c_str(), mode)
	{}



	ipc::channel channel;
};