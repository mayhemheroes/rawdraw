#include <stdint.h>
#include <stdio.h>
#include <climits>

#define CNFG_IMPLEMENTATION

#include "rawdraw_sf.h"
#include <fuzzer/FuzzedDataProvider.h>

// necessary for compilation to succeed
void HandleKey(int keycode, int bDown) {}
void HandleButton(int x, int y, int button, int bDown) {}
void HandleMotion(int x, int y, int mask) {}
void HandleDestroy() {}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString(1000);
    int textsize = provider.ConsumeIntegral<int>();

    int x, y;
    CNFGGetTextExtents(str.c_str(), &x, &y, textsize);
    return 0;
}
