#include <iostream>

class DominoItem
{
	public:
		DominoItem( void );
		~DominoItem ( void );
		void setItemValues(int, int);
		void printValues( void ) const;
		void swapValues( void );
		void tryToConnect(DominoItem &d2);

		bool operator==(const DominoItem &d2) const;
		bool operator!=(const DominoItem &d2) const;

	private:
		int _left;
		int _right;
};

DominoItem::DominoItem( void ) {}
DominoItem::~DominoItem( void ) {}

bool
DominoItem::operator==(const DominoItem &d2) const {
	return (_left == d2._left || _left == d2._right || _right == d2._left || _right == d2._right);
}

bool
DominoItem::operator!=(const DominoItem &d2) const {
	return (!(_left == d2._left || _left == d2._right || _right == d2._left || _right == d2._right));
}

void
DominoItem::swapValues( void ) {
	int temp = this->_left;
	_left = _right;
	_right = temp;
}

void
DominoItem::printValues( void ) const {
	std::cout << _left << " " << _right;
}

void
DominoItem::setItemValues(int left, int right) {
	_left = left;
	_right = right;
}

void
DominoItem::tryToConnect(DominoItem &d2)
{
	if (this->_left == d2._right) {
		this->swapValues();
		d2.swapValues();
	}
	else if (this->_right == d2._right) {
		d2.swapValues();
	}
	else if (this->_left == d2._left) {
		this->swapValues();
	}
}

void
readValues(int &first, int &second)
{
	std::cin >> first >> second;
}

void
printAnswer(const DominoItem &d1, const DominoItem &d2)
{
	if (d1 != d2)
	{
		std::cout << "-1" << std::endl;
	}
	else
	{
		d1.printValues();
		std::cout << " ";
		d2.printValues();
		std::cout << std::endl;
	}
}

int main(void)
{
	DominoItem d1, d2;
	int left, right;

	readValues(left, right);
	d1.setItemValues(left, right);
	readValues(left, right);
	d2.setItemValues(left, right);
	d1.tryToConnect(d2);
	printAnswer(d1, d2);	
	return (0);
}