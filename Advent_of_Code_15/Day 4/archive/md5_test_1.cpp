#include <openssl/md5.h>
unsigned char *MD5(const unsigned char *d, unsigned long n, unsigned char *md);

int main(){
    unsigned char result[MD5_DIGEST_LENGTH];
    const unsigned char* str;
    str = (unsigned char*)"hello";
    unsigned int long_size = 100;
    MD5(str,long_size,result);
}