import base64
import pickle
import sys


def ToBase64(file, txt):
    with open(file, 'rb') as fileObj:
        image_data = fileObj.read()
        base64_data = base64.b64encode(image_data)
        fout = open(txt, 'wb')
        pickle.dump(base64_data.decode(), fout)
        fout.close()


def ToFile(txt, file):
    with open(txt, 'rb') as fileObj:
        base64_data = pickle.load(fileObj)
        ori_image_data = base64.b64decode(base64_data)
        fout = open(file, 'wb')
        fout.write(ori_image_data)
        fout.close()


if len(sys.argv) < 4:
    print("""
usage: 
    load fileName outputName
    save fileName outputName
    """)
    sys.exit(0)

if sys.argv[1] == "load":
    ToFile(sys.argv[2], sys.argv[3])  # base64编码转换为二进制文件
elif sys.argv[1] == "save":
    ToBase64(sys.argv[2], sys.argv[3])  # 文件转换为base64
