

// -------------------------------------------------------------------
template <typename T>
class List {
private:
	T *_values;
	int _last;
	int _size;

	bool isFull();
	int find(T value);
	void increase();
	void decrease();

public:
	List(int size = 8);
	List(const List& l);
	~List();
	void append(T value);
	void remove(T value);
	T getValueAt(int pos);
	int size();

	T operator[](int pos);
	List& operator=(const List& l);
};

// -------------------------------------------------------------------
template <typename T>
List<T>::List(int size) {
	_size = size;
	_last = 0;
	_values = new T[size];
}

// -------------------------------------------------------------------
template <typename T>
List<T>::List(const List& l) {
	_size = l._size;
	_last = l._last;
	_values = new T[_size];

	for (int i = 0; i < _last; i++)
		_values[i] = l._values[i];
}

// -------------------------------------------------------------------
template <typename T>
List<T>::~List() {
	delete[] _values;
}

// -------------------------------------------------------------------
template <typename T>
void List<T>::increase() {
	T *tmp = new T[_size * 2];

	for (int i = 0; i < _size; i++)
		tmp[i] = _values[i];

	delete[] _values;
	_values = tmp;
	_size *= 2;
}

// -------------------------------------------------------------------
template <typename T>
void List<T>::decrease() {
	_size /= 2;
	T *tmp = new T[_size];

	for (int i = 0; i < _size; i++)
		tmp[i] = _values[i];

	delete[] _values;
	_values = tmp;
}

// -------------------------------------------------------------------
template <typename T>
bool List<T>::isFull() {
	return _last == _size;
}

// -------------------------------------------------------------------
template <typename T>
int List<T>::find(T val) {
	int pos;

	for (pos = 0; pos < _last; pos++)
		if (_values[pos] == val)
			return pos;
	return -1;
}

// -------------------------------------------------------------------
template <typename T>
T List<T>::getValueAt(int pos) {
	if (pos < 0 || pos >= _last)
		throw "OutOfBoundsException";

	return _values[pos];
}

// -------------------------------------------------------------------
template <typename T>
void List<T>::append(T val) {
	if (isFull())
		increase();

	_values[_last] = val;
	_last += 1;
}

// -------------------------------------------------------------------
template <typename T>
void List<T>::remove(T val) {
	int pos = find(val);

	if (pos == -1)
		throw "ValueNotFoundException";

	for (; pos < _last - 1; pos++)
		_values[pos] = _values[pos + 1];
	_last -= 1;

	if (_last < _size / 4)
		decrease();
}

// -------------------------------------------------------------------
template <typename T>
int List<T>::size() {
	return _last;
}

// -------------------------------------------------------------------
template <typename T>
T List<T>::operator[](int pos) {
	return getValueAt(pos);
}

// -------------------------------------------------------------------
template <typename T>
List<T>& List<T>::operator=(const List<T>& l) {
	if (this != &l) {
		delete[] _values;

		_size = l._size;
		_last = l._last;
		_values = new T[_size];

		for (int i = 0; i < _last; i++)
			_values[i] = l._values[i];
	}
	return *this;
}
