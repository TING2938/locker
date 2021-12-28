import pexpect
import sys
import re 

child=pexpect.spawn('ssh root@10.227.4.32', encoding="utf-8")

child.expect('password:')

child.sendline('h3cai123')
child.expect('#')
a = child.before

child.sendline('ls /home')
child.expect('#')
a = child.before

print(a)

b = re.sub(r"\x1b.*?m", "", a, )

print(b)
