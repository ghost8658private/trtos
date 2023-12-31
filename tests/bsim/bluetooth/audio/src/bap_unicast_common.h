/**
 * Common functions and helpers for unicast audio BSIM audio tests
 *
 * Copyright (c) 2021-2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_TEST_BSIM_BT_AUDIO_TEST_UNICAST_COMMON_
#define ZEPHYR_TEST_BSIM_BT_AUDIO_TEST_UNICAST_COMMON_

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/audio/audio.h>

void print_hex(const uint8_t *ptr, size_t len);
void print_codec_cap(const struct bt_audio_codec_cap *codec_cap);
void print_codec_cfg(const struct bt_audio_codec_cfg *codec_cfg);
void print_qos(const struct bt_audio_codec_qos *qos);

#endif /* ZEPHYR_TEST_BSIM_BT_AUDIO_TEST_UNICAST_COMMON_ */
