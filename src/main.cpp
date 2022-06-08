#include <Controller.h>
#include <iostream>


int main() try
{
	Controller controller;

	controller.run();


	return EXIT_SUCCESS;
}
catch (exception& e){
	cerr << e.what();
}
catch (...){
	cerr << "exception thrown. Exit from main\n";
}