#pragma once
#include "Field.h"

template<typename ... Rules>
class Field_Generator {

public:
	Field FieldGenerate(int&, int&);

	template<typename Rule>
	void setRule(Field*);
};


template<typename ... Rules>
Field Field_Generator<Rules ...>::FieldGenerate(int& height, int& width) {
	Field field(height, width);
	
	(setRule<Rules>(&field), ...);

	return field;
}

template<typename... Rules>
template<typename Rule>
void Field_Generator<Rules ...>::setRule(Field* field) {
	Rule rule;
	rule.add(field);
}