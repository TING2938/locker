# 导入 ncclient 相关模块，用于使用 NETCONF 协议连接设备
from ncclient import manager

# 根据网络环境，构建包含设备信息的字典
host = {
    'host': '10.227.6.254',
    'username': 'netdevops',
    'password': 'yt1111111111',
    'port': 830,
    'device_params': {'name': 'h3c'},
}

get_all_iface = """
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
"""

# 对于 ssh 协议，连接设备时会先保存对端的 key，并从本机查找并验证，使用以下两个 False 的参数来跳过检查
conn = manager.connect(**host, hostkey_verify=False, look_for_keys=False)
# 获取设备所有接口的名称、IP地址、状态
ret = conn.get(('subtree', get_all_iface))
print(ret)

