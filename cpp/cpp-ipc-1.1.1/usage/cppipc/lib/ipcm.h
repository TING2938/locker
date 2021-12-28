/*****************************************************************************
 * NOTICE:
 * Copyright (c) 2018 Cambricon, Inc. All rights reserved.
 * All Rights Reserved.
 * Property of Cambricon, Inc.
 * This software is made available solely pursuant to the
 * terms of a Cambricon license agreement which governs its use.
 ****************************************************************************/

#ifndef _UAPI_IPCM_H
#define _UAPI_IPCM_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef DRV_TEST_PRT
#define DRV_TEST_PRT printf
#endif

#define RPMSG_DEV_NAME_MAXLEN	32

	/* physical size */
#define MAX_RPMSG_BUF_SIZE	(1024)
/* MAX_RPMSG_BUF_SIZE - package_hdr(34) - cmsg_hdr(16) */
/* user available size */
#define MAX_BUF_LEN	(MAX_RPMSG_BUF_SIZE - 64)

	enum rpmsg_role {
		RPMSG_CLIENT = 0,
		RPMSG_SERVER = 1,
	};

	/*!
	 * @brief Structure returned during ipcm_create_endpoint
	 *
	 * @param fd Opened file descriptor for the local rpmsg endpoint device
	 * @param endpt Local Endpoint address used for receiving messages
	 */
	struct ipcm_dev {
		int fd;
		int endpt;
	};

	/*!
	 *  @brief      Function to create and access a rpmsg endpoint device for a
	 *              given rpmsg device
	 *
	 *              This function is to be used to open a communication channel
	 *              in a Linux application with any rpmsg device that is bound to
	 *              the Linux kernel rpmsg_chrdev driver (rpmsg_char.ko module).
	 *
	 *              The function returns a pointer to a ipcm_dev structure
	 *              with the file descriptor and local end-point address filled in
	 *              and usable by an application for a given remoteproc, rpmsg
	 *              device (identified by published name from remote processor) and
	 *              the remote end-point address used by the rpmsg device.
	 *
	 *              The opened file descriptor can be used with regular file
	 *              operations such as select(), read() and write() functions to
	 *              wait, receive and send messages to the rpmsg device on the
	 *              remote processor. The messages are received on the local
	 *              end-point address.
	 *
	 *  @param      id remoteproc enum value identifying a remote processor.
	 *						 (related to arm:vf_id/host:card_id)
	 *                       Value is a local id used by the library
	 *
	 *  @param      endpt_addr rpmsg rpmsg_role == server ? local : remote end-point address for the rpmsg device
	 *                           to open. Valid value is mandatory
	 *
	 *  @param      eptdev_name Name used to create and identify the local endpoint
	 *                          device. Needs to be unique across all the Linux
	 *                          applications. The maximum length for the
	 *                          eptdev_name is RPMSG_DEV_NAME_MAXLEN (32 bytes)
	 *
	 *  @param      flags Flags used to open the local end-point device
	 *
	 *  @ret        A valid pointer to a struct ipcm_dev on success, NULL on
	 *              failures
	 *
	 *  @sa         ipcm_destroy_endpoint
	 */
	struct ipcm_dev* ipcm_create_endpoint(int id, int endpt_addr, const char* eptdev_name,
		int flags, enum rpmsg_role role);

	/*!
	 *  @brief      Function to close and delete a previously created local endpoint
	 *              device with ipcm_create_endpoint
	 *
	 *              Once this function is called, any regular file operations on the
	 *              underlying fd cannot be used. The pointer value is not modified
	 *              within the function, but is no longer valid after a successful
	 *              return.
	 *
	 *  @param      rcdev  Pointer to the previously created struct ipcm_dev. The
	 *                     handle will be unusable with any of the regular file
	 *                     operation functions after a success
	 *
	 *  @ret        0 on success, a negative value on failure
	 *
	 *  @sa         ipcm_create_endpoint
	 */
	int ipcm_destroy_endpoint(struct ipcm_dev* rcdev);

	/*!
	 *  @brief      Function to initialize the library
	 *
	 *              This function initializes the library after performing SoC
	 *              detection and corresponding initialization. This needs to be
	 *              invoked before being able to use any other function. This only
	 *              needs to be invoked once in an application, there is no reference
	 *              counting. The function also registers signal handlers optionally
	 *              (if none are installed prior) to perform any cleanup of stale
	 *              rpmsg endpoint devices during abnormal termination of
	 *              applications.
	 *
	 *  @param      soc_name  Name of the SoC family to be used for manual detection
	 *                        if kernel doesn't support a socbus device for a
	 *                        particular SoC and auto detection fails. Preferred
	 *                        usage is just to pass NULL
	 *
	 *  @ret        0 on success, 1 if already invoked previously, and a negative
	 *              value on failure
	 *
	 *  @sa         ipcm_lib_exit
	 */
	int ipcm_lib_init(void);

	/*!
	 *  @brief      Function to finalize the library
	 *
	 *              This function finalizes and performs all the de-initialization
	 *              and any cleanup on the library. This is the last function that
	 *              needs to be invoked after all usage is done as part of the
	 *              application's cleanup. This only need to be invoked once in an
	 *              application, there is no reference counting. The function also
	 *              needs to be invoked in any application's signal handlers to
	 *              perform the necessary cleanup of stale rpmsg endpoint devices.
	 *
	 *  @ret        None
	 *
	 *  @sa         ipcm_lib_init
	 */
	void ipcm_lib_exit(void);


	/*
	 * ipcm setup the signal handlers only if applications have not
	 * registered one themselves. Any new signal handler registration in
	 * the application after ipcm_lib_init() is invoked will install the
	 * application's handlers. Applications are responsible for calling
	 * ipcm_signal_handler() in their signal handlers (if present) to send hup
	 * and ensure proper cleanup
	 */
	void ipcm_signal_handler(void);

	/*
	 * sync api without msg header
	 * aka. raw api
	 */
	int ipcm_send_packet(struct ipcm_dev* rcdev, void* msg, int len);

	int ipcm_recv_packet(struct ipcm_dev* rcdev, void* reply_msg, int len);

	/*
	 * async api with msg header
	 *
	 */

	 /* default is async mode */
	void ipcm_set_async_mode(struct ipcm_dev* rcdev);
	void ipcm_set_sync_mode(struct ipcm_dev* rcdev);
	typedef int (*ipcm_rx_cb_t)(struct ipcm_dev* rcdev, unsigned long packet_id,
		void* message, int message_size, unsigned int src);
	void ipcm_set_rx_callback(struct ipcm_dev* rcdev, ipcm_rx_cb_t rx_callback);

	/* send msg non-blocking/async, when response arrive will call the callback, remote use ipcm_send_response() to reply */
	typedef int (*request_cb_t)(void* data, void* req, int req_sz, void* resp, int resp_sz);
	int ipcm_send_request_with_callback(struct ipcm_dev* rcdev,
		void* message, int message_size, void* cb_data,
		request_cb_t callback);

	/* send msg blocking/sync, blocked until the response arrived, remote use ipcm_send_response() to reply */
	int ipcm_send_request_with_response(struct ipcm_dev* rcdev,
		void* message, int message_size,
		void* response, int* real_size, int response_size);

	/* send msg without response */
	int ipcm_send_message(struct ipcm_dev* rcdev,
		void* message, int message_size);

	/* send response to the related package_id */
	int ipcm_send_response(struct ipcm_dev* rcdev, unsigned long packet_id,
		void* response, int response_size);

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
		char* func_name;
		rpmsg_rpc_service_t func;
	};

	void ipcm_set_rpc_services(struct ipcm_dev* rcdev, struct rpmsg_rpc_service_set* functions);
	/* caller must make sure the sizeof */
	int ipcm_rpc_call(struct ipcm_dev* rcdev, char* fn_name,
		void* in, int in_size,
		void* out, int* real_size, int out_size);

	int ipcm_rpc_call_timeout(struct ipcm_dev* rcdev, char* fn_name,
		void* in, int in_size,
		void* out, int* real_size, int out_size, int time_out_ms);

	typedef int (*ipcm_hup_handler_t)(struct ipcm_dev* rcdev, void* priv, unsigned int src);
	void ipcm_set_hup_handler(struct ipcm_dev* rcdev, ipcm_hup_handler_t hup_handler, void* priv);

	/* port api */
	/* server are always in async mode */
	/* _name MUST be unique */
	struct ipcm_dev* ipcm_create_port(const char* _name, int id, int server_port, enum rpmsg_role role);
	int ipcm_destroy_port(struct ipcm_dev* rcdev);
	/* client api */
	int ipcm_send_message_by_port(struct ipcm_dev* rcdev, void* message, int message_size);
	/* server api when client in sync/block mode, client use ipcm_recv_packet() to wait msg */
	int ipcm_send_packet_to_port(struct ipcm_dev* rcdev, void* msg, int len, int port);
	/* server api when client in async/non-block mode */
	int ipcm_send_message_to_port(struct ipcm_dev* rcdev, void* msg, int len, int port);
	int ipcm_send_response_to_port(struct ipcm_dev* rcdev, unsigned long packet_id,
		void* response, int response_size, int port);

	int ipcm_recv_packet_break(struct ipcm_dev* rcdev);

	/* client only */
	/* file xfer api */
	int ipcm_send_file(int id, char* local_path, char* remote_path);
	int ipcm_recv_file(int id, const char* remote_path, char* local_path);
	/* cmd exec api */
	int ipcm_exec_cmd(int card, const char* cmd, ipcm_rx_cb_t rx_callback);

#if defined(__cplusplus)
}
#endif

#endif /* _UAPI_IPCM_H */
