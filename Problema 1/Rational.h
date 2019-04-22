#ifndef _RATIONAL_H
#define	_RATIONAL_H
template <class T>
class Rational
{
public:
	//Constructori
	Rational();
	Rational(T numarator);
	Rational(T numarator, T numitor);
	Rational(const Rational<T>&);
	//End Constructori

	//Destructori
	~Rational();
	//End Destructori

	//Getteri
	T getNumitor();
	T getNumarator();
	//End Getteri

	//Setteri
	void setNumitor(T);
	void setNumarator(T);
	//End Setteri

	//Operatori
	friend Rational<T> operator+(T, Rational<T>);
	Rational<T> operator+(Rational<T>);
	Rational<T> operator+(T);
	Rational<T> operator+();

	friend Rational<T> operator-(T, Rational<T>);
	Rational<T> operator-(Rational<T>);
	Rational<T> operator-(T);
	Rational<T> operator-();

	friend Rational<T> operator*(T, Rational<T>);
	Rational<T> operator*(Rational<T>);
	Rational<T> operator*(T);

	friend Rational<T> operator/(T, Rational<T>);
	Rational<T> operator/(Rational<T> f);
	Rational<T> operator/(T nr);

	Rational<T>& operator+=(const Rational<T>&);
	Rational<T>& operator+=(const T&);

	Rational<T>& operator-=(const Rational<T>&);
	Rational<T>& operator-=(const T&);

	Rational<T>& operator*=(const Rational<T>&);
	Rational<T>& operator*=(const T&);

	Rational<T>& operator/=(const Rational<T>&);
	Rational<T>& operator/=(const T&);

	friend bool operator==(T, Rational<T>);
	bool operator==(Rational<T>);
	bool operator==(T);

	friend bool operator!=(T, Rational<T>);
	bool operator!=(Rational<T>);
	bool operator!=(T);

	friend bool operator<(T, Rational<T>);
	bool operator<(Rational<T>);
	bool operator<(T);

	friend bool operator<=(T, Rational<T>);
	bool operator<=(Rational<T>);
	bool operator<=(T);

	friend bool operator>(T, Rational<T>);
	bool operator>(Rational<T>);
	bool operator>(T);

	friend bool operator>=(T, Rational<T>);
	bool operator>=(Rational<T>);
	bool operator>=(T);

	Rational<T>& operator=(const Rational<T>&);

	//End Operatori

	//Metode	
	void print();
	Rational<T> scan();
	//End Metode

private:
	T numitor;
	T numarator;
	void simplificare();
	static T getCMMMC(T nr1, T nr2);
	static T getCMMDC(T nr1, T nr2);
};

//Operatori
template <class T>
Rational<T> Rational<T>::operator+(Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator*f.numitor + f.numarator*this->numitor;
	r.numitor = this->numitor*f.numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> Rational<T>::operator+(T nr) {
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator + nr * this->numitor;
	r.numitor = numitor;
	return r;
}

template <class T>
Rational<T> operator+(T nr, Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator(f.numarator + nr * f.numitor);
	r.numarator = f.numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> Rational<T>::operator+()
{
	return this;
}


template <class T>
Rational<T> Rational<T>::operator-(Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator*f.numitor - f.numarator*this->numitor;
	r.numitor = this->numitor*f.numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> Rational<T>::operator-(T nr)
{
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator - nr * this->numitor;
	r.numitor = this->numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> operator-(T nr, Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = nr * f.numitor + f.numarator;
	r.numitor = f.numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> Rational<T>::operator-()
{
	Rational<T> r = Rational<T>();
	r.numarator = -this->numarator;
	r.numitor = this->numitor;
	return r;
};


template <class T>
Rational<T> Rational<T>::operator*(Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator*f.numarator;
	r.numitor = this->numitor*f.numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> Rational<T>::operator*(T nr)
{
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator*nr;
	r.numitor = this->numitor;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> operator*(T nr, Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = nr * f.numarator;
	r.numitor = f.numitor;
	r.simplificare();
	return r;
}


template <class T>
Rational<T> Rational<T>::operator/(Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = this->numarator*f.numitor;
	r.numitor = this->numitor*f.numarator;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> Rational<T>::operator/(T nr)
{
	Rational<T> r = Rational<T>();
	r.numitor = this->numitor*nr;
	r.numarator = this->numarator;
	r.simplificare();
	return r;
}

template <class T>
Rational<T> operator/(T nr, Rational<T> f)
{
	Rational<T> r = Rational<T>();
	r.numarator = f.numitor*nr;
	r.numitor = f.numarator;
	r.simplificare();
	return r;
}


template<class T>
Rational<T>& Rational<T>::operator+=(const Rational<T>& f)
{
	this->numarator = this->numarator*f.numitor + f.numarator*this->numitor;
	this->numitor = this->numitor*f.numitor;
	this->simplificare();
	return *this;
}

template <class T>
Rational<T>& Rational<T>::operator+=(const T& nr)
{
	this->numarator = this->numarator + nr * this->numitor;
	return *this;
}


template <class T>
Rational<T>& Rational<T>::operator-=(const Rational<T>& f)
{
	this->numarator = this->numarator*f.numitor - f.numarator*this->numitor;
	this->numitor = this->numitor*f.numitor;
	this->simplificare();
	return *this;
}

template <class T>
Rational<T>& Rational<T>::operator-=(const T& nr)
{
	this->numarator = this->numarator - nr * this->numitor;
	this->simplificare();
	return *this;
}


template <class T>
Rational<T>& Rational<T>::operator*=(const Rational<T>& f)
{
	this->numarator = this->numarator*f.numarator;
	this->numitor = this->numitor*f.numitor;
	this->simplificare();
	return *this;
}

template <class T>
Rational<T>& Rational<T>::operator*=(const T& nr)
{
	this->numarator = this->numarator*nr;
	this->simplificare();
	return *this;
}


template <class T>
Rational<T>& Rational<T>::operator/=(const Rational<T>& f)
{
	this->numarator = this->numarator*f.numitor;
	this->numitor = this->numitor*f.numarator;
	this->simplificare();
	return *this;
}

template <class T>
Rational<T>& Rational<T>::operator/=(const T& nr)
{
	this->numitor = this->numitor*nr;
	this->simplificare();
	return *this;
}


template <class T>
bool Rational<T>::operator==(Rational<T> f) {
	return this->numarator == f.numarator && this->numitor == f.numitor;
}

template <class T>
bool Rational<T>::operator==(T nr)
{
	return this->numitor == 1 && this->numarator == nr;
}

template <class T>
bool operator==(T nr, Rational<T> f)
{
	return f.numitor == 1 && f.numarator == nr;
}


template <class T>
bool Rational<T>::operator!=(Rational<T> f)
{
	return this->numarator != f.numarator || this->numitor != f.numitor;
}

template <class T>
bool Rational<T>::operator!=(T nr)
{
	return this->numarator != nr || this->numitor != 1;
}

template <class T>
bool operator!=(T nr, Rational<T> f)
{
	return f.numitor != 1 || f.numarator != nr;
}


template <class T>
bool Rational<T>::operator<(Rational<T> f)
{
	return this->numarator*f.numitor < this->numitor*f.numarator;
}

template <class T>
bool Rational<T>::operator<(T nr)
{
	return this->numarator < this->numitor*nr;
}

template <class T>
bool operator<(T nr, Rational<T> f)
{
	return f.numitor*nr < f.numarator;
}


template <class T>
bool Rational<T>::operator<=(Rational<T> f)
{
	return this->numarator*f.numitor <= this->numitor*f.numarator;
}

template <class T>
bool Rational<T>::operator<=(T nr)
{
	return this->numarator <= this->numitor*nr;
}

template <class T>
bool operator<=(T nr, Rational<T> f)
{
	return f.numitor*nr <= f.numarator;
}


template <class T>
bool Rational<T>::operator>(Rational<T> f)
{
	return this->numarator*f.numitor > this->numitor*f.numarator;
}

template <class T>
bool Rational<T>::operator>(T nr)
{
	return this->numarator > this->numitor*nr;
}

template <class T>
bool operator>(T nr, Rational<T> f)
{
	return f.numitor*nr > f.numarator;
}


template <class T>
bool Rational<T>::operator>=(Rational<T> f)
{
	return this->numarator*f.numitor >= this->numitor*f.numarator;
}

template <class T>
bool Rational<T>::operator>=(T nr)
{
	return this->numarator >= this->numitor*nr;
}

template <class T>
bool operator>=(T nr, Rational<T> f)
{
	return f.numitor*nr >= f.numarator;
}

template <class T>
std::ostream& operator<<(std::ostream& stream, Rational<T>& f)
{
	stream << f.getNumarator() << "/" << f.getNumitor();
	return stream;
}

template <class T>
std::istream& operator>>(std::istream& stream, Rational<T>& f)
{
	T aux;
	std::cout << "Numarator: ";
	stream >> aux;
	f.setNumarator(aux);
	std::cout << "Numitor: ";
	stream >> aux;
	f.setNumitor(aux);
	return stream;
}


template<class T>
Rational<T>& Rational<T>::operator=(const Rational<T>& f)
{
	Rational<T> r = Rational<T>();
	r.numarator = f.numarator;
	r.numitor = f.numitor;
	return r;
}



//End Operatori

//Constructori
template<class T>
Rational<T>::Rational()
{
	this->numarator = 0;
	this->numitor = 1;
}

template<class T>
Rational<T>::Rational(T numarator)
{
	this->numarator = numarator;
	this->numitor = 1;
}

template<class T>
Rational<T>::Rational(T numarator, T numitor)
{
	this->numarator = numarator;
	this->numitor = numitor;
	this->simplificare();
}
template<class T>
Rational<T>::Rational(const Rational<T>& f)
{
	this->numarator = f.numarator;
	this->numitor = f.numitor;
}
//End Constructori

template<class T>
Rational<T>::~Rational()
{
}

template<class T>
T Rational<T>::getNumitor()
{
	return this->numitor;
}

template<class T>
T Rational<T>::getNumarator()
{
	return this->numarator;
}

template<class T>
void Rational<T>::setNumitor(T numitor)
{
	this->numitor = numitor;
}

template<class T>
void Rational<T>::setNumarator(T numarator)
{
	this->numarator = numarator;
}

template<class T>
T Rational<T>::getCMMMC(T nr1, T nr2)
{
	return nr1 * nr2 / getCMMDC(nr1, nr2);
}

template<class T>
T Rational<T>::getCMMDC(T nr1, T nr2)
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
void Rational<T>::print()
{
	std::cout << "Numarator: " << this->numarator << std::endl;
	std::cout << "Numitor: " << this->numitor << std::endl;
}

template<class T>
Rational<T> Rational<T>::scan()
{
	T aux;
	std::cout << "Numarator: ";
	std::cin >> aux;
	this.setNumarator(aux);
	std::cout << "Numitor: ";
	std::cin >> aux;
	this.setNumitor(aux);
	return Rational<T>();
}

template<class T>
void Rational<T>::simplificare()
{
	T cmmdc = getCMMDC(this->numarator, this->numitor);
	this->numarator /= cmmdc;
	this->numitor /= cmmdc;
	if (this->numarator == 0)
		this->numitor = 1;

	if (numitor < 0) {
		this->numarator = -this->numarator;
		this->numitor = -this->numitor;
	}
}
#endif // !_RATIONAL_H