#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
struct Bag {
	std::string Name;
	std::string Section;
	Bag() : Name(""), Section(""){}
	Bag(const std::string& s_, const std::string n_) : Name(s_), Section(n_) {}
	~Bag() = default;
	friend std::istream& operator>>(std::istream& is, Bag& a);
	friend std::ostream& operator<<(std::ostream& os, Bag& a);
};
struct Prod {
	std::string Name;
	int Price;
	Prod() : Name(""), Price(0) {}
	Prod(const std::string& s_,  const int& ew) : Name(s_), Price(ew) {}
	~Prod() = default;
	bool operator==(const Bag& to_cmp) {
		return (Name == to_cmp.Name);
	}
	Prod(const std::string& a, const std::string& b, int c) : Name(a), Price(c) {}
	friend std::istream& operator>>(std::istream& is, Prod& a);
	friend std::ostream& operator<<(std::ostream& os, Prod& a);
};
struct Market {
	std::string Name;
	std::string Section;
	int Price;
	Market() : Name(""), Section(""), Price(0) {}
	Market(const std::string& s_, const std::string n_, const int& ew) : Name(s_), Section(n_), Price(ew) {}
	~Market() = default;
	Market& operator=(const Prod& to_copy) {
		this->Name = to_copy.Name;
		this->Price = to_copy.Price;
		this->Section = "Bacaleya";
		return *this;
	}
	friend std::istream& operator>>(std::istream& is, Market& a);
	friend std::ostream& operator<<(std::ostream& os, Market& a);
};
template <class T>
class PROD
{
	int maxsize;
	T* M;
public:
	int GetCount() {
		return maxsize;
	}
	PROD() : maxsize(0), M(nullptr) {}
	PROD(const int& a) : maxsize(a), M(new T[a]) {}
	PROD(const PROD<T>& a) {
		maxsize = a.maxsize;
		M = new T[maxsize];
		for (int i = 0; i < maxsize; i++)
		{
			M[i] = a.M[i];
		}
	}
	PROD<T>& operator=(const PROD<T>& a) {
		if (&a == this)
		{
			return *this;
		}
		delete[] M;
		this->maxsize = a.maxsize;
		M = new T[maxsize];
		for (int i = 0; i < maxsize; i++)
		{
			M[i] = a.M[i];
		}
		return *this;
	}
	~PROD() {
		M = nullptr;
		delete[] M;
	}
	void ReadData(std::ifstream& file) {
		char* str = new char[1024];
		int i = 0;
		while (!file.eof())
		{
			file.getline(str, 1024, '\n');
			i++;
		}
		delete[] M;
		maxsize = i / 2;
		M = new T[maxsize];
		file.seekg(0);
		i = 0;
		while (!file.eof())
		{
			file >> M[i];
			i++;
		}
	}
	T& operator[](const int& b) {
		return M[b];
	}
	void ReadBinaryData(char* file)
	{
			std::vector<T> result;
			T temp;
			std::fstream f1(file, std::fstream::in | std::fstream::out | std::ios::binary);
			while (!f1.eof()) {
				f1.read((char*)&temp, sizeof(temp));
					result.push_back(temp);
				
			}
			f1.close();
			delete[] M;
			maxsize = result.size();
			M = new T[maxsize];
			for (int i = 0; i < maxsize; i++) {
				M[i] = result[i];
			}
	}
	void WriteData(std::ofstream& file) {
		file << "Наименование товара\t\tСекция\n";
		for (size_t i = 0; i < maxsize; i++)
		{
			file << M[i] << "\n";
		}
	}
	void FindInMass(const std::string& name) {
		bool flag = false;
		for (size_t i = 0; i < GetCount(); i++)
		{
			if (name == M[i].Name) {
				std::cout << M[i];
				flag = true;
			}
		}
		if (!flag) std::cout << "There is no product with such name!";
	}
    template<typename T1> friend std::ostream& operator << (std::ostream& os, const PROD<T>& a);
    template<typename T2> friend std::istream& operator >> (std::istream& is, PROD<T>& a);
	PROD<Market> function(PROD<Prod>& m1, PROD<Bag>& m2) {
		delete[] this->M;
		maxsize = 0;
		PROD<Market> tmp(m1.GetCount());
		bool flag = true;
		for (size_t i = 0, h = 0; i < m1.GetCount(); i++)
		{
			for (size_t j = 0; j < m2.GetCount(); j++)
			{
				if (m1[i] == m2[j])
					flag = false;
			}
			if (flag) {
				maxsize++;
				tmp[h] = m1[i];
				h++;
			}
			flag = true;
		}
		M = new Market[maxsize];
		for (size_t i = 0; i < maxsize; i++)
		{
			M[i] = tmp.M[i];
		}
		return *this;
	}
	void SortDownName() {
		std::sort(M, M + maxsize, [](T& lhs, T& rhs) {
			return lhs.Name > rhs.Name;
			});
	}
	void SortDownSectionName() {
		std::sort(M, M + maxsize, [](T& lhs, T& rhs) {
			if (lhs.Section == rhs.Section)
				return lhs.Name > rhs.Name;
			return lhs.Section < rhs.Section;
		});
	}

};

template<typename T>
std::ostream& operator << (std::ostream& os, const PROD<T>& a)
{
	for (int i = 0; i < a.maxsize; i++)
	{
		os << a.M[i] << "\n";
	}
	return os;
}

template<typename T>
std::istream& operator >> (std::istream& is, PROD<T>& a)
{
	std::string s;
	getline(is, s);
	a.maxsize = stoi(s);
	a.M = new T[a.maxsize];
	for (int i = 0; i < a.maxsize; i++)
	{
		is >> a.M[i];
	}
	return is;
}

