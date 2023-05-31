#pragma once
unsigned COBSEncode(const unsigned char* src, unsigned len, unsigned char* dst, unsigned char r);
unsigned COBSDecode(const unsigned char* src, unsigned len, unsigned char* dst, unsigned char r);
bool check(const char* src, char r);