#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> names;
long name_score_total = 0;

std::string read_file(std::string file_name) {
	
	FILE* fp = fopen(file_name.c_str(), "r");
	 
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	rewind(fp);

	char* buffer = new char[size];
	fread(buffer, 1, size, fp);
	   
	std::string names_buf(buffer, size);
	delete buffer;
	return names_buf;

}
//////////


void tokenize(const std::string& str) {
	
	unsigned i = 0;
	
    while (i < str.length()) {
		if (str[i] == '"') {
			++i; // first quotation mark.
			std::string n;
			n.reserve(15);
	        while (str[i] != '"') {
				n.push_back(str[i]);
				++i;			
			}
			names.push_back(n);
			++i; // second quotation mark.
		}
		++i; // comma
	}	
}

int calculate_name_value(const std::string& name) {
	
	int total = 0;
	
	for (auto& n : name) {
		total += (n - 65) + 1;
	}
	return total;
}

int main() {
	
	std::string str = read_file("p022_names.txt");
	tokenize(str);
	std::sort(std::begin(names), std::end(names));

	unsigned counter = 1;
	for (auto& a : names) {
		name_score_total += counter * calculate_name_value(a);
		++counter;
	}
	std::cout << "Name score total: " << name_score_total << std::endl;
}
