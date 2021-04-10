#include <string>
using namespace std;

class NineOpMock : public Base {
    public:
	NineOpMock() { }

	virtual double evaluate() { return 9.2; }
	virtual string stringify() {return "9.2"; }
};
