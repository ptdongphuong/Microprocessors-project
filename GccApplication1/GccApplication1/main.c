#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>


// 1. Font chân 5x8 LCD GRAPHIC

const uint8_t font5x8[] = {
    0x00, 0x00, 0x00, 0x00, 0x00,   // sp
    0x00, 0x00, 0x2f, 0x00, 0x00,   // !
    0x00, 0x07, 0x00, 0x07, 0x00,   // "
    0x14, 0x7f, 0x14, 0x7f, 0x14,   // #
    0x24, 0x2a, 0x7f, 0x2a, 0x12,   // $
    0x23, 0x13, 0x08, 0x64, 0x62,   // %
    0x36, 0x49, 0x55, 0x22, 0x50,   // &
    0x00, 0x05, 0x03, 0x00, 0x00,   // '
    0x00, 0x1c, 0x22, 0x41, 0x00,   // (
    0x00, 0x41, 0x22, 0x1c, 0x00,   // )
    0x14, 0x08, 0x3e, 0x08, 0x14,   // *
    0x08, 0x08, 0x3e, 0x08, 0x08,   // +
    0x00, 0x50, 0x30, 0x00, 0x00,   // ,
    0x08, 0x08, 0x08, 0x08, 0x08,   // -
    0x00, 0x60, 0x60, 0x00, 0x00,   // .
    0x20, 0x10, 0x08, 0x04, 0x02,   // /
    0x3e, 0x51, 0x49, 0x45, 0x3e,   // 0
    0x00, 0x42, 0x7f, 0x40, 0x00,   // 1
    0x42, 0x61, 0x51, 0x49, 0x46,   // 2
    0x21, 0x41, 0x45, 0x4b, 0x31,   // 3
    0x18, 0x14, 0x12, 0x7f, 0x10,   // 4
    0x27, 0x45, 0x45, 0x45, 0x39,   // 5
    0x3c, 0x4a, 0x49, 0x49, 0x30,   // 6
    0x01, 0x71, 0x09, 0x05, 0x03,   // 7
    0x36, 0x49, 0x49, 0x49, 0x36,   // 8
    0x06, 0x49, 0x49, 0x29, 0x1e,   // 9
    0x00, 0x36, 0x36, 0x00, 0x00,   // :
    0x00, 0x56, 0x36, 0x00, 0x00,   // ;
    0x08, 0x14, 0x22, 0x41, 0x00,   // <
    0x14, 0x14, 0x14, 0x14, 0x14,   // =
    0x00, 0x41, 0x22, 0x14, 0x08,   // >
    0x02, 0x01, 0x51, 0x09, 0x06,   // ?
    0x32, 0x49, 0x79, 0x41, 0x3e,   // @
    0x7e, 0x11, 0x11, 0x11, 0x7e,   // A
    0x7f, 0x49, 0x49, 0x49, 0x36,   // B
    0x3e, 0x41, 0x41, 0x41, 0x22,   // C
    0x7f, 0x41, 0x41, 0x22, 0x1c,   // D
    0x7f, 0x49, 0x49, 0x49, 0x41,   // E
    0x7f, 0x09, 0x09, 0x09, 0x01,   // F
    0x3e, 0x41, 0x49, 0x49, 0x7a,   // G
    0x7f, 0x08, 0x08, 0x08, 0x7f,   // H
    0x00, 0x41, 0x7f, 0x41, 0x00,   // I
    0x20, 0x40, 0x41, 0x3f, 0x01,   // J
    0x7f, 0x08, 0x14, 0x22, 0x41,   // K
    0x7f, 0x40, 0x40, 0x40, 0x40,   // L
    0x7f, 0x02, 0x0c, 0x02, 0x7f,   // M
    0x7f, 0x04, 0x08, 0x10, 0x7f,   // N
    0x3e, 0x41, 0x41, 0x41, 0x3e,   // O
    0x7f, 0x09, 0x09, 0x09, 0x06,   // P
    0x3e, 0x41, 0x51, 0x21, 0x5e,   // Q
    0x7f, 0x09, 0x19, 0x29, 0x46,   // R
    0x46, 0x49, 0x49, 0x49, 0x31,   // S
    0x01, 0x01, 0x7f, 0x01, 0x01,   // T
    0x3f, 0x40, 0x40, 0x40, 0x3f,   // U
    0x1f, 0x20, 0x40, 0x20, 0x1f,   // V
    0x3f, 0x40, 0x38, 0x40, 0x3f,   // W
    0x63, 0x14, 0x08, 0x14, 0x63,   // X
    0x07, 0x08, 0x70, 0x08, 0x07,   // Y
    0x61, 0x51, 0x49, 0x45, 0x43,   // Z
    0x00, 0x7f, 0x41, 0x41, 0x00,   // [
    0x02, 0x04, 0x08, 0x10, 0x20,   //
    0x00, 0x41, 0x41, 0x7f, 0x00,   // ]
    0x04, 0x02, 0x01, 0x02, 0x04,   // ^
    0x40, 0x40, 0x40, 0x40, 0x40,   // _
    0x00, 0x01, 0x02, 0x04, 0x00,   // `
    0x20, 0x54, 0x54, 0x54, 0x78,   // a
    0x7f, 0x48, 0x44, 0x44, 0x38,   // b
    0x38, 0x44, 0x44, 0x44, 0x20,   // c
    0x38, 0x44, 0x44, 0x48, 0x7f,   // d
    0x38, 0x54, 0x54, 0x54, 0x18,   // e
    0x08, 0x7e, 0x09, 0x01, 0x02,   // f
    0x0c, 0x52, 0x52, 0x52, 0x3e,   // g
    0x7f, 0x08, 0x04, 0x04, 0x78,   // h
    0x00, 0x44, 0x7d, 0x40, 0x00,   // i
    0x20, 0x40, 0x44, 0x3d, 0x00,   // j
    0x7f, 0x10, 0x28, 0x44, 0x00,   // k
    0x00, 0x41, 0x7f, 0x40, 0x00,   // l
    0x7c, 0x04, 0x18, 0x04, 0x78,   // m
    0x7c, 0x08, 0x04, 0x04, 0x78,   // n
    0x38, 0x44, 0x44, 0x44, 0x38,   // o
    0x7c, 0x14, 0x14, 0x14, 0x08,   // p
    0x08, 0x14, 0x14, 0x18, 0x7c,   // q
    0x7c, 0x08, 0x04, 0x04, 0x08,   // r
    0x48, 0x54, 0x54, 0x54, 0x20,   // s
    0x04, 0x3f, 0x44, 0x40, 0x20,   // t
    0x3c, 0x40, 0x40, 0x20, 0x7c,   // u
    0x1c, 0x20, 0x40, 0x20, 0x1c,   // v
    0x3c, 0x40, 0x30, 0x40, 0x3c,   // w
    0x44, 0x28, 0x10, 0x28, 0x44,   // x
    0x0c, 0x50, 0x50, 0x50, 0x3c,   // y
    0x44, 0x64, 0x54, 0x4c, 0x44    // z
};


// 2. Th? vi?n GLCD KS0108 128x64

#define GLCD_DATA_PORT PORTC
#define GLCD_DATA_DDR  DDRC
#define GLCD_CTRL_PORT PORTD
#define GLCD_CTRL_DDR  DDRD

#define RS PD0
#define RW PD1
#define EN PD2
#define CS1 PD3
#define CS2 PD4

uint8_t glcd_x = 0;
uint8_t glcd_y = 0;

void GLCD_Enable() {
	GLCD_CTRL_PORT |= (1 << EN); _delay_us(2);
	GLCD_CTRL_PORT &= ~(1 << EN); _delay_us(2);
}

void GLCD_Command(uint8_t cmd, uint8_t chip) {
	GLCD_CTRL_PORT &= ~((1<<CS1) | (1<<CS2));
	if(chip == 1) GLCD_CTRL_PORT |= (1<<CS1);
	if(chip == 2) GLCD_CTRL_PORT |= (1<<CS2);
	
	GLCD_CTRL_PORT &= ~(1 << RS);
	GLCD_CTRL_PORT &= ~(1 << RW);
	GLCD_DATA_PORT = cmd;
	GLCD_Enable();
}

void GLCD_Data(uint8_t data, uint8_t chip) {
	GLCD_CTRL_PORT &= ~((1<<CS1) | (1<<CS2));
	if(chip == 1) GLCD_CTRL_PORT |= (1<<CS1);
	if(chip == 2) GLCD_CTRL_PORT |= (1<<CS2);
	
	GLCD_CTRL_PORT |= (1 << RS);
	GLCD_CTRL_PORT &= ~(1 << RW);
	GLCD_DATA_PORT = data;
	GLCD_Enable();
}

void GLCD_Init() {
	GLCD_DATA_DDR = 0xFF;
	GLCD_CTRL_DDR |= (1<<RS)|(1<<RW)|(1<<EN)|(1<<CS1)|(1<<CS2);
	_delay_ms(50);
	GLCD_Command(0x3F, 1);
	GLCD_Command(0x3F, 2);
	GLCD_Command(0xC0, 1);
	GLCD_Command(0xC0, 2);
}

void GLCD_SetCursor(uint8_t page, uint8_t col) {
	glcd_y = page;
	glcd_x = col;
	uint8_t chip = (col < 64) ? 1 : 2;
	uint8_t local_col = (col < 64) ? col : (col - 64);
	
	GLCD_Command(0xB8 | page, chip);      // Set Page (0-7)
	GLCD_Command(0x40 | local_col, chip); // Set Y Address (0-63)
}

void GLCD_Clear() {
	for (uint8_t p = 0; p < 8; p++) {
		GLCD_SetCursor(p, 0);
		for (uint8_t c = 0; c < 64; c++) GLCD_Data(0x00, 1);
		GLCD_SetCursor(p, 64);
		for (uint8_t c = 0; c < 64; c++) GLCD_Data(0x00, 2);
	}
	GLCD_SetCursor(0,0);
}

void GLCD_Char(char c) {
	if (c < 32 || c > 126) return;
	uint8_t chip = (glcd_x < 64) ? 1 : 2;
	uint16_t idx = (c - 32) * 5;
	
	for (uint8_t i = 0; i < 5; i++) {
		if (glcd_x == 64) { chip = 2; GLCD_SetCursor(glcd_y, 64); }
		GLCD_Data(font5x8[idx + i], chip);
		glcd_x++;
	}
	
	if (glcd_x == 64) { chip = 2; GLCD_SetCursor(glcd_y, 64); }
	GLCD_Data(0x00, chip);
	glcd_x++;
}

void GLCD_String(const char *str) {
	while (*str) {
		if (glcd_x >= 120) { // T? ??ng xu?ng dòng n?u h?t màn hình ngang
			glcd_y++;
			GLCD_SetCursor(glcd_y, 0);
		}
		GLCD_Char(*str++);
	}
}


// 3. Th? vi?n KEYPAD 5x4

char keys[4][5] = {
	{'7', '8', '9', '+', 'S'}, // S = SHIFT
	{'4', '5', '6', '-', 'C'}, // C = AC (All Clear)
	{'1', '2', '3', '*', 'D'}, // D = DEL
	{'0', '.', '=', '/', 'A'}  // A = ANS
};

void Keypad_Init() {
	DDRA = 0x0F;  PORTA = 0xFF;
	DDRB &= ~(1<<PB0); PORTB |= (1<<PB0);
}

char Keypad_Scan() {
	for (uint8_t r = 0; r < 4; r++) {
		PORTA = (PORTA | 0x0F) & ~(1 << r); _delay_us(10);
		
		if (!(PINA & (1 << PA4))) { _delay_ms(20); while(!(PINA & (1 << PA4))); return keys[r][0]; }
		if (!(PINA & (1 << PA5))) { _delay_ms(20); while(!(PINA & (1 << PA5))); return keys[r][1]; }
		if (!(PINA & (1 << PA6))) { _delay_ms(20); while(!(PINA & (1 << PA6))); return keys[r][2]; }
		if (!(PINA & (1 << PA7))) { _delay_ms(20); while(!(PINA & (1 << PA7))); return keys[r][3]; }
		if (!(PINB & (1 << PB0))) { _delay_ms(20); while(!(PINB & (1 << PB0))); return keys[r][4]; }
	}
	return 0;
}

// 4. Thu?t toán tính toán

const char* expr_ptr;
double parse_expression();

char peek() { return *expr_ptr; }
char get()  { return *expr_ptr++; }

double parse_factor() {
	if (peek() >= '0' && peek() <= '9') {
		return strtod(expr_ptr, (char**)&expr_ptr);
		} else if (peek() == '(') {
		get(); double result = parse_expression();
		if (peek() == ')') get(); return result;
		} else if (peek() == '-') { get(); return -parse_factor(); }
		else if (strncmp(expr_ptr, "sin(", 4) == 0) {
			expr_ptr += 4; double val = parse_expression();
			if (peek() == ')') get(); return sin(val * M_PI / 180.0);
			} else if (strncmp(expr_ptr, "cos(", 4) == 0) {
			expr_ptr += 4; double val = parse_expression();
			if (peek() == ')') get(); return cos(val * M_PI / 180.0);
			} else if (strncmp(expr_ptr, "tan(", 4) == 0) {
			expr_ptr += 4; double val = parse_expression();
			if (peek() == ')') get(); return tan(val * M_PI / 180.0);
			} else if (strncmp(expr_ptr, "sqrt(", 5) == 0) {
			expr_ptr += 5; double val = parse_expression();
			if (peek() == ')') get(); return sqrt(val);
		}
		return 0;
	}

	double parse_term() {
		double result = parse_factor();
		while (peek() == '*' || peek() == '/' || peek() == '^') {
			if (peek() == '*') { get(); result *= parse_factor(); }
			else if (peek() == '/') { get(); result /= parse_factor(); }
			else if (peek() == '^') { get(); result = pow(result, parse_factor()); }
		}
		return result;
	}

	double parse_expression() {
		double result = parse_term();
		while (peek() == '+' || peek() == '-') {
			if (peek() == '+') { get(); result += parse_term(); }
			else if (peek() == '-') { get(); result -= parse_term(); }
		}
		return result;
	}

	double evaluate(const char* expr) {
		expr_ptr = expr;
		return parse_expression();
	}


	// 5. Ch??ng trình chính

	typedef enum { STATE_NORMAL, STATE_M1, STATE_M2, STATE_M3 } CalcState;

	int main(void) {
		MCUCR = (1<<JTD);
		MCUCR = (1<<JTD);
		
		GLCD_Init();
		Keypad_Init();
		
		GLCD_Clear();
		GLCD_SetCursor(3, 15); GLCD_String("CASIO Fx");
		GLCD_SetCursor(5, 30); GLCD_String("Loading...");
		_delay_ms(1000);
		GLCD_Clear();

		CalcState state = STATE_NORMAL;
		char buffer[60] = "";
		uint8_t b_idx = 0;
		double ans = 0.0;
		char display_str[16];
		
		uint8_t is_shift_active = 0; // Theo dõi SHIFT
		uint8_t eq_step = 0;
		double a_val = 0, b_val = 0, c_val = 0;

		while (1) {
			char key = Keypad_Scan();
			
			if (key != 0) {
				
				// SHIFT
				if (key == 'S') {
					is_shift_active = 1;
					GLCD_SetCursor(0, 100); GLCD_String("[SHIFT]"); // Hi?n th? SHIFT
					continue; // Thoát vòng l?p
				}

				// Menu ch?c n?ng
				if (is_shift_active == 1) {
					is_shift_active = 0;
					GLCD_SetCursor(0, 100); GLCD_String("   "); // Xóa h?t ch?
					
					if (key == '1') {
						state = STATE_M1; GLCD_Clear();
						GLCD_SetCursor(0,0); GLCD_String("M1: PHEP TOAN");
						GLCD_SetCursor(2,0); GLCD_String("1:(  2:)  3:^  4:v");
						continue;
					}
					else if (key == '2') {
						state = STATE_M2; GLCD_Clear();
						GLCD_SetCursor(0,0); GLCD_String("M2: LUONG GIAC");
						GLCD_SetCursor(2,0); GLCD_String("1:sin( 2:cos( 3:tan(");
						continue;
					}
					else if (key == '3') {
						state = STATE_M3; eq_step = 0; b_idx = 0; buffer[0] = '\0';
						GLCD_Clear();
						GLCD_SetCursor(0,0); GLCD_String("M3: PT BAC 2");
						GLCD_SetCursor(2,0); GLCD_String("Nhap a = ");
						continue;
					}
					// N?u b?m SHIFT, b?m linh tinh s? quay v? bình th??ng
				}

				// Tr?ng thái BÌNH TH??NG
				if (state == STATE_NORMAL) {
					if (key == 'C') { // AC
						b_idx = 0; buffer[0] = '\0'; GLCD_Clear();
					}
					else if (key == 'D') { // DEL
						if (b_idx > 0) {
							b_idx--; buffer[b_idx] = '\0';
							GLCD_Clear(); GLCD_SetCursor(0,0); GLCD_String(buffer);
						}
					}
					else if (key == '=') { // B?ng
						ans = evaluate(buffer);
						GLCD_SetCursor(3, 0); GLCD_String("=                   ");
						GLCD_SetCursor(4, 0);
						dtostrf(ans, 8, 3, display_str); GLCD_String(display_str);
						b_idx = 0; buffer[0] = '\0';
					}
					else if (key == 'A') { // ANS
						dtostrf(ans, 4, 2, display_str);
						strcat(buffer, display_str);
						b_idx = strlen(buffer);
						GLCD_Clear(); GLCD_SetCursor(0,0); GLCD_String(buffer);
					}
					else { // Các phím s?, d?u
						if (b_idx < 55) {
							buffer[b_idx++] = key; buffer[b_idx] = '\0';
							GLCD_Clear(); GLCD_SetCursor(0,0); GLCD_String(buffer);
						}
					}
				}
				
				// SHIFT + 1
				else if (state == STATE_M1) {
					if (key == '1') strcat(buffer, "(");
					else if (key == '2') strcat(buffer, ")");
					else if (key == '3') strcat(buffer, "^");
					else if (key == '4') strcat(buffer, "sqrt(");
					
					b_idx = strlen(buffer); state = STATE_NORMAL;
					GLCD_Clear(); GLCD_SetCursor(0,0); GLCD_String(buffer);
				}
				
				// SHIFT + 2
				else if (state == STATE_M2) {
					if (key == '1') strcat(buffer, "sin(");
					else if (key == '2') strcat(buffer, "cos(");
					else if (key == '3') strcat(buffer, "tan(");
					
					b_idx = strlen(buffer); state = STATE_NORMAL;
					GLCD_Clear(); GLCD_SetCursor(0,0); GLCD_String(buffer);
				}

				// SHIFT + 3
				else if (state == STATE_M3) {
					if (key == 'C') { // Thoát
						state = STATE_NORMAL; b_idx = 0; buffer[0]='\0'; GLCD_Clear();
					}
					else if (key == 'D') { // DEL trong b?c 2
						if (b_idx > 0) {
							b_idx--; buffer[b_idx] = '\0';
							GLCD_SetCursor(2 + eq_step, 54); // Xóa trên màn hình GLCD
							GLCD_String(buffer); GLCD_String("  ");
						}
					}
					else if (key == '=') { // Nh?p
						if (eq_step == 0) {
							a_val = atof(buffer); eq_step = 1; b_idx = 0; buffer[0] = '\0';
							GLCD_SetCursor(3, 0); GLCD_String("Nhap b = ");
						}
						else if (eq_step == 1) {
							b_val = atof(buffer); eq_step = 2; b_idx = 0; buffer[0] = '\0';
							GLCD_SetCursor(4, 0); GLCD_String("Nhap c = ");
						}
						else if (eq_step == 2) {
							c_val = atof(buffer); GLCD_Clear();
							if (a_val == 0) { GLCD_String("Loi: a phai khac 0!"); }
							else {
								double delta = b_val * b_val - 4 * a_val * c_val;
								if (delta < 0) { GLCD_String("PT Vo nghiem!"); }
								else if (delta == 0) {
									double x = -b_val / (2 * a_val);
									GLCD_String("Nghiem kep:");
									GLCD_SetCursor(2, 0); GLCD_String("x = ");
									dtostrf(x, 6, 2, display_str); GLCD_String(display_str);
									} else {
									double x1 = (-b_val + sqrt(delta)) / (2 * a_val);
									double x2 = (-b_val - sqrt(delta)) / (2 * a_val);
									GLCD_String("2 nghiem phan biet:");
									GLCD_SetCursor(2, 0); GLCD_String("x1 = ");
									dtostrf(x1, 6, 2, display_str); GLCD_String(display_str);
									GLCD_SetCursor(4, 0); GLCD_String("x2 = ");
									dtostrf(x2, 6, 2, display_str); GLCD_String(display_str);
								}
							}
							eq_step = 3;
						}
						else if (eq_step == 3) {
							state = STATE_NORMAL; b_idx = 0; buffer[0]='\0'; GLCD_Clear();
						}
					}
					else {
						if ((key >= '0' && key <= '9') || key == '.' || key == '-') {
							if (b_idx < 10) {
								buffer[b_idx++] = key; buffer[b_idx] = '\0';
								GLCD_SetCursor(2 + eq_step, 54);
								GLCD_String(buffer);
							}
						}
					}
				}
			}
		}
	}

