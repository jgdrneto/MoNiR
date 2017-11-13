#include <iostream>

#include "GPIO.cpp"

using namespace std;

int main(int argc, char const *argv[])
{		
	
	GPIO::setup(PORTNUMBER::P9_40);
	GPIO::setup(PORTNUMBER::P9_14,DIRECTION::OUT); 

	GPIO::output(PORTNUMBER::P9_14,VALUE::LOW);
	
	while(true){
		cout << "Valor lido na porta P9_40: " << GPIO::input(PORTNUMBER::P9_40) << endl;
	}

	return 0;
}
