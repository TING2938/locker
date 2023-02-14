#include <stdio.h>
#include <string.h>
#include "zlib.h"

int main()
{
    char* data = "this is a gzip test from NinGoo.net";
    gzFile fp  = NULL;
    fp         = gzopen("test_out.gz", "wb");
    gzwrite(fp, data, strlen(data));
    gzclose(fp);
}
