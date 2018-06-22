/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef _SHLIBPP_VOCAB_
#define _SHLIBPP_VOCAB_

#include <string>

namespace shlibpp {
    class Vocab;

    // We need a macro for efficient switching.
    constexpr int32_t VOCAB(char a, char b = 0, char c = 0, char d = 0)  { return ((((int32_t)(d))<<24)+(((int32_t)(c))<<16)+(((int32_t)(b))<<8)+((int32_t)(a))); }
}


class shlibpp::Vocab {
public:

    static int encode(const std::string& s) {
        char a = '\0';
        char b = '\0';
        char c = '\0';
        char d = '\0';
        if (s.length()>=1) {
            a = s[0];
            if (s.length()>=2) {
                b = s[1];
                if (s.length()>=3) {
                    c = s[2];
                    if (s.length()>=4) {
                        d = s[3];
                    }
                }
            }
        }
        return VOCAB(a,b,c,d);
    }


    static std::string decode(int code) {
        std::string s;
        for (int i=0; i<4; i++) {
            int ch = code%256;
            if (ch>0) {
                s += ((char)ch);
            }
            code /= 256;
        }
        return s;
    }

};

#endif // VOCAB_H
