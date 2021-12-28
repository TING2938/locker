# 下发配置需要有 config 元素，且命名空间固定，之后再加入 top 元素及具体的配置信息元素
from lxml import etree
from lxml.builder import ElementMaker
from ncclient import manager
from ncclient.transport import ssh

host = {
    'host': '10.227.6.254',
    'username': 'netdevops',
    'password': 'yt1111111111',
    'port': 830,
    'device_params': {'name': 'h3c'},
}

# 配置 asn
xml_bgp_asn_cfg = """
<config xmlns="urn:ietf:params:xml:ns:netconf:base:1.0">
<top xmlns="http://www.h3c.com/netconf/config:1.0">
<BGP>
 <Instances>
 <Instance>
 <Name></Name>
 <ASNumber>62333</ASNumber>
 </Instance>
 </Instances>
</BGP>
</top>
</config>"""
# 配置单播 ipv4 地址族
xml_bgp_familys_cfg="""
<config xmlns="urn:ietf:params:xml:ns:netconf:base:1.0">
<top xmlns="http://www.h3c.com/netconf/config:1.0">
<BGP>
<Familys>
<Family>
<Name></Name>
<VRF></VRF>
<Type>1</Type>
</Family>
</Familys>
</BGP>
</top>
</config>
"""
# 在单播 ipv4 地址族中宣告网段
xml_bgp_net_cfg = """
<config xmlns="urn:ietf:params:xml:ns:netconf:base:1.0">
<top xmlns="http://www.h3c.com/netconf/config:1.0">
<BGP>
 <Networks>
 <Network>
 <Name></Name>
 <VRF></VRF>
 <Family>1</Family>
 <IpAddress>1.1.1.1</IpAddress>
 <Mask>24</Mask>
 </Network>
 </Networks>
</BGP>
</top>
</config>
"""


conn = manager.connect(**host, hostkey_verify=False, look_for_keys=False)
conn.edit_config(target="running", config=xml_bgp_net_cfg)
conn.edit_config(target="running", config=xml_bgp_net_cfg)
conn.edit_config(target="running", config=xml_bgp_net_cfg)
