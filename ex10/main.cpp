#include "stdafx.h"
#include "COBS.h"

int main()
{
	char cOperation;
	cout << "Enter the first letter of the operation (e - encode; d - decode):";
	cin >> cOperation; cin.get();

	if (cOperation != 'e' && cOperation != 'd') {
		printf("Error: can't recognize this operation!...\n");
		return -1;
	}

	string sFInName, sFOutName;
	cout << "Enter name of Input File:" << endl;
	getline(cin, sFInName);
	cout << "Enter name of Output File:" << endl;
	getline(cin, sFOutName);

	struct stat stat_buf;
	int rc = stat(sFInName.c_str(), &stat_buf);
	if (rc == -1)
		cout << "can't open '" << sFInName << "'" << endl;

	unsigned int inLen = stat_buf.st_size;
	char *buf = new char[inLen];
	bool ans = check(buf, 'c');
	cout << "IN = " << ans << endl;
	ifstream ifs;
	ifs.open(sFInName, ios_base::binary);

	if (ifs.is_open())
	{
		ifs.read(buf, inLen);
		ifs.close();
	}

	unsigned int outlen = (inLen + 1 + (inLen / 254) + 1);
	char* outbuf = new char[outlen];
	if (cOperation == 'e') {
		unsigned int encoded_len = COBSEncode((const unsigned char*)buf, inLen, (unsigned char*)outbuf,'c');
		ofstream ofs;
		ofs.open(sFOutName, ios_base::binary);

		if (ofs.is_open()) {
			ofs.write(outbuf, encoded_len);
			ofs.close();
		}

		cout << encoded_len << endl;
	}

	else {
		unsigned int decoded_len = COBSDecode((const unsigned char*)buf, inLen, (unsigned char*)outbuf,'c');
		ofstream ofs;
		ofs.open(sFOutName, ios_base::binary);

		if (ofs.is_open()) {
			ofs.write(outbuf, decoded_len);
			ofs.close();
		}

		cout << decoded_len << endl;
		int ans1 = check(outbuf, 'c');
		cout << "OUT = " << ans1 << endl;
	}

	for (int i = 0; i < outlen; i++)
		std::cout << outbuf[i];

	delete[] outbuf;
	delete[] buf;
}