#include <iostream>
using namespace std;
void reverse(unsigned char* s) {
    int len = strlen((char*)s);
    unsigned char tmp[1024];
    unsigned char* p1 = s;
   
    unsigned char* p2 = tmp + len;
    *p2-- = 0;
    while (*p1) {
        if (*p1 < 0x80) {
            *p2-- = *p1++;
        }
        else {
            *(p2 - 1) = *p1++;
            *p2 = *p1++;
            p2 -= 2;
        }
    }
    for (int i = 0; i < len; i++) {
        s[i] = tmp[i];
    }
}
int main()
{
    unsigned char str[] = "jack call dave";
    reverse(str);
    printf("%s\n", str);
}

