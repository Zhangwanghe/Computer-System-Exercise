static void place(void* bp, size_t size)
{
	int block_size = size;
	int available_size = GET_SIZE(HDRP(bp))
	int rest_size = available_size - size;
	if (rest_size < 2 * DSIZE)
	{
		block_size = available_size;
	}
	
	PUT(HDRP(bp), PACK(block_size, 1));
	PUT(FTRP(bp), PACK(block_size, 1));
	
	if (rest_size >= 2 * DSIZE)
	{
		bp = NEXT_BLKP(bp);
		PUT(HDRP(bp), PACK(rest_size, 1));
		PUT(FTRP(bp), PACK(rest_size, 1));
	}	
}