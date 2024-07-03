#include <stdint.h>
#include <stdio.h>

struct t_test {
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

/* 定义结构体变量tt，并把它放置在0x20001000地址位置 */
static struct t_test tt __attribute__((section(".ARM.__at_0x20001000")));

int main(void) {
    struct t_test *p_s = &tt;
    uint8_t *p_char = (uint8_t *)(&tt);
    uint16_t *p_short = (uint16_t *)(&tt);
    uint32_t *p_int = (uint32_t *)(&tt);
    uint32_t p, d;

    tt.a = 0x234A8B3E;
    tt.b = 0x191C9834;
    tt.c = 0x2790BC4E;

    p = (uint32_t)(p_s + 1);
    // 在此语句运行完后，p 等于什么值？
    // 解释：p_s 指向 tt，p_s+1 指向 tt 的下一个 t_test 结构体（如果有的话）的地址。
	  // 因为 tt 是在地址 0x20001000 处定义的，所以 p 的值将是 0x20001000 + sizeof(struct t_test)，即为0x20001060。

    p = (uint32_t)((&tt.a) + 1);
    // 在此语句运行完后，p 等于什么值？
    // 解释：&tt.a 指向 tt 的第一个成员变量 tt.a，(&tt.a)+1 指向 tt.a 的下一个 uint32_t（如果有的话）的地址。
    // 因为 tt.a 在 tt 的起始地址 0x20001000 处定义，所以 p 的值将是 0x20001000 + sizeof(uint32_t)，即为0x20001020。

    p = ((uint32_t)p_s) + 4;
    // 在此语句运行完后，p 等于什么值？
    // 解释：p_s 指向 tt，将 p_s 转换为 uint32_t 类型指针后，其值是 tt 的起始地址 0x20001000。
    // 加上 4 后，p 的值将是 0x20001000 + 4 = 0x20001004。

    d = *((uint32_t *)p);
    // 在此语句运行完后，d 等于什么值？
    // 解释：p 指向 0x20001004，d 将指向 p 地址处的无符号整数值，即为0x4A8B3E19。

    d = *(p_char + 5);
    // 在此语句运行完后，d 等于什么值？
    // 解释：p_char 指向 tt 的起始地址，加上 5 个字节后，指向 tt.b 的第 2 个字节。
    // 所以 d 的值为0x1C983427。

    d = *(p_short + 3);
    // 在此语句运行完后，d 等于什么值？
    // 解释：p_short 指向 tt 的起始地址，加上 3 个 uint16_t 后，指向 tt.b的第 3 个字节。
    // 所以 d 的值为0x98342790。

    d = *(p_int + 2);
    // 在此语句运行完后，d 等于什么值？
    // 解释：p_int 指向 tt 的起始地址，加上 2 个 uint32_t 后，指向 tt.c 的第 1 个字节。
    // 所以 d 的值将是 tt.c 的值，即为0x2790BC4E。

    return 0;
}