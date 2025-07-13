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
	bool operator==(const Bag& to_cmp) {
		return (Name == to_cmp.Name);
	}
	friend std::istream& operator>>(std::istream& is, Bag& a);
	friend std::ostream& operator<<(std::ostream& os, Bag& a);
};
struct Prod {
	std::string Name;
	int Price;
	Prod() : Name(""), Price(0) {}
	Prod(const std::string& s_,  const int& ew) : Name(s_), Price(ew) {}
	~Prod() = default;
	bool operator==(const Prod& to_cmp) {
		return (Name == to_cmp.Name);
	}
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
	bool operator==(const Market& to_cmp) {
		return (Name == to_cmp.Name);
	}
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
	int count;
	T* M;
	int maxsize;
public:
	int GetCount() {
		return count;
	}
	PROD() : count(0), M(nullptr) {}
	PROD(const int& a) : count(a), M(new T[a]) {}
	PROD(const PROD<T>& a) {
		count = a.count;
		M = new T[count];
		for (int i = 0; i < count; i++)
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
		this->count = a.count;
		M = new T[count];
		for (int i = 0; i < count; i++)
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
		count = i / 2;
		M = new T[count];
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
	void WriteBinaryData(char* file)
	{
		std::fstream out;
		out.open(file, std::ofstream::out | std::ofstream::binary);
		if (!out.is_open())
		{
			std::cout << "Open file failed.\n";
		}
		else
		{
			int i = 0;
			while (i < count)
			{
				out.write((char*)&M[i], sizeof(T));
				i++;
			}
			out.close();
		}
	}
	void ReadBinaryData(char* file)
	{
			std::vector<T> result;
			T temp;
			std::ifstream f1(file, std::ios::binary);
			while (!f1.eof()) {
				f1.read((char*)&temp, sizeof(temp));
				result.push_back(temp);
			}
			f1.close();
			delete[] M;
			//result.resize(result.size() - 1);
			count = result.size();
			M = new T[count];
			for (int i = 0; i < count; i++) {
				M[i] = result[i];
			}

	}
	void WriteData(std::ofstream& file) {
		file << "Наименование товара\t\tСекция\n";
		for (size_t i = 0; i < count; i++)
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
	template<typename T> friend std::ostream& operator << (std::ostream& os, const PROD<T>& a);
	template<typename T> friend std::istream& operator >> (std::istream& is, PROD<T>& a);
	PROD<Market> function(PROD<Prod>& m1, PROD<Bag>& m2) {
		delete[] this->M;
		count = 0;
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
				count++;
				tmp[h] = m1[i];
				h++;
			}
			flag = true;
		}
		M = new Market[count];
		for (size_t i = 0; i < count; i++)
		{
			M[i] = tmp.M[i];
		}
		return *this;
	}
	void SortDownName() {
		std::sort(M, M + count, [](T& lhs, T& rhs) {
			return lhs.Name > rhs.Name;
			});
	}
	void SortDownSectionName() {
		std::sort(M, M + count, [](T& lhs, T& rhs) {
			if (lhs.Section == rhs.Section)
				return lhs.Name > rhs.Name;
			return lhs.Section < rhs.Section;
		});
	}

};

template<typename T>
std::ostream& operator << (std::ostream& os, const PROD<T>& a)
{
	for (int i = 0; i < a.count; i++)
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
	a.count = stoi(s);
	a.M = new T[a.count];
	for (int i = 0; i < a.count; i++)
	{
		is >> a.M[i];
	}
	return is;
}

