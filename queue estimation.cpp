#ifndef Queue
#define Queue

#include <Arduino.h>

template<class T>
class Queue {
  private:
    int _front, _back, _count;
    T *_data;
    int _maxcars;
    int n;
    int i;
    public:
    while(i<=n) 
    {
    Queue(int _maxcars = n)
    { 
      _front = 0;
      _back = 0;
      _count = 0;
      _maxcars = _maxcars;
      _data = new T[_maxcars + 1];   
    n++;
    }
    ~Queue()
    {
      delete[] _data;  
    }
    inline int count();
    inline int front();
    inline int back();
    void push(const T &item);
    T peak();
    T pop();
    void clr();
};

template<class T>
inline int Queue<T>::count() 
{
  return _count;
}

template<class T>
inline int Queue<T>::front() 
{
  return _front;
}

template<class T>
inline int Queue<T>::back() 
{
  return _back;
}

template<class T>
void Queue<T>::push(const T &item)
{
  if(_count < _maxcars) 
  { // Drops out when full
    _data[_back++]=item;
    ++_count;
    // Check wrap around
    if (_back >_maxcars)
      _back -= (_maxcars + 1);
  }
}

template<class T>
 Queue<T>::pop() 
 {
  if(_count <= 0) 
  return T(); // Returns empty
  else {
    T result = _data[_front];
    _front++;
    _count--;
    // Check if the front columm of cars have left the lane
    if (_front > _maxcars) 
      _front =_front - (_maxcars+ 1);
    return result; 
  }
}

template<class T>
T Queue<T>::peak() 
{
  if(_count <= 0) return T(); // Returns empty
  else return _data[_front];
}

template<class T>
void Queue<T>::clr() 
{
  _front = _back;
  _count = 0;
}

