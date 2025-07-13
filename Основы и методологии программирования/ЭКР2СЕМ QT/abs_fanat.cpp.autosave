#include "abs_fanat.h"

Fanat1::Fanat1() :Name(""), Nationality(""), Year(0), N(0) {}

Fanat1::Fanat1(const string& name_, const string nt_, int year_, int n) :Name(name_), Nationality(nt_), Year(year_), N(n) {}

bool Fanat1::operator==(const Fanat1& to_compare) {
    return (Name == to_compare.Name);
}
string Fanat1::GetName() {
    return Name;
}
void Fanat1::SetName(string x) {
    Name = x;
}

ostream& operator<< (ostream& os, const Fanat1& m) {
    os << m.Name << "\t\t\t\t" << m.Nationality << "\t\t\t\t" << m.Year << "\t\t\t\t" << m.N;
    return os;
}
istream& operator>> (istream& is, Fanat1& s) {
    string str;
    getline(is, str);
    s.Name = str;
    getline(is, str);
    s.Nationality = str;
    getline(is, str);
    s.Year = stoi(str);
    getline(is, str);
    s.N = stoi(str);
    return is;
}

Fanat2::Fanat2() :Name(""), Code(0), N(0) {}

Fanat2::Fanat2(const string& name_, int code_, int n) :Name(name_), Code(code_), N(n) {}

bool Fanat2::operator<(const Fanat1& to_compare) {
    return (Name < to_compare.Name);
}
bool Fanat2::operator==(const Fanat2& to_compare) {
    return (Name == to_compare.Name);
}
string Fanat2::GetName() {
    return Name;
}
void Fanat2::SetName(string x) {
    Name = x;
}

bool operator<(const Fanat1& to_compare_1, const Fanat2& to_compare_2) {
    return (to_compare_1.Name < to_compare_2.Name);
}
ostream& operator<< (ostream& os, const Fanat2& f2) {
    os << f2.Name << "\t\t\t\t" << f2.Code << "\t\t\t\t" << f2.N;
    return os;
}
istream& operator>> (istream& is, Fanat2& f2) {
    string str;
    getline(is, str);
    f2.Name = str;
    getline(is, str);
    f2.Code = stoi(str);
    getline(is, str);
    f2.N = stoi(str);
    return is;
}

Fanat3::Fanat3() :Name(""), Nationality(""), Year(0), Code(0), N(0) {}
Fanat3::Fanat3(const string& name_, const string nt_, int year_, int code_, int n) :Name(name_), Nationality(nt_), Year(year_), Code(code_), N(n) {}
bool Fanat3::operator<(const Fanat3& to_compare) {
    return (Name < to_compare.Name);
}
bool Fanat3::operator==(const Fanat3& to_compare) {
    return (Name == to_compare.Name);
}
string Fanat3::GetName() {
    return Name;
}
void Fanat3::SetName(string x) {
    Name = x;
}

ostream& operator<< (ostream& os, const Fanat3& f3) {
    os << f3.Nationality << "\t\t\t\t" << f3.Name << "\t\t\t\t" << f3.N << "\t\t\t\t" << f3.Year << "\t\t\t\t" << f3.Code;
    return os;
}
istream& operator>> (istream& is, Fanat3& f3) {
    string str;
    getline(is, str);
    f3.Name = str;
    getline(is, str);
    f3.Nationality = str;
    getline(is, str);
    f3.Year = stoi(str);
    getline(is, str);
    f3.Code = stoi(str);
    getline(is, str);
    f3.N = stoi(str);
    return is;
}

BF::BF() :count(0), M(nullptr) {}
    BF::BF(const int& c) : count(c), M(new Fanat1[count]) {}
    BF::BF(const BF& to_copy) {
        count = to_copy.count;
        for (int i = 0; i < count; ++i)
            M[i] = to_copy.M[i];
    }
    BF& BF::operator=(const BF& to_copy) {
        if (&to_copy == this)
            return *this;
        else {
            delete[]M;
            M = new Fanat1[to_copy.count];
            count = to_copy.count;
            for (int i = 0; i < count; ++i)
                M[i] = to_copy.M[i];
            return *this;
        }
    }
    void BF::GetFanats(ifstream& file) {
        string str;
        int i;
        getline(file, str);
        i = stoi(str);
        count = i;
        delete[] M;
        M = new Fanat1[count];
        i = 0;
        while (!file.eof())
        {
            file >> M[i];
            i++;
        }
    }
    void BF::PutFanats(ofstream& file) {
        file << "Имя\t\t\tСтрана\t\t\tГод рождения\t\t\tКоличество задержаний\n";
        for (size_t i = 0; i < count; i++)
        {
            file << M[i] << "\n";
        }
    }

    int BF::GetCount() {
        return count;
    }
    Fanat1& BF::operator[](const int& b) {
        return M[b];
    }
    void BF::SortUp() {
        QSort(M, 0, count - 1);
    }
    void BF::QSort(Fanat1* M, int left, int right) {
        int mid = (left + right) / 2;
        Fanat1 x = M[mid];
        int i = left, j = right;
        do {
            while (M[i].Name < x.Name) i++;
            while (x.Name < M[j].Name) j--;
            if (i <= j) {
                swap(M[i], M[j]);
                i++;
                j--;
            }
        } while (i < j);
        if (left < j) QSort(M, left, j);
        if (i < right) QSort(M, i, right);
    }
    void BF::FindInMass(const string& name) {
        bool flag = false;
        for (size_t i = 0; i < GetCount(); i++)
        {
            if (name == M[i].Name) {
                cout << M[i];
                flag = true;
            }
        }
        if (!flag) std::cout << "Нет такого значения.";
    }
    void BF::SortDown() {
        std::sort(M, M + count, [](Fanat1& lhs, Fanat1& rhs) {
            return lhs.Name > rhs.Name;
            });
    }
    ABS_Fanat* BF::Merge(ABS_Fanat* a_1, ABS_Fanat* a_2) { return this; }
    BF::~BF() {
        delete[] M;
    }
    BADBOY::BADBOY() :count(0), M(nullptr) {}
        BADBOY::BADBOY(const int& c) : count(c), M(new Fanat2[count]) {}
        BADBOY::BADBOY(const BADBOY& to_copy) {
            count = to_copy.count;
            for (int i = 0; i < count; ++i)
                M[i] = to_copy.M[i];
        }
        BADBOY& BADBOY::operator=(const BADBOY& to_copy) {
            if (&to_copy == this)
                return *this;
            else {
                delete[]M;
                M = new Fanat2[to_copy.count];
                count = to_copy.count;
                for (int i = 0; i < count; ++i)
                    M[i] = to_copy.M[i];
                return *this;
            }
        }
        void BADBOY::GetFanats(ifstream& file) {
            string str;
            int i;
            getline(file, str);
            i = stoi(str);
            count = i;
            delete[] M;
            M = new Fanat2[count];
            i = 0;
            while (!file.eof())
            {
                file >> M[i];
                i++;
            }
        }
        ABS_Fanat* BADBOY::Merge(ABS_Fanat* a_1, ABS_Fanat* a_2) { return this; }
        void BADBOY::PutFanats(ofstream& file) {
            file << "Имя\tНомер паспорта\tКоличество задержаний\t\n";
            for (size_t i = 0; i < count; i++)
            {
                file << M[i] << "\n";
            }
        }

        int BADBOY::GetCount() {
            return count;
        }
        Fanat2& BADBOY::operator[](const int& b) {
            return M[b];
        }
        void BADBOY::SortUp() {
            QSort(M, 0, count - 1);
        }
        void BADBOY::QSort(Fanat2* M, int left, int right) {
            int mid = (left + right) / 2;
            Fanat2 x = M[mid];
            int i = left, j = right;
            do {
                while (M[i].Name < x.Name) i++;
                while (x.Name < M[j].Name) j--;
                if (i <= j) {
                    swap(M[i], M[j]);
                    i++;
                    j--;
                }
            } while (i < j);
            if (left < j) QSort(M, left, j);
            if (i < right) QSort(M, i, right);
        }
        void BADBOY::FindInMass(const string& name) {
            bool flag = false;
            for (size_t i = 0; i < GetCount(); i++)
            {
                if (name == M[i].Name) {
                    cout << M[i];
                    flag = true;
                }
            }
            if (!flag) std::cout << "Нет такого значения.";
        }
        void BADBOY::SortDown() {
            std::sort(M, M + count, [](Fanat2& lhs, Fanat2& rhs) {
                return lhs.Name > rhs.Name;
                });
        }

        BADBOY::~BADBOY() {
            delete[] M;
        }

        F18::F18() :count(0), M(nullptr) {}
            F18::F18(const int& c) : count(c), M(new Fanat3[count]) {}
            F18::F18(const F18& to_copy) {
                count = to_copy.count;
                for (int i = 0; i < count; ++i)
                    M[i] = to_copy.M[i];
            }
            F18& F18::operator=(const F18& to_copy) {
                if (&to_copy == this)
                    return *this;
                else {
                    delete[]M;
                    M = new Fanat3[to_copy.count];
                    count = to_copy.count;
                    for (int i = 0; i < count; ++i)
                        M[i] = to_copy.M[i];
                    return *this;
                }
            }
            void F18::GetFanats(ifstream& file) {
                string str;
                int i;
                getline(file, str);
                i = stoi(str);
                count = i;
                delete[] M;
                M = new Fanat3[count];
                i = 0;
                while (!file.eof())
                {
                    file >> M[i];
                    i++;
                }
            }
            void F18::PutFanats(ofstream& file) {
                file << "Страна\tИмя \tГод рождения\tКоличество задержаний\tНомер паспорта\n";
                for (size_t i = 0; i < count; i++)
                {
                    file << M[i] << "\n";
                }
            }

            int F18::GetCount() {
                return count;
            }
            Fanat3& F18::operator[](const int& b) {
                return M[b];
            }
            ABS_Fanat* F18::Merge(ABS_Fanat* a_1, ABS_Fanat* a_2) {
                BF* mass_1 = (BF*)a_1;
                BADBOY* mass_2 = (BADBOY*)a_2;
                delete[] M;
                count = mass_2->GetCount();
                if (mass_1->GetCount() <= mass_2->GetCount())
                    count = mass_1->GetCount();
                M = new Fanat3[count];
                int i = 0, j = 0, k = 0;
                mass_1->SortUp();
                mass_2->SortUp();
                while (i < mass_1->GetCount() && j < mass_2->GetCount()) {
                    if (mass_1->M[i] < mass_2->M[j])
                        i++;
                    else if (mass_2->M[j] < mass_1->M[i])
                        j++;
                    else {
                        M[k].Name = mass_2->M[j].Name;
                        M[k].Nationality = mass_1->M[i].Nationality;
                        M[k].Year = mass_1->M[i].Year;
                        M[k].Code = mass_2->M[j].Code;
                        M[k].N = mass_2->M[j].N;
                        i++;
                        j++;
                        k++;
                    }
                }
                count = k;
                return this;
            }
            void F18::QSort(Fanat3* M, int left, int right) {
                int mid = (left + right) / 2;
                Fanat3 x = M[mid];
                int i = left, j = right;
                do {
                    while (M[i].Name < x.Name) i++;
                    while (x.Name < M[j].Name) j--;
                    if (i <= j) {
                        swap(M[i], M[j]);
                        i++;
                        j--;
                    }
                } while (i < j);
                if (left < j) QSort(M, left, j);
                if (i < right) QSort(M, i, right);
            }
            void F18::FindInMass(const string& name) {
                bool flag = false;
                for (size_t i = 0; i < GetCount(); i++)
                {
                    if (name == M[i].Name) {
                        cout << M[i];
                        flag = true;
                    }
                }
                if (!flag) std::cout << "Нет такого значения.";
            }
            void F18::SortDown() {
                std::sort(M, M + count, [](Fanat3& lhs, Fanat3& rhs) {
                    return lhs.Name > rhs.Name;
                    });
            }
            void F18::SortUp() {
                QSort(M, 0, count - 1);
            }
            void F18::QSort(Fanat1* M, int left, int right) {
                int mid = (left + right) / 2;
                Fanat1 x = M[mid];
                int i = left, j = right;
                do {
                    while (M[i].Name > x.Name) i++;
                    while (x.Name > M[j].Name) j--;
                    if (i <= j) {
                        swap(M[i], M[j]);
                        i++;
                        j--;
                    }
                } while (i < j);
                if (left < j) QSort(M, left, j);
                if (i < right) QSort(M, i, right);
            }
            F18::~F18() {
                delete[] M;
            }
