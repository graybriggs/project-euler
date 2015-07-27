
#include <cstring>
#include <iostream>
#include <string>


struct NumComponents {
	char units;
	char tens;
	char hundreds;
};

std::size_t total = 0;

NumComponents get_components(int num) {
	NumComponents components;
	components.hundreds = num / 100;
	components.tens = (num / 10) % 10;
	components.units = num % 10;
	
	return components;
}

void teen_values(char units) {
	
	switch (units) {
		case 0: total += strlen("ten"); break;
		case 1: total += strlen("eleven"); break;
		case 2: total += strlen("twelve"); break;
		case 3: total += strlen("thirteen"); break;
		case 4: total += strlen("fourteen"); break;
		case 5: total += strlen("fifteen"); break;
		case 6: total += strlen("sixteen"); break;
		case 7: total += strlen("seventeen"); break;
		case 8: total += strlen("eighteen"); break;
		case 9: total += strlen("nineteen"); break;
	}
}

int main() {
	
	for (int i = 1; i < 1000; ++i) {
		
		NumComponents nc = get_components(i);
		
		if (nc.hundreds > 0) {
			switch (nc.hundreds) {
			case 1: total += strlen("one"); break;
			case 2: total += strlen("two"); break;
			case 3: total += strlen("three"); break;
			case 4: total += strlen("four"); break;
			case 5: total += strlen("five"); break;
			case 6: total += strlen("six"); break;
			case 7: total += strlen("seven"); break;
			case 8: total += strlen("eight"); break;
			case 9: total += strlen("nine"); break;
			}
			total += strlen("hundred");
			if (nc.tens != 0 || nc.units != 0)
				total += strlen("and");
		}
		
		if (nc.tens > 0) {
			switch (nc.tens) {
			case 1: teen_values(nc.units); continue;
			case 2: total += strlen("twenty"); break;
			case 3: total += strlen("thirty"); break;
			case 4: total += strlen("forty"); break;
			case 5: total += strlen("fifty");  break;
			case 6: total += strlen("sixty");  break;
			case 7: total += strlen("seventy");  break;
			case 8: total += strlen("eighty");  break;
			case 9: total += strlen("ninety");  break;
			}
		}
		if (nc.units > 0) {
			switch (nc.units) {
			case 1: total += strlen("one");   break;
			case 2: total += strlen("two");   break;
			case 3: total += strlen("three"); break;
			case 4: total += strlen("four");  break;
			case 5: total += strlen("five");  break;
			case 6: total += strlen("six");   break;
			case 7: total += strlen("seven"); break;
			case 8: total += strlen("eight"); break;
			case 9: total += strlen("nine");  break;
			}
		}
	}
	total += strlen("onethousand");
	std::cout << "Total: " << total << std::endl;
}





