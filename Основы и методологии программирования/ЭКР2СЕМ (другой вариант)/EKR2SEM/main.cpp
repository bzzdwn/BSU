#include "PROD.h"
template<class T>
void convert_from_txt_to_bin(char* filename, char* filename_binary) {
	T userInfo;
	std::ifstream in(filename);
	std::ofstream out(filename_binary, std::ios::binary);
		while (!in.eof())
		{
			in >> userInfo;
			out.write((char*)&userInfo, sizeof(userInfo));
		}
}
int main() {
	PROD<Prod> M1, M2;
	PROD<Bag> K1;
	std::ifstream in1("F1.txt");
	std::ifstream in2("F2.txt");
	std::ofstream out1("out_1.txt");
	std::ofstream out2("out_sortName.txt");
	std::ofstream out3("out_sortSect.txt");
	convert_from_txt_to_bin<Prod>((char*)"F1.txt", (char*)"F1_BIN.bin");
	std::ifstream in3("F1_BIN.bin", std::ios::binary);
	M1.ReadData(in1);
	K1.ReadData(in2);
	PROD<Market> R(M1.GetCount());
	R.function(M1, K1);
	std::ofstream out4("Market.txt");
	R.WriteData(out1);
	out4 << R;
	std::cout << M1;
	R.FindInMass("Sugar");
	K1.WriteData(out3);

	M2.ReadBinaryData((char*)"F1_BIN.bin");
	std::ofstream out5("Binary_Res.txt");
	M2.WriteData(out5);
	/*M2.WriteBinaryData((char*)"F1_BIN.bin");
	M2.ReadBinaryData((char*)"F1_BIN.bin");
	M2.WriteData(out5);*/
}