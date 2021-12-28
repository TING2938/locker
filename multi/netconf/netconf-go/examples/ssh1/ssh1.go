// Go NETCONF Client - Example
//
// Copyright (c) 2013-2018, Juniper Networks, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package main

import (
	"fmt"
	"log"

	"github.com/Juniper/go-netconf/netconf"
	"golang.org/x/crypto/ssh"
)

const (
	user   = "netdevops"
	passwd = "yt1111111111"
	ip     = "10.227.6.254"
)

func main() {
	sshConfig := &ssh.ClientConfig{
		User:            user,
		Auth:            []ssh.AuthMethod{ssh.Password(passwd)},
		HostKeyCallback: ssh.InsecureIgnoreHostKey(),
	}
	s, err := netconf.DialSSH(ip, sshConfig)
	if err != nil {
		log.Fatal(err)
	}
	defer s.Close()

	fmt.Println(s.SessionID)

	msg := `
<get>
	<filter type="subtree">
		<top xmlns="http://www.h3c.com/netconf/data:1.0">
			<Ifmgr>
				<Interfaces>
					<Interface>
						<Name></Name>
						<InetAddressIPV4></InetAddressIPV4>
						<AdminStatus></AdminStatus>
					</Interface>
				</Interfaces>
			</Ifmgr>
		</top>
	</filter>
</get>`

	// Sends raw XML
	reply, err := s.Exec(netconf.RawMethod(msg))
	if err != nil {
		panic(err)
	}
	fmt.Printf("Reply: %+v", reply)
}
