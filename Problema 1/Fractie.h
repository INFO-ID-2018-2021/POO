#pragma once

template <class T>
class Fractie
{
public:
	Fractie();
	Fractie(T numarator, T numitor);
	~Fractie();
	T getNumitor();
	T getNumarator();
	Fractie<T> operator+(const Fractie<T>& f2);
	Fractie<T> operator-();
	Fractie<T> operator-(const Fractie<T>& f2);
	Fractie<T> operator*(const Fractie<T>& f2);
	Fractie<T> operator/(const Fractie<T>& f2);
	bool operator==(const Fractie<T>& f2);
	Fractie<T> operator Fractie<T>();
	void operator=(const Fractie<T>& f2);
	static T getCMMMC(T nr1, T nr2);
	static T getCMMDC(T nr1, T nr2);
	void print();
private:
	T numitor;
	T numarator;
	void simplificare();
};

template<class T>
Fractie<T>::Fractie()
{
	numarator = (T)0;
	numitor = (T)1;
}

template<class T>
Fractie<T>::Fractie(T numaratorInput, T numitorInput)
{
	if (numitorInput == 0)
		throw std::invalid_argument("Numitorul nu poate fi 0!");
	numarator = numaratorInput;
	numitor = numitorInput;
	simplificare();
}

template<class T>
Fractie<T>::~Fractie()
{
}

template<class T>
T Fractie<T>::getNumitor()
{
	return numitor;
}

template<class T>
T Fractie<T>::getNumarator()
{
	return numarator;
}

template<class T>
Fractie<T> Fractie<T>::operator+(const Fractie<T>& f2)
{
	Fractie<T> f;
	f.numarator = this->numarator*f2.numitor + f2.numarator*this->numitor;
	f.numitor = this->numitor*f2.numitor;
	f.simplificare();
	return f;
}

template<class T>
Fractie<T> Fractie<T>::operator-() {
	Fractie<T> f;
	f.numarator = -this->numarator;
	f.numitor = this->numitor;
	return f;
}

template<class T>
Fractie<T> Fractie<T>::operator-(const Fractie<T>& f2) {
	Fractie<T> f;
	f.numarator = this->numarator*f2.numitor - f2.numarator*this->numitor;
	f.numitor = this->numitor*f2.numitor;
	f.simplificare();
	return f;
}

template<class T>
Fractie<T> Fractie<T>::operator*(const Fractie<T>& f2) {
	Fractie<T> f;
	f.numarator = this->numarator*f2.numarator;
	f.numitor = this->numitor*f2.numitor;
	f.simplificare();
	return f;
}

template<class T>
Fractie<T> Fractie<T>::operator/(const Fractie<T>& f2) {
	Fractie<T> f, aux;
	f.numarator = this->numarator;
	f.numitor = this->numitor;
	aux.numitor = f2.numarator;
	aux.numarator = f2.numitor;
	return f * aux;
}

template<class T>
bool Fractie<T>::operator==(const Fractie<T>& f2) {
	this->simplificare();
	f2.simplificare();
	return this.numarator == f2.numitor && this.numitor == f2.numitor;
}

template<class T>
Fractie<T> Fractie<T>::operator Fractie<T>()
{
	return NULL;
}

template<class T>
void Fractie<T>::operator=(const Fractie<T>& f2)
{
	numarator = f2.numarator;
	numitor = f2.numitor;
}

template<class T>
T Fractie<T>::getCMMMC(T nr1, T nr2)
{
	return nr1 * nr2 / getCMMDC(nr1, nr2);
}

template<class T>
T Fractie<T>::getCMMDC(T nr1, T nr2)
{
	T t;
	while (nr2 != 0)
	{
		t = nr2;
		nr2 = nr1 % nr2;
		nr1 = t;
	}
	return nr1;
}

template<class T>
void Fractie<T>::print()
{
	std::cout << "Numarator: " << this->numarator << std::endl;
	std::cout << "Numitor: " << this->numitor << std::endl;
	std::cout << numarator << "/" << numitor << std::endl;
}

template<class T>
void Fractie<T>::simplificare()
{
	T cmmdc = getCMMDC(numarator, numitor);
	numarator /= cmmdc;
	numitor /= cmmdc;
}