/**
 * The MIT License (MIT)
 *
 * Author: Junjie Chen (595355940@qq.com)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "Grove_Sunlight_Sensor/SI114X.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}


#define  si114x     (*(SI114X   *)self->module)
void * operator new(size_t, void *);

extern "C"{
    void common_hal_si114x_construct(abstract_module_t * self){
        self->module = new(m_new_obj(si114x)) SI114X();
        si114x.WriteByte(SI114X_COMMAND, SI114X_RESET);
        delay(100);
        si114x.Begin();
    }
    void common_hal_si114x_deinit(abstract_module_t * self){
        si114x.~SI114X();
    }
    uint16_t common_hal_si114x_ReadVisible(abstract_module_t * self){
        return si114x.ReadVisible();
    }
    uint16_t common_hal_si114x_ReadIR(abstract_module_t * self){
        return si114x.ReadIR();
    }
    uint16_t common_hal_si114x_ReadUV(abstract_module_t * self){
        return si114x.ReadUV();
    }  

}