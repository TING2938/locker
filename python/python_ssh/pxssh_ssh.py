#!/usr/bin/python

import pexpect

 # ['#', '$', '>', '\$', '>>>']
PROMPT = '#'

def send_command(child, cmd):
    child.sendline(cmd)
    child.expect(PROMPT)
    print(child.before)

def createChildSession(host, username, password):
    command = 'ssh '+username+'@'+host
    child = pexpect.spawn(command, encoding="utf-8")
    child.expect('[p|P]assword:')
    send_command(child, password)
    return child


def main():

    host = "10.227.4.32"
    username = "root"
    password = "h3cai123"

    session = createChildSession(host, username, password)
    send_command(session, "cd /home/yeting/work/learn/python_ssh")
    send_command(session, "pwd > output.dat")
    send_command(session, "ls")

if __name__ == '__main__':
    main()
