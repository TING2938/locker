
#pragma once

#include <libipc/ipc.h>

#ifndef DRV_TEST_PRT
#define DRV_TEST_PRT printf
#endif

#define RPMSG_DEV_NAME_MAXLEN	32

/* physical size */
#define MAX_RPMSG_BUF_SIZE	(1024)
/* MAX_RPMSG_BUF_SIZE - package_hdr(34) - cmsg_hdr(16) */
/* user available size */
#define MAX_BUF_LEN	(MAX_RPMSG_BUF_SIZE - 64)

enum class ipcm_packet_type {
	RPMSG_IPC_PACKET_TYPE_REQUEST,
	RPMSG_IPC_PACKET_TYPE_RESPONSE,
	RPMSG_IPC_PACKET_TYPE_MESSAGE,
	RPMSG_IPC_PACKET_TYPE_RPC,
	RPMSG_IPC_PACKET_TYPE_RPC_RET,
	RPMSG_IPC_PACKET_TYPE_HUP,
	RPMSG_IPC_PACKET_TYPE_MAX,
};

enum class rpmsg_role {
	RPMSG_CLIENT = 0,
	RPMSG_SERVER = 1,
};

struct ipcm_device_header {
	/* enum: ipcm_packet_type */
	ipcm_packet_type packet_type;
	uint32_t resp_size;
	/* rpc function name hash only if packet_type is RPMSG_IPC_PACKET_TYPE_RPC */
	unsigned long long func_name;
};

/* rpc call */
#ifndef DEF_CALLBACK_PAIR
#define DEF_CALLBACK_PAIR(fn) \
	{#fn, fn}
#endif

#ifndef DEF_CALLBACK_PAIR_END
#define DEF_CALLBACK_PAIR_END \
	{NULL, NULL}
#endif

#define IPCM_DECLARE_CALLBACK_FUNC(fn) \
static int fn(void *, int, void *, int *, int)

typedef int (*rpmsg_rpc_service_t)(void* in_msg, int in_len, void* out_msg, int* out_len, int vf_id);

struct rpmsg_rpc_service_set {
	const char* func_name;
	rpmsg_rpc_service_t func;
};

struct ipcm_dev
{
	ipc::channel* channel;
	struct rpmsg_rpc_service_set* services;
};

ipcm_dev* ipcm_create_endpoint(int id, int endpt_addr, const char* eptdev_name, int flags, rpmsg_role role);

void ipcm_set_rpc_services(struct ipcm_dev* rcdev, struct rpmsg_rpc_service_set* functions);

unsigned long long ipcm_string_hash(const char* name);

int ipcm_rpc_call(ipcm_dev* rcdev, const char* fn_name, void* in, int in_size, void* out, int* real_size, int out_size);


