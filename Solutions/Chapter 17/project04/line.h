#ifndef LINE_H
#define LINE_H


//Clears the current line;
void clear_line();

//adds word to the end of the current line. If this is not the first word on the line,
//puts one space before word
void add_word(const char *word);

//returns the number of characters left in the current line.
int space_remaining();

//writes the current line with justification
void write_line();

//writes the current line without justification, if the line is empty, does nothing.
void flush_line();

#endif
