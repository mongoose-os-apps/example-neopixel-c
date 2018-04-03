/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "common/cs_dbg.h"

#include "mgos_app.h"
#include "mgos_neopixel.h"
#include "mgos_timers.h"

#define PIN 5
#define NUM_PIXELS 12
#define ORDER MGOS_NEOPIXEL_ORDER_GRB

struct mgos_neopixel *s_strip = NULL;

static void pixel_timer_cb(void *arg) {
  static int s_cnt = 0;
  int pixel = (s_cnt++) % NUM_PIXELS;
  int r = s_cnt % 255, g = (s_cnt * 2) % 255, b = s_cnt * s_cnt % 255;
  mgos_neopixel_clear(s_strip);
  mgos_neopixel_set(s_strip, pixel, r, g, b);
  mgos_neopixel_show(s_strip);
  LOG(LL_INFO, ("%3d %3d %3d %3d", pixel, r, g, b));
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  s_strip = mgos_neopixel_create(PIN, NUM_PIXELS, ORDER);
  mgos_set_timer(150 /* ms */, MGOS_TIMER_REPEAT, pixel_timer_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
