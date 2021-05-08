#include <iostream>
#include <vector>

class Box
{
    public:
        Box( void );
        ~Box( void );
        int calculatePrice( void );
        int minValue( void );
        int maxValue( void );
        void pop( void );
        void push( int );
        void setPrice( int );
        int  size( void );
        void clear(void);
        void printValues(void);

    private:
        int _boxPrice;
        std::vector<int> vec;
};

Box::Box( void ) {}

Box::~Box( void ) {}

int
Box::size( void )
{
    return vec.size();
}

void
Box::clear( void )
{
    while (this->vec.size())
        vec.pop_back();
}

void
Box::setPrice( int price)
{
    this->_boxPrice = price;
}

int
Box::calculatePrice(void)
{
    int min = this->minValue();
    int max = this->maxValue();
    if (vec.size() == 0)
        return (0);
    return ((max - min) * vec.size() * vec.size() + this->_boxPrice);
}

int
Box::maxValue(void)
{
    int max = 0;

    for (size_t i = 0; i < this->vec.size(); i++)
    {
        if (vec[i] > max)
            max = vec[i];
    }
    return (max);
}

int
Box::minValue(void)
{
    int min = this->maxValue();

    for (size_t i = 0; i < this->vec.size(); i++)
    {
        if (vec[i] < min)
            min = vec[i];
    }
    
    return (min);
}

void
Box::printValues(void)
{
    for (size_t i = 0; i < this->vec.size(); i++)
    {
        std::cout << this->vec[i] << " ";
    }
    std::cout << std::endl;
}

void
Box::push( int value )
{
    vec.push_back(value);
}

void
Box::pop( void )
{
    vec.pop_back();
}

int main(void)
{
    Box box;

    int ordersCount, maxOrdersInBox, boxPrice;
    std::cin >> ordersCount >> maxOrdersInBox >> boxPrice;
    
    box.setPrice(boxPrice);

    int totalPrice = 0;
    int oldPrice, newPrice;
    for (int i = 0, temp; i < ordersCount; i++)
    {
        oldPrice = box.calculatePrice();
        std::cin >> temp;
        box.push(temp);
        newPrice = box.calculatePrice();

        if ((double)newPrice / (double)oldPrice >= 2)
        {
            totalPrice += oldPrice;
            box.clear();
            box.push(temp);
        }
    }
    totalPrice += box.calculatePrice();
    std::cout << totalPrice << std::endl;
    return (0);
}
