#ifndef _TOKENIZER_H
#define _TOKENIZER_H

#include <string>
#include "list2.h"

class Tokenizer {
private:
	unsigned int _pos;
	List<std::string> _tokens;

public:
	Tokenizer(std::string data, std::string separators);
	int countTokens();
	std::string nextToken();
	bool hasMoreTokens();
};

#endif
