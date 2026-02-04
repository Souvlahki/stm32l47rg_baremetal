#ifndef UART_H_
#define UART_H_

void usart2_init(int baud_rate);
void usart2_write_char(char ch);
void usart2_write_string(char *s);
char usart2_read();

#endif