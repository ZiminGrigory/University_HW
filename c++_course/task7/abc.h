#pragma once

class Abc {
public:
	static int count;

	Abc() {
		count++;
	}

	~Abc() {
		count--;
	}

	Abc(const Abc& from) {
		//Q_Unused(from);
		count++;
	}

	static int num() {
		return count;
	}
};

int Abc::count = 0;
