/*
 * Copyright � 2014 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *     Wei Lin<wei.w.lin@intel.com>
 *     Yuting Yang<yuting.yang@intel.com>
 */

#pragma once

#include "cm_mem.h"

class CmDynamicArray {
 public:

	CmDynamicArray(const DWORD initSize);
	 CmDynamicArray();
	~CmDynamicArray(void);

	void *GetElement(const DWORD index);
	bool SetElement(const DWORD index, const void *element);

	DWORD GetSize(void);
	DWORD GetMaxSize(void);

	void Delete(void);

	DWORD GetFirstFreeIndex();
	bool SetElementIntoFreeSlot(const void *element);

	 CmDynamicArray & operator=(const CmDynamicArray & array);

 protected:

	void CreateArray(const DWORD size);
	void DeleteArray(void);

	bool IsValidIndex(const DWORD index);

	void **m_pArrayBuffer;

	DWORD m_UsedSize;
	DWORD m_ActualSize;

 private:

	 CmDynamicArray(const CmDynamicArray & other);

};
