/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CHOICE_H_
#define _CHOICE_H_

#include "window.h"

class Choice : public Window {
  public:
    Choice(Window * parent, const rect_t & rect, const char * values, int16_t vmin, int16_t vmax,
           std::function<int16_t()> getValue, std::function<void(int16_t)> setValue, LcdFlags flags = 0
    );

    virtual void paint(BitmapBuffer * dc) override;

    virtual bool onTouchEnd(coord_t x, coord_t y) override;

  protected:
    const char * values;
    int16_t vmin;
    int16_t vmax;
    std::function<int16_t()> getValue;
    std::function<void(int16_t)> setValue;
    LcdFlags flags;
};

#endif // _CHOICE_H_