// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>
#define HASH_SIZE 8

extern "C" __declspec(dllexport)

void __stdcall compute_hash(char* command, unsigned char* prev_hash, unsigned char* output) {
	unsigned char* data = (unsigned char*)command;
	int len = strlen(command);
	unsigned long long h = 0;

	// Store prev_hash in h to perform operations
	for (int i = 0; i < HASH_SIZE; i++) {
		h = (h << 8) | prev_hash[i];
	}

	// Mix data
	for (int i = 0; i < len; i++) {
		h ^= data[i];
		h = (h << 5) | (h >> (64 - 5));
		h &= ~(h >> 1);
		h |= (h << 1);
	}

	h = ~h;

	// Output
	for (int i = HASH_SIZE - 1; i >= 0; i--) {
		output[i] = (unsigned char)(h & 0xFF); // extracting one byte from the right of h and inserting that at the left-most position of the output array
		h >>= 8; // shifting the right-most 8 bits to the right, essentially deleting them, putting the next byte into place
	}
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

