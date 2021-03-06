#pragma once

template<class T> class BarbaArray
{
public:
	explicit BarbaArray(void){}
	explicit BarbaArray(size_t size) {assign(size);}
	explicit BarbaArray(size_t size, T value) {assign(size, value);}
	explicit BarbaArray(void* data, size_t size) { append(data, size); }
	explicit BarbaArray(BarbaArray* barbaArray) { append(barbaArray); }
	~BarbaArray(void){}
	size_t size() { return buf.size(); }
	size_t capacity() { return buf.capacity(); }
	void resize(size_t size) { buf.resize(size); }
	T* data() { return buf.data(); }
	void assign(size_t size) {buf.assign(size, T());} 
	void assign(size_t size, T value) {buf.assign(size, value);}
	void assign(T* data, size_t size) {resize(0); append(data, size); }
	void assign(BarbaArray<T>* buffer) {resize(0); append(buffer); }
	void reserve(size_t size) {buf.reserve(size);}
	void append(void* data, size_t size) { size_t oldSize = this->size(); resize(oldSize + size); memcpy_s(this->data() + oldSize, (this->size()-oldSize) * sizeof(T), data, size * sizeof(T) );}	
	void append(BarbaArray<T>* buffer) { append(buffer->data(), buffer->size()); }
	void append(T value) {buf.push_back(value);}
	bool empty() {return buf.empty();}
	void clear() {return buf.clear();}
	T at(size_t nIndex) const { return buf.at(nIndex); }
	T& at(size_t nIndex) { return buf.at(nIndex); }
	T operator[](size_t nIndex) const { return buf[nIndex]; }
	T& operator[](size_t nIndex) { return buf[nIndex]; }

protected:
	std::vector<T> buf;
};

typedef BarbaArray<BYTE> BarbaBuffer;

