// ----------------------------------------------------------------------------
// Copyright 2017-2019 ARM Ltd.
//  
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//  
//     http://www.apache.org/licenses/LICENSE-2.0
//  
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------

#ifndef __SDA_MALLOC_H__
#define __SDA_MALLOC_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef SDA_MEM_PROFILER_ENABLED

/**
* Allocate the requested amount of bytes and log heap statistics.
* - It is assumed FCC running in a single thread (no thread safety)
* - This function does not allows re-entrance
*
* @param size The amount of bytes to allocate on the heap memory
*
* @returns
*     If allocation succeeded - a valid pointer to the beginning of the allocated heap memory
*     If allocation failed - a NULL pointer will be returned
*/
void *sda_malloc(size_t size);

/**
* Free the heap bytes followed by the given pointer and log heap statistics.
* - It is assumed FCC running in a single thread (no thread safety)
* - This function does not allows re-entrance
*
* @param ptr A pointer to the beginning of bytes allocated on the heap memory
*/
void sda_free(void *ptr);

/**
* Prints heap statistics results.
* - Usually user will call this function at program end.
*/
void sda_display_mem_usage_results(void);

#else

#define sda_malloc(size) malloc( (size) )
#define sda_free(ptr) free( (ptr) )
#define sda_display_mem_usage_results()

#endif // SDA_MEM_PROFILER_ENABLED

#ifdef __cplusplus
}
#endif

#endif // __SDA_MALLOC_H__
