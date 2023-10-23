

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


#define COLS			4
#define ROWS			4

#define NO_KEY			'`'
	
void KEYPAD_Init(void);
u8 KEYPAD_GetKey(void);


#endif /* KEYPAD_INTERFACE_H_ */


