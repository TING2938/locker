#include "rpclib.h"
#include <thread>

unsigned long long ipcm_string_hash(const char* name)
{
	unsigned long long base = 131;
	unsigned long long mod = 212370440130137957ll;
	unsigned long long ans = 0;
	int len = (int)strlen(name);
	int i = 0;

	for (i = 0; i < len; i++)
		ans = (ans * base + (unsigned long long)name[i]) % mod;

	return ans;
}

void hander_receive_data(ipcm_dev* rcdev, void* data, int len)
{
	ipcm_device_header* hdr = (ipcm_device_header*)data;
	void* message = (void*)(&hdr[1]);
	int message_len = len - sizeof(*hdr);
	int ret;
	char response[MAX_BUF_LEN];
	int response_size = 0;

	if (hdr->packet_type == ipcm_packet_type::RPMSG_IPC_PACKET_TYPE_RPC)
	{
		rpmsg_rpc_service_set* service;
		bool found = false;
		for (service = rcdev->services; service->func_name; service++) {
			if (ipcm_string_hash(service->func_name) == hdr->func_name) {
				found = true;
				break;
			}
		}
		if (found) {
			ret = service->func(message, message_len, response, &response_size, 0);
		}
		rcdev->channel->send(ipc::buff_t(response, response_size));
	}
}

ipcm_dev* ipcm_create_endpoint(int id, int endpt_addr, const char* eptdev_name, int flags, rpmsg_role role)
{
	ipcm_dev* rcdev = new ipcm_dev;
	rcdev->channel = new ipc::channel(eptdev_name, ipc::receiver | ipc::sender);
	if (role == rpmsg_role::RPMSG_SERVER)
	{
		std::thread([&] {
			while (1)
			{
				auto buf = rcdev->channel->recv();
				std::thread(hander_receive_data, rcdev, buf.data(), int(buf.size())).join();
			}
			}).detach();
	}
	return rcdev;
}

int ipcm_rpc_call(ipcm_dev* rcdev, const char* fn_name, void* in, int in_size, void* out, int* real_size, int out_size)
{
	ipcm_device_header* header = nullptr;
	int tot_size = in_size + sizeof(header);
	header = (ipcm_device_header*)malloc(tot_size);
	if (header == nullptr) {
		return 1;
	}

	header->func_name = ipcm_string_hash(fn_name);
	header->packet_type = ipcm_packet_type::RPMSG_IPC_PACKET_TYPE_RPC;
	header->resp_size = out_size;

	void* dst = (void*)(&header[1]);
	memcpy(dst, in, in_size);
	while (rcdev->channel->send(ipc::buff_t(header, tot_size))) {
		rcdev->channel->wait_for_recv(2);
	}
	auto resp = rcdev->channel->recv();
	*real_size = int(resp.size());
	memcpy(out, resp.data(), *real_size);
	return *real_size;
}

// for server 
void ipcm_set_rpc_services(ipcm_dev* rcdev, rpmsg_rpc_service_set* functions)
{
	rcdev->services = functions;
}

