
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


#include <Queue.h>

Queue<char> queue = Queue<char>(5);

void setup() 
{
  Serial.begin(9600);
}

void loop()
  {
  while(Serial.available()) 
  {
    queue.push(Serial.read());
  }

  Serial.print(millis() / 1000);
  Serial.print(": ");
  int count = queue.count();
  if (count > 0) {
    Serial.print("Found ");
    Serial.print(count);
    Serial.print(" cars.. '");
    Serial.print(queue.pop());
    Serial.print("cars just entered the queue");
    Serial.print(queue.front());
    Serial.print(" cars standing  at the front");
    Serial.print(queue.back());
    Serial.print(" cars standing at the back '");
    Serial.print(queue.peak());
    Serial.println("'.");
  } else {
    Serial.println("no movement of cars"); 
  }
  Serial.print("Stop the car");
  delay(5000);
}
