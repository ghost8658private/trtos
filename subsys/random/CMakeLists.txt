# SPDX-License-Identifier: Apache-2.0

if (CONFIG_ENTROPY_DEVICE_RANDOM_GENERATOR OR
    CONFIG_TIMER_RANDOM_GENERATOR OR
    CONFIG_XOSHIRO_RANDOM_GENERATOR)
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/random/rand32.h)
zephyr_library()
zephyr_library_sources_ifdef(CONFIG_USERSPACE           rand32_handlers.c)
endif()

if (CONFIG_TIMER_RANDOM_GENERATOR)
  message(WARNING "
    Warning: CONFIG_TIMER_RANDOM_GENERATOR is not a truly random generator.
    This capability is not secure and it is provided for testing purposes only.
    Use it carefully.")
endif()

# XOROSHIRO builds the XOSHIRO implementation because a Kconfig choice cannot
# select another choice as a means of deprecating the symbol. Swapping out the
# implementation lets out-of-tree users still build until the symbol is removed.
zephyr_library_sources_ifdef(CONFIG_TIMER_RANDOM_GENERATOR          rand32_timer.c)
zephyr_library_sources_ifdef(CONFIG_XOROSHIRO_RANDOM_GENERATOR      rand32_xoshiro128.c)
zephyr_library_sources_ifdef(CONFIG_XOSHIRO_RANDOM_GENERATOR        rand32_xoshiro128.c)
zephyr_library_sources_ifdef(CONFIG_CTR_DRBG_CSPRNG_GENERATOR       rand32_ctr_drbg.c)

if (CONFIG_ENTROPY_DEVICE_RANDOM_GENERATOR OR CONFIG_HARDWARE_DEVICE_CS_GENERATOR)
zephyr_library_sources(rand32_entropy_device.c)
endif()

if (CONFIG_CTR_DRBG_CSPRNG_GENERATOR)
zephyr_library_link_libraries_ifdef(CONFIG_MBEDTLS mbedTLS)
endif()
