#pragma once
#include <fstream>
#include <iostream>
template<class T> class MED
{
private:
    int count;
    T* M;
public:
    MED():count (0), M(nullptr){}
    MED(const int& c_) : count(c_), M(new T[count]) {}
    MED(const MED<T>& to_copy) {
        count = to_copy.count;
        M = new T[count];
        for (size_t i = 0; i < count; i++)
        {
            M[i] = to_copy.M[i];
        }
    }
    MED<T>& operator=(const MED<T>& to_copy) {
        if (&to_copy == this)
            return *this;
        else {
            delete[] M;
            count = to_copy.count;
            M = new T[count];
            for (size_t i = 0; i < count; i++)
            {
                M[i] = to_copy.M[i];
            }
            return *this;
        }
    }
    T& operator[](const int& b) {
        return M[b];
    }
    MED<T> Union(MED<T>& m_1, MED<T>& m_2) {
        delete[] M;
        int size = m_1.GetCount() + m_2.GetCount();
        count = size;
        M = new T[count];
        for (size_t i = 0; i < m_1.GetCount(); i++)
        {
            M[i] = m_1[i];
        }
        for (size_t i = 0; i < m_2.GetCount(); i++)
        {
            M[m_1.GetCount() + i] = m_2[i];
        }
        return *this;
    }
    int GetCount() {
        return count;
    }
    template <class T2>
    friend std::ostream& operator<< (std::ostream& v, const MED<T2>& mas);
    template <class T2>
    friend std::istream& operator>> (std::istream& f, MED<T2>& mas);
    virtual ~MED() {
        delete[]M;
    }

};
template <class T2>
std::ostream& operator <<(std::ostream& v, const MED<T2>& mas) {
    for (int i = 0; i < mas.count; i++)
        v << mas.M[i];
    return v;
}
template <class T2>
std::istream& operator>> (std::istream& f, MED<T2>& mas) {
    for (int i = 0; i < mas.count; i++)
        f >> mas.M[i];
    return f;

}






