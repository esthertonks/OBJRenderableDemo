#pragma once

#include <cctype>
#include <algorithm>
#include <Shlwapi.h>

class StringUtils
{
public:

	static std::string ToLower(std::string string) {
		std::transform(string.begin(), string.end(), string.begin(),
			[](unsigned char c) {
				return std::tolower(c); 
			}
		);
		return string;
	}

	static std::string GetFileExtension(std::string filename) {
		auto index = filename.rfind('.', filename.length());

		if (index != std::string::npos) {
			return filename.substr(index + 1);
		}

		return "";
	}

	static void TrimRight(std::string &string) {
		string.erase(std::find_if(string.rbegin(), string.rend(), [](int character) {
			return !std::isspace(character);
		}).base(), string.end());
	}
};

