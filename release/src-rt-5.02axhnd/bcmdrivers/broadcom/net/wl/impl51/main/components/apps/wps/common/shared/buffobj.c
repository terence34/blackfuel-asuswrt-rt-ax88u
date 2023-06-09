/*
 * Buffer Object
 *
 * Copyright 2018 Broadcom
 *
 * This program is the proprietary software of Broadcom and/or
 * its licensors, and may only be used, duplicated, modified or distributed
 * pursuant to the terms and conditions of a separate, written license
 * agreement executed between you and Broadcom (an "Authorized License").
 * Except as set forth in an Authorized License, Broadcom grants no license
 * (express or implied), right to use, or waiver of any kind with respect to
 * the Software, and Broadcom expressly reserves all rights in and to the
 * Software and all intellectual property rights therein.  IF YOU HAVE NO
 * AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE IN ANY
 * WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE ALL USE OF
 * THE SOFTWARE.
 *
 * Except as expressly set forth in the Authorized License,
 *
 * 1. This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof, and to
 * use this information only in connection with your use of Broadcom
 * integrated circuit products.
 *
 * 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED
 * "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR
 * OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 *
 * 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL,
 * SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR
 * IN ANY WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
 * IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii)
 * ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF
 * OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY
 * NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
 *
 * $Id: buffobj.c 470127 2014-04-14 04:14:51Z $
 */

#include <stdlib.h>
#include <wpscommon.h>
#include <wpserror.h>
#include <wpstlvbase.h>
#include <tutrace.h>

/* Buffer class methods */

uint8 *buffobj_Pos(BufferObj *b) { return b->pCurrent;}
uint32 buffobj_Length(BufferObj *b) { return b->m_dataLength;}
uint32 buffobj_Remaining(BufferObj *b) { return b->m_bufferLength - b->m_currentLength;}
uint8 *buffobj_GetBuf(BufferObj *b) { return b->pBase; }

char *
alloc_init(int size)
{
	char *p = (char *)calloc(1, size);

	return p;
}

int
buffobj_lock(BufferObj *b)
{
	/* is it locked ?  */
	if (b->magic == BUF_ALLOC_MAGIC)
		return 0;
	b->magic = BUF_ALLOC_MAGIC;
	return 1;
}

int
buffobj_unlock(BufferObj *b)
{
	/* is it locked ?  */
	if (b->magic != BUF_ALLOC_MAGIC)
		return 0;
	b->magic = ~BUF_ALLOC_MAGIC;
	return 1;
}

void
buffobj_dserial(BufferObj * b, uint8 *ptr, uint32 length)
{
	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj Adavance : tryng to use a non-allocated object !!!\n");
		return;
	}
	/* if we allocated the memory : free it */
	if (b->m_allocated && b->pBase)
		free(b->pBase);
	b->pBase = ptr;
	b->pCurrent = ptr;
	b->m_bufferLength = length;
	b->m_currentLength = 0;
	b->m_dataLength = length;
	b->m_allocated = false;
}

BufferObj *
buffobj_new()
{
	BufferObj *b = (BufferObj *)malloc(sizeof(BufferObj));
	if (!b) {
		TUTRACE((TUTRACE_ERR, "buffobj_new: memory allocation error\n"));
		return NULL;
	}

	b->m_bufferLength = BUF_BLOCK_SIZE;
	b->pBase = (uint8 *) malloc(b->m_bufferLength);
	if (!b->pBase) {
		TUTRACE((TUTRACE_ERR, "buffobj_new: memory allocation error\n"));
		free(b);
		return NULL;
	}

	b->m_currentLength = 0;
	b->m_dataLength = 0;
	b->m_allocated = true;
	b->pCurrent = b->pBase;
	b->magic = BUF_ALLOC_MAGIC;
	return b;
}

BufferObj *
buffobj_setbuf(uint8 *buf, int len)
{
	BufferObj *b = (BufferObj *)malloc(sizeof(BufferObj));
	if (!b) {
		TUTRACE((TUTRACE_ERR, "buffobj_new: memory allocation error\n"));
		return NULL;
	}

	b->m_bufferLength = len;
	b->pBase = buf;
	b->m_currentLength = 0;
	b->m_dataLength = 0;
	b->m_allocated = false;
	b->pCurrent = b->pBase;
	b->magic = BUF_ALLOC_MAGIC;
	return b;
}

void
buffobj_del(BufferObj *b)
{
	if (!b)
		return;

	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj del : tryng to use a non-allocated object !!!\n");
		return;
	}

	if ((b->m_allocated) && (b->pBase)) {
		free(b->pBase);
		/* just in case we try to re-use this guy before re-allocating :-) */
		b->magic = 0;
	}

	free(b);
}

uint8 *
buffobj_Advance(BufferObj *b, uint32 offset)
{
	/*
	 * Advance the pCurrent pointer. update current length
	 * Don't disturb the dataLength variable here
	 */
	if (b->m_currentLength+offset > b->m_bufferLength)
		return NULL;

	b->m_currentLength += offset;
	b->pCurrent += offset;
	return b->pCurrent;
}

uint8 *
buffobj_Append(BufferObj *b, uint32 length, uint8 *pBuff)
{

	if ((pBuff == NULL) || (length == 0))
		return b->pCurrent;

	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj Append : tryng to use a non-allocated object !!!\n");
		return NULL;
	}

	/*
	 * IMPORTANT: if this buffer was not allocated by us
	 * and points to an existing buffer, then we should be extremely careful
	 * how much data we append
	 */
	if ((!b->m_allocated) && (buffobj_Remaining(b) < length)) {
		uint8 *ptr;
		TUTRACE((TUTRACE_INFO, "TLV: Explicitly allocating memory\n"));

		/*
		 * now we need to explicitly allocate memory.
		 * while in the process, allocate some extra mem
		 */
		ptr = (uint8 *) malloc(b->m_bufferLength+BUF_BLOCK_SIZE);
		if (!ptr) {
			TUTRACE((TUTRACE_ERR, "buffobj_Append: memory allocation error\n"));
			return NULL;
		}

		/* copy the existing data */
		if (b->m_currentLength)
			memcpy(ptr, b->pBase, b->m_currentLength);

		/* update internal variables */
		b->pBase = ptr;
		b->pCurrent = b->pBase + b->m_currentLength;
		b->m_bufferLength += BUF_BLOCK_SIZE;
		b->m_allocated = true;
	}

	if (b->m_bufferLength - b->m_currentLength < length) {
		/* the available bufferspace isn't sufficient for the current data */

		/*
		 * determine how much more space we need, either the block size or
		 * the data length, whichever is bigger
		 */
		int tempLen = (length > BUF_BLOCK_SIZE) ? length : BUF_BLOCK_SIZE;

		/* Allocate more memory */
		b->pBase = (uint8 *)realloc(b->pBase, b->m_currentLength+tempLen);
		if (!b->pBase) {
			TUTRACE((TUTRACE_ERR, "buffobj_Append: memory allocation error\n"));
			return NULL;
		}
		b->m_bufferLength = b->m_currentLength+tempLen;
		b->pCurrent = b->pBase + b->m_currentLength;
	}

	memcpy(b->pCurrent, pBuff, length);
	b->pCurrent += length;
	b->m_currentLength += length;

	/*
	 * the data length needs to be updated based on the pointer locations,
	 * since the pointers could have been moved around (using rewind and
	 * advance) before the call to append.
	 */
	b->m_dataLength = (uint32)(b->pCurrent - b->pBase);

	return b->pCurrent-length; /* return the location at which the data was copied */
}

uint8 *
buffobj_Set(BufferObj *b, uint8 *pos)
{
	int32 offset;

	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj Set : tryng to use a non-allocated object !!!\n");
		return NULL;
	}
	if (pos < b->pBase) {
		TUTRACE((TUTRACE_ERR, "buffobj_Set: Buffer underflow\n"));
		return NULL;
	}
	if (pos > b->pBase + b->m_bufferLength) {
		TUTRACE((TUTRACE_ERR, "buffobj_Set: Buffer overflow\n"));
		return NULL;
	}

	/*
	 * Perform operation as if pos lies before pCurrent.
	 * If it lies after pCurrent, offset will be negative, so we'll be OK
	 */
	offset = (int32)(b->pCurrent-pos);
	b->pCurrent = pos;
	b->m_currentLength -= offset;
	return b->pCurrent;
}

uint16
buffobj_NextType(BufferObj *b)
{
	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj NextType : tryng to use a non-allocated object !!!\n");
		return 0;
	}
	if (buffobj_Remaining(b) < 4) /* at least size of the header */
		return 0;
	return WpsNtohs(b->pCurrent);
}

uint8 *
buffobj_Reset(BufferObj *b)
{
	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj Reset : tryng to use a non-allocated object !!!\n");
		return NULL;
	}
	b->pCurrent = b->pBase;
	b->m_currentLength = b->m_dataLength = 0;
	return b->pBase;
}

uint8 *
buffobj_RewindLength(BufferObj *b, uint32 length)
{
	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj RewindLength : tryng to use a non-allocated object !!!\n");
		return NULL;
	}
	if (length > b->m_currentLength) {
		TUTRACE((TUTRACE_ERR, "buffobj_Rewind: Buffer underflow\n"));
		return NULL;
	}

	b->m_currentLength -= length;
	b->pCurrent = b->pBase + b->m_currentLength;
	return b->pCurrent;
}

uint8 *
buffobj_Rewind(BufferObj *b)
{
	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj Rewind : tryng to use a non-allocated object !!!\n");
		return NULL;
	}
	b->m_currentLength = 0;
	b->pCurrent = b->pBase;
	return b->pCurrent;
}

/* WSC 2.0 */
uint8
buffobj_NextSubId(BufferObj *b)
{
	if (b->magic != BUF_ALLOC_MAGIC) {
		printf("BuffObj NextSubId : tryng to use a non-allocated object !!!\n");
		return 0;
	}

	if (buffobj_Remaining(b) < 2) /* at least size of the header */
		return 0;

	return *b->pCurrent;
}

uint8 *
buffobj_Write(BufferObj *b, uint32 length, uint8 *pBuff)
{
	if (pBuff == NULL || length == 0 || buffobj_Remaining(b) < length)
		return NULL;

	memcpy(b->pCurrent, pBuff, length);
	return b->pCurrent; /* return the location at which the data was write */
}
