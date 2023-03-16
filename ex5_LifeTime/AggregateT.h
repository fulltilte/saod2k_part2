#pragma once
#include <iostream>
#include "Aggregate.h"
using namespace std;

template <typename m_objTest> class AggregareT {
	m_objTest a;
public:
	AggregareT(m_objTest A = 0) {
		a = A;
		cout << "const last" << endl;
	}

	~AggregareT() {
		cout << "dest last" << endl;
	}
};