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
<edit-config>
	<target>
		<running/>
	</target>
	<config>
		<top xmlns="http://www.h3c.com/netconf/config:1.0">
			<Syslog>
				<LogBuffer>
					<BufferSize>512</BufferSize>
				</LogBuffer>
			</Syslog>
		</top>
	</config>
</edit-config>`

	reply, err := s.Exec(netconf.RawMethod(msg))
	if err != nil {
		panic(err)
	}
	fmt.Printf("Reply: %+v", reply)
}
