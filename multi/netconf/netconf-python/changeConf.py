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

BASE_NS_1_0 = "urn:ietf:params:xml:ns:netconf:base:1.0"
H3C_CONFIG_1_0 = "http://www.h3c.com/netconf/base:1.0"
C = ElementMaker(namespace=BASE_NS_1_0, nsmap={None: BASE_NS_1_0})
E = ElementMaker(namespace=H3C_CONFIG_1_0, nsmap={None: H3C_CONFIG_1_0})

xml_ifcfg = C.config(
    E.top(
        E.Ifmgr(
            E.Interfaces(
                E.Interface(
                    E.IfIndex("2"),
                    E.Description("Configured by netconf"),
                    E.InetAddressIPV4("1.1.1.1"),
                    E.InetAddressIPV4Mask("23")
                )
            )
        )
    )
)
print(etree.tostring(xml_ifcfg))

# 将接口配置下发到 running 配置库中
conn = manager.connect(**host, hostkey_verify=False, look_for_keys=False)
ret = conn.edit_config(target="running", config=xml_ifcfg)
print(ret)
