#include "Observable.h"

void Observable::addObserver(Observer* observer) {
	this->observer = observer;
}
void Observable::notifyUpdate() {
	observer->update();
}