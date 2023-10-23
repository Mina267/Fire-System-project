# define F_CPU 8000000
#include <util/delay.h>

#include "StdTypes.h"
#include "DIO_interface.h"
#include "KeyPad_interface.h"
#include "Keypad_Private.h"


void KEYPAD_Init(void)
{
	for (u8 RowIdx = 0; RowIdx < ROWS; RowIdx++)
	{
		DIO_WritePin(RowIdx_Array[RowIdx], HIGH);
	}
}

u8 KEYPAD_GetKey(void)
{
	u8 key = NO_KEY;
	for (u8 r = 0; r < ROWS; r++)
	{
		DIO_WritePin(RowIdx_Array[r], LOW);
		for (u8 c = 0; c < COLS; c++)
		{
			if (DIO_ReadPin(ColIdx_Array[c]) == LOW)
			{
				key = KeysArray[r][c];
				while(DIO_ReadPin(ColIdx_Array[c]) == LOW);
				DIO_WritePin(RowIdx_Array[r], HIGH);
				return key;
			}
		}
		DIO_WritePin(RowIdx_Array[r], HIGH);
	}
	return key;
}


