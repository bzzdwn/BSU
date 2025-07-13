#ifndef ABS_FANAT_H
#define ABS_FANAT_H
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct Fanat2;
struct Fanat1 {
    string Name;
    string Nationality;
    int Year;
    int N;
    Fanat1();
    Fanat1(const string& name_, const string nt_, int year_, int n);
    friend ostream& operator<< (ostream& os, const Fanat1& m);
    friend istream& operator>> (istream& is, Fanat1& s);
    friend bool operator<(const Fanat1& to_compare_1, const Fanat2& to_compare_2);
    bool operator==(const Fanat1& to_compare);
    string GetName();
    void SetName(string x);
};
struct Fanat2 {
    string Name;
    int Code, N;
    Fanat2();
    Fanat2(const string& name_, int code_, int n) ;
    friend ostream& operator<< (ostream& os, const Fanat2& f2);
    friend istream& operator>> (istream& is, Fanat2& f2);
    bool operator<(const Fanat1& to_compare);
    bool operator==(const Fanat2& to_compare);
    string GetName();
    void SetName(string x);
};
struct Fanat3 {
    string Name;
    string Nationality;
    int Year, Code, N;
    Fanat3();
    Fanat3(const string& name_, const string nt_, int year_, int code_, int n);
    bool operator<(const Fanat3& to_compare);
    bool operator==(const Fanat3& to_compare);
    string GetName();
    void SetName(string x);
};
class ABS_Fanat
{
public:
    virtual void GetFanats(ifstream&) = 0;
    virtual void PutFanats(ofstream&) = 0;
    virtual ABS_Fanat* Merge(ABS_Fanat*, ABS_Fanat*) = 0;
    virtual void SortUp() = 0;
    virtual void SortDown() = 0;
    virtual void FindInMass(const string& name) = 0;
};

class BF :public ABS_Fanat {
    int count;
    Fanat1* M;
public:
    BF();
    BF(const int& c);
    BF(const BF& to_copy) ;
    BF& operator=(const BF& to_copy);
    void GetFanats(ifstream& file) override;
    void PutFanats(ofstream& file) override;
    int GetCount();
    Fanat1& operator[](const int& b);
    void SortUp() override;
    void QSort(Fanat1* M, int left, int right);
    void FindInMass(const string& name) override;
    void SortDown() override;
    ABS_Fanat* Merge(ABS_Fanat* a_1, ABS_Fanat* a_2);
    friend class F18;
    virtual ~BF();
};

class BADBOY :public ABS_Fanat {
    int count;
    Fanat2* M;
public:
    BADBOY();
    BADBOY(const int& c);
    BADBOY(const BADBOY& to_copy);
    BADBOY& operator=(const BADBOY& to_copy);
    void GetFanats(ifstream& file) override ;
    ABS_Fanat* Merge(ABS_Fanat* a_1, ABS_Fanat* a_2);
    void PutFanats(ofstream& file) override ;

    int GetCount();
    Fanat2& operator[](const int& b) ;
    void SortUp() override ;
    void QSort(Fanat2* M, int left, int right);
    void FindInMass(const string& name);
    void SortDown() override ;

    virtual ~BADBOY();
    friend class F18;
};
class F18 :public ABS_Fanat {
    int count;
    Fanat3* M;
public:
    F18();
    F18(const int& c) ;
    F18(const F18& to_copy) ;
    F18& operator=(const F18& to_copy) ;
    void GetFanats(ifstream& file) override ;
    void PutFanats(ofstream& file) override ;

    int GetCount() ;
    Fanat3& operator[](const int& b) ;
    ABS_Fanat* Merge(ABS_Fanat* a_1, ABS_Fanat* a_2);
    void QSort(Fanat3* M, int left, int right) ;
    void FindInMass(const string& name) ;
    void SortDown() override ;
    void SortUp() override ;
    void QSort(Fanat1* M, int left, int right);
    virtual ~F18();
};

#endif // ABS_FANAT_H
