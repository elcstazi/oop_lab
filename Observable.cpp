#include "Observable.h"

void Observable::Notify(std::string message, std::string className, logLevel level){
	for (auto current : observers)
		current->Update(message, className, level);
}

void Observable::addObserver(Observer*){

}
