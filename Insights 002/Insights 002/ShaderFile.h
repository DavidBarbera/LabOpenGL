#pragma once

#include <iostream>
#include <fstream>

class ShaderFile {


public:

	char* _buffer;

	ShaderFile() {}

	void init(char const* file)
	{
		std::ifstream is(file, std::ifstream::binary);

		//	if (is.bad()) return 1;

		if (is) {
			// get length of file:
			is.seekg(0, is.end);
			int length = is.tellg();
			is.seekg(0, is.beg);

			// allocate memory:
			_buffer = new char[length + 1];

			// read data as a block:
			is.read(_buffer, length);
			//_buffer[length] = '\0';
			int i = 0;
			for (i = 0; i < length; ++i) _buffer[i] = (char)_buffer[i];
			_buffer[i] = '\0';

			is.close();

			// print content:
			std::cout.write(_buffer, length);
			std::cout << "\n" << is.gcount();
			std::cout << "\n" << length;
			std::cout << "\n" << _buffer;
			//getchar();
		}
	}

	~ShaderFile()
	{
		//delete[] buffer;
	}

	char* get()
	{
		return _buffer;
	}

};
