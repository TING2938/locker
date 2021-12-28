#include "rpclib.h"
#include <iostream>

IPCM_DECLARE_CALLBACK_FUNC(rpc_print);
static struct rpmsg_rpc_service_set service_table[] = {
		DEF_CALLBACK_PAIR(rpc_print),
		DEF_CALLBACK_PAIR_END,
};
#define COMMU_SERVICE_TABLE service_table

struct rpc_print_info 
{
	int a;
	double b;
};

int rpc_print(void* in_msg, int in_len, void* out_msg, int* out_len, int vf_id)
{
	std::cout << "call rpc_print func ......\n";
	rpc_print_info* info = (rpc_print_info*)in_msg;
	std::cout << "a: " << info->a << ", b: " << info->b << "\n";
	((rpc_print_info*)out_msg)->a = info->a + 1;
	((rpc_print_info*)out_msg)->b = info->b + 1.2;
	*out_len = sizeof(rpc_print_info);
	std::cout << "call rpc_print func finished\n";
	return 12;
}

int main(int argc, char** argv)
{
	std::string mode{ argv[1] };
	if (mode == "server")
	{
		auto rcdev = ipcm_create_endpoint(0, 0x32fd, "testrpmsg", 0, rpmsg_role::RPMSG_SERVER);
		ipcm_set_rpc_services(rcdev, COMMU_SERVICE_TABLE);
		while (true)
		{
		}
	}
	else
	{
		auto rcdev = ipcm_create_endpoint(0, 0x32fd, "testrpmsg", 0, rpmsg_role::RPMSG_CLIENT);
		rpc_print_info info, out_info;
		int real_len;
		info.a = 102;
		info.b = 3.21;
		ipcm_rpc_call(rcdev, "rpc_print", (void*)(&info), sizeof(rpc_print_info), &out_info, &real_len, sizeof(rpc_print_info));
		std::cout << "a: " << out_info.a << ", b: " << out_info.b << "\n";
	}
	
}