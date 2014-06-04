/*
 * Author: Yevgeniy Kiveisha <yevgeniy.kiveisha@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once

#include <string>
#include <maa/aio.h>
#include <maa/gpio.h>
#include <maa/pwm.h>
#include <sys/time.h>

#define HIGH                   1
#define LOW                    0

#define MAX_PERIOD             7968
#define TRIGGER_PULSE          10

namespace upm {

class HCSR04 {
    public:
        HCSR04 (uint8_t triggerPin, uint8_t echoPin, void (*fptr)(void));
        ~HCSR04 ();
        int getDistance ();
        void ackEdgeDetected ();

        uint8_t m_doWork;

        std::string name()
        {
            return m_name;
        }

    private:
        maa_pwm_context     m_pwmTriggerCtx;
        maa_gpio_context    m_echoPinCtx;

        uint8_t m_waitEcho;
        long    m_RisingTimeStamp;
        long    m_FallingTimeStamp;
        uint8_t m_InterruptCounter;

        std::string         m_name;
};

}
